#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include "CPU_game.h"
#include "CPU_controller.h"

int jj, d, key;
int BE();
int GE();
int LE();
int Check(int num1); // 1은 그만, 2는 계속
int Check2(int num2); // 어디를 볼까?
int computer(int key); //컴터켠후
int com();//컴퓨터 켜기전
int printgey(); //프린트기
int count = 0;
int hello(int key);

int CPU_Game::escape2()  //프로그램 실행 : Ctrl+F5k
{

	int a = 1;
	int b = 1;
	int c = 1;
	int d = 1;
	int f = 1;
	char g[10];
	int h = 1;
	int i = 1;
	char pw1[10];
	int ch1;
	int num; // 노트확인 or 확인x
	int num1 = 0; // 명단 계속 or 계속x
	int num2 = 0;

	for (;;) {
		system("cls");
		printf("\n         =============================================================\n\n");
		printf("\n                                 제 2교무실 탈출                     \n\n");
		printf("\n          =============================================================\n\n");
		printf(" ┌──────────────────────────────────────────────────────────────────┐\n");
		printf(" │※주의!                                                           │\n");
		printf(" │본 작품은 픽션으로 실존하는 인물, 단체와는 아무련 관련이 없습니다.│\n");
		printf(" │본 작품의 저작권은 김서연, 이채원, 박희경에게 있으며              │\n");
		printf(" │무단 배포 및 상업적 용도로 사용하실 수 없습니다.                  │\n");
		printf(" └──────────────────────────────────────────────────────────────────┘\n");
		printf("\n1)이야기 소개\n");
		printf("\n2)등장인물 소개\n");
		printf("\n3)게임 종료\n\n선택지 입력 > ");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
		{
			system("cls");
			printf("\n ┌────────────────────────────────────────┐\n");
			printf(" │                                        │\n");
			printf(" │  ENTER를 누르시면 이야기가 전개됩니다. │\n");
			printf(" │                                        │\n");
			printf(" └────────────────────────────────────────┘\n");
			_getch();

			system("cls");
			printf("\n         =============================================================\n");
			printf("\n		미소쇼를 준비하느라 늦게까지 남아있던 3인 ….\n");
			printf("\n         =============================================================\n"); _getch(); system("cls");
			printf("\n         =============================================================\n");
			printf("\n		적적해진 분위기를 전환하고자 서연이 말을 꺼내는데 -\n");
			printf("\n         =============================================================\n"); _getch(); system("cls");
			printf("\n\n\n	서연 : 얘들아, 무서운 얘기하자.\n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n	채원 : 좋아! 근데 난 아는게 얼마 없는데... \n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n	희경 : 어, 야 너네 그거 알아? 우리 학교 괴담? \n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n	서연 : 응? 우리학교 괴담? 난 못들어 봤어. 뭔데? \n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n ┌──────────────────────────────────────────────────────────────────┐\n");
			printf(" │-                                                                 │\n");
			printf(" │밤 12시만 되면 배드민턴 채를 들고 복도를 거닌다는 제 2교무실의    │\n");
			printf(" │박 향 규 선생님... 많은 학생들이 그가 퇴근하는 모습을 봤음에도    │\n");
			printf(" │퇴근 시간이 훨씬 지난 12시까지도 2교무실엔                        │\n");
			printf(" │그의 그림자가 남아있었다는데 . . .                                │\n");
			printf(" │-                                                                 │\n");
			printf(" └──────────────────────────────────────────────────────────────────┘\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n1) 진실을 파헤치러 2교무실로 간다.\n");
			printf("\n2) 너무 무섭다. 그만둔다.\n\n선택지 입력 >");
			scanf_s("%d", &b);
			switch (b) {
			case 1: { system("cls");
				printf("\n         =============================================================\n");
				printf("\n	    그렇게 교실을 빠져나와 제 2교무실 쪽으로 내려가는 3인 \n");
				printf("\n         =============================================================\n"); _getch(); system("cls");
				printf("\n\n\n 채원 : ㅗㅜㅑ.. 여기 좀 많이 무서운 것 같아..  그냥 반 다시 가면 안돼?\n\n\n\n\n"); _getch(); system("cls");
				printf("\n\n\n 서연 : 에에 ! 그래도 이미 여기까지 왔는걸ㅎㅎ 내 이름은 고난 ,, 역경이죠.\n\n\n\n\n"); _getch(); system("cls");
				printf("\n\n\n 희경 : 야 이건 나도 들은 얘긴데, 저번에 방과후 째고 담 넘던 선배님이\n  갑자기 뭔가에 맞아서 기절했었는데 .. 눈 떠보니까 2교무실에 갇혀있었데.\n\n\n\n"); _getch(); system("cls");
				printf("\n\n\n 채원 : 꺅 !!!!!! 야 나 너무 무서워 흐어엉\n\n\n\n\n"); _getch(); system("cls");
				printf("\n\n\n 서연 : 쉿.. 야 조용히해.. 오늘 방과후 감독 박향규 선생님이야...\n  우리 여기 몰래온거 아시면 우리도 갇히고 말거라구\n\n\n\n"); _getch(); system("cls");
				printf("\n\n\n 희경 : 얘기하다 보니까 벌써 2교무실 앞이네..\n\n\n\n\n"); _getch(); system("cls");
				printf("\n\n\n1) 제 2교무실로 들어간다. \n");
				printf("\n2) 역시 너무 무섭다. 그만둔다.\n\n선택지 입력 >");
				scanf_s("%d", &c);
				switch (c) {
				case 1: { system("cls");
					printf("\n\n\n 끼이익 - . . .\n\n\n\n\n"); _getch(); system("cls");
					printf("\n\n\n 채원 : 교무실 막 들어와도 되는건가 진짜 ㅜㅜ?\n\n\n\n\n"); _getch(); system("cls");
					printf("\n\n\n 서연 : 에이 , 괜찮아! 설마 무슨 일이야 나겠어?!\n  어 , 저기가 박향규 선생님 자리 아니야?\n\n\n\n"); _getch(); system("cls");
					printf("\n\n\n 희경 : 오오, 맞는거 같아! 어두워서 명패가 잘 안보이긴 해도.. \n  누가 휴대폰 불빛 좀 비춰봐\n\n\n\n"); _getch(); system("cls");
					printf("\n\n\n 채원이 급히 휴대폰 화면을 켠다\n\n\n\n\n"); _getch(); system("cls");
					printf("\n\n\n 희경 : 어라, 이게 뭐지?\n\n\n\n\n"); _getch(); system("cls");
					printf("\n         =============================================================\n\n");
					printf("\n              책상 위에는 검은 노트와 빨간 볼펜 한자루가 놓여있다.                     \n\n");
					printf("\n         =============================================================\n\n");
					printf("1) 노트를 확인한다.\n");
					printf("2) 확인하지 않는다.\n\n> 선택지 입력 : ");
					scanf_s("%d", &num);
					system("cls");

					switch (num) {
					case 1: {// 노트를 확인함. -> 선생님 명단
						int i = Check(num1);
						switch (i) {
						case 1: {// 그만 읽는다. -> 퍽
							break;
						}//case 1
						case 2: //계속 읽는다. -> 학생 명단
						{
							printf(" ┌──────────────────────────────────┐\n");
							printf(" │                                  │\n");
							printf(" │            11월 23일             │\n");
							printf(" │                                  │\n");
							printf(" │           11xx 박희경            │\n");
							printf(" │           16xx 김서연            │\n");
							printf(" │           16xx 이채원            │\n");
							printf(" │                                  │\n");
							printf(" └──────────────────────────────────┘\n");
							_getch();   system("cls");
							printf("\n\n\n              서연 : 잠깐 .. 우리 이름도 있는ㄷ..\n\n\n\n\n");
							_getch();
							system("cls");
							break;
						}
						default: // 노트를 확인하지 않음 -> 퍽
							break;
						}//switch i


					}//case 1

					}//switch num`
					for (;;) {
						hello(key);
						break;
					}

				}//case1 교무실로 들어온거
				}//switch c 교무실 들어온 후
			case 2: { printf("게임을 종료합니다 감사합니다!\n"); _getch(); break;  } break;//case 2
			}//switch c
					break;
			}//case 1
		}//switch b
		break;
		case 2:
		{
			system("cls"); printf("Enter를 계속 누르시면 이야기가 진행됩니다.\n\n\n"); _getch(); system("cls");
			printf("\n         =============================================================\n");
			printf("\n				등장인물 소개\n");
			printf("\n         =============================================================\n"); _getch(); system("cls");
			printf("\n\n\n 이름 : 김 서 연\n 특징 : 활동적이고 무서운 이야기 듣는 것을 좋아한다. 꽤나 미지의 인물로 등장을 한다. 채원과 같은 반이다.\n 기타 : (명예로운)걸스카우트의 단원\n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n 이름 : 이 채 원\n 특징 : 무서운 것을 싫어한다. 겁이 많고 소심한 편이다. 묵묵히 자신의 역할을 해낸다. 서연과 같은 반이다. \n 기타 : (총애받는)선도부의 부원\n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n 이름 : 박 희 경\n 특징 : 추리하는 것을 좋아하고 모험심이 넘친다. 괴담에 대한 호기심을 키운 장본인이다. \n 기타 : (우주최강)CPU의 부원\n\n\n\n\n"); _getch(); system("cls");
			printf("\n\n\n 이름 : 박 향 규 (선생님)\n 직업 : 체육 교사\n 특징 : 서연 , 채원 , 희경의 공포의 대상이다. 괴담의 주인공이자 미지의 인물.\n 기타 : 학생복지부\n\n\n\n\n"); _getch(); system("cls");
			continue; }
		case 3:
			system("cls");
			return 0;
		}//switch a
	}//for
}//main

int Check(int num1) {
	printf("\n\n\n                     서연 : 이게 뭐지? 무슨 명단인데..?                    \n\n\n\n\n");
	_getch(); system("cls");

	printf(" ┌──────────────────────────────────────┐\n");
	printf(" │                                      │\n");
	printf(" │            9월 3일                   │\n");
	printf(" │            16xx 김영철               │\n");
	printf(" │                                      │\n");
	printf(" │            9월 16일                  │\n");
	printf(" │            13xx 박성래               │\n");
	printf(" │                                      │\n");
	printf(" │            9월 21일                  │\n");
	printf(" │            14xx 김윤환               │\n");
	printf(" │                                      │\n");
	printf(" │            10월 9일                  │\n");
	printf(" │            15xx 이호연               │\n");
	printf(" │                                      │\n");
	printf(" │            10월 12일                 │\n");
	printf(" │            12xx 유병석               │\n");
	printf(" │                                      │\n");
	printf(" │            10월 17일                 │\n");
	printf(" │            11xx 정혜선               │\n");
	printf(" │                                      │\n");
	printf(" └──────────────────────────────────────┘\n\n\n\n\n");
	_getch(); system("cls");

	printf("\n\n\n              희경 : 이게 다 뭐야? 그러고보니 여기 적힌 사람들 최근에 다 자퇴했다고 들었는데,,                 \n\n\n\n\n");
	_getch(); system("cls");
	printf("\n\n\n              채원 : 뭐야 무서워.. 그만 읽자 응? 나 이거 걸리면 진짜 큰일나ㅠㅠ                 \n\n\n\n\n");
	printf("1) 그만 읽는다.\n");
	printf("2) 계속 읽는다.\n\n > 선택지 입력 : ");
	scanf_s("%d", &num1);
	system("cls");

	return num1;
}

int Check2(int num2) {
	printf("\n         =============================================================\n\n");
	printf("\n              퍽 -                     \n");
	printf("\n              무언가에 맞아 정신을 잃는다.                     \n\n");
	_getch();
	printf("\n              .                     \n");
	printf("\n              .                     \n");
	printf("\n              .                     \n\n");
	printf("\n         =============================================================\n\n");
	_getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n              정신을 차린다.                 \n\n");
	printf("\n              교무실 밖으로 나가려 문을 흔들지만 열리지 않는다.                    \n\n");
	printf("\n         =============================================================\n\n\n");

	return 0;
}

int seorap(int key) {
	for (;;) {
		int e = 0;
		system("cls");
		printf("\n         =============================================================\n");
		printf("\n			몇번째 서랍을 확인할까요?\n");
		printf("\n			1) 첫번째 서랍\n			2) 두번째 서랍\n			3) 세번째 서랍\n			4) 뒤로가기\n");
		printf("\n         =============================================================\n");
		printf("\n\n\n	선택지 입력 > ");
		scanf_s("%d", &e);

		if (e == 1) {
			system("cls");
			printf("\n         =============================================================\n");
			printf("\n		열쇠 구멍이 없는 서랍이다. 열리지 않는다.\n");
			printf("\n         =============================================================\n");
			printf("\n		enter : 뒤로가기\n");
			_getch();
		}
		else if (e == 3) {
			if (key == 0) {
				system("cls");
				printf("\n         =============================================================\n");
				printf("\n		굳게 닫혀있다. 열려면 열쇠를 찾아봐야 할 것 같다.\n");
				printf("\n         =============================================================\n");
				printf("\n		enter : 뒤로가기\n");
				_getch();
			}
			else if (key == 1) {
				system("cls");
				printf("\n\n\n	앗! 쪽지가 있다. \n\n\n\n\n");

				printf(" ┌──────────────────────────────────────┐\n");
				printf(" │                  -                   │\n");
				printf(" │              ★자물쇠★              │\n");
				printf(" │               5+3 = 28               │\n");
				printf(" │              9+1 = 810               │\n");
				printf(" │              8+6 = 214               │\n");
				printf(" │               5+4 = 19               │\n");
				printf(" │            21+10 = ? ? ? ?           │\n");
				printf(" │                  -                   │\n");
				printf(" └──────────────────────────────────────┘\n");
				printf("\n		enter : 뒤로가기\n");
				_getch();
			}
		}
		//if 1,3
		else if (e == 2) {
			system("cls");

			printf("\n\n\n	앗! 쪽지가 있다. \n\n\n");

			printf(" ┌──────────────────────────────────────────────────────────────────┐\n");
			printf(" │                                                                  │\n");
			printf(" │                               키를                               │\n");
			printf(" │                             찾으세요                             │\n");
			printf(" │                                                                  │\n");
			printf(" └──────────────────────────────────────────────────────────────────┘\n");
			printf("\n		enter : 뒤로가기\n");
			_getch();
		}//if 2
		else if (e == 4) {
			hello(key);
		}
	}//for
}//seorap
int printgey() {
	int k;
	system("cls");
	printf("\n\n\n	아무것도 발견하지 못했다. \n\n\n\n\n");
	printf("\n	1) 뒤로가기\n");
	scanf_s("%d", &k);
	if (k == 1) hello(key);
	return 0;
}
int computer(int ch3) {
	switch (ch3) {
	case 1:

		system("cls");
		printf("\n         =============================================================\n\n");
		printf("\n              이번 달 벌점자 명단이다. 우리의 이름도 있다.                \n\n\n");
		printf("     ┌──────────────────────────────────────┐\n");
		printf("     │                  -                   │\n");
		printf("     │              16xx 김영철             │\n");
		printf("     │              13xx 박성래             │\n");
		printf("     │              14xx 김윤환             │\n");
		printf("     │              16xx 김서연             │\n");
		printf("     │              16xx 이채원             │\n");
		printf("     │              11xx 박희경             │\n");
		printf("     │                  -                   │\n");
		printf("     └──────────────────────────────────────┘\n\n\n");
		printf("\n         =============================================================\n\n\n");
		_getch();
		system("cls");
		break;
		return 0;

	case 2:
	{

		system("cls");
		printf("\n         =============================================================\n\n");
		printf("\n              아무것도 적혀있지 않다 . . .               \n\n");
		printf("\n              -                  \n\n");
		printf("\n         =============================================================\n\n\n");
		_getch();
		system("cls");
		break;
		return 0;
	}
	case 3:
	{
		system("cls");
		printf(" ┌──────────────────────────────────────┐\n");
		printf(" │                  -                   │\n");
		printf(" │    네이버 비밀번호 : hyanggyu1004    │\n");
		printf(" │   다음 비밀번호 : bbeuttihyangggyu   │\n");
		printf(" │                  -                   │\n");
		printf(" │              ★자물쇠★              │\n");
		printf(" │     서랍 첫번째 세번째 잊지말긔 ^^   │\n");
		printf(" │                  -                   │\n");
		printf(" └──────────────────────────────────────┘\n");

		_getch();
		system("cls");
		break;
		return 0;
	}
	case 4:
	{
		system("cls");
		printf(" ┌──────────────────────────────────────┐\n");
		printf(" │                  -                   │\n");
		printf(" │               9월 20일               │\n");
		printf(" │     아무리 말을 해도 듣질 않는다..   │\n");
		printf(" │         벌을 받아야 마땅해..         │\n");
		printf(" │                  -                   │\n");
		printf(" │              10월 17일               │\n");
		printf(" │          참는 것도 한계야..          │\n");
		printf(" │                  -                   │\n");
		printf(" │              11월 23일               │\n");
		printf(" │         교칙을 지키는 학생만이..     │\n");
		printf(" │              살아 남는다…           │\n");
		printf(" │                  -                   │\n");
		printf(" └──────────────────────────────────────┘\n");

		_getch();
		system("cls");
		break;
		return 0;
	}
	case 5:
		hello(key);
	}
}
int window() {
	system("cls");
	int f;
	int key = 0;
	printf("\n\n\n	먼지만 나풀거린다. \n\n\n	1) 다시 창틀을 확인		2) 뒤로가기\n\n\n\n\n");
	scanf_s("%d", &f);

	if (f == 2) {
		hello(key);
	}
	else {
		int m;
		system("cls");
		printf("\n\n\n	앗! 자세히 보니 닫힌 서랍에 꼭 맞을 것 같은 열쇠가 있다.\n		열쇠 획득입니다! \n\n\n\n\n");
		key = 1;
		printf("\n 1) 뒤로가기\n");
		scanf_s("%d", &m);
		if (m == 1) {
			hello(key);
			return key;
		}
	}//else
}//window 함수
int com() {
	int h;
	system("cls");
	printf("\n			1) 벌점자 명단\n			2) 메모\n			3) 비밀번호\n			4) 일기\n			5) 뒤로가기\n\n\n");
	printf("		선택지 입력 > ");
	scanf_s("%d", &h);
	return h;
}//com함수
int choose() {
	int d;
	system("cls");
	printf("\n         =================================================================================\n");
	printf("\n			어디를 먼저 살펴보시겠습니까?\n");
	printf("\n			1) 컴퓨터\n			2) 서랍\n			3) 프린트기\n			4) 창틀\n			5) 탈출 시도\n");
	printf("\n         =================================================================================\n");
	printf("\n\n\n	선택지 입력 > ");
	scanf_s("%d", &d);
	return d;
}
int talzzul() {
	int pw;
	for (;;) {
		system("cls");
		printf("\n         =================================================================================\n");
		printf("\n               굳게 닫혀있는 자물쇠. 4개의 숫자를 조합해야 나갈 수 있는 듯 하다. \n");
		printf("\n         =================================================================================\n");
		printf("\n           비밀번호 입력 : ");
		scanf_s("%d", &pw);
		if (pw == 1131) {
			GE();
			return 0;
		}
		else {
			int n;
			count++;
			system("cls");
			printf("\n         =================================================================================\n");
			printf("\n             신중하게 생각하고 입력해주세요. 그렇지 않으면 모두가 위험해집니다 . . . \n");
			printf("\n         =================================================================================\n\n");
			printf("\n            1) 재입력		2)메인화면 \n");
			scanf_s("%d", &n);
			if (count == 3) {
				BE();
				return 0;
			}
			if (n == 1) {
				continue;
			}
			else if (n == 2) { hello(key); }
		}
	}
}
int hello(int key) {
	int h;
	system("cls");
	d = choose();
	switch (d) {
	case 1:
		for (;;) {
			h = com();
			computer(h);
		}
	case 2:
		seorap(key);
	case 3:
		printgey();
	case 4:
		key = window();
	case 5:
		talzzul();
	}

	return 0;
}
int GE() {
	system("cls");
	printf("\n\n\n              채원 : 엇 ! 문이 열렸다.. 휴 다행이야 ㅠㅠ              \n\n\n\n\n");	_getch(); system("cls");
	printf("\n\n\n              희경 : 아 ㅜㅜ 너무 무서웠는데 괜히 왔어.. 얼른 집가자. \n\n\n\n\n");	_getch(); system("cls");
	printf("\n\n\n              채원 : 맞아, 서연아 빨리 나랑 기숙사 가자…..           \n\n\n\n\n");	_getch(); system("cls");
	printf("\n\n\n              희경 : …어? 서연이는?                                  \n\n\n\n\n");	_getch(); system("cls");
	printf("\n\n\n              채원 : 김서연? 뭐 알아서 잘 오겠지 !!          \n\n\n\n\n");	_getch(); system("cls");
	printf("\n\n\n              희경 : 그렇겠지..?                                  \n\n\n\n\n");	_getch(); system("cls");
	printf("\n\n\n              서연은 어디론가 사라지고 온데 간데 없었다.              \n\n\n\n\n");	_getch(); system("cls");
	printf("\n\n\n              그리고 그 이후로 학교에서 서연은 점점 잊혀져만 갔다.    \n\n\n\n\n");	_getch(); system("cls");
	LE();

	return 0;
}
int BE() {
	system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n                꼭꼭 숨어라.., 머리카락 보일라.., 꼭꼭 숨어라…       \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n                      복도 너머에서 가까워지는 노랫소리.              \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n             심장이 터질듯한 두려움에 계속해서 자물쇠를 돌려봤지만    \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n                               미동도 하지않는 문…                   \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n                        노랫소리가 아주 가까워 졌을 때                \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n                         무언가 둔탁한 것이 날아왔다.                 \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n             그리고 의식은 희미해져만 갔고 마지막 내 귓가에 들린 건.. \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n                                   “ 찾았다. ”                      \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	printf("\n         =============================================================\n\n");
	printf("\n                                    _The End_                         \n\n");
	printf("\n         =============================================================\n\n"); _getch(); system("cls");
	LE();
	return 0;
}
int LE() {
	int l;
	printf("\n         =============================================================\n\n");
	printf("\n                 마지막 이야기가 남았습니다. 확인하시겠습니까?        \n\n");
	printf("\n         =============================================================\n\n");
	printf("1) 확인한다.\n");
	printf("2) 확인하지 않는다.\n");
	scanf_s("%d", &l);	system("cls");

	if (l == 1) {
		printf("\n         =============================================================\n\n");
		printf("\n                                     3년 후,,                         \n\n");
		printf("\n         =============================================================\n\n"); _getch(); system("cls");
		printf("\n         =============================================================\n\n");
		printf("\n          채원과 희경은 무사히 미림을 졸업하고 동창회에서 다시 만난다.\n\n");
		printf("\n         =============================================================\n\n"); _getch(); system("cls");
		printf("\n\n\n              채원 : 오랜만에 보니까 너무 좋다~                                                        \n\n\n\n\n");	_getch(); system("cls");
		printf("\n\n\n              희경 : 그러게 얼마만이야? 다시 보니까 .. 옛날 생각도 나고,, 미림에 많은 추억이 있었는데..\n\n\n\n\n");	_getch(); system("cls");
		printf("\n\n\n              채원 : 야.. 근데 그거 기억나? 우리 2교무실 들어갔다가 갇힌 날.. 결국 서연이는 못찾았잖아..\n\n\n\n\n");	_getch(); system("cls");
		printf("\n\n\n              희경 : 응? 서연이?? 그게 누구야?                                                         \n\n\n\n\n");	_getch(); system("cls");
		printf("\n\n\n              채원 : 아~ 그 왜 ~~ 우리 같이 교무실 갔었잖아!!                                          \n\n\n\n\n");	_getch(); system("cls");
		printf("\n\n\n              희경 : 무슨..소리야 ? 우리 둘이 들어갔잖아…                                             \n\n\n\n\n");	_getch(); system("cls");
		printf("\n\n\n              채원 : 그럼 그 때 그 애는…                                                                \n\n\n\n\n");	_getch(); system("cls");
		printf("\n         =============================================================\n\n");
		printf("\n                                    _The End_                         \n\n");
		printf("\n         =============================================================\n\n");
		_getch();
		return 0;
	}
	else if (l == 2) {
		printf("\n         =============================================================\n\n");
		printf("\n                                    _The End_                         \n\n");
		printf("\n                                     THANK U                        \n\n");
		printf("\n         =============================================================\n\n");
		_getch();
		return 0;
	}
}