#include "stdafx.h"
#include "header.h"
#include "obstancle.h"
#include "Rock_UP.h"
#include "CPU_Game.h"
#include "shooting.h"

void gotoxy_1(int x, int y)//�̰� ������ ��ǥ �� ��������~
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int CPU_Game::ddong() // first_o -> ddong
{
	int speed;	// ���� ��ü ���ǵ� *����ü ���� speed�� �ٸ� ������
	int freq;	// �� �������� �ʱ� ����
	int score;	// ����
	int select;	// �޴� ����
	int level, temp_level = 1;
	int i = 0, j = 0;
	struct dump d[MAX];	// �� ����
	struct player p[1];	// �÷��̾� ����
start: // ���� ��õ� ���� ���̺�

	select = menu();	// �޴����

	init(d, p, &speed, &freq, &score, &temp_level);	// ���ӽ��� �� �ʱ�ȭ �ϴ� �Լ�.
	switch (select)
	{
	case 1:	// ���ӽ���
		system("cls");
		print_background();	// �����
		while (1)
		{
			// ������ ���� ����� ���
			level = lev(score);
			if (level == 0)
				return 0;
			if (level > temp_level)
			{
				gotoxy_1(12, 10);
				textcolor(15);
				printf("������ �ö󰩴ϴ�.");
				Sleep(1500);
				gotoxy_1(12, 10);
				printf("                  ");
			}
			gotoxy_1(24, 22);
			textcolor(14);
			printf("level : %d", level);
			temp_level = level;
			control_player(p);	// �÷��̾� ��Ʈ��(ȭ��ǥ Ű �� ��� ����)
			if (!d_drop(d, p, score, freq))	// ����ڰ� ���� �¾��� �� if�� ����(�ٽ� start���̺��)
			{
				return 0;
				//goto start;	// �ٽ� ó������ ���ư�
			}
			speed = whole_speed(score);	// ���� �������� speed ���̵� ����
			freq = control_bindo(score);	// ���� �������� ���� ����
			gotoxy_1(11, 22);	// ���ھ� ���
			textcolor(15);
			printf("score : %d", score++);
			Sleep(speed);	// speed�� �������� ���� while���� ������ ����
		}
		break;

	case 2:	// ���� �����
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

// �ʱ�ȭ �Լ�
void init(struct dump d[MAX], struct player p[1], int *speed, int *freq, int *score, int *temp_level)
{
	int i;
	*speed = 50;	// ���� �ʱ� ���ǵ�
	*freq = 20;	// �� �������� �ʱ� ����
	*score = 0;	// ����
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

// ��ü ���ǵ� ����
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

// ȭ����� ��ü ���� ������ ����
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

// �޴����
int menu()
{
	system("cls");
	//system("pause>null");


	int select;
	textcolor(15);
	box2();
	textcolor(0x00f0);
	gotoxy_1(23, 7);
	printf("������ ������ ���ϴ� ����");
	textcolor(6);
	gotoxy_1(20, 8);
	printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�");
	textcolor(15);
	gotoxy_1(24, 10);
	printf("1.���� ����");
	gotoxy_1(21, 12);
	printf("q�� ������ ����Ǵ� �����ϼ���.");
	gotoxy_1(21, 14);
	printf("����Ű: �� �� ��");
	textcolor(6);
	gotoxy_1(20, 16);
	printf("�١١١١١١١١١١١١١١�");
	gotoxy_1(22, 18);
	textcolor(15);
	printf("��ȣ ����>>");
	scanf("%d", &select);

	return select;
}

void control_player(struct player p[1]) // �÷��̾� ��Ʈ�Ѱ� �޴� �Լ�
{
	char ch;    // Ű���� ���� �޴� ����

	gotoxy_1(p[0].x, 19);
	textcolor(14);
	putchar(' ');

	if (kbhit())	// �Ű���� �Է��� ������ 1 ���� ��ȯ, ���� ��ȯ�� ���� �ִٸ�
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

//�� ������ �Լ�,�ε������� ó��
int d_drop(struct dump d[MAX], struct player p[1], int score, int freq)
{
	int i;

	for (i = 0; i < freq; i++)
	{
		if (d[i].speed-- == 0)
			// �� ����ü �˸��� speed�� 0�� �Ǿ����� ���!!!,�� speed�� �������� ���� ���� ��µ�.
		{
			gotoxy_1(d[i].x, d[i].y);
			textcolor(d[i].color);
			putchar(' ');// �������� ���� �ܻ��� ����
			d[i].y++;	// �� ��ĭ ����
			if (d[i].x == p[0].x && d[i].y == 19)// �˿� �ε������� ó��
			{
				system("cls");
				box();
				gotoxy_1(15, 8);
				textcolor(15);
				printf("����� ������ ������ ������ ���ϰ�");
				gotoxy_1(15, 10);
				textcolor(15);
				printf("�׾����ϴ�..");
				gotoxy_1(12, 11);
				Sleep(2000);	// 1.5�� ���
				system("cls");
				return 0;
			}
			if (d[i].y == 20) // ���� �ؿ� �� �������� �� �ٽ� ������ ��������
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
			d[i].speed = d[i].tmp;	// ���� speed�� ����.
		}
	}
}

// �� ���
void print_background()
{
	int i;

	for (i = 0; i < 20; i++)
	{
		gotoxy_1(0, i);
		printf("|                                        |");
	}
	gotoxy_1(1, 20);
	printf("���������������������");
}

int level_is_9() {
	box();
	gotoxy_1(15, 7);
	textcolor(14);
	printf("������ ������ �� �����ϼ̽��ϴ�.\n");
	gotoxy_1(15, 9);
	textcolor(15);
	printf("5�ʵ��� ��ٸ��� ���� ���������� �Ѿ�ϴ�.");
	Sleep(5000);//5��
	//system("pause");

	return 0;
}



//���� 2���� �����ȿ��� �������� ���
int baserand(int x, int y)
{
	static int seed = 1;
	seed = abs(((seed * 124245423 * time(NULL) * 2432523 + 346356) / 65535) % 32768);
	return seed % (y - x + 1) + x;
}

