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


	void storyGame(); // CPU캐슬 스토리게임 2 o
	void snakeGame(); // 스네이크 게임 2 o
	int RSP(); // 가위바위보 게임 2 o
	int ddong(); // 똥게임 2 o
	int shootingGame(); // 슈팅게임 2 o
	int updownGame(); // 업다운게임 2 o
	int vaccine(); // 몬스터 2 o

	int escape2(); // 제2교무실 탈출 3 o
	int avoidHeart(); // 하트를 피해라 3 o
	int ballGame(); // 공게임 3 o
	int bingoGame(); // 빙고게임 3 o
	int mugunghwa(); // 무궁화 꽃이 피었습니다 3
};

#endif