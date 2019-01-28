#include "pch.h"
#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Event.h"
#include "FatMan.h"
#include "Smoker.h"
#include "Slave.h"
#include "Game.h"
#include <ctime>

int main()
{
	Game::GameInfo();

	srand(time(NULL));
	Board board;
	Person *Player[4];
	for(int i = 0; i < 4; ++i)
	{
		Player[i] = Game::RandomSelect(i);
		board.PutPlayerFirstLocation(Player[i]);
	}
	board.Print();
	Event even(&board);

	int count = 4;
	while(true)
	{
		int PlayerNum = count % 4;
		board.Print();
		Player[PlayerNum]->RollingDice();
		Sleep(1000);
		board.MovePlayer(Player[PlayerNum]);
		even.GenerateEvent(Player[PlayerNum]);
		if(even.IsInGoal(Player[PlayerNum]))
			break;
		count++;
	}

	return 0;
}
