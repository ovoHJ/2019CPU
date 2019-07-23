#ifndef __CPU_VIEW_H__
#define __CPU_VIEW_H__
#pragma warning(disable : 4996)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define COLUMN 80 //ȭ���� ����ũ�� 
#define ROW    24 //ȭ���� ���� ũ��

#define	ENTER   		13
#define UP				72
#define DOWN			80
#define LEFT			75
#define RIGHT			77

enum {
	BLACK,			/*  0 : ��� */
	DARK_BLUE,		/*  1 : ��ο� �Ķ� */
	DARK_GREEN,		/*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,	/*  3 : ��ο� �ϴ� */
	DARK_RED,		/*  4 : ��ο� ���� */
	DARK_VIOLET,	/*  5 : ��ο� ���� */
	DARK_YELLOW,	/*  6 : ��ο� ��� */
	GRAY,			/*  7 : ȸ�� */
	DARK_GRAY,		/*  8 : ��ο� ȸ�� */
	BLUE,			/*  9 : �Ķ� */
	GREEN,			/* 10 : �ʷ� */
	SKY_BLUE,		/* 11 : �ϴ� */
	RED,			/* 12 : ���� */
	VIOLET,			/* 13 : ���� */
	YELLOW,			/* 14 : ��� */
	WHITE,			/* 15 : �Ͼ� */
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

