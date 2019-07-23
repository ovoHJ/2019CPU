#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "CPU_game.h"

int Menu();
int** myAlloc(int num);
int same_num(int **user, int tmp, int num);
int del_num(int **user, int check, int num);
int check_bingo(int **user, int num, int mode);
int input_num(int *check_ary, int num, int *count, int mode);

void init_bingo(int **init, int num);
void Monitor(int **user, int **com, int num);
void one(int **user, int num, int mode);
void two(int **user, int **com, int num, int mode);

int CPU_Game::bingoGame()
{
	int **user = 0, **com = 0, mode, num = 5;
	srand(time(0));

	while (1)
	{
		mode = Menu();
		switch (mode)
		{
		case 1:
			one(user, num, mode);
			break;
		case 2:
			two(user, com, num, mode);
			break;
		case 3:
			printf("\n게임을 종료하셨습니다.\n\n");
			int i = _getch();
			system("cls");
			return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}

int Menu()
{
	int sel;
	printf("1. 연습용 게임\n");
	printf("2. 대전용 게임\n");
	printf("3. 게임 종료\n");

	while (1)
	{
		printf("#메뉴 입력(1~3) : ");
		scanf_s("%d", &sel);

		if (sel > 3 || sel < 1)
			printf("잘못 입력하셨습니다.\n\n");
		else
			break;
	}

	return sel;
}

int** myAlloc(int num)
{
	int **tmp, i;

	tmp = (int **)malloc(num * sizeof(int *));

	for (i = 0; i < num; i++)
		tmp[i] = (int *)malloc(num * sizeof(int));

	return tmp;
}

void one(int **user, int num, int mode)
{
	int *check_ary, i, j, tmp, count = 0;

	user = myAlloc(num);
	check_ary = (int *)malloc((num*num) * sizeof(int));

	init_bingo(user, num);

	while (1)
	{
		system("cls");
		printf("\n      [연습게임]\n\n");

		for (i = 0; i < num; i++)
		{
			printf("|");

			for (j = 0; j < num; j++)
			{
				if (user[i][j] == 88)
					printf("%4c", user[i][j]);
				else
					printf("%4d", user[i][j]);
			}

			printf("|\n");
		}

		if (check_bingo(user, num, mode))
		{
			printf("\n빙고 1줄을 완성하셨습니다.\n");
			break;
		}


		if ((tmp = input_num(check_ary, num, &count, 1)) == 0)
			break;

		for (i = 0; i < (num*num); i++)
			del_num(user, check_ary[i], num);
	}
}

void two(int **user, int **com, int num, int mode)
{
	int *check_ary;
	int i, tmp, count = 0;

	user = myAlloc(num);
	com = myAlloc(num);

	check_ary = (int *)malloc((num*num) * sizeof(int));

	init_bingo(user, num);
	init_bingo(com, num);

	while (1)
	{

		system("cls");
		Monitor(user, com, num);

		if (check_bingo(user, num, mode) == 5)
		{
			printf("빙고 5개로 당신의 승리 입니다.\n");
			break;
		}
		if (check_bingo(com, num, mode) == 5)
		{
			printf("빙고 5개로 컴퓨터의 승리 입니다.\n", num);
			break;
		}


		if ((tmp = input_num(check_ary, num, &count, 1)) == 0)
			break;

		for (i = 0; i < (num*num); i++)
		{
			del_num(user, check_ary[i], num);
			del_num(com, check_ary[i], num);
		}

		system("cls");
		Monitor(user, com, num);

		tmp = input_num(check_ary, num, &count, mode);
		printf("\n컴퓨터가 선택한 값은 (%d) 입니다.", tmp);

		for (i = 0; i < (num*num); i++)
		{
			del_num(user, check_ary[i], num);
			del_num(com, check_ary[i], num);
		}

		fflush(stdin);
		getchar();
	}
}

void Monitor(int **user, int **com, int num)
{
	int i, j;

	printf("\t[user] \t\t\t\t [computer]\n");
	for (i = 0; i < num; i++)
	{
		printf("|");

		for (j = 0; j < num; j++)
		{
			if (user[i][j] == 88)
				printf("%4c", user[i][j]);
			else
				printf("%4d", user[i][j]);
		}

		printf("  |\t |");

		for (j = 0; j < num; j++)
		{
			if (com[i][j] == 88)
				printf("%4c", com[i][j]);
			else
				printf("%4d", com[i][j]);
		}

		printf("  |\n");
	}
}

void init_bingo(int **init, int num)
{
	int i, j, tmp;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			tmp = rand() % (num*num) + 1;

			if (same_num(init, tmp, num))
				j--;
			else
				init[i][j] = tmp;
		}
	}
}

int input_num(int *check_ary, int num, int *count, int mode)
{
	int tmp, i;

	while (1)
	{
		if (mode == 1)
		{
			printf("\n# 지울 숫자 입력 [메뉴(0)] : ");
			scanf_s("%d", &tmp);
			if (tmp == 0)
			{
				printf("메뉴를 선택하셨습니다. \n");
				break;
			}
		}
		else
			tmp = rand() % (num*num);

		if (tmp > 0 && tmp < (num*num) + 1)
		{
			for (i = 0; i < (num*num); i++)
			{
				if (check_ary[i] == tmp)
					break;
			}

			if (i == (num*num))
			{
				check_ary[(*count)++] = tmp;
				return tmp;
			}
			else
				if (mode == 1)	printf("\n중복된 숫자 이므로 다시\n");
		}

		else
		{
			fflush(stdin);
			printf("1~%d값만 가능합니다. \n\n", num*num);
		}
	}

	return tmp;
}

int check_bingo(int **user, int num, int mode)
{
	int i, j, bingo = 0;
	int garo, sero, x_1 = 0, x_2 = 0;

	for (i = 0; i < num; i++)
	{
		garo = 0;

		for (j = 0; j < num; j++)
		{
			if (user[i][j] == 88) garo++;

			if (i == j)
			{
				if (user[i][j] == 88)
					x_1++;
			}

			if ((i + j) == 4)
			{
				if (user[i][j] == 88)
					x_2++;
			}
		}

		if (garo == 5)
		{
			bingo++;
			if (mode == 1) return bingo;
		}
	}

	for (j = 0; j < num; j++)
	{
		sero = 0;

		for (i = 0; i < num; i++)
			if (user[i][j] == 88) sero++;

		if (sero == 5)
		{
			bingo++;
			if (mode == 1) return bingo;
		}
	}

	bingo = bingo + (x_1 / 5) + (x_2 / 5);

	return bingo;
}


int del_num(int **user, int check, int num)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (check == user[i][j])
			{
				user[i][j] = 88;
				return 0;
			}
		}
	}
	return 0;
}

int same_num(int **user, int tmp, int num)
{
	int i, j;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (user[i][j] == tmp)
				return 1;
		}
	}

	return 0;
}
