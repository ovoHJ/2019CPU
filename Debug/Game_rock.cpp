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
	printf("������� ������������ �Ѵ�.");
	gotoxy(13, 8);
	printf("10���� �ؾ��ϴµ� 3���� �̰ܾ� �Ѵ�.");
	gotoxy(13, 9);
	printf("����� ���� �ϰ� ���踦 ȹ���ϼ���! ");
	gotoxy(13, 10);
	printf("�׷� START~!");
	getchar();

	RockSP();
	return 0;
}

int RockSP() {

	system("cls");

	srand((unsigned)time(NULL));//��� �ٸ� ���� ������ �ϱ�

	int computer_rand = (rand() % 3) + 1;//��ǻ�Ͱ� �����ϴ� ��
										 //1~3������ ���� ����
	char *computer_crand = 0;//����, ����, �� �� �Ѱ� �����ϱ�
	int my_input;//���� �����ϴ� ��
	
	int count = 1;//0�� �Ǹ� ���� ��

	switch (computer_rand) {
	case 1: computer_crand = (char*)"����"; break;
	case 2: computer_crand = (char*)"����"; break;
	case 3: computer_crand = (char*)"��"; break;
	}
	
	box_1();
	while (1) {

		

		textcolor(12);
		gotoxy(55, 5);
		printf("Ƚ�� : %d", count);

		textcolor(8);
		gotoxy(3, 12);
		printf("����� �����ϴ� ");
		textcolor(8);
		gotoxy(3, 13);
		printf("1.(����) 2.(����) 3.(��)�� �Է��ϼ���.");
		textcolor(6);//���
		gotoxy(3, 14);
		printf(" >> ");
		scanf("%d", &my_input);

		if (my_input == 1) {
			textcolor(7);
			gotoxy(3, 19);
			printf("����� �� �д� �����Դϴ�.");
			if (computer_rand == 1) {
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(6);
				gotoxy(3, 24);
				printf("�����ϴ�.");
				count++;
			}
			else if (computer_rand == 2) {
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(5);
				gotoxy(3, 24);
				printf("�����ϴ�.");
				count++;
			}
			else if (computer_rand == 3) {
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(2);
				gotoxy(3, 24);
				printf("�̰���ϴ�.");
				count++;
				k++;
			}
		}


		else if (my_input == 2) {//���� ��
			textcolor(7);
			gotoxy(3, 19);
			printf("����� �� �д� �����Դϴ�.");
			if (computer_rand == 1) {//����
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(2);
				gotoxy(3, 24);
				printf("�̰���ϴ�.");
				count++;
				k++;
			}
			else if (computer_rand == 2) {//����
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(6);
				gotoxy(3, 24);
				printf("�����ϴ�.");
				count++;
			}
			else if (computer_rand == 3) {//��
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(5);
				gotoxy(3, 24);
				printf("�����ϴ�.");
				count++;
			}

		}
		else if (my_input == 3) {//��
			textcolor(7);
			gotoxy(3, 19);
			printf("����� �� �д� ���Դϴ�.");
			if (computer_rand == 1) {//����
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(5);
				gotoxy(3, 24);
				printf("�����ϴ�.");
				count++;
			}
			else if (computer_rand == 2) {//����
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(2);
				gotoxy(3, 24);
				printf("�̰���ϴ�.");
				count++;
				k++;
			}
			else if (computer_rand == 3) {//��
				textcolor(8);
				gotoxy(3, 21);
				printf("��ǻ�Ͱ� ������ ���� %s�����ϴ�.", computer_crand);
				textcolor(6);
				gotoxy(3, 24);
				printf("�����ϴ�.");
				count++;
			}
		}
		//else { textcolor(15); gotoxy(10, 8); printf("�߸��Է��Ͽ����ϴ�. "); textcolor(15); gotoxy(10, 10); printf("��ȸ�� ���󰩴ϴ�.."); count--; }

		if (k == 3) {
			/*system("cls"); /*getchar(); getchar(); box_1(); gotoxy(3, 15); textcolor(6); printf("����� ��������� �ο򿡼� �̰���ϴ�!");
			textcolor(6); gotoxy(3, 16); printf("����� ���⿡ �־����ϴ�!!");  */ finish();
		return 0;
		}
		if (count == 10) {
			system("cls"); box_1(); textcolor(5); gotoxy(3, 17);  printf("��ȸ�� �������ȴ�."); textcolor(5); gotoxy(3, 19); printf("����� ���� ��������ΰ� ����."); return 0;
		}
	}

}

void textcolor1(int color_number) //�ؽ�Ʈ Į�� �ٲ��ִ� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
