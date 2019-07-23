#include "stdafx.h"
#include "header.h"
#include "CPU_game.h"

#define ESC 27
#define ENTER 13

CPU_Game game_mon;

void box() {
	char start = 0;
	unsigned char a = 0xa6, b[7], i;

	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	gotoxy(6, 5);
	printf("%c%c", a, b[3]); //r
	for (int i = 1; i <= 70; i++) printf("%c%c", a, b[1]); //-
	printf("%c%c", a, b[4]); //��

	printf("\n");
	for (int i = 1; i <= 5; i++) {
		printf("      ");
		printf("%c%c", a, b[2]);
		for (int j = 1; j <= 70; j++) printf(" ");
		printf("%c%c\n", a, b[2]);
	}

	printf("\n");
	gotoxy(6, 11);
	printf("%c%c", a, b[6]); //��
	for (int i = 1; i <= 70; i++) printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]); //l
	printf("\n\n");

}

int infor_Game() {
	textcolor(1);
	box();
	textcolor(15);
	gotoxy(10, 7); printf("���Ͱ� �Ѹ� ȯ���� ���̷���! ����� ã�� �������ϴ� ���.\n ");
	gotoxy(10, 8); printf("����� ã������ ���͸� óġ�ؾ� �մϴ�!\n");
	gotoxy(10, 9); printf("���͸� óġ�ϰ� ���踦 ��� ����� ����ּ���!!\n\n\n");

	system("pause>null");
	game_mon.shootingGame();//���ð������� �Ѿ
	return 0;
}
void title() {
	char key;

	box();
	gotoxy(20, 7);
	textcolor(6);
	printf("\t\t  ����� ã����! \n");

	while (1) {
		if (kbhit()) { //Ű�Է¹��� 
			key = getch();
			if (key == ESC) exit(0); // ESCŰ�� ���� 
			else break; //�ƴϸ� �׳� ��� ���� 
		}
		textcolor(15);
		gotoxy(21, 13);
		printf("       < PRESS ANY KEY TO START > ");
		Sleep(400);
		gotoxy(21, 13);
		printf("                                    ");
		Sleep(400);

	}
	system("pause>null");
}

int EscapeDoor1() {
	system("color 07");
	game_mon.RSP(); // ���������� ����
	return 0;
}

int EscapeDoor2() {
	game_mon.updownGame(); // ���ٿ� ����
	return 0;
}

int infor_Box() {
	box();
	gotoxy(10, 7); printf("���ʹ� ���������� ����� ����...!!!!\n ");
	gotoxy(10, 8); printf("������ ���Ͱ� �˷��� �� �� ���� �湮���� �ִ� ��...\n");
	textcolor(9);
	gotoxy(10, 9); printf("�ݵ�� ����� �� �����ּ���!!!\n\n\n");

	menu_main();
	return 0;
}

int CPU_Game::vaccine() {
	title();
	infor_Game();
	system("pause>null");
	system("cls");

	//if������ ����� Ŭ�����/���гĸ� ������ �� �ؾ��ϴµ� ��ĳ����
	//infor_Box();

	return 0;
}

int menu_main() {
	int DoorChoice = 0;
	while (1) {
		textcolor(15);
		printf("�� ��° ������ ���ðڽ��ϱ�? ");
		printf("���� : 1����,  2����  \n");
		textcolor(6);
		printf(">>>> ");
		textcolor(0x00f0);
		scanf("%d", &DoorChoice);

		switch (DoorChoice) {
		case 1:
			EscapeDoor1();
			return 0;
			break;
		case 2:
			system("cls");
			EscapeDoor2();
			infor_Box();
			break;
		}
		if (DoorChoice > 2 || DoorChoice <= 0) {
			printf(" %d�� ���� �������� �ʽ��ϴ�.\n", DoorChoice);
		}
	}
	return 0;
}

int finish() {
	system("cls");
	getchar();

	printf("          �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
	printf("          �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
	printf("          �ڡ�                                                            �ڡ�\n");
	printf("          �ڡ�                                                            �ڡ�\n");
	printf("          �ڡ�                !!!!!!����� ����� ã�ҽ��ϴ�!!!!!!        �ڡ�\n");
	printf("          �ڡ�                                                            �ڡ�\n");
	printf("          �ڡ�                 ���� Ż�� �� �� �ֽ��ϴ�!!                 �ڡ�\n");
	printf("          �ڡ�                                                            �ڡ�\n");
	printf("          �ڡ�                 ������ �� �� �� �� �� ������               �ڡ�\n");
	printf("          �ڡ�                                                            �ڡ�\n");
	printf("          �ڡ�                                                            �ڡ�\n");
	printf("          �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
	printf("          �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
	gotoxy(10, 20);


	textcolor(15);

	Sleep(1000);
	heart();
	return 0;


}
int heart() {
	system("cls");

	int i, j;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	textcolor(4);
	for (i = 4; i < 10; i += 2) {
		for (j = 0; j <= (10 - i); j++) { printf("  "); }
		for (j = 0; j <= i * 2; j++) { printf("��"); }
		for (j = 0; j <= (10 - i) * 2; j++) { printf("  "); }
		for (j = 0; j <= i * 2; j++) { printf("��"); }
		printf("\n");
	}
	for (i = 20; i >= 0; i -= 2) {
		for (j = 0; j <= 20 - i; j++) { printf("  "); }
		for (j = 0; j <= i * 2; j++) { printf("��"); }
		printf("\n");
	}
	Sleep(1500);

	return 0;
}