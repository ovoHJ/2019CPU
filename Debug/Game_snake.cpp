#include "stdafx.h"
#include <stdio.h>
#include <windows.h> //좌표값을 저장해 주기 위해, Sleep함수, goto함수, system함수등을 사용하기 위해 선언
#include <stdlib.h>
#include <time.h>
#include <conio.h> //getch함수를 사용하기 위해 선언
#include "header.h"
#include "CPU_game.h"
#include "Hgotoxy.h"

#pragma warning(disable : 4996)

void gotoxy_snake(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int rand_x = 0; //gotoxy_snake로 임의의 좌표로 먹이를 놓기 위한 변수
int rand_y = 0;
int speed = 150; // 게임의 스피드를 조절

unsigned char body[1823];

// 좌표 총 1823칸중 뱀 머리의 위치를 표시하기 위해
// 뱀이 자신의 몸을 물었을 경우를 체크
//y최대 :  75이고 x최대 : 23)
unsigned int remove_tail_check[75 * 23];
// 뱀의 꼬리가 지나가는 부분을 체크하기 위한 배열로 맵의 좌표가 저장
//  point_head와 point_tail을 포인터로 사용함

int point_head;

// remove_tail_check의 포인터로 쓰임
// 뱀의 몸이 커질때마다 포인터를 1씩 증가시키면서 포인터가 가리키는 값에는 새로이 추가되는(먹이를 먹어서) 뱀의 몸 위치값을 나타냄

int point_tail;
// remove_tail_check의 포인터로 쓰임
// 뱀의 자취(꼬리가 지나가는 부분)를 체크하여 없애주기 위한 포인터
// 뱀이 움직일때마다 point_tail이 가리키는 부분에 저장된 맵의 좌표로 가서 그곳의 뱀 흔적을 없앰


void textcolor(int color_number) //텍스트 칼라를 바꿔주는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}



void back_round()  // 외곽선을 표시하기 위한 함수
{

	unsigned char a = 0xa6;//확장 아스키 코드로 16진수, 10진수로는 166
	int i, j;
	int x = 39; //행
	int y = 24; //열
				//윗변 테두리

	printf("%c%c", a, 0xa3);//163
	for (i = 0; i < x + 35; i++)
		printf("%c%c", a, 0xa1);

	printf("%c%c\n", a, 0xa4);
	//양변 그리기. 이중 for문을 사용한다.

	for (j = 0; j < y - 2; j++)
	{

		printf("%c%c", a, 0xa2);
		for (i = 0; i < x - 2; i++)
			printf("  ");
		printf("%c%c", a, 0xa2);
		printf("\n");

	}
	//아랫변 테두리
	printf("%c%c", a, 0xa6);
	for (i = 0; i < x + 35; i++)printf("%c%c", a, 0xa1);
	printf("%c%c\n", a, 0xa5);
}

// 가로 37칸, 세로 22칸

void game_option() { // 게임옵션 설정(스피드)을 위한 함수

	while (1) {

		int nan = 10;
		system("cls");
		gotoxy_snake(1, 1); //1,1에 문구 출력
		printf("숫자가 높을수록 난이도가 높습니다\n");
		printf("게임의 난이도를 선택하고 엔터키를 누르세요(1~6) :");
		scanf("%d", &nan);

		if (nan == 1)
		{
			speed = 130;
		}
		else if (nan == 2)
		{
			speed = 120;
		}
		else if (nan == 3)
		{
			speed = 100;
		}
		else if (nan == 4)
		{
			speed = 90;
		}
		else if (nan == 5)
		{
			speed = 80;
		}
		else if (nan == 6)
		{
			speed = 70;
		}
		else
		{

			printf("1~6사이의 숫자를 입력하세요.\n"); //1~6사이의 숫자를 재입력 받도록
			Sleep(300); // 300/1000초만큼 지연시키는 역할
			continue; //다시 위로 간다
		}

		system("cls");
		break;

	}

}

void start() {


	unsigned char start = 2; // 게임 스타트를 체크하기 위한 변수

	int x, y; //행 : x, 열 : y

	int ago_x; // 뱀의 꼬리 흔적을 없애기 위해 좌표값을 임시 저장하기위한 변수

	int ago_y;

	int body_number; //뱀이 늘린 몸통 수

	unsigned char chr; // 방향키의 키값을 받기위한 변수


					   /*********** 변수 초기화 ***************/
	while (1)
	{


		ago_x = 3;

		ago_y = 2;

		chr = 99;

		point_head = 1;

		point_tail = 0;

		body_number = 1;

		memset(body, 0, 1823);

		memset(remove_tail_check, 0, 1725);

		remove_tail_check[0] = 155;



		/*************  초기화면 **********************/

		printf("게임을 시작하려면 1을 누르시오\n");

		printf("게임을 종료하려면 0를 누르시오\n");

		start = getch();

		if (start == '0')
		{
			system("cls");
			break;

		}
		else if (start != '1')
		{
			system("cls");
			continue;
		}

		game_option(); //게임 스피드 조절

		gotoxy_snake(1, 1);

		back_round();  //게임맵 외곽선 그리기

		rand_x = ((rand() % 37)) * 2 + 3; //난수생성하여 먹잇감의 좌표를 얻음

		rand_y = (rand() % 22) + 2;

		gotoxy_snake(rand_x, rand_y);

		textcolor(12);  //빨간색

		printf("♣");   //먹잇감의 좌표로가서 먹이를 나타냄

		int rand_a = ((rand() % 40)) * 2 + 3;
		int rand_b = (rand() % 20) + 2;


		x = 3;  // 뱀의 최초 시작 좌표를 나타냄

		y = 2;

		gotoxy_snake(x, y);

		while (1)
		{

			if (kbhit() != 0) //아무키나 입력받았을시 if문을 실행함
			{

				chr = getch();

				if (chr == 0 || chr == 0xe0)
				{

					chr = getch();

				}

			}

			if (chr == 72) //방향키 '↑' 입력받을시
			{

				y -= 1;

				if (y < 2)
				{

					system("cls"); // 화면을 깨끗이 지운다

					gotoxy_snake(30, 10);

					printf("GAME OVER\n"); // 30,10에 종료문구 출력

					break;

				}

			}
			else if (chr == 80) //방향키 '↓' 입력받을시
			{

				y += 1;

				if (y > 23)
				{

					system("cls");

					gotoxy_snake(30, 10);

					printf("GAME OVER\n");

					break;

				}

			}
			else if (chr == 75) //방향키 '←' 입력받을시

			{
				x -= 2; // 네모는 특수문자(2byte)이므로 가로는 2칸씩 이동해야함

				if (x < 3)
				{

					system("cls");

					gotoxy_snake(30, 10);

					printf("GAME OVER\n");

					break;

				}

			}
			else if (chr == 77) //방향키 '→' 입력받을시
			{

				x += 2;

				if (x > 75)
				{

					system("cls");

					gotoxy_snake(30, 10);

					printf("GAME OVER\n");

					break;

				}

			}

			if ((x == rand_x) && (y == rand_y))
			{ // 먹이를 먹었을 경우

			  //난수를 사용하여 새로운 먹이를 맵에 표현함

				rand_x = ((rand() % 37)) * 2 + 3;

				rand_y = (rand() % 22) + 2;

				gotoxy_snake(rand_x, rand_y);

				textcolor(12);

				printf("♣");//뱀 먹이 그림

				int rand_a = ((rand() % 40)) * 2 + 3;
				int rand_b = (rand() % 20) + 2;

				/*gotoxy_snake(rand_a, rand_b);
				textcolor(11);

				printf("◆");

				if (x == rand_a && y == rand_b) exit(0);*/


				//아래 코드는 뱀이 먹이를 먹었으므로 새로이 추가된 몸통 좌표를 추가하고 뱀의 자취좌표를 추가하는 것

				//먹이를 먹은 경우에는 꼬리 자취를 지울필요없으므로(몸이 늘어나서) 이에 관한 코드는 없고,

				//그래서 if문 실행후 바로 반복문(while)의 조건문으로 이동함

				remove_tail_check[point_head] = (y) * 76 + x; // 뱀의 자취를 맵좌표값으로 추가

				point_head++;

				if (point_head >= 1656)point_head = 0;

				body[(y) * 76 + x] = 1; //몸통 좌표 추가(1이 몸통이 있다는 표시, 0이 몸통이 없다는 표시)

				body_number++;

				if (body_number >= 10) {

					speed -= 10;

					if (speed < 40)speed = 40;

					body_number = 0;

				}

				continue;

			}




			//꼬리가 지나간 부위를 지우기 위한 코드임

			ago_y = remove_tail_check[point_tail] / 76;  //ago에 임시저장

			ago_x = remove_tail_check[point_tail] % 76;

			if (ago_x == 0)ago_x = 75;

			gotoxy_snake(ago_x, ago_y);

			printf("%c%c", 0x00, 0x00);

			body[remove_tail_check[point_tail]] = 0; //뱀이 지나간 좌표는 몸이 존재하지 않으므로 몸통좌표에서 삭제

			point_tail++;

			if (point_tail >= 1656)point_tail = 0;




			//뱀 머리가 가는 방향으로 뱀 머리를 새로이 그려넣기 위한 코드임

			remove_tail_check[point_head] = (y) * 76 + x;

			if (body[remove_tail_check[point_head]] == 0)//뱀 머리가 있을 곳에 뱀 몸통이 없을 경우
			{

				body[remove_tail_check[point_head]] = 1;

			}
			else//뱀 머리와 몸통좌표가 겹쳤을 경우로, gameover임
			{
				system("cls");

				gotoxy_snake(30, 10);
				printf("머리가 몸통에 닿았습니다..ㅠㅠ");
				gotoxy_snake(30, 14);
				printf("GAME OVER\n");

				break;

			}

			point_head++;

			if (point_head >= 1656)point_head = 0;

			gotoxy_snake(x, y);

			textcolor(rand() % 15 + 1); // 텍스트색깔을 난수로 설정하여 LED처럼 반짝이게 한다.

			printf("□"); //뱀 머리를 그린다




			Sleep(speed); // 게임의 스피드 조절


		}

	}
}


void CPU_Game::snakeGame()
{
	start();

	srand(time(NULL)); // 난수 초기화 설정

}

