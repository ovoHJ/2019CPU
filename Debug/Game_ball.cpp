#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "CPU_game.h"

using namespace std;
#define LINE_X 79
#define LINE_Y 24
#define BLACK 0 
#define CYAN 3 
#define YELLOW 14 
#define WHITE 15
#define RED 4 
void cursor(int n) // Ŀ�� �����
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
BOOL IsKeyDown(int Key)
{
	return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}
void gotoxy_ball(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int xx[85] = { 0 };
int yy[21] = { 0 };
int mod;
class Ball {					//Game1 Ƣ������ �� Ŭ���� 
public:
	class Ball * nextPtr;
	int x, y, z;
	unsigned char s;
public:
	Ball() {
		nextPtr = nullptr;
		do {
			x = (rand() % 78) + 1;			//���� ƨ������ ��ġ ���ϱ�
			y = (rand() % 19) + 1;
			z = (rand() % 4) + 1;
		} while (x != 40 && y != 10);
		xx[x] += 1;
		yy[y] += 1;
	}
	void setNext(class Ball *p) {		//�� ���� ��
		nextPtr = p;
	}
	class Ball* getNext() {
		return nextPtr;
	}
	void pon() {				//���� �������� ������ ������ �ε��ļ� �ٽó��� �� z�� �ٲ� 
		if (y > 19 && x > 78) {
			z = 4;
			return;
		}
		if (y < 1 && x>77) {
			z = 3;
			return;
		}
		if (y > 19 && x < 1) {
			z = 1;
			return;
		}
		if (y < 1 && x < 1) {
			z = 2;
			return;
		}
		if (x < 1) {
			if (z == 4) {
				z = 1;
			}
			if (z == 3) {
				z = 2;
			}
			return;
		}
		if (x > 78) {
			if (z == 2) {
				z = 3;
			}
			if (z == 1) {
				z = 4;
			}
			return;
		}
		if (y < 1) {
			if (z == 1) {
				z = 2;
			}
			if (z == 4) {
				z = 3;
			}
			return;
		}
		if (y > 19) {
			if (z == 2) {
				z = 1;
			}
			if (z == 3) {
				z = 4;
			}
			return;
		}
	}
	void display() {
		gotoxy_ball(x, y);
		cout << s;
	}
	void mov() {	//���� �ε����� �� ��ȭ�ϴ� x y �Լ� 
		if (z == 1) {
			s = ' ';
			display();
			xx[x] -= 1;
			yy[y] -= 1;
			x += 1;
			y -= 1;
			xx[x] += 1;
			yy[y] += 1;
			s = 'O';
			display();
		}
		else if (z == 2) {
			s = ' ';
			display();
			xx[x] -= 1;
			yy[y] -= 1;
			x += 1;
			y += 1;
			xx[x] += 1;
			yy[y] += 1;
			s = 'O';
			display();

		}
		else if (z == 3) {
			s = ' ';
			display();
			xx[x] -= 1;
			yy[y] -= 1;
			x -= 1;
			y += 1;
			s = 'O';
			display();
			xx[x] += 1;
			yy[y] += 1;
		}
		else {
			s = ' ';
			display();
			xx[x] -= 1;
			yy[y] -= 1;
			x -= 1;
			y -= 1;
			s = 'O';
			display();
			xx[x] += 1;
			yy[y] += 1;
		}
		if (y > 20 || x > 78 || y < 1 || x < 1) {    //�ε����� �� z�ٽ� ���ϱ�
			pon();
			return;
		}
	}
};
class Man {
public:
	int x, y;
	Man() {
		x = 40;
		y = 10;
	}									//�������Ű������ ������ ���� ��ȭ�ϴ� ��ġ ���� 
	void setxy(int xxx, int yyy) {
		x = xxx;
		y = yyy;
	}
	void xdes() {
		if (x > 1)
			x -= 2;
	}
	void xins() {
		if (x < 79)
			x += 2;
	}
	void ydes() {
		if (y > 1)
			y -= 2;
	}
	void yins() {
		if (y < 19)
			y += 2;
	}
	void display(char s) {
		gotoxy_ball(x, y);
		cout << s;
	}
};
typedef class Ball ball;
typedef class Man man;
void soccer() {						//Game1�� �ؾ� �Ǵ��� Game2�� �ؾߵǴ��� �����ϴ� �Լ�
	textcolor(YELLOW, BLACK);
	gotoxy_ball(10, 5);
	cout << "    �����    ����    �����   �����  �����  �����" << endl <<
		"           ��           ��      �� ��         ��         ��        ��      ��" << endl <<
		"            ������  ��      �� ��         ��         �����  �����" << endl <<
		"                    ��  ��      �� ��         ��         ��        ��   ��           " << endl <<
		"            ������    ����    �����   �����  �����  ��     ��" << endl;
	cout << "" << endl << endl;

	while (1) {
		cout << "choose one! \n 1)Game1  2)Game2 \n\n > ";
		cin >> mod;
		if (mod == 1 || mod == 2)
			break;
	}
	system("cls");
}
void print_home2() {			//Game2�� ���ӹ�� �� ��� �� ���� 
	gotoxy_ball(25, 10);
	textcolor(CYAN, BLACK);
	cout << "���ƴٴϴ� ���� ���ض�" << endl;
	gotoxy_ball(24, 13);
	cout << "�����ӹ���� " << endl;
	gotoxy_ball(24, 16);
	cout << " MOVE : W , A , S , D " << endl;
	gotoxy_ball(24, 17);
	cout << "�ƹ��ų� ������ �Ѿ�ϴ�" << endl;
	cout << "" << endl;
	textcolor(WHITE, BLACK);
	_getch();
	system("cls");
}
int Game2() {
	srand(time(NULL));
	ball *x;
	ball *cur;
	man playera;
	int k = 0;
	char s;
	x = new ball();
	int i;

	system("CLS");
	gotoxy_ball(30, 8);
	cout << "Ready";					//���ӽ��� �ٷ� �� ȭ�� 
	for (int j = 3; j > 0; j--) {
		gotoxy_ball(37, 8);
		cout << j;
		Sleep(1000);
	}
	for (int j = 0; j < 10; j++) {
		gotoxy_ball(30 + j, 8);
		cout << " ";
	}
	system("CLS");
	for (k = 0;;) {
		k += 1;

		Sleep(50);
		playera.display(' ');

		if (k == 50) {
			k = 0;
			cur = x;
			for (i = 0; cur->getNext() != nullptr; i++, cur = cur->getNext());
			cur->setNext(new ball());
		}
		if (_kbhit()) {     //������� Ű ���� 
			s = _getch();
			/*	if (s == '+') {
			cur = x;
			for (i = 0; cur->getNext() != nullptr; i++, cur = cur->getNext());
			cur->setNext(new ball());
			}
			*/			if (mod == 1) {				//Ű���忡 ���� ������
				if (s == 'w') {
					playera.ydes();
				}
				if (s == 's') {
					playera.yins();
				}
				if (s == 'a') {
					playera.xdes();
				}
				if (s == 'd') {
					playera.xins();
				}
			}
		}
		playera.display('a');
		//�浹�� �Ǿ����� Ȯ���ϰ� ����
		for (i = 0, cur = x; cur != nullptr; i++, cur = cur->getNext()) {
			if (cur->x == playera.x&&cur->y == playera.y) {
				gotoxy_ball(0, 0);
				cout << " gameover!!!";
				gotoxy_ball(0, 10);
				cout << " �������� n�� ��������";
				while (1) {
					if (_kbhit()) {
						s = _getch();
						if (s == 'n' || s == 'N')
							system("cls");
						return 0;
					}
				}

			}
		}
		for (i = 0, cur = x; cur != nullptr; i++, cur = cur->getNext()) {//���ƴٴϴ� ���� ������ 
			cur->mov();

			gotoxy_ball(10, 21);
			cout << "x: " << cur->x;
			gotoxy_ball(10, 22);
			cout << "y: " << cur->y;
			gotoxy_ball(10, 23);
			cout << "z: " << cur->z;
		}
	}
}

struct Soccer {
	int x, y, wait;
};

struct Soccer defence[100];

int level;
int heart = 3;
int Start = 1;

void print_home1() {				//Game1�� ���ӹ��ȭ�� 
	gotoxy_ball(25, 10);
	textcolor(CYAN, BLACK);
	cout << "�����ӹ����" << endl;
	gotoxy_ball(24, 13);
	cout << " MOVE : �� , �� , �� , �� " << endl;
	gotoxy_ball(24, 17);
	cout << "������� ���� ���� ���� ��" << endl;
	cout << "" << endl;
	gotoxy_ball(24, 17);
	cout << "������ ������ (1.�� 2.�� 3.��)  �ٷ� �����մϴ�" << endl;
	int i = 1;
	while (i) {
		level = _getch();
		switch (level - 48) {
		case 1:
		case 2:
		case 3: i = 0;
		}
	}
	textcolor(WHITE, BLACK);
	system("cls");
}

void goal() {				//��븦 �׸��� �Լ�
	gotoxy_ball(70, 9);
	cout << "�����" << endl;

	for (int i = 0; i < 6; i++) {
		gotoxy_ball(76, 10 + i);
		cout << "��";
	}
	gotoxy_ball(70, 16);
	cout << "�����" << endl;
}

void drawHeart() {				//����2�� ������ 3���̸� �پ�� ������ print�Ǵ� ��Ʈ�� �� ���� �޶���
	if (heart == 3) {
		gotoxy_ball(70, 5);
		cout << "������" << endl;
	}
	else if (heart == 2) {
		gotoxy_ball(72, 5);
		cout << "����" << endl;
	}
	else if (heart == 1) {
		gotoxy_ball(74, 5);
		cout << "��" << endl;
	}
}

int gameOver() {					//Game2�� ������ ����Ǿ��� �� ȣ�� �Ǹ� ���⼭ return�� boolean������ 
	char reStart;						//������ �ٽ� ����Ǵ� ���θ� �Ǵ��Ѵ�.	

	system("cls");

	textcolor(RED, BLACK);
	gotoxy_ball(20, 10);
	cout << "���ӿ� �����ϴ�.";

	textcolor(WHITE, BLACK);
	cout << "������ �̾� �ϰڽ��ϱ�? (y | n) ";
	Sleep(1000);		// �ߺ�
	reStart = (char)_getch();

	if (reStart == 'y' || reStart == 'Y') {
		return 1;
	}
	else
		return 0;
}
int win_lose = 1;
int player_x, player_y;
int user_x = 2, user_y = rand() % 20 + 1;	//������ġ �ʱ�ȭ 

int Game1() {
	//level 1������ 49, 50, 51
	srand((unsigned int)time(NULL));

	int count = 10 + level - 48;
	int i;

	user_x = 2, user_y = rand() % 20 + 1;	//������ġ �ʱ�ȭ 

	for (i = 0; i < count; i++) {			//�������� P������� ��ġ�� ���Ѵ�.
		defence[i].x = rand() % 45 + 20;
		defence[i].y = 3;
		defence[i].wait = rand() % 20;
	}

	while (Start) {
		system("cls");
		goal();
		drawHeart();

		gotoxy_ball(user_x, user_y);
		cout << "��";

		//���� ������ ����
		if (user_x > 69 && user_y > 10 && user_y < 16) {
			gotoxy_ball(user_x - 5, user_y + 8);
			cout << "���� �־����ϴ�. \n";
			Sleep(1000);
			system("cls");
			gotoxy_ball(35, 30);
			cout << "������ �����մϴ�\n";
			return 0;
		}

		//���� �����̱� (���� ���� ���� �� �� �ִ� �Ÿ��� �ٸ�..)
		if (IsKeyDown(VK_LEFT) && user_x > 1) {
			if (level == 49)
				user_x--;
			else if (level == 50)
				user_x -= 2;
			else if (level == 51)
				user_x -= 3;
		}

		if (IsKeyDown(VK_DOWN) && user_y < 24) {
			if (level == 49)
				user_y++;
			else if (level == 50)
				user_y += 2;
			else if (level == 51)
				user_y += 3;
		}

		if (IsKeyDown(VK_RIGHT) && user_x < 70) {
			if (level == 49)
				user_x++;
			else if (level == 50)
				user_x += 2;
			else if (level == 51)
				user_x += 3;
		}

		if (IsKeyDown(VK_UP) && user_y > 1) {
			if (level == 49)
				user_y--;
			else if (level == 50)
				user_y -= 2;
			else if (level == 51)
				user_y -= 3;
		}

		//���� ��� 
		gotoxy_ball(user_x, user_y);
		cout << "��";

		//����� ������
		for (int i = 0; i < count; i++)
		{
			if (defence[i].wait > 0)
			{
				defence[i].wait--;
			}

			else {
				defence[i].y++;
				if (defence[i].y >= 24)
				{
					defence[i].x = rand() % 47 + 10;
					defence[i].y = 2;
				}
				// ���
				gotoxy_ball(defence[i].x, defence[i].y);
				cout << "P";
				Sleep(10);
				// �浹ó�� 
				if (user_x == defence[i].x && user_y == defence[i].y) {
					gotoxy_ball(user_x, user_y);
					cout << "������� �������ϴ�. \n";
					Sleep(500);
					heart--;
					drawHeart();
					if (heart == -1) {
						Start = gameOver();
					}
				}
			}
		}
	}
	return 0;
}

int CPU_Game::ballGame() {
	cursor(0);
	soccer();
	if (mod == 1) {				//����1 �����
		print_home2();
		Game2();
	}
	else if (mod == 2) {		//����2 �����
		Start = 1;
		print_home1();
		goal();
		Game1();
	}
	int a = _getch();
	system("cls");
	return 0;
}