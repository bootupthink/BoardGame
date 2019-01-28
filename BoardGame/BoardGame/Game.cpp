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
	std::cout << "이 게임은 플레이어가 탈북해 무사히 남쪽으로 가는 게임입니다." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	std::cout << "최대 4명까지 플레이 할 수 있으며 각각 빨강 파랑 노랑 초록색 말을 가지고 있습니다." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	DrawingLocation(BLACK);
	std::cout << std::endl;
	std::cout << "보드 중간중간에 그려진 검정색 지역은 아오지 입니다." << std::endl;
	std::cout << "플레이어가 주사위를 굴려 이곳에 도착하게 되면 아오지에 끌려가 다음 한턴을 쉬게 됩니다." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	DrawingLocation(PURPLE);
	std::cout << std::endl;
	std::cout << "보드 곳곳에는 보이는 보라색 지역은 사다리입니다. " << std::endl; 
	std::cout << "이 사다리를 이용하면 더 앞으로 갈 수도있으며 뒤로 갈 수도 있습니다." << std::endl;
	std::cout << "\n[Press Enter]" << std::endl;
	getchar();
	system("cls");
	std::cout << "게임을 시작하려면 Enter키를 눌러 주세요" << std::endl;
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
