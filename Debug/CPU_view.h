#ifndef __CPU_VIEW_H__
#define __CPU_VIEW_H__
#pragma warning(disable : 4996)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define COLUMN 80 //화면의 가로크기 
#define ROW    24 //화면의 세로 크기

#define	ENTER   		13
#define UP				72
#define DOWN			80
#define LEFT			75
#define RIGHT			77

enum {
	BLACK,			/*  0 : 까망 */
	DARK_BLUE,		/*  1 : 어두운 파랑 */
	DARK_GREEN,		/*  2 : 어두운 초록 */
	DARK_SKY_BLUE,	/*  3 : 어두운 하늘 */
	DARK_RED,		/*  4 : 어두운 빨강 */
	DARK_VIOLET,	/*  5 : 어두운 보라 */
	DARK_YELLOW,	/*  6 : 어두운 노랑 */
	GRAY,			/*  7 : 회색 */
	DARK_GRAY,		/*  8 : 어두운 회색 */
	BLUE,			/*  9 : 파랑 */
	GREEN,			/* 10 : 초록 */
	SKY_BLUE,		/* 11 : 하늘 */
	RED,			/* 12 : 빨강 */
	VIOLET,			/* 13 : 보라 */
	YELLOW,			/* 14 : 노랑 */
	WHITE,			/* 15 : 하양 */
};

enum {
	HIDE,
	SHOW
};

enum {
	NUMOFMENU
};

class CPU_view {
private:
	int x, y;
	int menuNum;

public:
	CPU_view() {
	}
	void SetXY(const char* strMenu[], int ySize, int dx, int dy);
	void PrintMenu(const char* strMenu[], int ySize);
	void DrawMenuView();
	void DrawMenuText(int selectedNum);

	void GetCommand(int max, int type, int &selectedNum);
	int  GetKey();
	int  GetMenuNum();

	void CursorView(char show);
	void Gotoxy(int x, int y);
	void SetColor(int color);
	void SetColor(int color, int bgcolor);

};

#endif // __CPU_VIEW_H__

