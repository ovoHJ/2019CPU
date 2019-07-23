#include "stdafx.h"
#include "header.h"
#include "obstancle.h"
#include "Rock_UP.h"
#include "CPU_Game.h"
#include "shooting.h"

void gotoxy_1(int x, int y)//이거 없으면 좌표 다 망가져요~
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int CPU_Game::ddong() // first_o -> ddong
{
	int speed;	// 게임 전체 스피드 *구조체 안의 speed와 다른 개념임
	int freq;	// 똥 떨어지는 초기 개수
	int score;	// 점수
	int select;	// 메뉴 선택
	int level, temp_level = 1;
	int i = 0, j = 0;
	struct dump d[MAX];	// 똥 생성
	struct player p[1];	// 플레이어 생성
start: // 게임 재시도 역할 레이블

	select = menu();	// 메뉴출력

	init(d, p, &speed, &freq, &score, &temp_level);	// 게임시작 전 초기화 하는 함수.
	switch (select)
	{
	case 1:	// 게임시작
		system("cls");
		print_background();	// 벽출력
		while (1)
		{
			// 점수별 레벨 계산후 출력
			level = lev(score);
			if (level == 0)
				return 0;
			if (level > temp_level)
			{
				gotoxy_1(12, 10);
				textcolor(15);
				printf("레벨이 올라갑니다.");
				Sleep(1500);
				gotoxy_1(12, 10);
				printf("                  ");
			}
			gotoxy_1(24, 22);
			textcolor(14);
			printf("level : %d", level);
			temp_level = level;
			control_player(p);	// 플레이어 컨트롤(화살표 키 값 계속 받음)
			if (!d_drop(d, p, score, freq))	// 사용자가 똥을 맞았을 때 if문 수행(다시 start레이블로)
			{
				return 0;
				//goto start;	// 다시 처음으로 돌아감
			}
			speed = whole_speed(score);	// 게임 전반적인 speed 난이도 조절
			freq = control_bindo(score);	// 똥이 떨어지는 개수 조절
			gotoxy_1(11, 22);	// 스코어 출력
			textcolor(15);
			printf("score : %d", score++);
			Sleep(speed);	// speed가 낮아지면 점점 while문이 빠르게 동작
		}
		break;

	case 2:	// 게임 종료시
		system("cls");
		for (i = 0; i < 16; i++)
		{
			gotoxy_1(28, 10);
			textcolor(i);
			printf("Bye Bye!!!\n");
			Sleep(500);
		}
		gotoxy_1(28, 11);
		return 0;
	}
	goto start;
}

int lev(int score)
{
	int level, tmp_level = 1;

	if (score < 200)
		level = 1;
	else if (score <400) {
		level = 2;
	}
	else if (score < 550)
		level = 3;
	else if (score < 700)
		level = 4;
	else if (score < 750) {
		level = 5;
		system("cls");
		level_is_9();
		infor_Box();
		return 0;
	}
	tmp_level = level;
	return level;
}

// 초기화 함수
void init(struct dump d[MAX], struct player p[1], int *speed, int *freq, int *score, int *temp_level)
{
	int i;
	*speed = 50;	// 게임 초기 스피드
	*freq = 20;	// 똥 떨어지는 초기 개수
	*score = 0;	// 점수
	*temp_level = 1;
	for (i = 0; i < MAX; i++)
	{
		d[i].x = baserand(1, 40);
		d[i].y = 0;
		d[i].color = baserand(1, 15);
		d[i].speed = baserand(2, 10);
		d[i].tmp = d[i].speed;
	}
	p[0].x = 20;
	p[0].c = 'A';
}

// 전체 스피드 조절
int whole_speed(int score)
{
	int speed = 30;

	if (score >= 150)
		speed = 22;
	if (score >= 300)
		speed = 18;
	if (score >= 450)
		speed = 11;
	if (score >= 600)
		speed = 12;
	if (score >= 750)
		speed = 8;
	if (score >= 900)
		speed = 5;
	if (score >= 1100)
		speed = 3;
	if (score >= 1250)
		speed = 1;

	return speed;
}

// 화면안의 전체 똥의 개수를 조절
int control_bindo(int score)
{
	int freq = 6;

	if (score >= 150)
		freq = 8;
	if (score >= 300)
		freq = 11;
	if (score >= 450)
		freq = 15;
	if (score >= 600)
		freq = 20;
	if (score >= 750)
		freq = 25;
	if (score >= 900)
		freq = 30;
	if (score >= 1100)
		freq = 35;
	if (score >= 1250)
		freq = 40;

	return freq;
}

// 메뉴출력
int menu()
{
	system("cls");
	//system("pause>null");


	int select;
	textcolor(15);
	box2();
	textcolor(0x00f0);
	gotoxy_1(23, 7);
	printf("몬스터의 공격을 피하는 게임");
	textcolor(6);
	gotoxy_1(20, 8);
	printf("★★★★★★★★★★★★★★★");
	textcolor(15);
	gotoxy_1(24, 10);
	printf("1.게임 시작");
	gotoxy_1(21, 12);
	printf("q를 누르면 종료되니 주의하세요.");
	gotoxy_1(21, 14);
	printf("방향키: → 와 ←");
	textcolor(6);
	gotoxy_1(20, 16);
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆");
	gotoxy_1(22, 18);
	textcolor(15);
	printf("번호 선택>>");
	scanf("%d", &select);

	return select;
}

void control_player(struct player p[1]) // 플레이어 컨트롤값 받는 함수
{
	char ch;    // 키보드 값을 받는 변수

	gotoxy_1(p[0].x, 19);
	textcolor(14);
	putchar(' ');

	if (kbhit())	// 어떤키보드 입력이 들어오면 1 값을 반환, 만약 반환된 값이 있다면
	{
		ch = getch();

		switch (ch)
		{
		case LEFT:
			if (p[0].x != 1)
				p[0].x--;
			break;
		case RIGHT:
			if (p[0].x != 40)
				p[0].x++;
			break;
		case 'q':
			system("cls");
			gotoxy_1(32, 10);
			infor_Box();
	

		}
	}
	gotoxy_1(p[0].x, 19);
	textcolor(14);
	putchar(p[0].c);
}

//똥 떨구기 함수,부딪혔을때 처리
int d_drop(struct dump d[MAX], struct player p[1], int score, int freq)
{
	int i;

	for (i = 0; i < freq; i++)
	{
		if (d[i].speed-- == 0)
			// 각 구조체 똥마다 speed가 0이 되었을때 출력!!!,즉 speed가 적을수록 똥이 자주 출력됨.
		{
			gotoxy_1(d[i].x, d[i].y);
			textcolor(d[i].color);
			putchar(' ');// 떨어지는 똥의 잔상을 없앰
			d[i].y++;	// 똥 한칸 내림
			if (d[i].x == p[0].x && d[i].y == 19)// 똥에 부딪혔을때 처리
			{
				system("cls");
				box();
				gotoxy_1(15, 8);
				textcolor(15);
				printf("당신은 몬스터의 공격을 피하지 못하고");
				gotoxy_1(15, 10);
				textcolor(15);
				printf("죽었습니다..");
				gotoxy_1(12, 11);
				Sleep(2000);	// 1.5초 대기
				system("cls");
				return 0;
			}
			if (d[i].y == 20) // 똥이 밑에 다 떨어졌을 때 다시 위에서 내려보냄
			{
				d[i].x = baserand(1, 40);
				d[i].y = 0;
				d[i].color = baserand(1, 15);
				d[i].speed = baserand(2, 10);
				d[i].tmp = d[i].speed;
			}
			gotoxy_1(d[i].x, d[i].y);
			textcolor(d[i].color);
			putchar('O');
			d[i].speed = d[i].tmp;	// 원래 speed로 복구.
		}
	}
}

// 벽 출력
void print_background()
{
	int i;

	for (i = 0; i < 20; i++)
	{
		gotoxy_1(0, i);
		printf("|                                        |");
	}
	gotoxy_1(1, 20);
	printf("□□□□□□□□□□□□□□□□□□□□");
}

int level_is_9() {
	box();
	gotoxy_1(15, 7);
	textcolor(14);
	printf("몬스터의 공격을 다 성공하셨습니다.\n");
	gotoxy_1(15, 9);
	textcolor(15);
	printf("5초동안 기다리면 다음 스테이지로 넘어갑니다.");
	Sleep(5000);//5초
	//system("pause");

	return 0;
}



//숫자 2개의 범위안에서 랜덤값을 출력
int baserand(int x, int y)
{
	static int seed = 1;
	seed = abs(((seed * 124245423 * time(NULL) * 2432523 + 346356) / 65535) % 32768);
	return seed % (y - x + 1) + x;
}

