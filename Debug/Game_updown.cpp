#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CPU_game.h"

// ���� ������� �Ƚᵵ �� �� ���Ƽ� �Ⱦ�.

int CPU_Game::updownGame() {
	srand((time(0)));
	printf("--- ����� ��� ���� up & down ���� ---\n\n\n\n");
	int com, me, count = 0, chance = 5;
	com = rand() % 101 + 1;


	while (count <= chance) {
		printf("��ȸ�� �ټ��� �Դϴ�!");
		printf("1~100 ������ ���ڸ� �Է��ϼ���! (%d��° ������)\n", count + 1);
		printf("->");
		scanf_s("%d", &me);
		if (me < 1 || me>100) {
			printf("1~100 ������ ���ڸ� �ٽ��Է����ּ���.\n");
		}
		else {
			if (me > com) {
				printf("DOWN!!\n");
				count++;
			}
			else if (me == com) {
				printf("������ϴ�!\n");
				printf("������ 2���濡�� ���谡 �������ϴ�..");
				int a = _getch();
				break;
			}
			else if (me < com) {
				printf("UP!!\n");
				count++;
			}


		}

		if (count >= chance) {
			printf("��ȸ 5���� �� ����ȳ׿�..\n");
			printf("����� ���� ������� �����ϴ�.");
			printf("������ %d �����ϴ�!\n", com);
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