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
void cursor(int n) // 커서 숨기기
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
class Ball {					//Game1 튀겨지는 공 클래스 
public:
	class Ball * nextPtr;
	int x, y, z;
	unsigned char s;
public:
	Ball() {
		nextPtr = nullptr;
		do {
			x = (rand() % 78) + 1;			//공이 튕겨지는 위치 정하기
			y = (rand() % 19) + 1;
			z = (rand() % 4) + 1;
		} while (x != 40 && y != 10);
		xx[x] += 1;
		yy[y] += 1;
	}
	void setNext(class Ball *p) {		//공 만들 때
		nextPtr = p;
	}
	class Ball* getNext() {
		return nextPtr;
	}
	void pon() {				//일정 프레임의 범위를 지날때 부딪쳐서 다시나올 때 z를 바꿈 
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
	void mov() {	//공이 부딪쳤을 때 변화하는 x y 함수 
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
		if (y > 20 || x > 78 || y < 1 || x < 1) {    //부딪쳤을 때 z다시 구하기
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
	}									//여기부터키보드의 눌림에 따라 변화하는 위치 설정 
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
void soccer() {						//Game1을 해야 되는지 Game2를 해야되는지 선택하는 함수
	textcolor(YELLOW, BLACK);
	gotoxy_ball(10, 5);
	cout << "    ■■■■    ■■■    ■■■■   ■■■■  ■■■■  ■■■■" << endl <<
		"           ■           ■      ■ ■         ■         ■        ■      ■" << endl <<
		"            ■■■■■  ■      ■ ■         ■         ■■■■  ■■■■" << endl <<
		"                    ■  ■      ■ ■         ■         ■        ■   ■           " << endl <<
		"            ■■■■■    ■■■    ■■■■   ■■■■  ■■■■  ■     ■" << endl;
	cout << "" << endl << endl;

	while (1) {
		cout << "choose one! \n 1)Game1  2)Game2 \n\n > ";
		cin >> mod;
		if (mod == 1 || mod == 2)
			break;
	}
	system("cls");
}
void print_home2() {			//Game2의 게임방법 을 출력 및 설명 
	gotoxy_ball(25, 10);
	textcolor(CYAN, BLACK);
	cout << "날아다니는 공을 피해라" << endl;
	gotoxy_ball(24, 13);
	cout << "《게임방법》 " << endl;
	gotoxy_ball(24, 16);
	cout << " MOVE : W , A , S , D " << endl;
	gotoxy_ball(24, 17);
	cout << "아무거나 누르면 넘어갑니다" << endl;
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
	cout << "Ready";					//게임시작 바로 전 화면 
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
		if (_kbhit()) {     //사용자의 키 받음 
			s = _getch();
			/*	if (s == '+') {
			cur = x;
			for (i = 0; cur->getNext() != nullptr; i++, cur = cur->getNext());
			cur->setNext(new ball());
			}
			*/			if (mod == 1) {				//키보드에 따른 움직임
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
		//충돌이 되었는지 확인하고 종료
		for (i = 0, cur = x; cur != nullptr; i++, cur = cur->getNext()) {
			if (cur->x == playera.x&&cur->y == playera.y) {
				gotoxy_ball(0, 0);
				cout << " gameover!!!";
				gotoxy_ball(0, 10);
				cout << " 닫으려면 n을 누르세요";
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
		for (i = 0, cur = x; cur != nullptr; i++, cur = cur->getNext()) {//날아다니는 공의 움직임 
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

void print_home1() {				//Game1의 게임방법화면 
	gotoxy_ball(25, 10);
	textcolor(CYAN, BLACK);
	cout << "《게임방법》" << endl;
	gotoxy_ball(24, 13);
	cout << " MOVE : ← , → , ↑ , ↓ " << endl;
	gotoxy_ball(24, 17);
	cout << "수비수를 피해 골대로 들어가야 함" << endl;
	cout << "" << endl;
	gotoxy_ball(24, 17);
	cout << "레벨을 고르세요 (1.하 2.중 3.상)  바로 시작합니다" << endl;
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

void goal() {				//골대를 그리는 함수
	gotoxy_ball(70, 9);
	cout << "■■■■" << endl;

	for (int i = 0; i < 6; i++) {
		gotoxy_ball(76, 10 + i);
		cout << "■";
	}
	gotoxy_ball(70, 16);
	cout << "■■■■" << endl;
}

void drawHeart() {				//게임2의 생명이 3개이며 줄어들 때마다 print되는 하트의 갯 수가 달라짐
	if (heart == 3) {
		gotoxy_ball(70, 5);
		cout << "♥♥♥" << endl;
	}
	else if (heart == 2) {
		gotoxy_ball(72, 5);
		cout << "♥♥" << endl;
	}
	else if (heart == 1) {
		gotoxy_ball(74, 5);
		cout << "♥" << endl;
	}
}

int gameOver() {					//Game2의 게임이 종료되었을 때 호출 되며 여기서 return된 boolean값으로 
	char reStart;						//게임이 다시 진행되는 여부를 판단한다.	

	system("cls");

	textcolor(RED, BLACK);
	gotoxy_ball(20, 10);
	cout << "게임에 졌습니다.";

	textcolor(WHITE, BLACK);
	cout << "게임을 이어 하겠습니까? (y | n) ";
	Sleep(1000);		// 삐빅
	reStart = (char)_getch();

	if (reStart == 'y' || reStart == 'Y') {
		return 1;
	}
	else
		return 0;
}
int win_lose = 1;
int player_x, player_y;
int user_x = 2, user_y = rand() % 20 + 1;	//유저위치 초기화 

int Game1() {
	//level 1누르면 49, 50, 51
	srand((unsigned int)time(NULL));

	int count = 10 + level - 48;
	int i;

	user_x = 2, user_y = rand() % 20 + 1;	//유저위치 초기화 

	for (i = 0; i < count; i++) {			//떨어지는 P수비수의 위치를 정한다.
		defence[i].x = rand() % 45 + 20;
		defence[i].y = 3;
		defence[i].wait = rand() % 20;
	}

	while (Start) {
		system("cls");
		goal();
		drawHeart();

		gotoxy_ball(user_x, user_y);
		cout << "▲";

		//골이 들어갔는지 여부
		if (user_x > 69 && user_y > 10 && user_y < 16) {
			gotoxy_ball(user_x - 5, user_y + 8);
			cout << "골을 넣었습니다. \n";
			Sleep(1000);
			system("cls");
			gotoxy_ball(35, 30);
			cout << "게임을 종료합니다\n";
			return 0;
		}

		//유저 움직이기 (레벨 마다 움직 일 수 있는 거리가 다름..)
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

		//유저 출력 
		gotoxy_ball(user_x, user_y);
		cout << "▲";

		//수비수 움직임
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
				// 출력
				gotoxy_ball(defence[i].x, defence[i].y);
				cout << "P";
				Sleep(10);
				// 충돌처리 
				if (user_x == defence[i].x && user_y == defence[i].y) {
					gotoxy_ball(user_x, user_y);
					cout << "수비수에 막혔습니다. \n";
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
	if (mod == 1) {				//게임1 실행시
		print_home2();
		Game2();
	}
	else if (mod == 2) {		//게임2 실행시
		Start = 1;
		print_home1();
		goal();
		Game1();
	}
	int a = _getch();
	system("cls");
	return 0;
}