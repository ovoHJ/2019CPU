#include "stdafx.h"
#include "shooting.h"
#include "CPU_game.h"


CPU_Game game_shot;

void textcolor2(int color_number) //�ؽ�Ʈ Į�� �ٲ��ִ� �Լ�
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
	printf("%c%c", a, b[4]); //��

	printf("\n");

	for (int i = 1; i <= 14; i++) {
		printf("      ");
		printf("%c%c", a, b[2]);
		for (int j = 1; j <= 70; j++) printf(" ");

		printf("%c%c\n", a, b[2]);
	}

	printf("\n");
	gotoxy(6, 20);
	printf("%c%c", a, b[6]); //��

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
	textcolor2(3); //�ϴû�
	printf("�ڡ� ���� ���̱� 1�ܰ� �ڡ�\n\n\n");

	textcolor2(15);
	gotoxy(20, 10);
	printf("1�ܰ�� ���ð��� �Դϴ� !\n\n");
	gotoxy(20, 12);
	printf("���ּ��� Ÿ�� �̵��ϸ鼭\n");
	gotoxy(20, 14);
	printf("������(��) ������ ���ߴ� ����! �� �߻� : spaceŰ\n\n");
	gotoxy(20, 16);
	printf("������ �����Ϸ��� �ƹ�Ű�� ��������~");
	gotoxy(20, 18);
	printf("�׷� 1�ܰ� �����մϴ�~!!\n");
	key = _getch();


}
void display_text(int count, int r_count) {
	textcolor2(4);
	gotoxy(63, 2);
	printf("  �Ѿ� �߻�� space Ű!\n\n");
	textcolor2(4);
	gotoxy(63, 4);
	printf("  �Ѿ� : 10��\n\n");
	textcolor2(15);
	gotoxy(63, 6);
	printf("  ���ѹ߻�Ƚ�� : %d\n\n", count);
	gotoxy(63, 8);
	printf("  ������ ��� :");

	gotoxy(78, 8);
	for (int i = 0; i < r_count; i++) {
		printf("�� ");
	}
}

void game_control(int *r_c, int rnd, int *bar) {
	int i = 1, k = 1, y;//i=���ּ� ��ġ
	int i2 = 1, k2 = 1/*, y2*/; //i2=���� ��ġ
	char *horse = (char*)"��", chr; //���ּ�
	char *monster = (char*)"��"/*, chr2*/;

	do {
		i += k;
		if (i > 58) //������ �簢�� ���� ������ �ٽ� ��������
			k = -1;
		else if (i < 3) //���� �簢�� ���� ������ �ٽ� ����������
			k = +1;

		horizontal_slide(i, 20, horse);

	} while (!_kbhit());//Ű���尡 ���ȴ��� �ȴ��ȴ��� Ȯ��
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


	if (chr == 32) {//���� Ű�� �����̽���
		while (y > 2) {
			y -= 1;
			gotoxy(i + 1, y);
			printf("��");
			Sleep(30);
			printf("\b\b ");
		}
		if ((rnd - 1 <= i) && (i <= (rnd))) {
			gotoxy(rnd - 1, 2);
			textcolor2(11);
			printf("����");
			gotoxy(46, 13);
			printf("����:����.. ");
			Sleep(50);
			*r_c = *r_c - 1; //������ �Ѿ��� ������ ����� �ϳ� �ٴ� ��
		}

		if ((i2 - 1 <= i) && (i <= i2)) {//�Ѿ��� �����̴� ���Ϳ� ������ bar = -1
			*bar = -1; //
			return;
		}

		gotoxy(1, 24);
		printf("�ƹ�Ű�� ������ ���� ����...");
		_getch();
		gotoxy(1, 30);
	}

}
void horizontal_slide(int x, int y, char *c2) {//���ּ� �����̴� �ӵ�
	gotoxy(x, y);
	printf("%s", c2);
	Sleep(50);
	printf("\b\b");

}
void horizontal_slide2(int x, int y, char *c2) {//���ּ� �����̴� �ӵ�
	gotoxy(x, y);
	printf("%s", c2);
	Sleep(30);
	printf("\b\b");

}

int CPU_Game::shootingGame() { // first -> shootingGame
	int count = 0, rnd;
	int r_count = 3;
	char *target = (char*)"��";
	int bar = 1;//��ֹ� ����� �� �޴� ����
	srand((unsigned int)time(NULL));
	intro_game();


	do {
		system("cls");// ȭ�� �б�
		draw_rectangle(30, 20);
		rnd = rand() % 35 + 4;
		gotoxy(rnd, 2);
		textcolor2(4);
		printf("%s", target);
		count++;
		display_text(count, r_count);
		//gotoxy(3, 10);
		//monster(&r_count, rnd);

		game_control(&r_count, rnd, &bar); //���, �������ִ� ���� ��ġ, ��ֹ� ��Ҵ��� �� ��Ҵ��� �˷��ִ� ������

		if (bar == -1) {//��ֹ� ����� �� ���� �ƿ�
			break;
		}

	} while (count < 10 && r_count > 0);
	gotoxy(59, 8);
	if (r_count == 0)//�׾ ��������� 0�̸� ���� �Ѱ� ��� ����
		printf(" ");
	system("cls");
	if (((count == 10) && (r_count > 0)) || bar == -1) {
		
		box2();
		textcolor2(2);
		gotoxy(10, 10);
		printf("������ ���ظ� �ް� �����߽��ϴ�..TAT");
		textcolor2(8);
		gotoxy(10, 14);
		printf("EnterŰ�� ������ ����˴ϴ�..");
		system("pause>null");
		system("cls");
		return 0;


	} //������ gameover ��

	else if (r_count == 0) {
		
		box2();
		textcolor2(6);
		gotoxy(20, 11);
		printf("������ ���ظ� �� Ŭ���� �߽��ϴ�!!");
		textcolor2(15);
		gotoxy(20, 13);
		printf("���� ���ͷ� �Ѿ�ϴ�.");
		getchar();

		game_shot.ddong(); // first_o �˰�������
		return 0;
	} //�̱涧


	gotoxy(8, 30); //����Ϸ��� ~~ �ű��


}