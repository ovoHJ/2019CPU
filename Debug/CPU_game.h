#pragma once
#pragma warning(disable : 4996)
#ifndef __CPU_GAME_H__
#define __CPU_GAME_H__
#include "CPU_view.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

class CPU_Game {
public:

	CPU_Game() {

	}


	void storyGame(); // CPUĳ�� ���丮���� 2 o
	void snakeGame(); // ������ũ ���� 2 o
	int RSP(); // ���������� ���� 2 o
	int ddong(); // �˰��� 2 o
	int shootingGame(); // ���ð��� 2 o
	int updownGame(); // ���ٿ���� 2 o
	int vaccine(); // ���� 2 o

	int escape2(); // ��2������ Ż�� 3 o
	int avoidHeart(); // ��Ʈ�� ���ض� 3 o
	int ballGame(); // ������ 3 o
	int bingoGame(); // ������� 3 o
	int mugunghwa(); // ����ȭ ���� �Ǿ����ϴ� 3
};

#endif