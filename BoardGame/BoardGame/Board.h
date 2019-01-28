#pragma once
#include "Cell.h"
#include "Person.h"

class Board
{
private:
	Cell (*cells)[16];
	Cell *Locations[25][4];
	Color PlayerColors[4];
	void SetLocations();
	void PutPlayer(const Person *Player, int LocationNumber);
	void CleanUpFootPrint(const Person *Player, int LocationNumber);
	void SetEventLocations();
	void SetEventLocation(int LocationNumber, int attribute);
	void SetLadderGoal(int start, int goal);
public:
	Board();
	~Board();
	void Print() const;
	void PutPlayerFirstLocation(Person *Player);
	void MovePlayer(Person *Player);
	void LadderAction(Person *Player);
};

