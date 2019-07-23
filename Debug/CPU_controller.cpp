#include "stdafx.h"
#include "CPU_controller.h"
#include "CPU_Game.h"

using namespace std;


CPU_controller::CPU_controller(CPU_view *pView)
{
	this->pView = pView;
}

void CPU_controller::RunGame()
{
	while (1) {
		int selectedNum = 1;

		pView->DrawMenuView();
		pView->DrawMenuText(selectedNum);
		pView->GetCommand(pView->GetMenuNum(), NUMOFMENU, selectedNum);

		system("cls");

		CPU_Game game;

		switch (selectedNum)
		{
		case 1:
			//printf("\n\n\n  1���� �����ϼ̽��ϴ�.");
			
			game.avoidHeart();
			break;

		case 2:
			//printf("\n\n\n  2���� �����ϼ̽��ϴ�.");
			game.bingoGame();
			break;

		case 3:
			//printf("\n\n\n  3���� �����ϼ̽��ϴ�.");
			game.snakeGame();
			break;

		case 4:
			//printf("\n\n\n  4���� �����ϼ̽��ϴ�.");
			game.mugunghwa();
			break;

		case 5:
			//printf("\n\n\n  5���� �����ϼ̽��ϴ�.");
			game.escape2();
			break;

		case 6:
			//printf("\n\n\n  6���� �����ϼ̽��ϴ�.");
			game.ballGame();
			break;

		case 7:
			//printf("\n\n\n  6���� �����ϼ̽��ϴ�.");
			game.vaccine();
			break;

		case 8:
			//printf("\n\n\n  6���� �����ϼ̽��ϴ�.");
			game.storyGame();
			break;
		}
	}
}