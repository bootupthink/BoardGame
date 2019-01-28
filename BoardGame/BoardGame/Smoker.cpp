#include "pch.h"
#include "Smoker.h"


void Smoker::Ability()
{
	SmokingCount++;
	std::cout << GetNumber() + 1 << "�÷��̾��� ���Ÿ�� ī��Ʈ�� 1 �����մϴ�. Count : "
		<< SmokingCount << std::endl;
	std::cout << "Press Enter" << std::endl;
	getchar();
}

void Smoker::PrintCharacterInfo()
{
	system("cls");
	std::cout << GetNumber() + 1 << "�÷��̾�� ����ƾ �ߵ����Դϴ�.\n" << std::endl;
	std::cout << "����ƾ �ߵ��ڴ� �ֻ����� 3��° ������ ���Ÿ���� ������ Ư���� �ֽ��ϴ�.\n" << std::endl;
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
		std::cout << GetNumber() + 1 << "�÷��̾ ���Ÿ���� �����ϴ�(1ȸ �޽�)" << std::endl;
		SmokingCount = 0;
		MoveCount = 0;
		std::cout << "Press Enter" << std::endl;
		getchar();
	}
	else if (LocatedAOG)
	{
		MoveCount = 0;
		--RestCounterInAOG;
		std::cout << GetNumber() + 1 << "�÷��̾ �ƿ����� ������ �뵿���Դϴ�." << std::endl;
		std::cout << "Press Enter" << std::endl;
		getchar();
	}

	else
	{
		std::cout << std::endl << GetNumber() + 1 << " �÷��̾��� �����Դϴ� �ֻ����� ��������" << std::endl;
		std::cout << "\n\tPress Enter" << std::endl;
		getchar();
		MoveCount = rand() % 6 + 1;
		std::cout << "�ֻ��� ���� : " << MoveCount << std::endl;
		Ability();
	}
}
