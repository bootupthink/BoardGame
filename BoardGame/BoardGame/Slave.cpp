#include "pch.h"
#include "Slave.h"


void Slave::Ability()
{
	std::cout << "";
}

void Slave::PrintCharacterInfo()
{
	system("cls");
	std::cout << GetNumber() + 1 << "�÷��̾�� �뵿���Դϴ�.\n" << std::endl;
	std::cout << "�뵿�ڴ� �ƿ����� ������ �� ���� 2�Ͼ� ���� Ư���� �ֽ��ϴ�.\n" << std::endl;
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
