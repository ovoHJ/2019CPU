#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#pragma warning(disable : 4996)

#define UP 72 //����Ű ��
#define DOWN 80 //����Ű �Ʒ� 
#define LEFT 75
#define RIGHT 77
#define ENTER 13





void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void textColor(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}