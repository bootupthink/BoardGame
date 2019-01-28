#pragma once
#include "Person.h"

class Smoker :public Person
{
private:
	int SmokingCount;
	void Ability() override;
	void PrintCharacterInfo() override;
public:
	Smoker(int num);
	void RollingDice() override;
};

