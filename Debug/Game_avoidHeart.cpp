#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "CPU_game.h"

CPU_Game game;

//Console Text Color Manager

#define col1 GetStdHandle (STD_OUTPUT_HANDLE)
#define SetColor_Red SetConsoleTextAttribute (col1, 0x000c );
#define SetColor_Blue SetConsoleTextAttribute (col1, 0x0001 | 0x0008 );
#define SetColor_Green SetConsoleTextAttribute (col1, 0x0001 | 0x0008 );
#define SetColor_White SetConsoleTextAttribute (col1, 0x000f );
#define SetColor_Skyblue SetConsoleTextAttribute (col1, 0x000b );
#define SetColor_Yellow SetConsoleTextAttribute (col1, 0x000e );
#define SetColor_Chemical SetConsoleTextAttribute (col1, 0x000d );
#define SetColor_Gold SetConsoleTextAttribute (col1, 0x0006 );
#define SetColor_Wine SetConsoleTextAttribute (col1, 0x0005 );
#define SetColor_Blood SetConsoleTextAttribute (col1, 0x0004 );
#define SetColor_Violet SetConsoleTextAttribute (col1, 0x0001 | 0x0008 | 0x000c );


#define MAP_X 34 // ���� ����

#define MAP_Y 22 // ���� ����



#define HEART MAP_X-1 // �ִ� ��Ʈ�� ����



#define LEFT 75 // ����

#define RIGHT 77 // ������



#define DEAD 0 // �׾��� ���

#define CLEAR 1 // Ŭ���� ���� ���



int endGame(int); // ������ ������ ���

void init_field(void); // �⺻ ���� �׵θ� ���

void init_game(void); // ������ �ʱ�ȭ�Ѵ�

int start_game(void); // ������ �����Ѵ�

void print_heart(void); // ȭ�鿡 ��Ʈ�� �ѷ��ش�

int check_hit(void); // ��Ʈ�� ĳ���� �浹 üũ



typedef struct xy {

	int x;

	int y;

};



struct xy heart[HEART];

struct xy charic;



int max_heart = 0; // �������� �ϴ� ��Ʈ�� ��

int count_heart = 0; // ������ ��Ʈ�� ��

int game_speed = 0; // ���� �ӵ�

int stage = 0; // ��������



			   // �Է¹��� ��ǥ�� Ŀ���� �������ִ� �Լ�

void gotoxy(int x, int y)

{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



// ������ ������ ���

int endGame(int flag)

{

	// ����ڰ� �׾��� ���

	if (flag == DEAD)

	{

		_getch();



		system("cls");



		SetColor_Skyblue;
		printf("\n\n\n");
		printf("       ����     ���     ��    ��    ����\n");
		printf("      ��         ��  ��   �� ��� ��   ��\n");
		printf("      ��  ���  ����� ��   ��   ��  ����\n");
		printf("      ��    ��  ��    �� ��   ��   ��  ��\n");
		printf("       ����   ��    �� ��        ��  ����\n\n");
		SetColor_White;
		printf("                  ����   ��    ��   ����  ����\n");
		printf("                 ��    ��  ��    ��   ��      ��   ��\n");
		printf("                 ��    ��  ��    ��   ����  ����\n");
		printf("                 ��    ��   ��  ��    ��      ��   ��\n");
		printf("                  ����      ��      ����  ��    ��\n");




		_getch();
		system("cls");
		return 0;

		srand(time(0));

		SetColor_Yellow;
		printf("\n\n\n");
		printf("          ���        ��     ��       ���       ��      ���\n");
		printf("         ��  ��       ��     ��      ��  ��      ��      ��  ��\n");
		printf("        �����       ��   ��       ��  ��      ��      ��  ��\n");
		printf("        ��    ��        �� ��        ��  ��      ��      ��  ��\n");
		printf("        ��    ��          ��          ���       ��      ���\n\n");
		SetColor_Red;
		printf("                            ��    ��    �����     ���     ����    ����\n");
		printf("                            ��    ��    ��          ��  ��    ��   ��     ��\n");
		printf("                            �����    �����   �����   ����      ��\n");
		printf("                            ��    ��    ��         ��    ��   ��  ��      ��\n");
		printf("                            ��    ��    �����   ��    ��   ��    ��    ��\n\n\n\n\n\n\n");

		SetColor_White;
		printf("\t\t\t\t   P");
		printf("R");
		printf("E");
		printf("S");
		printf("S");
		printf(" A");
		printf("N");
		printf("Y");
		printf(" K");
		printf("E");
		printf("Y");
		_getch();



		system("cls");

		// ���� ���� �׵θ��� ������ش�.

		init_field();



		// ������ �⺻���� �ʱ�ȭ �۾�

		init_game();

	}

	else // ����ڰ� ���������� Ŭ�������� ���

	{

		_getch();

		_getch();



		system("cls");



		gotoxy(MAP_X / 2, MAP_Y / 2);
		SetColor_Green;
		printf("--- STAGE CLEAR ---\n");

		gotoxy(MAP_X / 2, MAP_Y / 2 + 1);
		SetColor_White;
		printf("# ��Ʈ�� �ӵ��� ������ �þ�ϴ�!\n");

		gotoxy(MAP_X / 2, MAP_Y / 2 + 2);

		printf("# PRESS ANY KEY\n");



		_getch();

		_getch();



		system("cls");



		// �� ���

		init_field();



		// �������� ����

		stage++;



		// ���� �ʱ�ȭ

		init_game();



		// ������ ��Ʈ�� ���� ����

		max_heart += stage * 30;



		// ���� �ӵ� ����

		game_speed -= stage * 10;

	}

}



// ���� ���� �׵θ��� ������ִ� �Լ�

void init_field(void)

{

	int col = 0; // ��

	int row = 0; // ��



				 // �̸� ������ ���� ���� ũ�⸸ŭ �ݺ�

	for (col = 0; col <= MAP_Y; col++)

	{

		// �� ó�� ��� ���� ������ �� �϶� ����

		if (col == 0 || col == MAP_Y)

		{

			for (row = 0; row <= MAP_X; row++)

			{

				gotoxy(row * 2, col);
				SetColor_Skyblue;
				printf("��");

			}

		}

		else// ������ �� �϶� ����

		{

			gotoxy(0, col);

			SetColor_Yellow;
			printf("��");

			gotoxy(MAP_X * 2, col);

			SetColor_Yellow;
			printf("��");

		}
		SetColor_White;
	}

}



// ������ �ʱ�ȭ �۾��� ���ִ� �Լ�

void init_game(void)

{

	int count = 0;



	// �������� ��Ʈ�� �ּ� ����

	max_heart = 50;



	// ���� ������ ��Ʈ�� ����

	count_heart = 0;



	// ���� �ӵ� ����

	game_speed = 100;



	// ��Ʈ ��ġ �ʱ�ȭ

	for (count = 0; count < HEART; count++)

	{

		heart[count].x = count + 1;

		heart[count].y = rand() % 50;

		heart[count].x *= 2;

		heart[count].y *= -1;

	}



	// ����� ��ġ �ʱ�ȭ

	charic.x = MAP_X;

	charic.y = MAP_Y - 1;



	// ĳ���� �⺻ ��ġ ���

	gotoxy(charic.x, charic.y - 2);

	printf("��");

	gotoxy(charic.x, charic.y - 1);

	printf("��");

	gotoxy(charic.x, charic.y);

	printf("II");



	// ���� ȭ�鿡 �޽��� ���

	gotoxy(0, MAP_Y + 2);

	printf("STAGE [ %d ]\n", stage + 1);

	printf(">> ���� ��Ʈ�� ���� : %d", count_heart);

}



void print_heart(void)

{

	int count = 0;



	// ��Ʈ�� ������ �ϴ� �Լ�

	for (count = 0; count < HEART; count++)

	{

		// ���� �������� ���

		if (heart[count].y == MAP_Y - 1) {

			// ���� ��ġ�� ��Ʈ�� �����Ѵ�.

			gotoxy(heart[count].x, heart[count].y);

			printf(" ");



			// ������ ��Ʈ�� ���� ����

			count_heart++;



			gotoxy(0, MAP_Y + 2);

			printf("STAGE [ %d ]\n", stage + 1);

			printf(">> ���� ��Ʈ�� ���� : %d", count_heart);



			// ������ ��Ʈ�� ������ �ִ� ��Ʈ�� ������ ���� ���

			if (max_heart == count_heart)

			{

				gotoxy(MAP_X, MAP_Y + 1);
				SetColor_Red;
				printf("[ ��Ʈ�� �� ���߽��ϴ�. �ƹ�Ű�� �������� ]");
				SetColor_White;
				// ���� Ŭ����

				endGame(CLEAR);

				return;

			}

			// ������ ��Ʈ�� ������ �ִ� ������ �ƴ� ���

			else if (max_heart > count_heart)

			{

				// ��Ʈ�� ������ �ٽ� ������ �Ѵ�

				heart[count].y = rand() % 50;

				heart[count].y *= -1;

			}

			continue;

		}

		// ��Ʈ�� ������ ��ĭ ������

		heart[count].y = heart[count].y + 1;

		if (heart[count].y > 1)

		{

			// ���� ��ġ�� ��Ʈ�� �����Ѵ�.

			gotoxy(heart[count].x, heart[count].y - 1);

			printf(" ");



			// ���ο� ��ġ�� ��Ʈ�� ����Ѵ�.

			gotoxy(heart[count].x, heart[count].y);
			SetColor_Red;
			printf("��");
			SetColor_White;

		}

	}

}



// ��Ʈ�� �¾Ҵ��� üũ

int check_hit(void)

{

	int count = 0;



	// ���� ��Ʈ�� �� ��ŭ �ݺ�

	for (count = 0; count < HEART; count++)

	{

		// ����ڿ� ���� ������ Ȯ��

		if (heart[count].x == charic.x)

		{

			// ���� ������ Ȯ��

			if (heart[count].y == charic.y || heart[count].y == charic.y - 1

				|| heart[count].y == charic.y - 2)

			{

				gotoxy(MAP_X, MAP_Y + 2);
				SetColor_Red;
				printf("[ ��Ʈ�� �¾ҽ��ϴ� ]");
				SetColor_White;
				// ���� ����

				endGame(DEAD);
				return 1;

			}

		}

	}
	return 0;
}



// ���� ���ۿ� ���� ������ ������ �κ�

int start_game(void)

{

	// ����ڷκ��� ���� �Է¹޴� ����

	char input = '\0';



	while (1)

	{

		// ����ڷ� ���� �Է��� �޴´�.

		if (_kbhit())

		{

			// �Է¹��� ���� �����Ѵ�.

			input = _getch();



			// �������� �̵��϶�� ���� ���

			if (input == LEFT)

			{

				// �������� �̵� �� �� ���� ���

				if (charic.x - 2 > 0)

				{

					// ���� ��ġ�� ĳ���͸� �����.

					gotoxy(charic.x, charic.y - 2);

					printf(" ");

					gotoxy(charic.x, charic.y - 1);

					printf(" ");

					gotoxy(charic.x, charic.y);

					printf("  ");



					// ��ġ�� �����Ѵ�.

					charic.x = charic.x - 2;



					// ���ο� ��ġ�� �ٽ� ����Ѵ�.

					gotoxy(charic.x, charic.y - 2);

					printf("��");

					gotoxy(charic.x, charic.y - 1);

					printf("��");

					gotoxy(charic.x, charic.y);

					printf("II");

				}

			}

			// ���������� �̵��϶�� ���� ���

			else if (input == RIGHT)

			{

				// ���������� �̵��� �� ���� ���

				if (charic.x + 2 < MAP_X * 2)

				{

					// ���� ��ġ�� ĳ���͸� �����.

					gotoxy(charic.x, charic.y - 2);

					printf(" ");

					gotoxy(charic.x, charic.y - 1);

					printf(" ");

					gotoxy(charic.x, charic.y);

					printf("  ");



					// ��ġ�� �����Ѵ�.

					charic.x = charic.x + 2;



					// ���ο� ��ġ�� �ٽ� ����Ѵ�.

					gotoxy(charic.x, charic.y - 2);

					printf("��");

					gotoxy(charic.x, charic.y - 1);

					printf("��");

					gotoxy(charic.x, charic.y);

					printf("II");

				}

			}

		}

		else

		{

			// ���� �ӵ� ����

			Sleep(game_speed);



			// ȭ�鿡 ��Ʈ ���

			print_heart();

		}

		// ��Ʈ�� �¾Ҵ��� Ȯ��

		int a = check_hit();
		if (a == 1) {
			return 0;
		}

	}

}



int CPU_Game::avoidHeart(void) // main -> avoidHeart

{

	// ���� �� �ʱ�ȭ

	srand(time(0));

	SetColor_Yellow;
	printf("\n\n\n");
	printf("          ���        ��     ��       ���       ��      ���\n");
	printf("         ��  ��       ��     ��      ��  ��      ��      ��  ��\n");
	printf("        �����       ��   ��       ��  ��      ��      ��  ��\n");
	printf("        ��    ��        �� ��        ��  ��      ��      ��  ��\n");
	printf("        ��    ��          ��          ���       ��      ���\n\n");
	SetColor_Red;
	printf("                            ��    ��    �����     ���     ����    ����\n");
	printf("                            ��    ��    ��          ��  ��    ��   ��     ��\n");
	printf("                            �����    �����   �����   ����      ��\n");
	printf("                            ��    ��    ��         ��    ��   ��  ��      ��\n");
	printf("                            ��    ��    �����   ��    ��   ��    ��    ��\n\n\n\n\n\n\n");

	SetColor_White;
	printf("\t\t\t\t   P");
	printf("R");
	printf("E");
	printf("S");
	printf("S");
	printf(" A");
	printf("N");
	printf("Y");
	printf(" K");
	printf("E");
	printf("Y");
	_getch();



	system("cls");

	// ���� ���� �׵θ��� ������ش�.

	init_field();



	// ������ �⺻���� �ʱ�ȭ �۾�

	init_game();



	// ������ �����Ѵ�

	start_game();


	system("cls");
	return 0;

}