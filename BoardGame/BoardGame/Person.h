#pragma once
#include <cstdlib>
#include <iostream>
#include "Cell.h"

class Person
{
protected:
	int MoveCount;
	Cell *LocatedCell;
	int LocationNum;
	int RestCounterInAOG;
	int Number;
	bool LocatedAOG;
	virtual void Ability() = 0;
	virtual void PrintCharacterInfo() = 0;
public:
	Person(int number);
	virtual void RollingDice();
	void SetLocatedCell(Cell *cell);
	Cell* GetLocatedCell();
	int GetNumber() const;
	int GetMoveCount() const;
	int GetLocationNumber() const;
	void SetLocationNumber(int LocationNumber);
	bool GetLocatedAOG() const;
	virtual void SetLocatedAOG();
	int GetRestCount();
};