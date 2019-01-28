#pragma once
#include "Board.h"

class Event
{
private:
	Board *board;
	void BeDraggedAOG(Person *Player);
	void UseLadder(Person *Player);
public:
	Event(Board *board);
	void GenerateEvent(Person *Player);
	bool IsInGoal(Person *Player);
};

