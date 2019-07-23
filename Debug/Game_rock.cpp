#include "stdafx.h"
#include "Rock_UP.h"
#include "header.h"
#include "CPU_game.h"

int k = 0;


void box_1() {
	textcolor(7);
	int i, j;
	unsigned char a = 0xa6;;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);

	for (i = 0; i < 25; i++)
		printf("%c%c ", a, b[1]);

	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < 25; i++) {
		printf("%c%c", a, b[2]);
		for (j = 0; j < 25; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	printf("%c%c", a, b[6]);
	for (i = 0; i < 25; i++)
		printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

int CPU_Game::RSP() { // first_display_R -> RSP
	box();
	textcolor(15);
	gotoxy(13, 7);
	printf("문지기와 가위바위보를 한다.");
	gotoxy(13, 8);
	printf("10판을 해야하는데 3번을 이겨야 한다.");
	gotoxy(13, 9);
	printf("당신의 운을 믿고 열쇠를 획득하세요! ");
	gotoxy(13, 10);
	printf("그럼 START~!");
	getchar();

	RockSP();
	return 0;
}

int RockSP() {

	system("cls");

	srand((unsigned)time(NULL));//계속 다른 수가 나오게 하기

	int computer_rand = (rand() % 3) + 1;//컴퓨터가 생각하는 수
										 //1~3까지의 수를 돌림
	char *computer_crand = 0;//가위, 바위, 보 중 한개 저장하기
	int my_input;//내가 선택하는 것
	
	int count = 1;//0이 되면 게임 끝

	switch (computer_rand) {
	case 1: computer_crand = (char*)"가위"; break;
	case 2: computer_crand = (char*)"바위"; break;
	case 3: computer_crand = (char*)"보"; break;
	}
	
	box_1();
	while (1) {

		

		textcolor(12);
		gotoxy(55, 5);
		printf("횟수 : %d", count);

		textcolor(8);
		gotoxy(3, 12);
		printf("당신이 생각하는 ");
		textcolor(8);
		gotoxy(3, 13);
		printf("1.(가위) 2.(바위) 3.(보)를 입력하세요.");
		textcolor(6);//노란
		gotoxy(3, 14);
		printf(" >> ");
		scanf("%d", &my_input);

		if (my_input == 1) {
			textcolor(7);
			gotoxy(3, 19);
			printf("당신이 낸 패는 가위입니다.");
			if (computer_rand == 1) {
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(6);
				gotoxy(3, 24);
				printf("비겼습니다.");
				count++;
			}
			else if (computer_rand == 2) {
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(5);
				gotoxy(3, 24);
				printf("졌습니다.");
				count++;
			}
			else if (computer_rand == 3) {
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(2);
				gotoxy(3, 24);
				printf("이겼습니다.");
				count++;
				k++;
			}
		}


		else if (my_input == 2) {//바위 냄
			textcolor(7);
			gotoxy(3, 19);
			printf("당신이 낸 패는 바위입니다.");
			if (computer_rand == 1) {//가위
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(2);
				gotoxy(3, 24);
				printf("이겼습니다.");
				count++;
				k++;
			}
			else if (computer_rand == 2) {//바위
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(6);
				gotoxy(3, 24);
				printf("비겼습니다.");
				count++;
			}
			else if (computer_rand == 3) {//보
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(5);
				gotoxy(3, 24);
				printf("졌습니다.");
				count++;
			}

		}
		else if (my_input == 3) {//보
			textcolor(7);
			gotoxy(3, 19);
			printf("당신이 낸 패는 보입니다.");
			if (computer_rand == 1) {//가위
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(5);
				gotoxy(3, 24);
				printf("졌습니다.");
				count++;
			}
			else if (computer_rand == 2) {//바위
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(2);
				gotoxy(3, 24);
				printf("이겼습니다.");
				count++;
				k++;
			}
			else if (computer_rand == 3) {//보
				textcolor(8);
				gotoxy(3, 21);
				printf("컴퓨터가 생각한 것은 %s였습니다.", computer_crand);
				textcolor(6);
				gotoxy(3, 24);
				printf("비겼습니다.");
				count++;
			}
		}
		//else { textcolor(15); gotoxy(10, 8); printf("잘못입력하였습니다. "); textcolor(15); gotoxy(10, 10); printf("기회는 날라갑니다.."); count--; }

		if (k == 3) {
			/*system("cls"); /*getchar(); getchar(); box_1(); gotoxy(3, 15); textcolor(6); printf("당신은 문지기와의 싸움에서 이겼습니당!");
			textcolor(6); gotoxy(3, 16); printf("백신은 여기에 있었습니다!!");  */ finish();
		return 0;
		}
		if (count == 10) {
			system("cls"); box_1(); textcolor(5); gotoxy(3, 17);  printf("기회가 끝나버렸다."); textcolor(5); gotoxy(3, 19); printf("당신의 운은 여기까지인가 보다."); return 0;
		}
	}

}

void textcolor1(int color_number) //텍스트 칼라를 바꿔주는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
