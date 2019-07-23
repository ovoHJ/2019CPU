#pragma once
#pragma warning(disable : 4996)
#ifndef __GOTOXY_H__
#define __GOTOXY_H__

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

class Hgotoxy {
public:
	void gotoxy(int x, int y) {
		COORD Pos = { x - 1,y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

#endif