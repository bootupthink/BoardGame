#include "pch.h"
#include "Game.h"
#include "FatMan.h"
#include "Slave.h"
#include "Smoker.h"

void Game::DrawingLocation(Color LocationColor)
{
	Cell Location[4][4];
	for (int i = 1; i < 3; ++i)
		for (int j = 1; j < 3; ++j)
			Location[i][j].ChangeColor(LocationColor);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			Location[i][j].Print();
		std::cout << std::endl;
	}
}

void Game::GameInfo()
{
	std::cout << "�� ������ �÷��̾ Ż���� ������ �������� ���� �����Դϴ�." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	std::cout << "�ִ� 4����� �÷��� �� �� ������ ���� ���� �Ķ� ��� �ʷϻ� ���� ������ �ֽ��ϴ�." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	DrawingLocation(BLACK);
	std::cout << std::endl;
	std::cout << "���� �߰��߰��� �׷��� ������ ������ �ƿ��� �Դϴ�." << std::endl;
	std::cout << "�÷��̾ �ֻ����� ���� �̰��� �����ϰ� �Ǹ� �ƿ����� ������ ���� ������ ���� �˴ϴ�." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	DrawingLocation(PURPLE);
	std::cout << std::endl;
	std::cout << "���� �������� ���̴� ����� ������ ��ٸ��Դϴ�. " << std::endl; 
	std::cout << "�� ��ٸ��� �̿��ϸ� �� ������ �� ���������� �ڷ� �� ���� �ֽ��ϴ�." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	system("cls");
	std::cout << "������ �����Ϸ��� EnterŰ�� ���� �ּ���" << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
}

Person* Game::RandomSelect(int PlayerNumber)
{
	Person *Player;
	int RandomNumber = (rand() % 3) + 1;

	switch (RandomNumber)
	{
	case 1:
		Player = new FatMan(PlayerNumber);
		return Player;
	case 2:
		Player = new Slave(PlayerNumber);
		return Player;
	case 3:
		Player = new Smoker(PlayerNumber);
		return Player;
	}
}
