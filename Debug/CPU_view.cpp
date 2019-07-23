#include "stdafx.h"
#include "CPU_view.h"

void CPU_view::SetXY(const char* strMenu[], int ySize, int dx, int dy)
{
	// dx dy Text를 박스 가운데 오게 하기 위하여 조정이 필요할 경우 사용하기 위한  변수
	x = COLUMN / 2 - strlen(strMenu[0]) / 3;
	y = ROW / 2 - ySize / 2 + 2;
}

void CPU_view::PrintMenu(const char* strMenu[], int ySize)
{
	for (int i = 0; i < ySize; i++)
	{
		Gotoxy(x, y + i);
		printf("%s", strMenu[i]);
	}
}

void CPU_view::DrawMenuView()
{
	const char* strMenu[] = {
		"               ▲ ▲ ▲ ▲ ▲ ▲ ▲               ",
		"               ■ ■ ■ ■ ■ ■ ■          ",
		"       ▲ ▲┌──────────────────────┐ ▲ ▲",
		"     ┌──────┘  C P U   C A S T E L └──────┐",
		" ▲▲│                                    │ ▲▲",
		"┌────┘                                    └────┐",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"│                                              │",
		"└──────────────────────────────────────────────┘",
		" ※ 방향키(↑↓)로 선택 Enter Key로 결정하세요!!!  "
	};

	SetXY(strMenu, sizeof(strMenu) / sizeof(strMenu[0]), 0, 0);
	// SetXY(const char* strMenu[], int ySize, int dx, int dy)
	PrintMenu(strMenu, sizeof(strMenu) / sizeof(strMenu[0]));
}

void CPU_view::DrawMenuText(int selectedNum)
{
	int dy = (selectedNum - 1) * 2;
	static bool isFirst = true;

	// isFirst는 위와 같은 목적으로 사용되며
	// dy는 글자가 한 줄씩 공백을 두었기에 방향키 한 번에 다음 위치로 이동 시키기 위한 변수  
	static const char* strMenu[] = {
		"   ♡ AVOID HEART ♡ ",
		"                  ",
		"   맞춰보자 B I N G O ",
		"                  ",
		"   스네이크 게임 ",
		"                  ",
		"   무궁화 꽃이 피었습니다 ",
		"                  ",
		"   제2교무실을 탈출하자! ",
		"                  ",
		"   날아다니는 공을 피해라!! ",
		"                  ",
		"   백신으로 몬스터를 물리쳐줘! ",
		"                  ",
		"   SKY캐슬? CPU캐슬! ",
		"                  "
	};

	if (isFirst)
	{
		menuNum = (sizeof(strMenu) / sizeof(strMenu[0]) + 1) / 2;
		SetXY(strMenu, sizeof(strMenu) / sizeof(strMenu[0]) - 3, -1, -1);
		// SetXY(const char* strMenu[], int ySize, int dx, int dy)
		PrintMenu(strMenu, sizeof(strMenu) / sizeof(strMenu[0]));
		isFirst = false;
	}

	// 하이라이트 된 메뉴를 복원하기 위해서는 이전 선택된 것만 복원하는 게 원칙이지만
	// 메뉴수가 많지 않기에 전체를 다시 그려 이전 선택된 걸 복원한다. 
	SetXY(strMenu, sizeof(strMenu) / sizeof(strMenu[0]) - 3, -1, -1);
	PrintMenu(strMenu, sizeof(strMenu) / sizeof(strMenu[0]));

	// 새롭게 선택된 메뉴를 하이라이트 시킨다. 
	Gotoxy(x, y + dy);
	SetColor(YELLOW, DARK_BLUE);
	printf("%s", strMenu[dy]);
	Gotoxy(x, y + dy);
	// 선택된 메뉴에만 이 문양이 들어가기 때문에 별도로 그려줘야 한다. 
	printf(" ▶");
	SetColor(GRAY, BLACK);
}

int CPU_view::GetMenuNum()
{
	return menuNum;
}

int CPU_view::GetKey()
{
	int ch = _getch();
	if (ch == 0 || ch == 0xE0) ch = _getch();

	return ch;
}

void CPU_view::GetCommand(int max, int type, int &selectedNum)
{
	int ch;

	while (1)
	{
		ch = GetKey();
		switch (ch)
		{
		case UP: --selectedNum; break;
		case DOWN: ++selectedNum; break;
		case ENTER: return;
		default: break;
		}
		if (selectedNum > max) selectedNum = 1;
		else if (selectedNum < 1) selectedNum = max;
		if (type == NUMOFMENU) DrawMenuText(selectedNum);
	}
}

/* ========================================================================== */
/* 화면의 커서를 보이거나 숨기기 */
void CPU_view::CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

/* ========================================================================== */
/* x, y 좌표로 커서를 움직이는 함수 */
void CPU_view::Gotoxy(int x, int y) /*커서이동 함수 부분*/
{
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

/* ========================================================================== */
/* 콘솔 색깔을 지정하는 함수 */
void CPU_view::SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/* ========================================================================== */
/* 콘솔 바탕과 글자에 색깔을 지정하는 함수 */
void CPU_view::SetColor(int color, int bgcolor)
{

	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
