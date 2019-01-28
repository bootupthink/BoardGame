#pragma once
#include "Person.h"

class Slave : public Person
{
	void Ability() override;
	void PrintCharacterInfo() override;
public:
	Slave(int num);
	void SetLocatedAOG() override;
};

