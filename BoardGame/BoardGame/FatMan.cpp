#include "pch.h"
#include "FatMan.h"

FatMan::FatMan(int number)
	:Person(number)
{
	PrintCharacterInfo();
}

void FatMan::Ability()
{
	std::cout << "������ ȿ���� �ֻ��� ���ݰ��� 1 ���� �߽��ϴ�." << std::endl;
	this->MoveCount -= 1;
	std::cout << "\n\tPress Enter" << std::endl;
	getchar();
}

void FatMan::PrintCharacterInfo()
{
	system("cls");
	std::cout << GetNumber() + 1 << "�÷��̾�� �����Դϴ�.\n" << std::endl;
	std::cout << "������ ü�� ������ ���� �ʾ� ü���� �������ϴ�.\n�ֻ����� ���� �� ���� �ֻ��� ���ݰ��� 1 �����ϴ� ȿ���� Ư���� �ֽ��ϴ�.\n" << std::endl;
	std::cout << "Press Enter" << std::endl;
	getchar();
}
