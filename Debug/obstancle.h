#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 40
#define LEFT 75		// 좌, 우방향키 리턴값
#define RIGHT 77


// rank점수 저장
struct SCORE
{
	int c;
}rank[11], temp;

// player 자신, 좌우만 움직이기에 x좌표만 필요함
struct player
{
	int x;
	char c;
};

// 똥을 의미하는구조체
struct dump
{
	int x;
	int y;
	int color;
	int speed;	// 똥의 스피드 count
	int tmp;	// 똥의 초기 스피드 값을 저장
};
int level_is_9();//level이 9이면 종료하게 하기
//void first_o();
void print_background();		// 벽 출력
void textcolor(int color_number);
void gotoxy(int x, int y);
int baserand(int x, int y);
// 초기화 함수
void init(struct dump d[MAX], struct player p[1], int *speed, int *freq, int *score, int *temp_level);
int whole_speed(int score);		// speed 조절
int control_bindo(int score);	// 똥이 떨어지는 수 조절
int menu();		//메뉴출력
void control_player(struct player p[1]);	// 플레이어 컨트롤 함수
											// 똥 떨구기 함수,부딪혔을때 처리
int d_drop(struct dump d[MAX], struct player p[1], int score, int freq);
int lev(int score);