#include "pch.h"
#include "Smoker.h"


void Smoker::Ability()
{
	SmokingCount++;
	std::cout << GetNumber() + 1 << "플레이어의 담배타임 카운트가 1 증가합니다. Count : "
		<< SmokingCount << std::endl;
	std::cout << "Press Enter" << std::endl;
	getchar();
}

void Smoker::PrintCharacterInfo()
{
	system("cls");
	std::cout << GetNumber() + 1 << "플레이어는 니코틴 중독자입니다.\n" << std::endl;
	std::cout << "니코틴 중독자는 주사위를 3번째 굴릴때 담배타임을 가지는 특성이 있습니다.\n" << std::endl;
	std::cout << "Press Enter" << std::endl;
	getchar();
}

Smoker::Smoker(int num)
	:Person(num)
{
	SmokingCount = 0;
	PrintCharacterInfo();
}

void Smoker::RollingDice()
{
	if(SmokingCount == 2)
	{
		std::cout << GetNumber() + 1 << "플레이어가 담배타임을 가집니다(1회 휴식)" << std::endl;
		SmokingCount = 0;
		MoveCount = 0;
		std::cout << "Press Enter" << std::endl;
		getchar();
	}
	else if (LocatedAOG)
	{
		MoveCount = 0;
		--RestCounterInAOG;
		std::cout << GetNumber() + 1 << "플레이어가 아오지에 끌려가 노동중입니다." << std::endl;
		std::cout << "Press Enter" << std::endl;
		getchar();
	}

	else
	{
		std::cout << std::endl << GetNumber() + 1 << " 플레이어의 차례입니다 주사위를 굴리세요" << std::endl;
		std::cout << "\n\tPress Enter" << std::endl;
		getchar();
		MoveCount = rand() % 6 + 1;
		std::cout << "주사위 눈금 : " << MoveCount << std::endl;
		Ability();
	}
}
