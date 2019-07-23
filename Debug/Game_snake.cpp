#include "stdafx.h"
#include <stdio.h>
#include <windows.h> //��ǥ���� ������ �ֱ� ����, Sleep�Լ�, goto�Լ�, system�Լ����� ����ϱ� ���� ����
#include <stdlib.h>
#include <time.h>
#include <conio.h> //getch�Լ��� ����ϱ� ���� ����
#include "header.h"
#include "CPU_game.h"
#include "Hgotoxy.h"

#pragma warning(disable : 4996)

void gotoxy_snake(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int rand_x = 0; //gotoxy_snake�� ������ ��ǥ�� ���̸� ���� ���� ����
int rand_y = 0;
int speed = 150; // ������ ���ǵ带 ����

unsigned char body[1823];

// ��ǥ �� 1823ĭ�� �� �Ӹ��� ��ġ�� ǥ���ϱ� ����
// ���� �ڽ��� ���� ������ ��츦 üũ
//y�ִ� :  75�̰� x�ִ� : 23)
unsigned int remove_tail_check[75 * 23];
// ���� ������ �������� �κ��� üũ�ϱ� ���� �迭�� ���� ��ǥ�� ����
//  point_head�� point_tail�� �����ͷ� �����

int point_head;

// remove_tail_check�� �����ͷ� ����
// ���� ���� Ŀ�������� �����͸� 1�� ������Ű�鼭 �����Ͱ� ����Ű�� ������ ������ �߰��Ǵ�(���̸� �Ծ) ���� �� ��ġ���� ��Ÿ��

int point_tail;
// remove_tail_check�� �����ͷ� ����
// ���� ����(������ �������� �κ�)�� üũ�Ͽ� �����ֱ� ���� ������
// ���� �����϶����� point_tail�� ����Ű�� �κп� ����� ���� ��ǥ�� ���� �װ��� �� ������ ����


void textcolor(int color_number) //�ؽ�Ʈ Į�� �ٲ��ִ� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}



void back_round()  // �ܰ����� ǥ���ϱ� ���� �Լ�
{

	unsigned char a = 0xa6;//Ȯ�� �ƽ�Ű �ڵ�� 16����, 10�����δ� 166
	int i, j;
	int x = 39; //��
	int y = 24; //��
				//���� �׵θ�

	printf("%c%c", a, 0xa3);//163
	for (i = 0; i < x + 35; i++)
		printf("%c%c", a, 0xa1);

	printf("%c%c\n", a, 0xa4);
	//�纯 �׸���. ���� for���� ����Ѵ�.

	for (j = 0; j < y - 2; j++)
	{

		printf("%c%c", a, 0xa2);
		for (i = 0; i < x - 2; i++)
			printf("  ");
		printf("%c%c", a, 0xa2);
		printf("\n");

	}
	//�Ʒ��� �׵θ�
	printf("%c%c", a, 0xa6);
	for (i = 0; i < x + 35; i++)printf("%c%c", a, 0xa1);
	printf("%c%c\n", a, 0xa5);
}

// ���� 37ĭ, ���� 22ĭ

void game_option() { // ���ӿɼ� ����(���ǵ�)�� ���� �Լ�

	while (1) {

		int nan = 10;
		system("cls");
		gotoxy_snake(1, 1); //1,1�� ���� ���
		printf("���ڰ� �������� ���̵��� �����ϴ�\n");
		printf("������ ���̵��� �����ϰ� ����Ű�� ��������(1~6) :");
		scanf("%d", &nan);

		if (nan == 1)
		{
			speed = 130;
		}
		else if (nan == 2)
		{
			speed = 120;
		}
		else if (nan == 3)
		{
			speed = 100;
		}
		else if (nan == 4)
		{
			speed = 90;
		}
		else if (nan == 5)
		{
			speed = 80;
		}
		else if (nan == 6)
		{
			speed = 70;
		}
		else
		{

			printf("1~6������ ���ڸ� �Է��ϼ���.\n"); //1~6������ ���ڸ� ���Է� �޵���
			Sleep(300); // 300/1000�ʸ�ŭ ������Ű�� ����
			continue; //�ٽ� ���� ����
		}

		system("cls");
		break;

	}

}

void start() {


	unsigned char start = 2; // ���� ��ŸƮ�� üũ�ϱ� ���� ����

	int x, y; //�� : x, �� : y

	int ago_x; // ���� ���� ������ ���ֱ� ���� ��ǥ���� �ӽ� �����ϱ����� ����

	int ago_y;

	int body_number; //���� �ø� ���� ��

	unsigned char chr; // ����Ű�� Ű���� �ޱ����� ����


					   /*********** ���� �ʱ�ȭ ***************/
	while (1)
	{


		ago_x = 3;

		ago_y = 2;

		chr = 99;

		point_head = 1;

		point_tail = 0;

		body_number = 1;

		memset(body, 0, 1823);

		memset(remove_tail_check, 0, 1725);

		remove_tail_check[0] = 155;



		/*************  �ʱ�ȭ�� **********************/

		printf("������ �����Ϸ��� 1�� �����ÿ�\n");

		printf("������ �����Ϸ��� 0�� �����ÿ�\n");

		start = getch();

		if (start == '0')
		{
			system("cls");
			break;

		}
		else if (start != '1')
		{
			system("cls");
			continue;
		}

		game_option(); //���� ���ǵ� ����

		gotoxy_snake(1, 1);

		back_round();  //���Ӹ� �ܰ��� �׸���

		rand_x = ((rand() % 37)) * 2 + 3; //���������Ͽ� ���հ��� ��ǥ�� ����

		rand_y = (rand() % 22) + 2;

		gotoxy_snake(rand_x, rand_y);

		textcolor(12);  //������

		printf("��");   //���հ��� ��ǥ�ΰ��� ���̸� ��Ÿ��

		int rand_a = ((rand() % 40)) * 2 + 3;
		int rand_b = (rand() % 20) + 2;


		x = 3;  // ���� ���� ���� ��ǥ�� ��Ÿ��

		y = 2;

		gotoxy_snake(x, y);

		while (1)
		{

			if (kbhit() != 0) //�ƹ�Ű�� �Է¹޾����� if���� ������
			{

				chr = getch();

				if (chr == 0 || chr == 0xe0)
				{

					chr = getch();

				}

			}

			if (chr == 72) //����Ű '��' �Է¹�����
			{

				y -= 1;

				if (y < 2)
				{

					system("cls"); // ȭ���� ������ �����

					gotoxy_snake(30, 10);

					printf("GAME OVER\n"); // 30,10�� ���Ṯ�� ���

					break;

				}

			}
			else if (chr == 80) //����Ű '��' �Է¹�����
			{

				y += 1;

				if (y > 23)
				{

					system("cls");

					gotoxy_snake(30, 10);

					printf("GAME OVER\n");

					break;

				}

			}
			else if (chr == 75) //����Ű '��' �Է¹�����

			{
				x -= 2; // �׸�� Ư������(2byte)�̹Ƿ� ���δ� 2ĭ�� �̵��ؾ���

				if (x < 3)
				{

					system("cls");

					gotoxy_snake(30, 10);

					printf("GAME OVER\n");

					break;

				}

			}
			else if (chr == 77) //����Ű '��' �Է¹�����
			{

				x += 2;

				if (x > 75)
				{

					system("cls");

					gotoxy_snake(30, 10);

					printf("GAME OVER\n");

					break;

				}

			}

			if ((x == rand_x) && (y == rand_y))
			{ // ���̸� �Ծ��� ���

			  //������ ����Ͽ� ���ο� ���̸� �ʿ� ǥ����

				rand_x = ((rand() % 37)) * 2 + 3;

				rand_y = (rand() % 22) + 2;

				gotoxy_snake(rand_x, rand_y);

				textcolor(12);

				printf("��");//�� ���� �׸�

				int rand_a = ((rand() % 40)) * 2 + 3;
				int rand_b = (rand() % 20) + 2;

				/*gotoxy_snake(rand_a, rand_b);
				textcolor(11);

				printf("��");

				if (x == rand_a && y == rand_b) exit(0);*/


				//�Ʒ� �ڵ�� ���� ���̸� �Ծ����Ƿ� ������ �߰��� ���� ��ǥ�� �߰��ϰ� ���� ������ǥ�� �߰��ϴ� ��

				//���̸� ���� ��쿡�� ���� ���븦 �����ʿ�����Ƿ�(���� �þ��) �̿� ���� �ڵ�� ����,

				//�׷��� if�� ������ �ٷ� �ݺ���(while)�� ���ǹ����� �̵���

				remove_tail_check[point_head] = (y) * 76 + x; // ���� ���븦 ����ǥ������ �߰�

				point_head++;

				if (point_head >= 1656)point_head = 0;

				body[(y) * 76 + x] = 1; //���� ��ǥ �߰�(1�� ������ �ִٴ� ǥ��, 0�� ������ ���ٴ� ǥ��)

				body_number++;

				if (body_number >= 10) {

					speed -= 10;

					if (speed < 40)speed = 40;

					body_number = 0;

				}

				continue;

			}




			//������ ������ ������ ����� ���� �ڵ���

			ago_y = remove_tail_check[point_tail] / 76;  //ago�� �ӽ�����

			ago_x = remove_tail_check[point_tail] % 76;

			if (ago_x == 0)ago_x = 75;

			gotoxy_snake(ago_x, ago_y);

			printf("%c%c", 0x00, 0x00);

			body[remove_tail_check[point_tail]] = 0; //���� ������ ��ǥ�� ���� �������� �����Ƿ� ������ǥ���� ����

			point_tail++;

			if (point_tail >= 1656)point_tail = 0;




			//�� �Ӹ��� ���� �������� �� �Ӹ��� ������ �׷��ֱ� ���� �ڵ���

			remove_tail_check[point_head] = (y) * 76 + x;

			if (body[remove_tail_check[point_head]] == 0)//�� �Ӹ��� ���� ���� �� ������ ���� ���
			{

				body[remove_tail_check[point_head]] = 1;

			}
			else//�� �Ӹ��� ������ǥ�� ������ ����, gameover��
			{
				system("cls");

				gotoxy_snake(30, 10);
				printf("�Ӹ��� ���뿡 ��ҽ��ϴ�..�Ф�");
				gotoxy_snake(30, 14);
				printf("GAME OVER\n");

				break;

			}

			point_head++;

			if (point_head >= 1656)point_head = 0;

			gotoxy_snake(x, y);

			textcolor(rand() % 15 + 1); // �ؽ�Ʈ������ ������ �����Ͽ� LEDó�� ��¦�̰� �Ѵ�.

			printf("��"); //�� �Ӹ��� �׸���




			Sleep(speed); // ������ ���ǵ� ����


		}

	}
}


void CPU_Game::snakeGame()
{
	start();

	srand(time(NULL)); // ���� �ʱ�ȭ ����

}

