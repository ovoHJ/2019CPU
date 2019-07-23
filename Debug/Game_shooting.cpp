#include "stdafx.h"
#include "shooting.h"
#include "CPU_game.h"


CPU_Game game_shot;

void textcolor2(int color_number) //텍스트 칼라를 바꿔주는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void draw_rectangle(int size, int c) {
	int i, j;
	unsigned char a = 0xa6;;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);

	for (i = 0; i < size; i++)
		printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < c; i++) {
		printf("%c%c", a, b[2]);
		for (j = 0; j < size; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	printf("%c%c", a, b[6]);
	for (i = 0; i < size; i++)
		printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
void box2() {
	textcolor2(15);
	char start = 0;
	unsigned char a = 0xa6, b[7], i;


	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	gotoxy(6, 5);

	printf("%c%c", a, b[3]); //r
	for (int i = 1; i <= 70; i++) printf("%c%c", a, b[1]); //-
	printf("%c%c", a, b[4]); //ㄱ

	printf("\n");

	for (int i = 1; i <= 14; i++) {
		printf("      ");
		printf("%c%c", a, b[2]);
		for (int j = 1; j <= 70; j++) printf(" ");

		printf("%c%c\n", a, b[2]);
	}

	printf("\n");
	gotoxy(6, 20);
	printf("%c%c", a, b[6]); //ㄴ

	for (int i = 1; i <= 70; i++) printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]); //l
	printf("\n\n");

}



void intro_game(void) {
	system("cls");
	//("pause>null");
	char key;

	box2();

	gotoxy(23, 7);
	textcolor2(3); //하늘색
	printf("★★ 몬스터 죽이기 1단계 ★★\n\n\n");

	textcolor2(15);
	gotoxy(20, 10);
	printf("1단계는 슈팅게임 입니다 !\n\n");
	gotoxy(20, 12);
	printf("우주선을 타고 이동하면서\n");
	gotoxy(20, 14);
	printf("괴물을(▣) 총으로 맞추는 게임! 총 발사 : space키\n\n");
	gotoxy(20, 16);
	printf("게임을 시작하려면 아무키나 누르세요~");
	gotoxy(20, 18);
	printf("그럼 1단계 시작합니다~!!\n");
	key = _getch();


}
void display_text(int count, int r_count) {
	textcolor2(4);
	gotoxy(63, 2);
	printf("  총알 발사는 space 키!\n\n");
	textcolor2(4);
	gotoxy(63, 4);
	printf("  총알 : 10발\n\n");
	textcolor2(15);
	gotoxy(63, 6);
	printf("  ▷총발사횟수 : %d\n\n", count);
	gotoxy(63, 8);
	printf("  ▶괴물 목숨 :");

	gotoxy(78, 8);
	for (int i = 0; i < r_count; i++) {
		printf("■ ");
	}
}

void game_control(int *r_c, int rnd, int *bar) {
	int i = 1, k = 1, y;//i=우주선 위치
	int i2 = 1, k2 = 1/*, y2*/; //i2=몬스터 위치
	char *horse = (char*)"▲", chr; //우주선
	char *monster = (char*)"▲"/*, chr2*/;

	do {
		i += k;
		if (i > 58) //오른쪽 사각형 벽에 닿으면 다시 왼쪽으로
			k = -1;
		else if (i < 3) //왼쪽 사각형 벽에 닿으면 다시 오른쪽으로
			k = +1;

		horizontal_slide(i, 20, horse);

	} while (!_kbhit());//키보드가 눌렸는지 안눌렸는지 확인
	chr = _getch();
	y = 21;
	do {
		i2 += k2;
		if (i2 > 58)
			k2 = -1;
		else if (i2 < 3)
			k2 = +1;

		horizontal_slide2(i2, 8, monster);
	} while (!_kbhit());


	if (chr == 32) {//들어온 키가 스페이스면
		while (y > 2) {
			y -= 1;
			gotoxy(i + 1, y);
			printf("¶");
			Sleep(30);
			printf("\b\b ");
		}
		if ((rnd - 1 <= i) && (i <= (rnd))) {
			gotoxy(rnd - 1, 2);
			textcolor2(11);
			printf("으악");
			gotoxy(46, 13);
			printf("괴물:으악.. ");
			Sleep(50);
			*r_c = *r_c - 1; //괴물에 총알이 맞으면 목숨이 하나 다는 것
		}

		if ((i2 - 1 <= i) && (i <= i2)) {//총알이 움직이는 몬스터에 닿으면 bar = -1
			*bar = -1; //
			return;
		}

		gotoxy(1, 24);
		printf("아무키나 누르면 다음 진행...");
		_getch();
		gotoxy(1, 30);
	}

}
void horizontal_slide(int x, int y, char *c2) {//우주선 움직이는 속도
	gotoxy(x, y);
	printf("%s", c2);
	Sleep(50);
	printf("\b\b");

}
void horizontal_slide2(int x, int y, char *c2) {//우주선 움직이는 속도
	gotoxy(x, y);
	printf("%s", c2);
	Sleep(30);
	printf("\b\b");

}

int CPU_Game::shootingGame() { // first -> shootingGame
	int count = 0, rnd;
	int r_count = 3;
	char *target = (char*)"▣";
	int bar = 1;//장애물 닿았을 때 받는 변수
	srand((unsigned int)time(NULL));
	intro_game();


	do {
		system("cls");// 화면 밀기
		draw_rectangle(30, 20);
		rnd = rand() % 35 + 4;
		gotoxy(rnd, 2);
		textcolor2(4);
		printf("%s", target);
		count++;
		display_text(count, r_count);
		//gotoxy(3, 10);
		//monster(&r_count, rnd);

		game_control(&r_count, rnd, &bar); //목숨, 가만히있는 몬스터 위치, 장애물 닿았는지 안 닿았는지 알려주는 포인터

		if (bar == -1) {//장애물 닿았을 때 게임 아웃
			break;
		}

	} while (count < 10 && r_count > 0);
	gotoxy(59, 8);
	if (r_count == 0)//죽어서 괴물목숨이 0이면 남은 한개 목숨 삭제
		printf(" ");
	system("cls");
	if (((count == 10) && (r_count > 0)) || bar == -1) {
		
		box2();
		textcolor2(2);
		gotoxy(10, 10);
		printf("몬스터의 방해를 받고 실패했습니다..TAT");
		textcolor2(8);
		gotoxy(10, 14);
		printf("Enter키를 누르면 종료됩니다..");
		system("pause>null");
		system("cls");
		return 0;


	} //죽으면 gameover 문

	else if (r_count == 0) {
		
		box2();
		textcolor2(6);
		gotoxy(20, 11);
		printf("몬스터의 방해를 다 클리어 했습니다!!");
		textcolor2(15);
		gotoxy(20, 13);
		printf("다음 몬스터로 넘어갑니다.");
		getchar();

		game_shot.ddong(); // first_o 똥게임으로
		return 0;
	} //이길때


	gotoxy(8, 30); //계속하려면 ~~ 옮기기


}