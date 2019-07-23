#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CPU_game.h"

// 굳이 헤더파일 안써도 될 것 같아서 안씀.

int CPU_Game::updownGame() {
	srand((time(0)));
	printf("--- 백신을 얻기 위한 up & down 게임 ---\n\n\n\n");
	int com, me, count = 0, chance = 5;
	com = rand() % 101 + 1;


	while (count <= chance) {
		printf("기회는 다섯번 입니다!");
		printf("1~100 사이의 숫자를 입력하세요! (%d번째 도전중)\n", count + 1);
		printf("->");
		scanf_s("%d", &me);
		if (me < 1 || me>100) {
			printf("1~100 사이의 숫자를 다시입력해주세요.\n");
		}
		else {
			if (me > com) {
				printf("DOWN!!\n");
				count++;
			}
			else if (me == com) {
				printf("맞췄습니다!\n");
				printf("하지만 2번방에는 열쇠가 없었습니다..");
				int a = _getch();
				break;
			}
			else if (me < com) {
				printf("UP!!\n");
				count++;
			}


		}

		if (count >= chance) {
			printf("기회 5번을 다 써버렸네요..\n");
			printf("당신의 운은 여기까지 였습니다.");
			printf("정답은 %d 였습니다!\n", com);
			int a = _getch();
			system("cls");
			system("color 07");
			return 0;
		}

	}

	Sleep(2000);
	system("cls");
	return 0;

}