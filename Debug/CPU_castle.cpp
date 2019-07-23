#include "stdafx.h"
#include "CPU_controller.h"
#include <Windows.h>

int main() {
	//system("mode con cols=119 lines=35");
	system("title CPU Castle");
	CPU_view view;
	CPU_controller game(&view);

	view.CursorView(HIDE);
	game.RunGame();
	_getch();
	view.CursorView(SHOW);

	return 0;
}