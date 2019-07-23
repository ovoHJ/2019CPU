#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <process.h>
#include<thread>
#include<conio.h>
#include "CPU_game.h"
#include "CPU_controller.h"

CPU_controller game_mugung;

#define MAP_X 14
#define MAP_Y 21

using namespace std;

void gotoxy_mugung(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void field(void)
{
	int col = 0; // ��
	int row = 0; // ��
				 // �̸� ������ ���� ���� ũ�⸸ŭ �ݺ�
	for (col = 0; col <= MAP_X; col++)
	{
		// �� ó�� ��� ���� ������ �� �϶� ����
		if (col == 0 || col == MAP_X)
		{
			for (row = 0; row <= MAP_Y; row++)
			{
				gotoxy_mugung(row * 2, col);
				printf("��");
			}
		}
		else// ������ �� �϶� ����
		{
			gotoxy_mugung(0, col);
			if (row == 2) printf("|");
			printf("��");
			gotoxy_mugung(MAP_Y * 2, col);
			if (row == 2) printf("|");
			printf("��");
		}
	}
}

void character(void) {
	gotoxy_mugung(2, 1);
	printf("��");
	gotoxy_mugung(40, 13);
	printf("��");
}


void gameplay(void) {
	srand(time(NULL));
	int timearray[5] = { 100, 200, 300, 400, 500 };
	int rd = rand() % 6;

	int flowerX = 50;

	rd = rand() % 6;
	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX, 3);
	printf("�� ");
	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 3, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 6, 3);
	printf("ȭ ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 9, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 12, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 15, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 18, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 21, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 24, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 27, 3);
	printf("�� ");

	Sleep(timearray[rd]);
	gotoxy_mugung(flowerX + 30, 3);
	printf("!");

	Sleep(1000);
	gotoxy_mugung(50, 3);
	printf("                                    ");

}

void stop(void) {
	gotoxy_mugung(50, 4);
	printf("�� �̻� �� �� �����ϴ�. ���ư�����");
	gotoxy_mugung(50, 4);
	Sleep(1000);
	printf("                                ");
}


int collision(void) {
	gotoxy_mugung(50, 3);
	printf("����(2P)�� �̰���ϴ�\n");
	gotoxy_mugung(50, 4);
	printf("��հ��ϼ̳���?\n");
	gotoxy_mugung(50, 5);
	printf("CPU�� CPUĳ�� <����ȭ ���� �Ǿ����ϴ�> �����ϴ�!!\n");
	gotoxy_mugung(50, 6);
	int a = _getch();
	system("cls");
	return 0;

}

int winuser(void) {
	gotoxy_mugung(50, 3);
	printf("1P�� �̰���ϴ�.");
	gotoxy_mugung(50, 4);
	printf("��հ��ϼ̳���?\n");
	gotoxy_mugung(50, 5);
	printf("CPU�� CPUĳ�� <����ȭ ���� �Ǿ����ϴ�> �����ϴ�!!\n");
	gotoxy_mugung(50, 6);
	int a = _getch();
	system("cls");
	return 0;
}

int chase(void) {
	int chr = 0, x = 38, y = 12;
	int chr2 = 0, a = 40, b = 13;

	gotoxy_mugung(6, 7);
	printf("��");

	gotoxy_mugung(14, 3);
	printf("��");

	gotoxy_mugung(14, 11);
	printf("��");

	gotoxy_mugung(18, 7);
	printf("��");

	gotoxy_mugung(26, 5);
	printf("��");

	gotoxy_mugung(26, 9);
	printf("��");

	gotoxy_mugung(30, 12);
	printf("��");

	gotoxy_mugung(36, 8);
	printf("��");


	while (1) {
		chr = _getch();

		if (chr == 72 || chr == 80 || chr == 75 || chr == 77) {
			gotoxy_mugung(a, b);
			printf(" ");
			if (chr == 72) { //��
				b--;
				if (b <= 1)b = 1;

				if (a == 6 && b == 7) a = 6, b = 8;
				if (a == 14 && b == 3) a = 14, b = 4;
				if (a == 14 && b == 11) a = 14, b = 12;
				if (a == 18 && b == 7) a = 18, b = 8;
				if (a == 26 && b == 5) a = 26, b = 6;
				if (a == 26 && b == 9) a = 26, b = 10;
				if (a == 30 && b == 12) a = 30, b = 13;
				if (a == 36 && b == 8) a = 36, b = 9;
			}
			else if (chr == 80) { //��
				b++;
				if (b >= 13)b = 13;

				if (a == 6 && b == 7) a = 6, b = 6;
				if (a == 14 && b == 3) a = 14, b = 2;
				if (a == 14 && b == 11) a = 14, b = 10;
				if (a == 18 && b == 7) a = 18, b = 6;
				if (a == 26 && b == 5) a = 26, b = 4;
				if (a == 26 && b == 9) a = 26, b = 8;
				if (a == 30 && b == 12) a = 30, b = 11;
				if (a == 36 && b == 8) a = 36, b = 7;

			}
			else if (chr == 75) { //��
				a -= 2;
				if (a <= 4) {
					a = 4;
					stop();
				}

				if (a == 6 && b == 7) a = 8, b = 7;
				if (a == 14 && b == 3) a = 16, b = 3;
				if (a == 14 && b == 11) a = 16, b = 11;
				if (a == 18 && b == 7) a = 20, b = 7;
				if (a == 26 && b == 5) a = 28, b = 5;
				if (a == 26 && b == 9) a = 28, b = 9;
				if (a == 30 && b == 12) a = 32, b = 12;
				if (a == 36 && b == 8) a = 38, b = 8;

			}
			else if (chr == 77) { //��
				a += 2;
				if (a >= 40) a = 40;

				if (a == 6 && b == 7) a = 4, b = 7;
				if (a == 14 && b == 3) a = 12, b = 3;
				if (a == 14 && b == 11) a = 12, b = 11;
				if (a == 18 && b == 7) a = 16, b = 7;
				if (a == 26 && b == 5) a = 24, b = 5;
				if (a == 26 && b == 9) a = 24, b = 9;
				if (a == 30 && b == 12) a = 28, b = 12;
				if (a == 36 && b == 8) a = 34, b = 8;
			}
		}



		else if (chr == 119 || chr == 87 || chr == 115 || chr == 83 || chr == 97 || chr == 65 || chr == 100 || chr == 68) {
			gotoxy_mugung(x, y);
			printf(" ");
			if (chr == 119 || chr == 87) { //��
				y--;
				if (y <= 1)y = 1;

				if (x == 6 && y == 7) x = 6, y = 8;
				if (x == 14 && y == 3) x = 14, y = 4;
				if (x == 14 && y == 11) x = 14, y = 12;
				if (x == 18 && y == 7) x = 18, y = 8;
				if (x == 26 && y == 5) x = 26, y = 6;
				if (x == 26 && y == 9) x = 26, y = 10;
				if (x == 30 && y == 12) x = 30, y = 13;
				if (x == 36 && y == 8) x = 36, y = 9;
			}
			else if (chr == 115 || chr == 83) { //��
				y++;
				if (y >= 13)y = 13;

				if (x == 6 && y == 7) x = 6, y = 6;
				if (x == 14 && y == 11) x = 14, y = 10;
				if (x == 14 && y == 3) x = 14, y = 2;
				if (x == 18 && y == 7) x = 18, y = 6;
				if (x == 26 && y == 5) x = 26, y = 4;
				if (x == 26 && y == 9) x = 26, y = 8;
				if (x == 30 && y == 12) x = 30, y = 11;
				if (x == 36 && y == 8) x = 36, y = 7;

			}
			else if (chr == 97 || chr == 65) { //��
				x -= 2;
				if (x <= 2)x = 2;

				if (x == 6 && y == 7) x = 8, y = 7;
				if (x == 14 && y == 3) x = 16, y = 3;
				if (x == 14 && y == 11) x = 16, y = 11;
				if (x == 18 && y == 7) x = 20, y = 7;
				if (x == 26 && y == 5) x = 28, y = 5;
				if (x == 26 && y == 9) x = 28, y = 9;
				if (x == 30 && y == 12) x = 32, y = 12;
				if (x == 36 && y == 8) x = 38, y = 8;

			}
			else if (chr == 100 || chr == 68) { //��
				x += 2;
				if (x >= 40) x = 40;

				if (x == 6 && y == 7) x = 4, y = 7;
				if (x == 14 && y == 3) x = 12, y = 3;
				if (x == 14 && y == 11) x = 12, y = 11;
				if (x == 18 && y == 7) x = 16, y = 7;
				if (x == 26 && y == 5) x = 24, y = 5;
				if (x == 26 && y == 9) x = 24, y = 9;
				if (x == 30 && y == 12) x = 28, y = 12;
				if (x == 36 && y == 8) x = 34, y = 8;
			}
		}

		gotoxy_mugung(x, y);
		printf("��");
		gotoxy_mugung(a, b);
		printf("��");

		if (x == a && y == b) {
			collision();
			return 0;
		}
		else if (x == 4) {
			winuser();
			return 0;
		}
	}
}


void pursuit(void) {
	gotoxy_mugung(50, 3);
	printf("�߰����� ���۵˴ϴ�.");
	Sleep(1000);
	gotoxy_mugung(50, 3);
	printf("                                   ");

	gotoxy_mugung(50, 3);
	printf("3");

	Sleep(1000);
	gotoxy_mugung(50, 3);
	printf("2");

	Sleep(1000);
	gotoxy_mugung(50, 3);
	printf("1");

	Sleep(1000);
	gotoxy_mugung(50, 3);
	printf("�����̼���!");

	Sleep(1000);
	gotoxy_mugung(50, 3);
	printf("                   ");
	chase();
}


void chased(void) {
	int chr = 0, x = 2, y = 1;
	thread t1(gameplay);


	gotoxy_mugung(6, 7);
	printf("��");

	gotoxy_mugung(14, 3);
	printf("��");

	gotoxy_mugung(14, 11);
	printf("��");

	gotoxy_mugung(18, 7);
	printf("��");

	gotoxy_mugung(26, 5);
	printf("��");

	gotoxy_mugung(26, 9);
	printf("��");

	gotoxy_mugung(30, 12);
	printf("��");

	gotoxy_mugung(36, 8);
	printf("��");


	while (x != 40 || y != 13) {
		chr = _getch();
		gotoxy_mugung(x, y);
		printf(" ");
		if (chr == 119 || chr == 87) { //��
			y--;
			if (y <= 1)y = 1;

			if (x == 6 && y == 7) x = 6, y = 8;
			if (x == 14 && y == 3) x = 14, y = 4;
			if (x == 14 && y == 11) x = 14, y = 12;
			if (x == 18 && y == 7) x = 18, y = 8;
			if (x == 26 && y == 5) x = 26, y = 6;
			if (x == 26 && y == 9) x = 26, y = 10;
			if (x == 30 && y == 12) x = 30, y = 13;
			if (x == 36 && y == 8) x = 36, y = 9;
		}
		else if (chr == 115 || chr == 83) { //��
			y++;
			if (y >= 13)y = 13;

			if (x == 6 && y == 7) x = 6, y = 6;
			if (x == 14 && y == 11) x = 14, y = 10;
			if (x == 14 && y == 3) x = 14, y = 2;
			if (x == 18 && y == 7) x = 18, y = 6;
			if (x == 26 && y == 5) x = 26, y = 4;
			if (x == 26 && y == 9) x = 26, y = 8;
			if (x == 30 && y == 12) x = 30, y = 11;
			if (x == 36 && y == 8) x = 36, y = 7;

		}
		else if (chr == 97 || chr == 65) { //��
			x -= 2;
			if (x <= 2)x = 2;

			if (x == 6 && y == 7) x = 8, y = 7;
			if (x == 14 && y == 3) x = 16, y = 3;
			if (x == 14 && y == 11) x = 16, y = 11;
			if (x == 18 && y == 7) x = 20, y = 7;
			if (x == 26 && y == 5) x = 28, y = 5;
			if (x == 26 && y == 9) x = 28, y = 9;
			if (x == 30 && y == 12) x = 32, y = 12;
			if (x == 36 && y == 8) x = 38, y = 8;

		}
		else if (chr == 100 || chr == 68) { //��
			x += 2;
			if (x >= 40) x = 40;

			if (x == 6 && y == 7) x = 4, y = 7;
			if (x == 14 && y == 3) x = 12, y = 3;
			if (x == 14 && y == 11) x = 12, y = 11;
			if (x == 18 && y == 7) x = 16, y = 7;
			if (x == 26 && y == 5) x = 24, y = 5;
			if (x == 26 && y == 9) x = 24, y = 9;
			if (x == 30 && y == 12) x = 28, y = 12;
			if (x == 36 && y == 8) x = 34, y = 8;
		}
		gotoxy_mugung(x, y);
		printf("��");

	}
	pursuit();
	t1.join();

}

int howto(void) {
	printf("\n\n\t\t\t\t�� ����ȭ ���� �Ǿ����ϴ� ��\n\n");
	printf("*�� ������ ����� �� �ٳ�� ������ �ǻ�� ���� <����ȭ ���� �Ǿ����ϴ�> �Դϴ�.\n\n");
	printf("1. �� ������ 2�ο� �Դϴ�. 1P�� W(��), A(����), S(�Ʒ�), D(������)�� Ű�� ����ϰ�,\n");
	printf(" 2P�� ��(��), ��(����), ��(�Ʒ�), ��(������)�� Ű�� ����մϴ�.\n\n");
	printf("2. ������ ��ġ�� ��ֹ��� ���� ������ ��ġ�Ϸ�������\n\n");
	printf("3. ������ ��ġ�ϸ� ���۵Ǵ� �߰���..!\n\n");
	printf("4. ������ ����� �ִ� ������ ���� �� ������ �Ƚ��ϼ���.\n\n");
	printf("5. �������� ������ ����� �й�! ����ؼ� ������ ���ϼ���!\n\n");
	printf("\t\t\t�� ������ �����Ϸ��� �ƹ� Ű�� �������� ��\n");

	_getch();
	system("cls");
	field();
	character();
	chased();

	return 0;
}

void start_mu(void) {
	printf("����������������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\n");
	printf("	  ����ȭ ���� �Ǿ����ϴ� \t\t\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
	printf("   1. ���� ��� 2. ���� ���� 3. ������ \t\n");
	printf("\t\t\t\t\t\n");
	printf("����������������������������������������������������������������������������������\n");
}

int CPU_Game::mugunghwa() {
	int select;
	int select2;

	start_mu();
	printf("\n");
	printf("���� => ");
	scanf_s("%d", &select);
	if (select < 1 || select>3) {
		printf("1~3������ ���ڸ� �Է����ּ���.\n");
	}
	else if (select == 1) {
		system("cls");
		howto();
	}
	else if (select == 2) {
		system("cls");
		field();
		while (1) {
			character();
			//gameplay();
			chased();
			return 0;
		}
	}
	else {
		system("cls");
		printf("\n\n\t\t=============================\n\n");
		printf("\t\t <������>�� �����ϼ̽��ϴ�");
		printf("\n\n\t\t=============================\n");
		int a = _getch();
		system("cls");
		return 0;
	}
	return 0;
}