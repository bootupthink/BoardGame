#pragma once
#include "Person.h"
class Game
{
private:
	static void DrawingLocation(Color LocationColor);
public:
	static void GameInfo();
	static Person* RandomSelect(int PlayerNumber);
};

