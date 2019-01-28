#include "pch.h"
#include "Slave.h"


void Slave::Ability()
{
	std::cout << "";
}

void Slave::PrintCharacterInfo()
{
	system("cls");
	std::cout << GetNumber() + 1 << "플레이어는 노동자입니다.\n" << std::endl;
	std::cout << "노동자는 아오지에 끌려갈 때 마다 2턴씩 쉬는 특성이 있습니다.\n" << std::endl;
	std::cout << "Press Enter" << std::endl;
	getchar();
}

Slave::Slave(int num)
	:Person(num)
{
	PrintCharacterInfo();
}

void Slave::SetLocatedAOG()
{
	if (LocatedAOG == false)
	{
		RestCounterInAOG = 2;
	}
	LocatedAOG = !LocatedAOG;
}
