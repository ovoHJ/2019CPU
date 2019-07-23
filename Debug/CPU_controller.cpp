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
			//printf("\n\n\n  1번을 선택하셨습니다.");
			
			game.avoidHeart();
			break;

		case 2:
			//printf("\n\n\n  2번을 선택하셨습니다.");
			game.bingoGame();
			break;

		case 3:
			//printf("\n\n\n  3번을 선택하셨습니다.");
			game.snakeGame();
			break;

		case 4:
			//printf("\n\n\n  4번을 선택하셨습니다.");
			game.mugunghwa();
			break;

		case 5:
			//printf("\n\n\n  5번을 선택하셨습니다.");
			game.escape2();
			break;

		case 6:
			//printf("\n\n\n  6번을 선택하셨습니다.");
			game.ballGame();
			break;

		case 7:
			//printf("\n\n\n  6번을 선택하셨습니다.");
			game.vaccine();
			break;

		case 8:
			//printf("\n\n\n  6번을 선택하셨습니다.");
			game.storyGame();
			break;
		}
	}
}