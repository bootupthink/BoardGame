#include "pch.h"
#include "Cell.h"

Cell::Cell(Color color, Color origin)
{
	this->color = color;
	this->Origin = origin;
	cell[0] = ' ';
	cell[1] = ' ';
}

void Cell::SetPrintingColor(Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (color << 4));
}

void Cell::ChangeColor(Color color)
{
	this->color = color;
}

void Cell::SetOriginColor()
{
	color = Origin;
}

void Cell::ChangeOriginColor(Color color)
{
	Origin = color;
}

void Cell::SetConsoleColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE | (BLACK << 4));
}

void Cell::Print()
{
	SetPrintingColor(color);
	std::cout << cell[0];
	std::cout << cell[1];
	SetConsoleColor();
}

void Cell::SetAttribute(int attribute)
{
	Attribute = attribute;
}

void Cell::SetLadderGoal(Cell* goal)
{
	LadderGoal = goal;
}

int Cell::GetAttribute() const
{
	return Attribute;
}

int Cell::GetLocationNumber() const
{
	return LocationNumber;
}

Cell* Cell::GetLadderGoal()
{
	return LadderGoal;
}

void Cell::SetLocationNumber(int Number)
{
	LocationNumber = Number;
}
