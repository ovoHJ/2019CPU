#include "stdafx.h"
#include "header.h"
#include "CPUcastle_screenBase.h"
#include "CPUcastle_mainScreen.h"
#include "CPUcastle_storyScreen.h"
#include "CPU_game.h"


void CPU_Game::storyGame(void)
{
	system("mode con cols=119 lines=35");
	system("title CPUĳ��");
	CursorView(0);

	while (castleEnd) {		//ĳ���͸� �����ϱ� ���ؼ� ���ѷ���
		mainViewww();
		int nextView = mainMove();
		if (nextView == 0) {
			if (qy == 1) {
				while (1) {
					diningroom = 0;
					bedroom = 0;
					password = 0; //��ȣŰ
					deskKey = 0; //����
					roop = 1;
					pyramid = 0;
					FindThePyramid();
					nextScene();
					gotoxy(28, 5);
					printf("�ٽ��ϱ�");
					gotoxy(28, 9);
					printf("������");

					choose = keyControl2();
					system("cls");
					gotoxy(0, 17);
					mainView();

					if (choose == 2)
						break;
				}
				castleEnd == 0;
				system("cls");
				break;
			}
			else if (qy == 2) {
				EscapePrison();

				castleEnd == 0;
				system("cls");
				break;
			}
		}
	}
}

int EscapePrison()
{
	system("cls");
	gotoxy(20, 7);  printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
	gotoxy(20, 8);  printf("�� ��ī��ĳ������ �Ͼ ���λ��. ������ ���� ���� ���ο� ���� ������ ��");
	gotoxy(20, 9);  printf("�� ã�Ƴ´�. ������ ������ ���� ������ �� ��� ��Ȳ. ��Ȱ�� ���縦 ��  ��");
	gotoxy(20, 10); printf("�� �� ĳ�� �ֹε��� ��� ���縦 ����߰� ��ȭ�ο� �ϻ��� �����ϴ� ��¥ ��");
	gotoxy(20, 11); printf("�� ��Ž���� ���� �ð� �ȴ�. �������κ��� �Ϸ� ��, ������ �����ִ�. ��  ��");
	gotoxy(20, 12); printf("�� �� '��¥ ��Ž��'�� �Ϸ� �ȿ� ������ �濡�� �ܼ��� �ִ��� ��Ƽ�     ��");
	gotoxy(20, 13); printf("�� ���ǿ��� �̱� �� ������?                                            ��");
	gotoxy(20, 14); printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
	nextScene();
	gotoxy(15, 23);	printf("�̹��� ���� ���� ����� �žư� ���λ��. �̹� ����� ���ο� ���� ������ ���� ������");
	gotoxy(15, 24);	printf("�ִ� ����̴�. �̹��� ���� �ؾ� �ϴ� ���� ���� �������� ������ ���Ÿ� ã�� ������ ");
	gotoxy(15, 25);	printf("������ �ִ� ��!! �ð��� �� ���� �ʾ����� ���ѷ� ������ ��� ������ �����߰ڴ�.");
	nextScene();
	gotoxy(15, 23);	printf("���Ⱑ ������ ��... ���⼭���� ������ ������ ���� �� ����!");
	gotoxy(15, 24);	printf("���� �� ������ ��ƾ߰ھ�!");
	nextScene();
	gotoxy(15, 23);	printf("������ �濡 �ִ� ���� �繰�� ������ ������ ã�ƾ� �Ѵ�.");
	textColor(4);
	gotoxy(15, 24);	printf("����ǰ���� ����Ʈ���� �ʼ��̸�, �������� �� ������ ì�ܰ� �� �ִ�. ");
	gotoxy(15, 25);	printf("����� ������ ����ǰ�� ���� ������ ������ �������Ƿ� �����ϰ� �����ؾ� �Ѵ�.");
	textColor(7);
	next();

	int first_while;
	int second_while;
	int third_while;
	int fourth_while;
	int check = 0;
	bool usb = 0;
	bool smartphone = 0;
	
	int qovop = 0;

	int plus = 0;
	int desk = 0;
	int bag = 0;

	first_while = 1;
	while (first_while) {
		second_while = 1;
		while (second_while) {
			gotoxy(2, 1);	printf("1. å��");
			gotoxy(2, 2);	printf("2. ����");
			gotoxy(2, 3);	printf("3. ����");
			gotoxy(2, 4);	printf("4. ���� ����");
			gotoxy(2, 6);	printf("[�Է�] ");

			scanf("%d", &check);
			system("cls");

			switch (check) {
			case 1:
				third_while = 1;
				while (third_while) {
					gotoxy(2, 1);	printf("1. å����");
					gotoxy(2, 2);	printf("2. �ʱⱸ");
					gotoxy(2, 3);	printf("3. �޸𺸵�");
					gotoxy(2, 4);	printf("4. ����ǰ ����");
					gotoxy(2, 5);	printf("5. �ڷ� ����");
					gotoxy(2, 7);	printf("[�Է�] ");

					scanf("%d", &check);
					system("cls");

					switch (check) {
					case 1:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("��? ������ �����å�� �߰��ߴ�. ");
						next();
						gotoxy(20, 7);  printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
						gotoxy(20, 8);  printf("��   201x�� xx�� xx��                          ��");
						gotoxy(20, 9);  printf("��   ��-�б�-�п�-��. ��ҿ� ����              ��");
						gotoxy(20, 10); printf("��   201x�� xx�� xx��                          ��");
						gotoxy(20, 11); printf("��   ��-�б�-��. ���� ���� ����                ��");
						gotoxy(20, 12); printf("��   .                                         ��");
						gotoxy(20, 13); printf("��   .                                         ��");
						gotoxy(20, 14); printf("��   .                                         ��");
						gotoxy(20, 15); printf("��   201x�� 2�� 27��                           ��");
						gotoxy(20, 16); printf("��   ���� ���� �ȳ�                            ��");
						gotoxy(20, 17); printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
						next();
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("2�� 27�� ���ķ� �ۼ��Ǿ� ���� �ʴ�. ���ϱ�... ");
						next();

						break;
					case 2:
						usb = true;

						gotoxy(0, 17);
						mainView();
						textColor(4);
						gotoxy(15, 23);	printf("USB�� ȹ���Ͽ����ϴ�. ��Ʈ�Ͽ��� ������ Ȯ���� �� �ֽ��ϴ�. ");
						textColor(7);
						gotoxy(15, 24);	printf("����Ʈ���� ���� �ִ�. ");
						gotoxy(15, 25);	printf("�����¿��� '������ �������� ���� ���´�.'��� ���ִ�. ");
						next();

						break;
					case 3:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 23);	printf("�޸𺸵忡 ������ �ֺ��ι��� ������ �����Ǿ� �ִ�");
						nextScene();
						gotoxy(15, 24);	printf("������   200x�� 10�� 23��");
						gotoxy(15, 25);	printf("����1��. ����� ������� ����");
						nextScene();
						gotoxy(15, 24);	printf("Ȳ����   200x�� 2�� 27��");
						gotoxy(15, 25);	printf("����3��. �̸� ����� �����");
						nextScene();
						gotoxy(15, 24);	printf("������   200x�� 10�� 29��");
						gotoxy(15, 25);	printf("����2��. ���� ����� �����");
						next();

						break;
					case 4:
						fourth_while = 1;
						while (fourth_while) {
							gotoxy(2, 1);	printf("����� ������ å�� �ִ� ���ǵ� �� �ϳ��� ����ǰ�� ì�ܰ� �� �ֽ��ϴ�.");
							gotoxy(2, 2);	printf("");
							gotoxy(2, 3);	printf("1. �����ϱ�");
							gotoxy(2, 4);	printf("2. �ڷ� ����");
							gotoxy(2, 6);	printf("[�Է�] ");
							scanf("%d", &check);
							system("cls");

							if (check == 1) {
								gotoxy(2, 1);	printf("����� ������ å�� �ִ� ���ǵ� �� �ϳ��� ����ǰ�� ì�ܰ� �� �ֽ��ϴ�.");
								gotoxy(2, 3);	printf("[1. �����å   2. USB   3. �޸𺸵� �Կ�����]");
								gotoxy(2, 5);	printf("[�Է�] ");
								scanf("%d", &check);
								system("cls");
								if (check == 1)
									desk = 1;
								gotoxy(2, 1);	printf("%d���� ����ǰ���� ì��̽��ϴ�!", check);
								int a = _getch();
								system("cls");
								fourth_while = 0;
							}
						}

						break;
					case 5:
						third_while = 0;
						system("cls");
					}
				}
				break;
			case 2:
				third_while = 1;
				while (third_while) {
					gotoxy(2, 1);	printf("1. L������");
					gotoxy(2, 2);	printf("2. ��Ʈ��");
					gotoxy(2, 3);	printf("3. ���");
					gotoxy(2, 4);	printf("4. ����ǰ ����");
					gotoxy(2, 5);	printf("5. �ڷ� ����");
					gotoxy(2, 7);	printf("[�Է�] ");

					scanf("%d", &check);
					system("cls");

					switch (check) {
					case 1:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("���簳�� 100���� �ִ�. ");
						nextScene();
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("01. ���庸�� ���� �����?   ������ ");
						nextScene();
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("02. �ɰ��� ������ ���� �Ⱦ��ϴ� ���ô�?   �õ�� ");
						nextScene();
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("03. ���� ������?   ǲ�� ");
						next();

						break;
					case 2:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("�⺻ ���ȭ�鿡�� �⺻ ���� �ۿ� ����. ");
						nextScene();
						system("cls");
							fourth_while = 1;
							while (fourth_while) {
								gotoxy(2, 1);	printf("��ǻ�͸� �� �� �����غ��ڽ��ϱ�?");
								gotoxy(2, 2);	printf("");
								gotoxy(2, 3);	printf("1. ��� ã��");
								gotoxy(2, 4);	printf("2. �ڷ� ����");
								gotoxy(2, 6);	printf("[�Է�] ");
								scanf("%d", &check);
								system("cls");

								if (check == 1) {
									gotoxy(0, 17);
									mainView();
									gotoxy(15, 22);	printf("������ ������ �߰��ߴ�. ");
									gotoxy(15, 23);	printf("���� �ȿ��� �¶��� ��縦 ũ���� �������� �ִ�. ����� ����� �̾߱��");
									TEXT(4);
									gotoxy(15, 24);	printf("���ݱ��� ������ �ٸ� ������� ������, �ᱹ ������ �˸� ���� �ʾҴ� ����̴�. ");
									TEXT(7);
									gotoxy(15, 25); printf("���� ���� �ֱٿ� ������ ����");
									TEXT(4);
									printf("�žư� ���λ���� ��¥ ������?!");
									nextScene();
									system("cls");
								}
								else if (check == 2) {
									fourth_while = 0;
									break;
								}
						}
						if (usb == true) {
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 23); printf("usb����");
							gotoxy(15, 24);	printf("������ ���ڿ��� ���Դ� �������� ����Ǿ� �ִ�. �� �߿��� ���� ��� ������ �ִ�. ");
							nextScene();
							gotoxy(15, 22); printf("�������� : �Ź��ѹ���_�١�");
							gotoxy(15, 23); printf("9981 + 1601 = 2957");
							gotoxy(15, 24); printf("1080 + 9168 = ????");
							nextScene();
							system("cls");
						}

						break;
					case 3:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 23);	printf("�޴��� �������� ���� ����罺Ʈ�κ��� ����̴�.");
						gotoxy(15, 24); printf("����� ���� �ؼ� ���� ���� ����. �׸��� ��� �þƺ� ������ �� ����.");
						next();

						break;
					case 4:
						fourth_while = 1;
						while (fourth_while) {
							gotoxy(2, 1);	printf("����� ������ å�� �ִ� ���ǵ� �� �ϳ��� ����ǰ�� ì�ܰ� �� �ֽ��ϴ�.");
							gotoxy(2, 2);	printf("");
							gotoxy(2, 3);	printf("1. �����ϱ�");
							gotoxy(2, 4);	printf("2. �ڷ� ����");
							gotoxy(2, 6);	printf("[�Է�] ");
							scanf("%d", &check);
							system("cls");

							if (check == 1) {
								gotoxy(2, 1);	printf("����� ������ å�� �ִ� ���ǵ� �� �ϳ��� ����ǰ�� ì�ܰ� �� �ֽ��ϴ�.");
								gotoxy(2, 3);	printf("[1. L������   2. ��Ʈ��   3. ���]");
								gotoxy(2, 5);	printf("[�Է�] ");
								scanf("%d", &check);
								system("cls");
								if (check == 2)
									bag = 1;
								gotoxy(2, 1);	printf("%d���� ����ǰ���� ì��̽��ϴ�!", check);
								int a = _getch();
								system("cls");
								fourth_while = 0;
							}
							else if (check == 2) {
								fourth_while = 0;
								break;
							}
						}

						break;
					case 5:
						third_while = 0;
						system("cls");

						break;
					}
				}
				break;
			case 3:
				third_while = 1;
				while (third_while) {
					gotoxy(2, 1);	printf("1. ����Ʈ��");
					gotoxy(2, 2);	printf("2. �� ����");
					gotoxy(2, 3);	printf("3. �Ʒ� ����");
					gotoxy(2, 4);	printf("4. �ڷ� ����");
					gotoxy(2, 6);	printf("[�Է�] ");

					scanf("%d", &check);
					system("cls");

					switch (check) {
					case 1:
						if (smartphone == true) {
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 23);	printf("����Ʈ�� ������ ������. ");
							gotoxy(15, 24); printf("�Ϲ� �������� �޸𿡴��� ����� ������ �� �ۿ� ���� �ʾ� ����������");
							gotoxy(15, 25); printf("������ �ߴ�. ������ ��й�ȣ�� ���� �ܼ��� ");
							textColor(4);
							printf("�Ź��� �����̴�. ");
							textColor(7);
							next();

							fourth_while = 1;
							while (fourth_while) {
								gotoxy(2, 1);	printf("1. Ǯ��");
								gotoxy(2, 2);	printf("2. �ڷ� ����");
								gotoxy(2, 4);	printf("[�Է�] ");
								scanf("%d", &check);
								system("cls");

								if (check == 1) {
									gotoxy(2, 5);	printf("[�Է�] ");
									scanf("%d", &check);
									system("cls");
									if (check == 9717) {
										qovop = 1;

										gotoxy(0, 17);
										mainView();
										gotoxy(15, 23);	printf("�������� �ȿ��� �������� ������ ��ġ�� ������ ����ְ�");
										gotoxy(15, 24); printf("������ ���� �����ִ�.");
										nextScene();
										textColor(4);
										gotoxy(15, 24);
										printf("������ ���Ÿ� ã�ҽ��ϴ�! ������ ������ ���˸� ���� �� �����̴ϴ�!! ");
										textColor(7);
										next();
										fourth_while = 0;
									}
									else {
										gotoxy(0, 17);
										mainView();
										gotoxy(15, 23);	printf("Ʋ�Ƚ��ϴ�. ");
										next();
									}
								}
								else if (check == 2) {
									fourth_while = 0;
									break;
								}
							}
						}
						else {
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 23);	printf("������ ������ �ʴ´�. �Ƹ� ������ �ؾ��� �� ����. ");
							next();
						}

						break;
					case 2:
						fourth_while = 1;
						while (fourth_while) {
							gotoxy(2, 1);	printf("1. �η��� ����");
							gotoxy(2, 2);	printf("2. ����Ʈ�� ������");
							gotoxy(2, 3);	printf("3. �ڷ� ����");
							gotoxy(2, 5);	printf("[�Է�] ");
							scanf("%d", &check);
							system("cls");

							if (check == 1) {
								plus = 1;

								gotoxy(0, 17);
								mainView();
								gotoxy(15, 23);	printf("�ڼ��� ���캸�� �����⿴��. ");
								gotoxy(15, 24); printf("�η��� �����Ⱑ ������ ���̹Ƿ� ");
								textColor(4);
								printf("����ǰ���� ��������. ");
								textColor(7);
								next();
							}
							else if (check == 2) {
								smartphone = true;
								
								gotoxy(0, 17);
								mainView();
								textColor(4);
								gotoxy(15, 23);	printf("����Ʈ�� �����⸦ ȹ���Ͽ����ϴ�. ");
								textColor(7);
								next();

							}
							else if (check == 3) {
								fourth_while = 0;
							}
						}

						break;
					case 3:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 23);	printf("������ ������ ������ �ֺ������� ����� �������� ��Ʈ���� �ִ�.");
						gotoxy(15, 24); printf("���� �ڿ��� ������ �����ִ�.");
						nextScene();
						gotoxy(15, 23);	printf("����1�� ���� �� - 3�� 20��  ������ �ʹ� �����");
						gotoxy(15, 24);	printf("����2�� ���� �� - 1�� 4��  ���� �ʹ� ������");
						gotoxy(15, 25); printf("������ ���� �� - 2�� 26��");
						gotoxy(15, 26); printf("����3�� ���� �� - 8�� 25��  ������ ������");
						gotoxy(15, 27); printf("����4�� ���� �� - ������ �޴�ȭ��");
						next();

						break;
					case 4:
						third_while = 0;
						system("cls");

						break;
					}
				}
				break;
			case 4:
				system("cls");
				second_while = 0;
			}
		}
		int sum = plus + desk + bag;

		gotoxy(0, 17);
		mainView();
		gotoxy(15, 23);	printf("�׷� '�žư� ���λ��' �ǰ� ����� �˷��帮���� �ϰڽ��ϴ�.");
		gotoxy(15, 24); printf("�ǰ���!!");
		nextScene();

		if (qovop == 1) {
			if (sum == 0) {
				gotoxy(15, 23); printf("3�����Դϴ�!! ");
				gotoxy(15, 24); printf("�������� ���Ű� ������ ��߹������� ��ȹ�������� �� �� ���� �����Դϴ�.");
			}
			else if (sum == 1) {
				gotoxy(15, 23); printf("5�����Դϴ�!! ");
				gotoxy(15, 24); printf("�ǰ����� �����ڸ� �����ϱ� ���� ��ĥ���� �� ������ ������ �� ��ȹ������ ���� ���� �����Դϴ�.");
			}
			else if (sum == 2) {
				gotoxy(15, 23); printf("10�����Դϴ�! ");
				gotoxy(15, 24); printf("���ŵ��� ���� �� �ǰ����� ��߹��˰� �ƴ� ��ȹ������ ���� ���� �����Դϴ�.");
			}
			else if (sum == 3) {
				gotoxy(15, 23); printf("����¡���Դϴ�!! ");
				gotoxy(15, 24); printf("���ŵ��� ���� �� ���� �����ð����� �غ��� ��ȹ�����̱� �����Դϴ�.");
			}
		}
		else {
			gotoxy(15, 23); printf("�����Դϴ�!! ");
			gotoxy(15, 24); printf("�ǰ����� �����̶�� ������ ���Ű� ���� ������ ���˶�� ���� �� �����ϴ�.");
		}
		nextScene();
		gotoxy(15, 23); printf("�žư� ���λ���� �ǰ��� ���ſ� ���� ���Խ��ϴ�.");
		gotoxy(15, 24); printf("�ǰ� ����� �ƽ���ôٸ� �ٽ� �� �� �÷����ϴ� ���� ��õ�մϴ�.");
		next();

		system("cls");
		first_while = 0;
	}

	return 0;
}

int FindThePyramid()
{
	system("cls");

	CursorView(0);
	gotoxy(20, 13);
	textColor(8); //text color = gray
	//text color (������ 12, ����� 13, ���� 14, ?? 11, ������ 7, ������ 10, ���� �ؽ�Ʈ 8), ��Ʈ�ο����� �۾�ü ����, ���� �����ϸ� ����, ���� �Ͼ��
	printf("- 20XX�� 6�� �� ��ī�� ĳ�� ������ �����̳�");
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"������!!!!!! ������!!!!!! ���� �� �ϰ� �� �ϰ� �־�!!!!!!!!\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"��.. ���� 7�ùۿ� �� ���ݾƿ�.\"");
	textColor(10);
	gotoxy(20, 16);	printf("\"���� ������ 3�ÿ� ��µ�..\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"��ħ���� ������ ���� ������ �Ƕ�̵� ����⿡ ���� �� ����, �׷��ϱ� ..\"");

	textColor(7);
	gotoxy(20, 18);	printf("(�� �Ƕ�̵�.. ���� ���ֹ����� �ȵǳ� ..)");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"��, ���ؾ�.");
	gotoxy(20, 15);	printf("�츮, �� �Ƕ�̵� ���ٱ� ?\"");
	textColor(10);
	gotoxy(25, 18);	printf("\"�� ? �ƺ��� ���� ���������ϴ� ���� ?\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"����, �� �� �տ� ������ ������ ���ϰ���.\"\n");
	textColor(8);
	gotoxy(40, 25); printf("(���ѷαװ� �������ϴ�. Enter Ű�� ���� ���� ȭ������ �Ѿ �ּ���.)");
	// Finished intro

	nextScene();
	textColor(8); //change text color
	gotoxy(20, 8);	printf("-���� 2��, �����̳� ���� ��ΰ� �ῡ ���� �� ���߿� �����̿� �������� �濡�� ����");
	gotoxy(20, 10);	printf("�Һ��� ����Դ�.");
	nextScene();

	textColor(7);
	gotoxy(20, 8);	printf("\"���ؾ�, �Ͼ\"");

	keyy = _getch();
	if (keyy == 13) {
		gotoxy(15, 22);	printf("\"� ��ø�\"");
	} //enter if
	nextScene();

	gotoxy(15, 22);
	printf("\"�� �� ì�ܾ��ؼ�, �� .. �̰Ÿ� �ǰ��� ?\"");
	gotoxy(28, 5);	printf("- ��ο� ���� ���� �ڵ���");
	gotoxy(28, 9);	printf("- �Ƕ�̵带 ��ĥ �ָӴ�");
	gotoxy(28, 13);	printf("- �̲����� ���� �尩");

	nextScene();
	gotoxy(15, 22);	printf("\"����.\"");

	nextScene();
	gotoxy(15, 22);	printf("\"�ٵ�, ���� ������ ����?\"");

	while (roop) {
		nextScene();
		gotoxy(28, 5);	printf("�ƺ��� �Ƴ��� �͵鸸 �ִ� �ƺ��� ����");
		gotoxy(28, 9);	printf("���������� �ص� ���Ŀ��� �Ƕ�̵带 �ڶ��ϴ� �Ž�"); //�� ���� ������ diningroom = 0 -> 1;
		gotoxy(28, 13);	printf("�ƺ� ������ ���� �ڰ� ��ô� ħ��");// �� ���� ���� �� bedroom = 0 -> 1;

		choose = keyControl();
		system("cls");
		gotoxy(0, 17);
		mainView();

		gotoxy(20, 8);	printf("\"��� ���ܳ����� �� ���� ?\"");

		keyy = _getch();
		if (keyy == 13) {
			switch (choose) {
			case 1:
				gotoxy(15, 22);	printf("\"�ƺ� ����� ����.\"");
				nextScene();

				gotoxy(20, 8);	printf("\"���ؾ�, �츮 �������� ..?\"");

				keyy = _getch();
				if (keyy == 13) {
					gotoxy(15, 22);	printf("\"���ڱ� ���� �Ҹ���? ���� ��\"");
				} //enter if


				keyy = _getch();
				if (keyy == 13) {
					if (password == 1 && deskKey == 1) {
						roop = 0;

						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"��.. �Ʊ� ã�� ���踻�̾�, ���� ���� ���谰����?\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"��, �ѹ� �����.\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\'�ٵ� �� ���� �� �ϴ� �� ����...?\'");
						} //enter if

						nextScene();
						gotoxy(20, 8);	printf("- ö��");

						nextScene();
						gotoxy(20, 8);	printf("\"���ȴ�.\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"�ȿ� �� �־�?\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\"�� ���,\"'");
						} //enter if

						nextScene();
						gotoxy(28, 5);	printf("�� ����");//�� ������ ��� : �Ƕ�̵带 ���ܳ��Ҵٰ� ǥ�õ� ���� ����, �ɸ��� ��
						gotoxy(28, 9);	printf("�Ƕ�̵� å"); //�Ƕ�̵� å�� ��� : ������� ���� ���� ����
						gotoxy(28, 13);	printf("�ϱ���"); //������ �ϱ��� �� ��� : �Ǿ� �忡 �� ��ȣŰ : �ڵ��� �޸� 1�� �� �̶�� �ۼ��Ǿ� ����->�ݰ� ã��

						//�� ���� ������ ����� �� ��쿣 �ϱ��� ��� ����

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\"�� ���󵵰��� �͵� �־� �츮?\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"�׷��ϱ�, �ű⿡ ���� �־�?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"�� .. �Ƕ�̵� �ִ� �� �������. �� ���� ��¥ ������.\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"����.. �峭�ƴϴ�. ���� ���� ������ ��¥.\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("                                       ");
								gotoxy(15, 22);	printf("\"�׷�. ���� ��¥ ����.\"");
							} //enter if

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("�� ���󵵿� ���� �Ƕ�̵� ��ġ�� ������ ��� �� �� ���󵵴� ��¥�����ϴ� !!!");
							gotoxy(20, 7);	printf("��¥ �Ƕ�̵� ��ġ�� �� �����̿� �����̴� �ٽ� ����� �޷��ͼ� �ٸ� ���Ÿ�");
							gotoxy(20, 9);	printf("ã���� ������, �̹� ��ħ 7�� ���ð��� �ٰ����� ��¿ �� ���� �����ϰ� �������� �̷�ϴ�.");

							keyy = _getch();
							if (keyy == 13) {
								roop = 0;
								system("cls");
							} //enter if
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\".. �̰� �� ����, ��¥ ¡�׷��� ����.\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"�� .. �� ��¦ �Ҹ����Ҵµ� ����.\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"�̰� ������, ���� �������̳� �����.\"");
							} //enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\".. �츮 �ƺ� �ϱ⵵ ��?\"");


							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"��.. ���ó� ����, �� ���� �־� ??\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"2016�� 3�� 1��, ������ ������ �� �༮�� ���� �⿴��. �Ƕ�̵� ����, ���� �̰ŵ� �Ƕ�̵��?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"����.. �ϱ��忡�� �׷� �� ���ó�.      \"");
							} //enter if

							nextScene();
							gotoxy(15, 22);	printf("\"��, �� �ƺ� �ڵ��� �����Ծ��� �츮,\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"����, �ٵ� �� ?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"�ƴ�, �ű� �޸��� ���� ù��°�� ��ȣŰ��� ǥ���� �����ִµ�..?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"��? ����, ��ø� ..\"");
							} //enter if

							next();
							gotoxy(25, 10);	printf("------------------");
							gotoxy(25, 11);	printf("|                 |");
							gotoxy(25, 12);	printf("|  ������ ����    |");
							gotoxy(25, 13);	printf("|    0102         |");
							gotoxy(25, 14);	printf("|                 |");
							gotoxy(25, 15);	printf("------------------");

							nextScene();
							gotoxy(15, 22);	printf("\"����, ���� �����̳ס�\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 24);	printf("\"�Է��غ� ����,\"");
							} //enter if

							nextScene();
							gotoxy(15, 8); printf("- ��");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 10); printf("- ��");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 12); printf("- ��");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 14); printf("- ��");
							} //enter if


							nextScene();
							gotoxy(20, 8);	printf("\"����? ���� ������ ��\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"��, �Ƕ�̵� ���� �ִ� !!!!\"");
								pyramid = 1;
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"��, �ָӴϿ� ���ܼ� ������.\"");
								pyramid = 1;
							} //enter if
							break;
						}

					} //enter if
					else {
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);
						printf("\"���� .. �� �ݰ� ã����.. �� ���� �� ����\"");

						nextScene();
						gotoxy(15, 22);
						printf("\"�� ����, ��ȣŰ �־�� �ϴµ� ? \"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);
							printf("\"���⵵ ���� �־�� �� �� ����, �� ����\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);
							printf("                                           ");
							gotoxy(15, 22);
							printf("\"..�ٸ��� ���� ã��\"");
						} //enter if
					} //else (��ȣŰ�� ���谡 ���� ��쿡 ���縦 ������ �ٸ� ���� ���� ã�� ����)
				} //if (���縦 ã������ ��)
				break;
			case 2:
				if (diningroom == 1) {
					gotoxy(15, 22);	printf("���� �þ����ϱ� �ٸ� �� ����.");
					nextScene();
				} //if (�̹� �Ž��� �湮��)
				else {
					gotoxy(15, 22);
					printf("�Žǿ� ���� �� ���� �ʳ� ?");
					nextScene();
					gotoxy(15, 22);	printf("\"���� ���� ? ������, ���� �ڿ� �� ã�ƺ�.\"");
					gotoxy(20, 8);	printf("- ����");

					nextScene();
					gotoxy(20, 8);	printf("\"�� ��¥\"");

					keyy = _getch();
					if (keyy == 13) {
						textColor(11);
						gotoxy(20, 8);	printf("\"�ű� ������ ? \"");
					} //enter if

					keyy = _getch();
					if (keyy == 13) {
						textColor(7);
						gotoxy(15, 22);	printf(" ... ��� ���� ?");
					} //enter if

					nextScene();
					gotoxy(28, 5);	printf("������ ô�ϸ鼭 �� ������ Ƣ�����.");
					gotoxy(28, 9);	printf("�� ���÷� ���� ô�ϸ鼭 �������� ���ƺ���.");
					gotoxy(28, 13);	printf("���� ��Ǵ�� ���ϰ� �뼭�� ���Ѵ�.");

					choose = keyControl();

					switch (choose) {
					case 1: system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("��, �𸣰ڴ� Ƣ�� !!!");

						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("������ �����̿� �����̴� �� ������ �پ���� �� ���÷� ���� ������ ���� ");
						gotoxy(20, 7);	printf("������ �Ű��ϰ�, �����̿� �����̴� �ᱹ ���Ѽ� �ƺ����� ��û ȥ���� ���θ�");
						gotoxy(20, 9);	printf("�׾�� �ϰ� �Ǿ����ϴ�.");
						// (�̼� ����)

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if
						break; // �������� ��Ʈ�� �������� ���
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						textColor(7);
						gotoxy(15, 22);	printf("\"����, ������ ? �츮 �� ���÷� ������ ~");

						keyy = _getch();
						if (keyy == 13) {
							textColor(14);
							gotoxy(20, 8);	printf("\"�ʳ� ���� ���� �� ������ ..���� ���� ��\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							textColor(7);
							gotoxy(20, 12);	printf("\"�˾Ҿ�, ���� ����\"");
						} //enter if

						nextScene();
						gotoxy(15, 22);
						printf("\"... ���� ?\"");
						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("\"����, ���� ���� �̰�\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"����, ���� �ϰ� ����.\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"���, ������, �� ������ ���� �� ���� ? \"");
						} // enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                        ");
							gotoxy(20, 8);	printf("\"���, \"");
						}//enter if

						nextScene();
						gotoxy(28, 5);	printf("��ο� ���� ���� �ڵ���"); //�ڵ����� ����� ��Ŵ
						gotoxy(28, 9);	printf("�Ƕ�̵带 ��ĥ �ָӴ�"); //���� �ɸ��� ������ ���� ����
						gotoxy(28, 13);	printf("�̲����� ���� �尩"); //����

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(20, 8);	printf("\"�� ��� ..!\"");

							keyy = _getch();
							if (keyy == 13) {
								textColor(8);
								gotoxy(20, 12);	printf("- ����������������");
							} //enter if

							nextScene();
							textColor(12);
							gotoxy(20, 8);	printf("\"�� �� �߿� ������ !!!\"");

							nextScene();
							textColor(8);
							gotoxy(20, 8);	printf("�ڵ����� Ű�ٰ� �Ǽ��� �˶��� �������� �������� �Ǽ� ������ �ῡ�� ������ �ƺ����� �ɷ���");
							gotoxy(20, 10);	printf("�Ƕ�̵� Ż�� ����� ���з� ���ư��� �Ǿ����ϴ�.");

							keyy = _getch();
							if (keyy == 13) {
								roop = 0;
								system("cls");
							} //enter if (�̼� ����)
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"�ָӴϴ� �ʿ����..\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"�׳� ������ �� �׷�.\"");
							}// enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);
							printf("\"������.\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"������ �ؾ���, �˰��� ? \"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"�翬����, �� ������ ��\"");
							}// enter if
							nextScene();
							gotoxy(15, 22);	printf("\"��, ���ִ�.\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"����, ��¥ �� �־� ?\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"��, �����.");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 24);	printf("\"���谡 �� ���� ���� ? \"");
								deskKey = 1;
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("                          ");
								gotoxy(20, 8);	printf("\"�켱 ì�ܺ���. ��.\"");
							}// enter if

							nextScene();
							gotoxy(15, 24);	printf("\"�̰� ����� ���� ���� ���� ...\"");

							nextScene();
							gotoxy(20, 8);	printf("\"�׷� ���� �ٸ� �� ������.\"");
							break; // ���� �ùٸ� ��Ʈ�� ������
						} // switch (���踦 ã�� ���ؼ� ������ ����)
						break;
					case 3:
						system("cls");
						gotoxy(0, 17);
						mainView();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"�˼��ؿ�, ���� �ƹ��͵� �� �߾�� !\"");
						}// enter if

						keyy = _getch();
						if (keyy == 13) {
							textColor(13);
							gotoxy(20, 8);	printf("\"��..? ����\"");
						}// enter if

						keyy = _getch();
						if (keyy == 13) {
							textColor(7);
							gotoxy(20, 10);		printf("\"���...\"");
						}// enter if

						nextScene();
						textColor(8);
						gotoxy(20, 5); printf("���� ���÷� ���� �������� ��� ���� ��Ǵ�� �о���� �����̿� ������, ");
						gotoxy(20, 7);	printf("������ ��� ���� ��� ��� ������ �ϴ��� ���� �����شٰ� ���մϴ�. ������ ");
						gotoxy(20, 9);	printf("�ٽô� �̷� ���� ���� ����� ȥ�� �� �����̿� �����̴� ������ ���������ϴ�.");

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if (�̼� ����)
						break;
					} //switch (�������� ��ų ���� ���� ��Ʈ�� �����ϴ� switch)
					diningroom = 1;
				}//else (�Ž��� �ѹ��� �湮���� ����)
				break;
			case 3:
				if (bedroom == 1) {
					gotoxy(15, 22);	printf("���� �þ����ϱ� �ٸ� �� ����.");
					nextScene();
				} //if (�̹� ħ���� �湮��)
				else {

					gotoxy(15, 22);	printf("\"�����ƺ� ħ�� ������ ?\"");
					nextScene();
					gotoxy(20, 8);	printf("\"�ڰ� �ִ� �� ���� ?\"");

					keyy = _getch();
					if (keyy == 13) {
						gotoxy(15, 22);	printf("\"�´ٴϱ� �׷���. ���� ���� ã�⳪ ��.\"");
					}

					keyy = _getch();
					if (keyy == 13) {
						gotoxy(20, 8);	printf("\"�� �ٵ� �� ����..�� �� �� ���� ?\"");
					}

					nextScene();
					gotoxy(28, 5);	printf("��ο� ���� ���� �ڵ���"); //����
					gotoxy(28, 9);	printf("�Ƕ�̵带 ��ĥ �ָӴ�"); //(����߷��� �������� ��Ŵ)
					gotoxy(28, 13);	printf("�̲����� ���� �尩"); //�Ǽ��� �̲������� ū �Ҹ��� ���� �ƺ����� ���Ѽ� ��

					choose = keyControl();

					switch (choose) {
					case 1:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"��.. ���� ���忡 ���� �� ���� �ʾ�?\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"��� ���� �ϴ°ž�.\"");
						}

						nextScene();
						gotoxy(28, 5);	printf("������ �� ������");
						gotoxy(28, 9);	printf("������ ��� ������");
						gotoxy(28, 13);	printf("������ �Ʒ� ������"); //����

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"�� �ʹ� ��ο�.. \"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"�� ��� �Һ�..!\"");
							}// enter if

							next();
							textColor(12);
							gotoxy(20, 10);	printf("\"����... ������, ������. �� �� �ڰ� �ű⼭ ���ϴ� �ž�.\"");

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("������ Ž���Ϸ��ٰ� ������ ���� �ſ￡ ��ģ �ڵ��� �Һ��� �׸� �������� ");
							gotoxy(20, 7);	printf("���� ������ �������� �ῡ�� ������ϴ� !!! ");
							gotoxy(20, 9);	printf("�׷��� �����̿� �����̴� �� �� �߿� �������� �ܼҸ��� ȭ�� 3�ð� ���� ������ϴ�.");

							keyy = _getch();
							if (keyy == 13) {
								roop = 0;
								system("cls");
							} //enter if (�̼� ����)
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"�ƹ� �͵� ���µ�?\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"����, �׷� �Ʒ��� �����\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {

							}
						case 3:
							//�Ʒ��� : �ƺ� �ڵ����� �����־ ��
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"���� �ֱ� �Ѱž� �� ������..?\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"���ؾ�, ���� �ƺ� �ڵ��� �ƴϾ�? �� ���� ����.\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"�� ��¥��..                        ");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"Ȥ�� ���� ����� �ƺ� ���� ū���̴ϱ� �ۿ� ��������.\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("                                                        ");
								gotoxy(20, 8);	printf("\"�׷�.\"");
							}// enter if
							break;
						}//switch ���� ���Ʒ� ����
						break;
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"�ʹ� ��ο��� �� �� ���� ..\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"�ƴ�, ���� �� ��.\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("\"����, ã�Ҵµ� ����߷Ⱦ�...\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"��� .. \"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"�� !!!!\"");
						}

						nextScene();	textColor(12);
						gotoxy(20, 10);	printf("\"���� !!!! ����, ���� ������ !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("����߸� �ָӴϸ� ��� �Ѿ��� ���� �������� ���� �� �Ҹ��� �׸� �������� �����ȴ�.");
						gotoxy(20, 7);	printf("���� ������ �������� ȭ�� �Ӹ� ������ ���� �����̿� �����̸� �������� ���� �Ծ���,");
						gotoxy(20, 9);	printf("�׷��� �����̿� �����̴� �� �� �߿� �������� �ܼҸ��� ȭ�� 3�ð� ���� ���� �ߴ�.");

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if (�̼� ����)
						break;
					case 3:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("\"�ʹ� ��ο��� �� �� ���� ..\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("\"�ƴ�, ���� �� ��.\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"��, ã�Ҵµ� ����߷ȴ�.\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"�װ� ��ġ�� ... \"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"�� !!!!\"");
						}

						nextScene();
						gotoxy(20, 10);
						textColor(12);
						printf("\"���� ... ������, ������. ���ϴ� �ž� ���� !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("����߸� �尩�� �ʹ� �̲����� ��� �Ѿ��� ���� �������� ���� �� �Ҹ��� �׸� �������� �����Ƚ��ϴ�.");
						gotoxy(20, 7);	printf("�尩�� �������� ���� �׸��� ���� ������ ���� �Ӽ��� �˾����� �������� ȭ�� ���� ���ϰ�,");
						gotoxy(20, 9);	printf("�׷��� �����̿� �����̴� �� �� �߿� �������� �ܼҸ��� ȭ�� 3�ð� ���� ���� �߽��ϴ�.");

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if (�̼� ����)
						break;
					}//switch ���� Ž�� ������ ����
					password = 1;
					bedroom = 1;
				}//else (ħ���� �ѹ��� �湮���� �ʾ��� ���)
				break;
			}// switch (��� ���� �湮���� ������)
		} // enter if ( ù ������)
	}//while (�Ƕ�̵� Ž���� �ݺ���)

	if (pyramid == 1) {
		next();
		gotoxy(20, 10);	printf("- �� ���� ����");

		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 10);	printf("\"������, ���� �̰�\"");
		}//enter if

		system("cls");
		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 8);	printf("- ��                 ");
		}//enter if
		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 10);	printf("- ��");
		}//enter if
		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 12);	printf("- ��");
		}//enter if

		nextScene();
		textColor(7);
		gotoxy(20, 10);	printf("������ !!");
		textColor(10);
		gotoxy(20, 12);	printf("������ !!");

		next();
		gotoxy(20, 10);	printf("���ϵ帳�ϴ� !! �Ƕ�̵带 ã�Ƴ��� �����Ƚ��ϴ�!");
		gotoxy(20, 12);	printf("ENTER Ű�� �����ø� ĳ�� ���� �������� ���ư��ϴ� _");
	}//���� �Ƕ�̵带 ã�Ҵٸ�
	system("pause>null");

	return 0;
}


int mainViewww()
{
	system("cls");
	for (int i = 0; i < MAIN_VIEW_HEIGHT; i++) {
		for (int j = 0; j < MAIN_VIEW_WIDTH; j++) {
			if (mainScreen[i][j] == '1')
				printf("----");
			if (mainScreen[i][j] == '0')
				printf("    ");
			if (mainScreen[i][j] == '2')
				printf("+");
			if (mainScreen[i][j] == '3')
				printf("|");
			if (mainScreen[i][j] == '9')
				printf("  ");
		}
		printf("\n");
	}
	gotoxy(8, 4);	printf("�ԤԤԡ����ԤԤԡ�����ԤԤԡ�ԤԤԡ�ԤԤԤԡ����ԡ�ԡ�ԤԤԤԤԤԤԡ�ԤԤԤԤԤԤԤ�");
	gotoxy(8, 5);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԤԤԤԡ�ԡ�ԤԤԤԤԤԤ�");
	gotoxy(8, 6);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԤԤԡ�ԤԤԡ�ԤԤԤԤԤ�");
	gotoxy(8, 7);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԤԡ�ԤԤԤԤԡ�ԤԤԤԤ�");
	gotoxy(8, 8);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԤԤԤ�");
	gotoxy(8, 9);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ���ԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤ�");
	gotoxy(8, 10);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�����ԤԤԡ�ԤԤԡ�ԤԤԤԡ����ԡ�ԡ�Ԥԡ�����������ԤԤ�");
	gotoxy(8, 11);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤ�");
	gotoxy(8, 12);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԡ���������ԤԤԤ�");
	gotoxy(8, 13);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԤԤԤԤԤԤԤԤԡ�ԤԤԤ�");
	gotoxy(8, 14);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԡ���������ԤԤԤ�");
	gotoxy(8, 15);	printf("�Ԥԡ�ԤԤԤԤԤԤԡ�ԤԤԤԤԤԤԡ�ԤԤԡ�ԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԡ�ԤԤԤԤԤԤԤԤԤԤԤ�");
	gotoxy(8, 16);	printf("�ԤԤԡ����ԤԤԡ�ԤԤԤԤԤԤԤԡ���ԤԤԤԤԤԤԤԡ�ԡ�ԡ�ԤԤԡ���������ԤԤԤ�");

	gotoxy(20, 24);  printf("+----------------+");
	gotoxy(20, 25);  printf("|");
	gotoxy(20, 26);  printf("|");
	gotoxy(20, 27);  printf("|");
	gotoxy(20, 28);  printf("|");
	gotoxy(20, 29);  printf("|");

	gotoxy(37, 25);  printf("|");
	gotoxy(37, 26);  printf("|");
	gotoxy(37, 27);  printf("|");
	gotoxy(37, 28);  printf("|");
	gotoxy(37, 29);  printf("|");
	gotoxy(20, 30);  printf("+----------------+");

	gotoxy(25, 27);  printf("�Ƕ�̵�");
	gotoxy(85, 27);  printf("����ã��");

	return 0;
}

int mainMove()
{
	end = 1, qy = 1, py = 3;
	while (end) {
		chr = _getch();

		if (chr == 0 || chr == 0xe0) {
			chr = _getch();
			if (chr == LEFT) {
				qy--;
				if (qy < 1)  qy = 2;
			}
			else if (chr == RIGHT) {
				qy++;
				if (qy > 2)  qy = 1;
			}
		}
		else if (chr == ENTER) {
			return 0;
		}

		if (qy == 1) {
			gotoxy(20, 24);  printf("+----------------+");
			gotoxy(20, 25);  printf("|");
			gotoxy(20, 26);  printf("|");
			gotoxy(20, 27);  printf("|");
			gotoxy(20, 28);  printf("|");
			gotoxy(20, 29);  printf("|");
			gotoxy(37, 25);  printf("|");
			gotoxy(37, 26);  printf("|");
			gotoxy(37, 27);  printf("|");
			gotoxy(37, 28);  printf("|");
			gotoxy(37, 29);  printf("|");
			gotoxy(20, 30);  printf("+----------------+");

			gotoxy(50, 24);  printf("                  ");
			gotoxy(50, 25);  printf(" ");
			gotoxy(50, 26);  printf(" ");
			gotoxy(50, 27);  printf(" ");
			gotoxy(50, 28);  printf(" ");
			gotoxy(50, 29);  printf(" ");
			gotoxy(67, 25);  printf(" ");
			gotoxy(67, 26);  printf(" ");
			gotoxy(67, 27);  printf(" ");
			gotoxy(67, 28);  printf(" ");
			gotoxy(67, 29);  printf(" ");
			gotoxy(50, 30);  printf("                  ");

			gotoxy(80, 24);  printf("                  ");
			gotoxy(80, 25);  printf(" ");
			gotoxy(80, 26);  printf(" ");
			gotoxy(80, 27);  printf(" ");
			gotoxy(80, 28);  printf(" ");
			gotoxy(80, 29);  printf(" ");
			gotoxy(97, 25);  printf(" ");
			gotoxy(97, 26);  printf(" ");
			gotoxy(97, 27);  printf(" ");
			gotoxy(97, 28);  printf(" ");
			gotoxy(97, 29);  printf(" ");
			gotoxy(80, 30);  printf("                  ");
		}
		else if (qy == 2) {
			gotoxy(20, 24);	 printf("                  ");
			gotoxy(20, 25);	 printf(" ");
			gotoxy(20, 26);	 printf(" ");
			gotoxy(20, 27);	 printf(" ");
			gotoxy(20, 28);	 printf(" ");
			gotoxy(20, 29);	 printf(" ");
			gotoxy(37, 25);	 printf(" ");
			gotoxy(37, 26);	 printf(" ");
			gotoxy(37, 27);	 printf(" ");
			gotoxy(37, 28);	 printf(" ");
			gotoxy(37, 29);	 printf(" ");
			gotoxy(20, 30);	 printf("                  ");
			gotoxy(50, 24);	 printf("                  ");
			gotoxy(50, 25);	 printf(" ");
			gotoxy(50, 26);	 printf(" ");
			gotoxy(50, 27);	 printf(" ");
			gotoxy(50, 28);	 printf(" ");
			gotoxy(50, 29);	 printf(" ");
			gotoxy(67, 25);	 printf(" ");
			gotoxy(67, 26);	 printf(" ");
			gotoxy(67, 27);	 printf(" ");
			gotoxy(67, 28);	 printf(" ");
			gotoxy(67, 29);	 printf(" ");
			gotoxy(50, 30);	 printf("                  ");

			gotoxy(80, 24);	 printf("+----------------+");
			gotoxy(80, 25);	 printf("|");
			gotoxy(80, 26);	 printf("|");
			gotoxy(80, 27);	 printf("|");
			gotoxy(80, 28);	 printf("|");
			gotoxy(80, 29);	 printf("|");
			gotoxy(97, 25);	 printf("|");
			gotoxy(97, 26);	 printf("|");
			gotoxy(97, 27);	 printf("|");
			gotoxy(97, 28);	 printf("|");
			gotoxy(97, 29);	 printf("|");
			gotoxy(80, 30);	 printf("+----------------+");
		}
	}
}

int mainView() {
	int x, y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (y = 0; y < MAZE_BOARD_HEIGHT; y++) {
		for (x = 0; x < MAZE_BOARD_WIDTH; x++) {
			if (maze[y][x] == '1')
				printf("--------");
			if (maze[y][x] == '0')
				printf("        ");
			if (maze[y][x] == '2')
				printf("+");
			if (maze[y][x] == '3')
				printf("|");
			if (maze[y][x] == '9')
				printf("      ");
			if (maze[y][x] == '5')
				printf("<��      ");
			if (maze[y][x] == '6')
				printf("(ENTER) ");
			else if (maze[y][x] == '7' && qy == 1)
				printf("  ������");
			else if (maze[y][x] == '7' && qy == 2)
				printf("  ��Ž��");
		}
		printf("\n");
	}
	return 0;
}// mainView();

int keyControl() {
	answer = 1;
	int x = 20, y = 5, end = 1;
	gotoxy(x, y);
	printf("��");
	while (end) {
		keyy = _getch();
		if (keyy == UP) { //��
			y -= 4;
			if (y < 5) {
				y = 5;
				answer++;
			}
			gotoxy(x, y + 4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer--;
		} //UP if
		else if (keyy == DOWN) { //�Ʒ�
			y += 4;
			if (y > 14) {
				y = 13;
				answer--;
			}
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer++;
		} //DOWN if
		else if (keyy == ENTER) {
			//next = true;
			end = 0;
			return answer;
		} //else if
	} //while
} // keyControl()

int keyControl_2() {
	answer = 1;
	int x = 20, y = 5, end = 1;
	gotoxy(x, y);
	printf("��");
	while (end) {
		keyy = _getch();
		if (keyy == UP) { //��
			y -= 4;
			if (y < 5) y = 5;
			gotoxy(x, y + 4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer--;
		} //UP if
		else if (keyy == DOWN) { //�Ʒ�
			y += 4;
			if (y > 14) y = 13;
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer++;
		} //DOWN if
		else if (keyy == RIGHT) { //������
			x += 40;
			if (x > 61) x = 60;
			gotoxy(x - 40, y);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer++;
		} //RIGHT IF
		else if (keyy == LEFT) { //����
			x -= 40;
			if (x < 19) x = 20;
			gotoxy(x + 40, y);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer++;
		} //RIGHT IF
		else if (keyy == 13) {
			//next = true;
			end = 0;
			return answer;
		} //else if
	} //while
} // keyControl()

int next() { //��ȭ â ���� ���� ȭ������ �Ѿ�� : ��Ʈ�ο� �������� ���
	while (1) {
		keyy = _getch();
		if (keyy == 13) {
			system("cls");
			return 0;
		}
	}
} //next()

int nextScene() { //���� ȭ������ �Ѿ�� : ��ȭ�� ������ �� ���
	while (1) {
		keyy = _getch();
		if (keyy == ENTER) {
			system("cls");
			gotoxy(0, 17);
			mainView();
			return 0;
		}
	}
} //nextScene()

int keyControl2() {
	answer = 1;
	int x = 20, y = 5, end = 1;
	gotoxy(x, y);
	printf("��");
	while (end) {
		keyy = _getch();
		if (keyy == UP) { //��
			y -= 4;
			if (y < 5) {
				y = 5;
				answer++;
			}
			gotoxy(x, y + 4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer--;
		} //UP if
		else if (keyy == DOWN) { //�Ʒ�
			y += 4;
			if (y > 10) {
				y = 9;
				answer--;
			}
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer++;
		} //DOWN if
		else if (keyy == ENTER) {
			//next = true;
			end = 0;
			return answer;
		} //else if
	} //while
} // keyControl()