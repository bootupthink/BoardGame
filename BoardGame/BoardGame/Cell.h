#pragma once
#include <Windows.h>
#include <iostream>

#define BLACK 0
#define PURPLE 5
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define RED 12
#define YELLOW 14
#define WHITE 15

#define AOG 1
#define LADDER 2
#define GOAL 3

typedef unsigned short Color;

class Cell
{
	friend class Board;
private:
	char cell[2];
	Color color;
	Color Origin;
	int Attribute;
	int LocationNumber;
	Cell *LadderGoal;

	void SetPrintingColor(Color color);
	void SetOriginColor();
	void ChangeOriginColor(Color color);
	void SetConsoleColor();
	void SetAttribute(int attribute);
	void SetLadderGoal(Cell *goal);

public:
	Cell(Color color = GRAY, Color origin = GRAY);
	void ChangeColor(Color color);
	int GetAttribute() const;
	int GetLocationNumber() const;
	void SetLocationNumber(int Number);
	Cell* GetLadderGoal();
	void Print();
};

