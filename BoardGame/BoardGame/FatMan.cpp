#include "pch.h"
#include "FatMan.h"

FatMan::FatMan(int number)
	:Person(number)
{
	PrintCharacterInfo();
}

void FatMan::Ability()
{
	std::cout << "고도비만의 효과로 주사위 눈금값이 1 감소 했습니다." << std::endl;
	this->MoveCount -= 1;
	std::cout << "\n\tPress Enter" << std::endl;
	getchar();
}

void FatMan::PrintCharacterInfo()
{
	system("cls");
	std::cout << GetNumber() + 1 << "플레이어는 고도비만입니다.\n" << std::endl;
	std::cout << "고도비만은 체중 관리를 하지 않아 체력이 떨어집니다.\n주사위를 굴릴 때 마다 주사위 눈금값이 1 감소하는 효과를 특성이 있습니다.\n" << std::endl;
	std::cout << "Press Enter" << std::endl;
	getchar();
}
