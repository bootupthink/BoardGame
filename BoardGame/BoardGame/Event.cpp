#include "pch.h"
#include "Event.h"

void Event::BeDraggedAOG(Person* Player)
{
	const bool IsInAOG = Player->GetLocatedAOG();
	const int RestCount = Player->GetRestCount();
	const int PlayerNumber = Player->GetNumber();
	if(IsInAOG && RestCount == 0)
	{
		std::cout << PlayerNumber + 1 << " 플레이어가 아오지에서 벗어났습니다." << std::endl;
		Player->SetLocatedAOG();
		getchar();
		std::cout << "Press Enter" << std::endl;
	}
	else if(RestCount == 0)
	{
		std::cout << PlayerNumber + 1 << " 플레이어가 잡혀 아오지로 끌려갑니다." << std::endl;
		Player->SetLocatedAOG();
		getchar();
		std::cout << "Press Enter" << std::endl;
	}
}

void Event::UseLadder(Person* Player)
{
	board->LadderAction(Player);
}

Event::Event(Board* board)
{
	this->board = board;
}

void Event::GenerateEvent(Person* Player)
{
	const int Attribute = Player->GetLocatedCell()->GetAttribute();

	switch(Attribute)
	{
	case 1:
		BeDraggedAOG(Player);
		break;
	case 2:
		UseLadder(Player);
		GenerateEvent(Player);
		break;
	default:
		break;
	}
}

bool Event::IsInGoal(Person* Player)
{
	const int Attribute = Player->GetLocatedCell()->GetAttribute();
	const int PlayerNumber = Player->GetNumber();
	if(Attribute == 3)
	{
		std::cout << PlayerNumber + 1 << "플레이어의 승리입니다." << std::endl;
		return true;
	}

	else
		return false;
}
