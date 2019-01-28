#include "pch.h"
#include "Board.h"
#include "Person.h"

void Board::SetLocations()
{
	int FrontIndex = 1;
	int BackIndex = -2;
	for (int i = 0; i < 25; ++i)
	{
		if (i != 0 && i % 5 == 0)
			FrontIndex += 3;

		if ((i > 5 && i < 10) || (i > 15 && i < 20))
			BackIndex -= 3;

		else if (i != 0 && i % 5 == 0)
			;

		else
			BackIndex += 3;

		for (int j = 0; j < 4; ++j)
		{
			if (j >= 0 && j <= 1)
			{
				if (j % 2 == 0)
					Locations[i][j] = &cells[FrontIndex][BackIndex];
				else
					Locations[i][j] = &cells[FrontIndex][BackIndex + 1];
			}
			else
			{
				if (j % 2 == 0)
					Locations[i][j] = &cells[FrontIndex + 1][BackIndex];
				else
					Locations[i][j] = &cells[FrontIndex + 1][BackIndex + 1];
			}
		}
	}
	for(int i = 0; i < 25; ++i)
		for (int j = 0; j < 4; ++j)
		{
			Locations[i][j]->SetLocationNumber(i);
			Locations[i][j]->SetAttribute(0);
		}
}

void Board::PutPlayer(const Person *Player, int LocationNumber)
{
	const int PlayerNumber = Player->GetNumber();
	Locations[LocationNumber][PlayerNumber]->ChangeColor(PlayerColors[PlayerNumber]);
}

void Board::CleanUpFootPrint(const Person *Player, int LocationNumber)
{
	const int PlayerNumber = Player->GetNumber();
	Locations[LocationNumber][PlayerNumber]->SetOriginColor();
}

void Board::SetEventLocations()
{
	SetEventLocation(3, AOG);
	SetEventLocation(4, LADDER);
	SetLadderGoal(4, 14);
	SetEventLocation(10, AOG);
	SetEventLocation(12, LADDER);
	SetLadderGoal(12, 8);
	SetEventLocation(16, LADDER);
	SetLadderGoal(16, 21);
	SetEventLocation(17, AOG);
	SetEventLocation(22, LADDER);
	SetLadderGoal(22, 12);
	SetEventLocation(23, AOG);
	SetEventLocation(24, GOAL);
}

void Board::SetEventLocation(int LocationNumber, int attribute)
{
	Color color;

	switch(attribute)
	{
	case AOG:
		color = BLACK;
		break;
	case LADDER:
		color = PURPLE;
		break;
	case GOAL:
		color = WHITE;
		break;
	default:
		color = WHITE;
		attribute = 0;
		break;
	}

	for (int i = 0; i < 4; ++i)
	{
		Locations[LocationNumber][i]->ChangeColor(color);
		Locations[LocationNumber][i]->ChangeOriginColor(color);
		Locations[LocationNumber][i]->SetAttribute(attribute);
	}
}

void Board::SetLadderGoal(int start, int goal)
{
	for(int i = 0; i < 4; ++i)
		Locations[start][i]->SetLadderGoal(Locations[goal][i]);
}

Board::Board()
{
	cells = new Cell[16][16];

	for(int i = 0; i < 16; ++i)
		for(int j = 0; j < 16; ++j)
		{
			if (i % 3 == 0 || j % 3 == 0)
				continue;
			else
			{
				cells[i][j].ChangeColor(WHITE);
				cells[i][j].ChangeOriginColor(WHITE);
			}
		}

	SetLocations();
	SetEventLocations();

	PlayerColors[0] = RED;
	PlayerColors[1] = BLUE;
	PlayerColors[2] = YELLOW;
	PlayerColors[3] = GREEN;
}

Board::~Board()
{
	delete [] cells;
}

void Board::Print() const
{
	system("cls");
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
			cells[i][j].Print();
		std::cout << std::endl;
	}
}

void Board::PutPlayerFirstLocation(Person* Player)
{
	const int PlayerNumber = Player->GetNumber();
	Player->SetLocatedCell(Locations[0][PlayerNumber]);
	PutPlayer(Player, 0);
}

void Board::MovePlayer(Person* Player)
{
	const int MoveCount = Player->GetMoveCount();
	const int LocationNumber = Player->GetLocationNumber();
	const int PlayerNumber = Player->GetNumber();
	int NextLocation;
	if (LocationNumber + MoveCount >= 24)
		NextLocation = 24;
	else
		NextLocation = LocationNumber + MoveCount;

	CleanUpFootPrint(Player, LocationNumber);
	Player->SetLocatedCell(Locations[NextLocation][PlayerNumber]);
	Player->SetLocationNumber(NextLocation);

	for(int i = 0; i < MoveCount; ++i)
	{
		if (LocationNumber + i >= 24)
			break;
		PutPlayer(Player, LocationNumber + (i + 1));
		Print();
		if(i == 0 && LocationNumber == 0)
			CleanUpFootPrint(Player, 0);
		CleanUpFootPrint(Player, LocationNumber + (i + 1));
		Sleep(500);
	}

	PutPlayer(Player, NextLocation);
}

void Board::LadderAction(Person* Player)
{
	Cell *PlayerLocation = Player->GetLocatedCell();
	Cell *LadderGoal = PlayerLocation->GetLadderGoal();
	const int LocationNumber = Player->GetLocationNumber();
	const int PlayerNumber = Player->GetNumber();
	const int GoalLocation = LadderGoal->GetLocationNumber();

	std::cout << PlayerNumber + 1 << "플레이어가 사다리를 사용합니다." << std::endl;
	std::cout << "Press Enter" << std::endl;
	getchar();
	CleanUpFootPrint(Player, LocationNumber);
	PutPlayer(Player, GoalLocation);
	Player->SetLocatedCell(LadderGoal);
	Player->SetLocationNumber(GoalLocation);
	Print();
}