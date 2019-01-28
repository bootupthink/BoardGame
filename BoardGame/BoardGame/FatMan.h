#pragma once
#include "Person.h"

class FatMan : public Person
{
private:
	void Ability() override;
	void PrintCharacterInfo() override;
public:
	FatMan(int number);
};

