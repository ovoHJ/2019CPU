#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 40
#define LEFT 75		// ��, �����Ű ���ϰ�
#define RIGHT 77


// rank���� ����
struct SCORE
{
	int c;
}rank[11], temp;

// player �ڽ�, �¿츸 �����̱⿡ x��ǥ�� �ʿ���
struct player
{
	int x;
	char c;
};

// ���� �ǹ��ϴ±���ü
struct dump
{
	int x;
	int y;
	int color;
	int speed;	// ���� ���ǵ� count
	int tmp;	// ���� �ʱ� ���ǵ� ���� ����
};
int level_is_9();//level�� 9�̸� �����ϰ� �ϱ�
//void first_o();
void print_background();		// �� ���
void textcolor(int color_number);
void gotoxy(int x, int y);
int baserand(int x, int y);
// �ʱ�ȭ �Լ�
void init(struct dump d[MAX], struct player p[1], int *speed, int *freq, int *score, int *temp_level);
int whole_speed(int score);		// speed ����
int control_bindo(int score);	// ���� �������� �� ����
int menu();		//�޴����
void control_player(struct player p[1]);	// �÷��̾� ��Ʈ�� �Լ�
											// �� ������ �Լ�,�ε������� ó��
int d_drop(struct dump d[MAX], struct player p[1], int score, int freq);
int lev(int score);