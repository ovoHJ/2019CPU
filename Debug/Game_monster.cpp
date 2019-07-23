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
	printf("%c%c", a, b[4]); //ㄱ

	printf("\n");
	for (int i = 1; i <= 5; i++) {
		printf("      ");
		printf("%c%c", a, b[2]);
		for (int j = 1; j <= 70; j++) printf(" ");
		printf("%c%c\n", a, b[2]);
	}

	printf("\n");
	gotoxy(6, 11);
	printf("%c%c", a, b[6]); //ㄴ
	for (int i = 1; i <= 70; i++) printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]); //l
	printf("\n\n");

}

int infor_Game() {
	textcolor(1);
	box();
	textcolor(15);
	gotoxy(10, 7); printf("몬스터가 뿌린 환장할 바이러스! 백신을 찾아 떠나야하는 당신.\n ");
	gotoxy(10, 8); printf("백신을 찾으려면 몬스터를 처치해야 합니다!\n");
	gotoxy(10, 9); printf("몬스터를 처치하고 열쇠를 얻어 백신을 얻어주세요!!\n\n\n");

	system("pause>null");
	game_mon.shootingGame();//슈팅게임으로 넘어감
	return 0;
}
void title() {
	char key;

	box();
	gotoxy(20, 7);
	textcolor(6);
	printf("\t\t  백신을 찾아줘! \n");

	while (1) {
		if (kbhit()) { //키입력받음 
			key = getch();
			if (key == ESC) exit(0); // ESC키면 종료 
			else break; //아니면 그냥 계속 진행 
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
	game_mon.RSP(); // 가위바위보 게임
	return 0;
}

int EscapeDoor2() {
	game_mon.updownGame(); // 업다운 게임
	return 0;
}

int infor_Box() {
	box();
	gotoxy(10, 7); printf("몬스터는 물리쳤으나 열쇠는 없는...!!!!\n ");
	gotoxy(10, 8); printf("하지만 몬스터가 알려준 알 수 없는 방문들이 있는 곳...\n");
	textcolor(9);
	gotoxy(10, 9); printf("반드시 백신을 꼭 구해주세요!!!\n\n\n");

	menu_main();
	return 0;
}

int CPU_Game::vaccine() {
	title();
	infor_Game();
	system("pause>null");
	system("cls");

	//if게임의 결과가 클리어냐/실패냐를 나누는 걸 해야하는뒤 어캐하쥐
	//infor_Box();

	return 0;
}

int menu_main() {
	int DoorChoice = 0;
	while (1) {
		textcolor(15);
		printf("몇 번째 문으로 들어가시겠습니까? ");
		printf("종류 : 1번방,  2번방  \n");
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
			printf(" %d번 방이 존재하지 않습니다.\n", DoorChoice);
		}
	}
	return 0;
}

int finish() {
	system("cls");
	getchar();

	printf("          ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("          ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("          ★★                                                            ★★\n");
	printf("          ★★                                                            ★★\n");
	printf("          ★★                !!!!!!당신은 백신을 찾았습니다!!!!!!        ★★\n");
	printf("          ★★                                                            ★★\n");
	printf("          ★★                 이제 탈출 할 수 있습니다!!                 ★★\n");
	printf("          ★★                                                            ★★\n");
	printf("          ★★                 ♥♥♥ 감 사 합 니 다 ♥♥♥               ★★\n");
	printf("          ★★                                                            ★★\n");
	printf("          ★★                                                            ★★\n");
	printf("          ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("          ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
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
		for (j = 0; j <= i * 2; j++) { printf("♥"); }
		for (j = 0; j <= (10 - i) * 2; j++) { printf("  "); }
		for (j = 0; j <= i * 2; j++) { printf("♥"); }
		printf("\n");
	}
	for (i = 20; i >= 0; i -= 2) {
		for (j = 0; j <= 20 - i; j++) { printf("  "); }
		for (j = 0; j <= i * 2; j++) { printf("♥"); }
		printf("\n");
	}
	Sleep(1500);

	return 0;
}