#include "stdafx.h"
#include "header.h"
#include "CPUcastle_screenBase.h"
#include "CPUcastle_mainScreen.h"
#include "CPUcastle_storyScreen.h"
#include "CPU_game.h"


void CPU_Game::storyGame(void)
{
	system("mode con cols=119 lines=35");
	system("title CPU캐슬");
	CursorView(0);

	while (castleEnd) {		//캐릭터를 선택하기 위해서 무한루프
		mainViewww();
		int nextView = mainMove();
		if (nextView == 0) {
			if (qy == 1) {
				while (1) {
					diningroom = 0;
					bedroom = 0;
					password = 0; //번호키
					deskKey = 0; //열쇠
					roop = 1;
					pyramid = 0;
					FindThePyramid();
					nextScene();
					gotoxy(28, 5);
					printf("다시하기");
					gotoxy(28, 9);
					printf("끝내기");

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
	gotoxy(20, 7);  printf("┌ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┐");
	gotoxy(20, 8);  printf("│ 스카이캐슬에서 일어난 살인사건. 경찰의 조사 끝에 범인에 대한 심증을 │");
	gotoxy(20, 9);  printf("│ 찾아냈다. 하지만 물증이 없고 범인을 못 잡는 상황. 원활한 수사를 위  │");
	gotoxy(20, 10); printf("│ 해 캐슬 주민들은 모든 조사를 허용했고 평화로운 일상이 지루하던 괴짜 │");
	gotoxy(20, 11); printf("│ 명탐정이 일을 맡게 된다. 지금으로부터 하루 뒤, 재판이 잡혀있다. 과  │");
	gotoxy(20, 12); printf("│ 연 '괴짜 명탐정'은 하루 안에 범인의 방에서 단서를 최대한 모아서     │");
	gotoxy(20, 13); printf("│ 재판에서 이길 수 있을까?                                            │");
	gotoxy(20, 14); printf("└ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┘");
	nextScene();
	gotoxy(15, 23);	printf("이번에 내가 맡은 사건은 신아고 살인사건. 이번 사건은 범인에 대한 물증은 없고 심증만");
	gotoxy(15, 24);	printf("있는 사건이다. 이번에 내가 해야 하는 것은 재판 전날까지 결정적 증거를 찾아 범인을 ");
	gotoxy(15, 25);	printf("감옥에 넣는 일!! 시간도 얼마 남지 않았으니 서둘러 범인이 사는 곳으로 가봐야겠다.");
	nextScene();
	gotoxy(15, 23);	printf("여기가 범인의 방... 여기서부터 범인의 냄새가 나는 것 같군!");
	gotoxy(15, 24);	printf("내가 꼭 범인을 잡아야겠어!");
	nextScene();
	gotoxy(15, 23);	printf("범인의 방에 있는 여러 사물을 조사해 범인을 찾아야 한다.");
	textColor(4);
	gotoxy(15, 24);	printf("증거품으로 스마트폰은 필수이며, 구역마다 한 개씩만 챙겨갈 수 있다. ");
	gotoxy(15, 25);	printf("당신이 선택한 증거품에 따라 범인의 형량이 정해지므로 신중하게 선택해야 한다.");
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
			gotoxy(2, 1);	printf("1. 책상");
			gotoxy(2, 2);	printf("2. 가방");
			gotoxy(2, 3);	printf("3. 서랍");
			gotoxy(2, 4);	printf("4. 재판 날로");
			gotoxy(2, 6);	printf("[입력] ");

			scanf("%d", &check);
			system("cls");

			switch (check) {
			case 1:
				third_while = 1;
				while (third_while) {
					gotoxy(2, 1);	printf("1. 책꽃이");
					gotoxy(2, 2);	printf("2. 필기구");
					gotoxy(2, 3);	printf("3. 메모보드");
					gotoxy(2, 4);	printf("4. 증거품 선택");
					gotoxy(2, 5);	printf("5. 뒤로 가기");
					gotoxy(2, 7);	printf("[입력] ");

					scanf("%d", &check);
					system("cls");

					switch (check) {
					case 1:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("어? 수상한 노란공책을 발견했다. ");
						next();
						gotoxy(20, 7);  printf("┌ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┐");
						gotoxy(20, 8);  printf("│   201x년 xx월 xx일                          │");
						gotoxy(20, 9);  printf("│   집-학교-학원-집. 평소와 같음              │");
						gotoxy(20, 10); printf("│   201x년 xx월 xx일                          │");
						gotoxy(20, 11); printf("│   집-학교-집. 과외 선생 시작                │");
						gotoxy(20, 12); printf("│   .                                         │");
						gotoxy(20, 13); printf("│   .                                         │");
						gotoxy(20, 14); printf("│   .                                         │");
						gotoxy(20, 15); printf("│   201x년 2월 27일                           │");
						gotoxy(20, 16); printf("│   이제 정말 안녕                            │");
						gotoxy(20, 17); printf("└ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┘");
						next();
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("2월 27일 이후로 작성되어 있지 않다. 왜일까... ");
						next();

						break;
					case 2:
						usb = true;

						gotoxy(0, 17);
						mainView();
						textColor(4);
						gotoxy(15, 23);	printf("USB를 획득하였습니다. 노트북에서 내용을 확인할 수 있습니다. ");
						textColor(7);
						gotoxy(15, 24);	printf("포스트잇이 접혀 있다. ");
						gotoxy(15, 25);	printf("포스팃에는 '세상을 돌려보면 답이 나온다.'라고 써있다. ");
						next();

						break;
					case 3:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 23);	printf("메모보드에 혜나와 주변인물의 정보가 정리되어 있다");
						nextScene();
						gotoxy(15, 24);	printf("김혜나   200x년 10월 23일");
						gotoxy(15, 25);	printf("전교1등. 향수를 사용하지 않음");
						nextScene();
						gotoxy(15, 24);	printf("황우주   200x년 2월 27일");
						gotoxy(15, 25);	printf("전교3등. 미림 향수를 사용함");
						nextScene();
						gotoxy(15, 24);	printf("강예서   200x년 10월 29일");
						gotoxy(15, 25);	printf("전교2등. 여정 향수를 사용함");
						next();

						break;
					case 4:
						fourth_while = 1;
						while (fourth_while) {
							gotoxy(2, 1);	printf("당신은 범인의 책상에 있는 물건들 중 하나의 증거품만 챙겨갈 수 있습니다.");
							gotoxy(2, 2);	printf("");
							gotoxy(2, 3);	printf("1. 선택하기");
							gotoxy(2, 4);	printf("2. 뒤로 가기");
							gotoxy(2, 6);	printf("[입력] ");
							scanf("%d", &check);
							system("cls");

							if (check == 1) {
								gotoxy(2, 1);	printf("당신은 범인의 책상에 있는 물건들 중 하나의 증거품만 챙겨갈 수 있습니다.");
								gotoxy(2, 3);	printf("[1. 노란공책   2. USB   3. 메모보드 촬영사진]");
								gotoxy(2, 5);	printf("[입력] ");
								scanf("%d", &check);
								system("cls");
								if (check == 1)
									desk = 1;
								gotoxy(2, 1);	printf("%d번을 증거품으로 챙기셨습니다!", check);
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
					gotoxy(2, 1);	printf("1. L자파일");
					gotoxy(2, 2);	printf("2. 노트북");
					gotoxy(2, 3);	printf("3. 향수");
					gotoxy(2, 4);	printf("4. 증거품 선택");
					gotoxy(2, 5);	printf("5. 뒤로 가기");
					gotoxy(2, 7);	printf("[입력] ");

					scanf("%d", &check);
					system("cls");

					switch (check) {
					case 1:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("아재개그 100제가 있다. ");
						nextScene();
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("01. 추장보다 높은 사람은?   고추장 ");
						nextScene();
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("02. 꽃가게 주인이 가장 싫어하는 도시는?   시드니 ");
						nextScene();
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("03. 공이 웃으면?   풋볼 ");
						next();

						break;
					case 2:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 24);	printf("기본 배경화면에다 기본 폴더 밖에 없다. ");
						nextScene();
						system("cls");
							fourth_while = 1;
							while (fourth_while) {
								gotoxy(2, 1);	printf("컴퓨터를 좀 더 조사해보겠습니까?");
								gotoxy(2, 2);	printf("");
								gotoxy(2, 3);	printf("1. 계속 찾기");
								gotoxy(2, 4);	printf("2. 뒤로 가기");
								gotoxy(2, 6);	printf("[입력] ");
								scanf("%d", &check);
								system("cls");

								if (check == 1) {
									gotoxy(0, 17);
									mainView();
									gotoxy(15, 22);	printf("숨겨진 폴더를 발견했다. ");
									gotoxy(15, 23);	printf("폴더 안에는 온라인 기사를 크롭한 사진들이 있다. 기사의 공통된 이야기는");
									TEXT(4);
									gotoxy(15, 24);	printf("지금까지 범인을 다른 사람으로 착각해, 결국 범인은 죄를 받지 않았던 기사이다. ");
									TEXT(7);
									gotoxy(15, 25); printf("또한 가장 최근에 저장한 기사는");
									TEXT(4);
									printf("신아고 살인사건의 진짜 범인은?!");
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
							gotoxy(15, 23); printf("usb에는");
							gotoxy(15, 24);	printf("문제적 남자에서 나왔던 문제들이 저장되어 있다. 그 중에서 눈에 띄는 폴더가 있다. ");
							nextScene();
							gotoxy(15, 22); printf("파일제목 : 신박한문제_☆★");
							gotoxy(15, 23); printf("9981 + 1601 = 2957");
							gotoxy(15, 24); printf("1080 + 9168 = ????");
							nextScene();
							system("cls");
						}

						break;
					case 3:
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 23);	printf("달달한 과일향이 나는 블루블루스트로베리 향수이다.");
						gotoxy(15, 24); printf("사용을 많이 해서 양이 별로 없다. 그리고 어디서 맡아본 냄새인 것 같다.");
						next();

						break;
					case 4:
						fourth_while = 1;
						while (fourth_while) {
							gotoxy(2, 1);	printf("당신은 범인의 책상에 있는 물건들 중 하나의 증거품만 챙겨갈 수 있습니다.");
							gotoxy(2, 2);	printf("");
							gotoxy(2, 3);	printf("1. 선택하기");
							gotoxy(2, 4);	printf("2. 뒤로 가기");
							gotoxy(2, 6);	printf("[입력] ");
							scanf("%d", &check);
							system("cls");

							if (check == 1) {
								gotoxy(2, 1);	printf("당신은 범인의 책상에 있는 물건들 중 하나의 증거품만 챙겨갈 수 있습니다.");
								gotoxy(2, 3);	printf("[1. L자파일   2. 노트북   3. 향수]");
								gotoxy(2, 5);	printf("[입력] ");
								scanf("%d", &check);
								system("cls");
								if (check == 2)
									bag = 1;
								gotoxy(2, 1);	printf("%d번을 증거품으로 챙기셨습니다!", check);
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
					gotoxy(2, 1);	printf("1. 스마트폰");
					gotoxy(2, 2);	printf("2. 윗 서랍");
					gotoxy(2, 3);	printf("3. 아래 서랍");
					gotoxy(2, 4);	printf("4. 뒤로 가기");
					gotoxy(2, 6);	printf("[입력] ");

					scanf("%d", &check);
					system("cls");

					switch (check) {
					case 1:
						if (smartphone == true) {
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 23);	printf("스마트폰 전원이 켜졌다. ");
							gotoxy(15, 24); printf("일반 갤러리나 메모에느느 평범한 사진과 글 밖에 있지 않아 보안폴더를");
							gotoxy(15, 25); printf("열어보기로 했다. 하지만 비밀번호에 대한 단서는 ");
							textColor(4);
							printf("신박한 문제이다. ");
							textColor(7);
							next();

							fourth_while = 1;
							while (fourth_while) {
								gotoxy(2, 1);	printf("1. 풀기");
								gotoxy(2, 2);	printf("2. 뒤로 가기");
								gotoxy(2, 4);	printf("[입력] ");
								scanf("%d", &check);
								system("cls");

								if (check == 1) {
									gotoxy(2, 5);	printf("[입력] ");
									scanf("%d", &check);
									system("cls");
									if (check == 9717) {
										qovop = 1;

										gotoxy(0, 17);
										mainView();
										gotoxy(15, 23);	printf("보안폴더 안에는 누군가가 혜나를 밀치는 영상이 담겨있고");
										gotoxy(15, 24); printf("범인의 얼굴이 나와있다.");
										nextScene();
										textColor(4);
										gotoxy(15, 24);
										printf("결정적 증거를 찾았습니다! 이제를 범인은 유죄를 받을 수 있을겁니다!! ");
										textColor(7);
										next();
										fourth_while = 0;
									}
									else {
										gotoxy(0, 17);
										mainView();
										gotoxy(15, 23);	printf("틀렸습니다. ");
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
							gotoxy(15, 23);	printf("전원이 켜지지 않는다. 아마 충전을 해야할 것 같다. ");
							next();
						}

						break;
					case 2:
						fourth_while = 1;
						while (fourth_while) {
							gotoxy(2, 1);	printf("1. 부러진 볼펜");
							gotoxy(2, 2);	printf("2. 스마트폰 충전기");
							gotoxy(2, 3);	printf("3. 뒤로 가기");
							gotoxy(2, 5);	printf("[입력] ");
							scanf("%d", &check);
							system("cls");

							if (check == 1) {
								plus = 1;

								gotoxy(0, 17);
								mainView();
								gotoxy(15, 23);	printf("자세히 살펴보니 녹음기였다. ");
								gotoxy(15, 24); printf("부러진 녹음기가 수상해 보이므로 ");
								textColor(4);
								printf("증거품으로 가져간다. ");
								textColor(7);
								next();
							}
							else if (check == 2) {
								smartphone = true;
								
								gotoxy(0, 17);
								mainView();
								textColor(4);
								gotoxy(15, 23);	printf("스마트폰 충전기를 획득하였습니다. ");
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
						gotoxy(15, 23);	printf("혜나를 포함한 혜나의 주변사진들 모두의 사진들이 흐트러져 있다.");
						gotoxy(15, 24); printf("사진 뒤에는 뭔가가 적혀있다.");
						nextScene();
						gotoxy(15, 23);	printf("지인1의 사진 뒤 - 3월 20일  혜나와 너무 가까움");
						gotoxy(15, 24);	printf("지인2의 사진 뒤 - 1월 4일  나를 너무 무시함");
						gotoxy(15, 25); printf("혜나의 사진 뒤 - 2월 26일");
						gotoxy(15, 26); printf("지인3의 사진 뒤 - 8월 25일  혜나를 괴롭힘");
						gotoxy(15, 27); printf("지인4의 사진 뒤 - 혜나를 뒷담화함");
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
		gotoxy(15, 23);	printf("그럼 '신아고 살인사건' 판결 결과를 알려드리도록 하겠습니다.");
		gotoxy(15, 24); printf("판결은!!");
		nextScene();

		if (qovop == 1) {
			if (sum == 0) {
				gotoxy(15, 23); printf("3년형입니다!! ");
				gotoxy(15, 24); printf("결정적인 증거가 있으나 우발범죄인지 계획범죄인지 알 수 없기 때문입니다.");
			}
			else if (sum == 1) {
				gotoxy(15, 23); printf("5년형입니다!! ");
				gotoxy(15, 24); printf("피고인이 피해자를 살인하기 위해 며칠동안 한 행적을 보았을 때 계획범죄인 것이 들어났기 때문입니다.");
			}
			else if (sum == 2) {
				gotoxy(15, 23); printf("10년형입니다! ");
				gotoxy(15, 24); printf("증거들을 봤을 때 피고인은 우발범죄가 아닌 계획범죄인 것이 들어났기 때문입니다.");
			}
			else if (sum == 3) {
				gotoxy(15, 23); printf("무기징역입니다!! ");
				gotoxy(15, 24); printf("증거들을 봤을 때 아주 오랜시간동안 준비한 계획범죄이기 때문입니다.");
			}
		}
		else {
			gotoxy(15, 23); printf("무죄입니다!! ");
			gotoxy(15, 24); printf("피고인이 범인이라는 결정적 증거가 없기 때문에 유죄라고 내릴 수 없습니다.");
		}
		nextScene();
		gotoxy(15, 23); printf("신아고 살인사건의 판결은 증거에 따라 나왔습니다.");
		gotoxy(15, 24); printf("판결 결과가 아쉬우시다면 다시 한 번 플레이하는 것을 추천합니다.");
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
	//text color (차교수 12, 노승혜 13, 세라 14, ?? 11, 기준이 7, 서준이 10, 설명 텍스트 8), 인트로에서만 글씨체 구분, 게임 시작하면 ㅅㅈ, ㄱㅈ 하얀색
	printf("- 20XX년 6월 말 스카이 캐슬 기준이 서준이네");
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"차기준!!!!!! 차서준!!!!!! 공부 안 하고 뭐 하고 있어!!!!!!!!\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"하.. 아직 7시밖에 안 됬잖아요.\"");
	textColor(10);
	gotoxy(20, 16);	printf("\"저희 어제도 3시에 잤는데..\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"아침부터 열심히 하지 않으면 피라미드 꼭대기에 앉을 수 없어, 그러니까 ..\"");

	textColor(7);
	gotoxy(20, 18);	printf("(저 피라미드.. 누가 없애버리면 안되나 ..)");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"야, 서준아.");
	gotoxy(20, 15);	printf("우리, 저 피라미드 없앨까 ?\"");
	textColor(10);
	gotoxy(25, 18);	printf("\"뭐 ? 아빠가 제일 애지중지하는 저걸 ?\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"저거, 내 눈 앞에 없으면 조금은 편하겠지.\"\n");
	textColor(8);
	gotoxy(40, 25); printf("(프롤로그가 끝났습니다. Enter 키를 눌러 다음 화면으로 넘어가 주세요.)");
	// Finished intro

	nextScene();
	textColor(8); //change text color
	gotoxy(20, 8);	printf("-새벽 2시, 기준이네 가족 모두가 잠에 빠진 한 밤중에 기준이와 서준이의 방에서 작은");
	gotoxy(20, 10);	printf("불빛이 새어나왔다.");
	nextScene();

	textColor(7);
	gotoxy(20, 8);	printf("\"기준아, 일어나\"");

	keyy = _getch();
	if (keyy == 13) {
		gotoxy(15, 22);	printf("\"어… 잠시만\"");
	} //enter if
	nextScene();

	gotoxy(15, 22);
	printf("\"짐 좀 챙겨야해서, 음 .. 이거면 되겠지 ?\"");
	gotoxy(28, 5);	printf("- 어두운 집을 밝힐 핸드폰");
	gotoxy(28, 9);	printf("- 피라미드를 훔칠 주머니");
	gotoxy(28, 13);	printf("- 미끄럽고 얇은 장갑");

	nextScene();
	gotoxy(15, 22);	printf("\"가자.\"");

	nextScene();
	gotoxy(15, 22);	printf("\"근데, 먼저 어디부터 가지?\"");

	while (roop) {
		nextScene();
		gotoxy(28, 5);	printf("아빠가 아끼는 것들만 있는 아빠의 서재");
		gotoxy(28, 9);	printf("어제까지만 해도 소파에서 피라미드를 자랑하던 거실"); //한 번만 들어가야함 diningroom = 0 -> 1;
		gotoxy(28, 13);	printf("아빠 엄마가 같이 자고 계시는 침실");// 한 번만 들어가야 함 bedroom = 0 -> 1;

		choose = keyControl();
		system("cls");
		gotoxy(0, 17);
		mainView();

		gotoxy(20, 8);	printf("\"어디에 숨겨놓았을 거 같아 ?\"");

		keyy = _getch();
		if (keyy == 13) {
			switch (choose) {
			case 1:
				gotoxy(15, 22);	printf("\"아빠 서재로 가자.\"");
				nextScene();

				gotoxy(20, 8);	printf("\"기준아, 우리 괜찮겠지 ..?\"");

				keyy = _getch();
				if (keyy == 13) {
					gotoxy(15, 22);	printf("\"갑자기 무슨 소리야? 빨리 들어가\"");
				} //enter if


				keyy = _getch();
				if (keyy == 13) {
					if (password == 1 && deskKey == 1) {
						roop = 0;

						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"으.. 아까 찾은 열쇠말이야, 여기 서랍 열쇠같은데?\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"오, 한번 열어보자.\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\'근데 왜 내가 다 하는 거 같지...?\'");
						} //enter if

						nextScene();
						gotoxy(20, 8);	printf("- 철컥");

						nextScene();
						gotoxy(20, 8);	printf("\"열렸다.\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"안에 뭐 있어?\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\"어 잠깐만,\"'");
						} //enter if

						nextScene();
						gotoxy(28, 5);	printf("집 구상도");//집 구상도일 경우 : 피라미드를 숨겨놓았다고 표시된 곳은 거짓, 걸리게 됨
						gotoxy(28, 9);	printf("피라미드 책"); //피라미드 책일 경우 : 쓸모없음 다음 서랍 열기
						gotoxy(28, 13);	printf("일기장"); //차교수 일기장 일 경우 : 맨앞 장에 ‘ 번호키 : 핸드폰 메모 1번 ‘ 이라고 작성되어 있음->금고 찾기

						//그 다음 서랍을 열어야 할 경우엔 일기장 들어 있음

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\"집 구상도같은 것도 있어 우리?\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"그러니까, 거기에 뭐라도 있어?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"와 .. 피라미드 있는 곳 적어놨어. 나 이제 진짜 무서워.\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"하하.. 장난아니다. 빨리 가서 버리자 진짜.\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("                                       ");
								gotoxy(15, 22);	printf("\"그래. 이제 진짜 제발.\"");
							} //enter if

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("집 구상도에 적힌 피라미드 위치로 갔지만 사실 그 집 구상도는 가짜였습니다 !!!");
							gotoxy(20, 7);	printf("가짜 피라미드 위치에 간 서준이와 기준이는 다시 서재로 달려와서 다른 증거를");
							gotoxy(20, 9);	printf("찾으려 하지만, 이미 아침 7시 기상시간이 다가오자 어쩔 수 없이 포기하고 다음으로 미룹니다.");

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

							gotoxy(15, 22);	printf("\".. 이건 또 뭐야, 진짜 징그럽다 이젠.\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"와 .. 나 살짝 소름돋았는데 지금.\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"이건 버리고, 다음 서랍장이나 열어보자.\"");
							} //enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\".. 우리 아빠 일기도 써?\"");


							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"으.. 쓰시나 보지, 뭐 써져 있어 ??\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"2016년 3월 1일, 차기준 차서준 두 녀석이 속을 썩였다. 피라미드 꼭대, 뭐야 이거도 피라미드야?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"하하.. 일기장에도 그런 걸 쓰시네.      \"");
							} //enter if

							nextScene();
							gotoxy(15, 22);	printf("\"어, 야 아빠 핸드폰 가져왔었지 우리,\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"그지, 근데 왜 ?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"아니, 거기 메모장 들어가면 첫번째에 번호키라고 표지에 써져있는데..?\"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"응? 뭐야, 잠시만 ..\"");
							} //enter if

							next();
							gotoxy(25, 10);	printf("------------------");
							gotoxy(25, 11);	printf("|                 |");
							gotoxy(25, 12);	printf("|  와이프 생일    |");
							gotoxy(25, 13);	printf("|    0102         |");
							gotoxy(25, 14);	printf("|                 |");
							gotoxy(25, 15);	printf("------------------");

							nextScene();
							gotoxy(15, 22);	printf("\"뭐야, 엄마 생일이네…\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 24);	printf("\"입력해봐 빨리,\"");
							} //enter if

							nextScene();
							gotoxy(15, 8); printf("- 삑");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 10); printf("- 삑");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 12); printf("- 삑");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 14); printf("- 삑");
							} //enter if


							nextScene();
							gotoxy(20, 8);	printf("\"열려? 빨리 꺼내봐 좀\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"어, 피라미드 여기 있다 !!!!\"");
								pyramid = 1;
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"쉿, 주머니에 숨겨서 나가자.\"");
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
						printf("\"어응 .. 난 금고를 찾을게.. 넌 서랍 좀 봐봐\"");

						nextScene();
						gotoxy(15, 22);
						printf("\"아 뭐야, 번호키 있어야 하는데 ? \"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);
							printf("\"여기도 열쇠 있어야 할 거 같아, 안 열려\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);
							printf("                                           ");
							gotoxy(15, 22);
							printf("\"..다른데 부터 찾자\"");
						} //enter if
					} //else (번호키와 열쇠가 없을 경우에 서재를 제외한 다른 곳을 먼저 찾기 위함)
				} //if (서재를 찾으려고 함)
				break;
			case 2:
				if (diningroom == 1) {
					gotoxy(15, 22);	printf("여긴 봤었으니까 다른 데 가자.");
					nextScene();
				} //if (이미 거실을 방문함)
				else {
					gotoxy(15, 22);
					printf("거실에 있을 거 같지 않냐 ?");
					nextScene();
					gotoxy(15, 22);	printf("\"누구 없지 ? 차서준, 소파 뒤에 좀 찾아봐.\"");
					gotoxy(20, 8);	printf("- 끼익");

					nextScene();
					gotoxy(20, 8);	printf("\"으 진짜\"");

					keyy = _getch();
					if (keyy == 13) {
						textColor(11);
						gotoxy(20, 8);	printf("\"거기 누구야 ? \"");
					} //enter if

					keyy = _getch();
					if (keyy == 13) {
						textColor(7);
						gotoxy(15, 22);	printf(" ... 어떻게 하지 ?");
					} //enter if

					nextScene();
					gotoxy(28, 5);	printf("도둑인 척하면서 집 밖으로 튀어나간다.");
					gotoxy(28, 9);	printf("물 마시러 나온 척하면서 누구인지 돌아본다.");
					gotoxy(28, 13);	printf("빨리 사실대로 말하고 용서를 구한다.");

					choose = keyControl();

					switch (choose) {
					case 1: system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("으, 모르겠다 튀어 !!!");

						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("도망간 기준이와 서준이는 집 밖으로 뛰어나갔고 물 마시러 나온 세리는 둘을 ");
						gotoxy(20, 7);	printf("경찰에 신고하고, 기준이와 서준이는 결국 들켜서 아빠한테 엄청 혼나고 공부만");
						gotoxy(20, 9);	printf("죽어라 하게 되었습니다.");
						// (미션 실패)

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if
						break; // 도망가는 루트를 선택했을 경우
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						textColor(7);
						gotoxy(15, 22);	printf("\"뭐야, 누나야 ? 우리 물 마시러 나왔지 ~");

						keyy = _getch();
						if (keyy == 13) {
							textColor(14);
							gotoxy(20, 8);	printf("\"너네 뭐해 지금 이 새벽에 ..빨리 들어가서 자\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							textColor(7);
							gotoxy(20, 12);	printf("\"알았어, 누나 잘자\"");
						} //enter if

						nextScene();
						gotoxy(15, 22);
						printf("\"... 갔지 ?\"");
						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("\"으아, 심장 떨려 이거\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"으으, 빨리 하고 가자.\"");
						} //enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"어라, 차서준, 뭐 조용히 뒤질 거 없냐 ? \"");
						} // enter if

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                        ");
							gotoxy(20, 8);	printf("\"잠깐만, \"");
						}//enter if

						nextScene();
						gotoxy(28, 5);	printf("어두운 집을 밝힐 핸드폰"); //핸드폰이 울려서 들킴
						gotoxy(28, 9);	printf("피라미드를 훔칠 주머니"); //딱히 걸리지 않지만 쓸모 없음
						gotoxy(28, 13);	printf("미끄럽고 얇은 장갑"); //정답

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(20, 8);	printf("\"으 잠깐만 ..!\"");

							keyy = _getch();
							if (keyy == 13) {
								textColor(8);
								gotoxy(20, 12);	printf("- 따르르르르르르르");
							} //enter if

							nextScene();
							textColor(12);
							gotoxy(20, 8);	printf("\"이 밤 중에 누구야 !!!\"");

							nextScene();
							textColor(8);
							gotoxy(20, 8);	printf("핸드폰을 키다가 실수로 알람을 눌러버린 서준이의 실수 때문에 잠에서 깨버린 아빠에게 걸려서");
							gotoxy(20, 10);	printf("피라미드 탈취 사건은 실패로 돌아가게 되었습니다.");

							keyy = _getch();
							if (keyy == 13) {
								roop = 0;
								system("cls");
							} //enter if (미션 실패)
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"주머니는 필요없어..\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"그냥 손으로 해 그럼.\"");
							}// enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);
							printf("\"오케이.\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"조심히 해야해, 알겠지 ? \"");
							} //enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"당연하지, 이 정도야 뭐\"");
							}// enter if
							nextScene();
							gotoxy(15, 22);	printf("\"어, 뭐있다.\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"뭐야, 진짜 뭐 있어 ?\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"엥, 열쇠네.");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 24);	printf("\"열쇠가 왜 여기 있지 ? \"");
								deskKey = 1;
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("                          ");
								gotoxy(20, 8);	printf("\"우선 챙겨보자. 줘.\"");
							}// enter if

							nextScene();
							gotoxy(15, 24);	printf("\"이거 빼고는 여긴 뭐가 없네 ...\"");

							nextScene();
							gotoxy(20, 8);	printf("\"그럼 이제 다른 데 가보자.\"");
							break; // 가장 올바른 루트를 선택함
						} // switch (열쇠를 찾기 위해서 아이템 선택)
						break;
					case 3:
						system("cls");
						gotoxy(0, 17);
						mainView();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"죄송해요, 아직 아무것도 안 했어요 !\"");
						}// enter if

						keyy = _getch();
						if (keyy == 13) {
							textColor(13);
							gotoxy(20, 8);	printf("\"응..? 뭐가\"");
						}// enter if

						keyy = _getch();
						if (keyy == 13) {
							textColor(7);
							gotoxy(20, 10);		printf("\"사실...\"");
						}// enter if

						nextScene();
						textColor(8);
						gotoxy(20, 5); printf("물을 마시러 나온 엄마에게 모든 것을 사실대로 털어놓은 기준이와 서준이, ");
						gotoxy(20, 7);	printf("엄마는 모든 것을 듣고 잠시 생각을 하더니 눈을 감아준다고 말합니다. 하지만 ");
						gotoxy(20, 9);	printf("다시는 이런 일을 하지 말라고 혼낸 후 서준이와 기준이는 방으로 돌려보냅니다.");

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if (미션 실패)
						break;
					} //switch (세라한테 들킬 것을 피할 루트를 선택하는 switch)
					diningroom = 1;
				}//else (거실을 한번도 방문하지 않음)
				break;
			case 3:
				if (bedroom == 1) {
					gotoxy(15, 22);	printf("여긴 봤었으니까 다른 데 가자.");
					nextScene();
				} //if (이미 침실을 방문함)
				else {

					gotoxy(15, 22);	printf("\"엄마아빠 침실 가볼까 ?\"");
					nextScene();
					gotoxy(20, 8);	printf("\"자고 있는 거 맞지 ?\"");

					keyy = _getch();
					if (keyy == 13) {
						gotoxy(15, 22);	printf("\"맞다니까 그러네. 깨기 전에 찾기나 해.\"");
					}

					keyy = _getch();
					if (keyy == 13) {
						gotoxy(20, 8);	printf("\"야 근데 안 보여..뭐 볼 거 없어 ?\"");
					}

					nextScene();
					gotoxy(28, 5);	printf("어두운 집을 밝힐 핸드폰"); //정답
					gotoxy(28, 9);	printf("피라미드를 훔칠 주머니"); //(떨어뜨려서 엄마한테 들킴)
					gotoxy(28, 13);	printf("미끄럽고 얇은 장갑"); //실수로 미끄러져서 큰 소리가 나자 아빠한테 들켜서 끝

					choose = keyControl();

					switch (choose) {
					case 1:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"어.. 저기 옷장에 있을 거 같지 않아?\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"어딜 봐야 하는거야.\"");
						}

						nextScene();
						gotoxy(28, 5);	printf("옷장의 윗 수납장");
						gotoxy(28, 9);	printf("옷장의 가운데 유리장");
						gotoxy(28, 13);	printf("옷장의 아래 서랍장"); //정답

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"으 너무 어두워.. \"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"야 잠깐만 불빛..!\"");
							}// enter if

							next();
							textColor(12);
							gotoxy(20, 10);	printf("\"으음... 차기준, 차서준. 잠 안 자고 거기서 뭐하는 거야.\"");

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("옷장을 탐색하려다가 옷장의 작은 거울에 비친 핸드폰 불빛이 그만 차교수의 ");
							gotoxy(20, 7);	printf("눈에 들어버려 차교수가 잠에서 깨어났습니다 !!! ");
							gotoxy(20, 9);	printf("그렇게 기준이와 서준이는 한 밤 중에 차교수의 잔소리와 화를 3시간 동안 들었습니다.");

							keyy = _getch();
							if (keyy == 13) {
								roop = 0;
								system("cls");
							} //enter if (미션 실패)
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"아무 것도 없는데?\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"뭐야, 그럼 아래나 열어보자\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {

							}
						case 3:
							//아래층 : 아빠 핸드폰이 켜져있어서 봄
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"뭐가 있긴 한거야 이 옷장은..?\"");

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("\"기준아, 저거 아빠 핸드폰 아니야? 왜 저기 있지.\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"엥 진짜네..                        ");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(15, 22);	printf("\"혹시 저거 울려서 아빠 깨면 큰일이니까 밖에 가져가자.\"");
							}// enter if

							keyy = _getch();
							if (keyy == 13) {
								gotoxy(20, 8);	printf("                                                        ");
								gotoxy(20, 8);	printf("\"그래.\"");
							}// enter if
							break;
						}//switch 옷장 위아래 선택
						break;
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"너무 어두워서 잘 안 보여 ..\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"아니, 가방 줘 봐.\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("\"으에, 찾았는데 떨어뜨렸어...\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"어디 .. \"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"악 !!!!\"");
						}

						nextScene();	textColor(12);
						gotoxy(20, 10);	printf("\"으아 !!!! 뭐야, 뭐야 누구야 !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("떨어뜨린 주머니를 밟고 넘어져 버린 기준이의 비명과 쿵 소리에 그만 차교수가 깨버렸다.");
						gotoxy(20, 7);	printf("같이 놀라버린 차교수는 화가 머리 끝까지 나서 기준이와 서준이를 벌세우기로 마음 먹었고,");
						gotoxy(20, 9);	printf("그렇게 기준이와 서준이는 한 밤 중에 차교수의 잔소리와 화를 3시간 동안 들어야 했다.");

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if (미션 실패)
						break;
					case 3:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("\"너무 어두워서 잘 안 보여 ..\"");

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("\"아니, 가방 줘 봐.\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(15, 22);	printf("\"아, 찾았는데 떨어뜨렸다.\"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"그걸 놓치냐 ... \"");
						}

						keyy = _getch();
						if (keyy == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"악 !!!!\"");
						}

						nextScene();
						gotoxy(20, 10);
						textColor(12);
						printf("\"으음 ... 차서준, 차기준. 뭐하는 거야 지금 !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("떨어뜨린 장갑이 너무 미끄러워 밟고 넘어져 버린 기준이의 비명과 쿵 소리에 그만 차교수가 깨버렸습니다.");
						gotoxy(20, 7);	printf("장갑과 여러가지 짐들 그리고 열린 옷장을 보고 속셈을 알아차린 차교수는 화를 참지 못하고,");
						gotoxy(20, 9);	printf("그렇게 기준이와 서준이는 한 밤 중에 차교수의 잔소리와 화를 3시간 동안 들어야 했습니다.");

						keyy = _getch();
						if (keyy == 13) {
							roop = 0;
							system("cls");
						} //enter if (미션 실패)
						break;
					}//switch 옷장 탐색 아이템 선택
					password = 1;
					bedroom = 1;
				}//else (침실을 한번도 방문하지 않았을 경우)
				break;
			}// switch (어디를 먼저 방문할지 선택함)
		} // enter if ( 첫 선택지)
	}//while (피라미드 탐색을 반복함)

	if (pyramid == 1) {
		next();
		gotoxy(20, 10);	printf("- 집 마당 구석");

		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 10);	printf("\"오케이, 깨자 이거\"");
		}//enter if

		system("cls");
		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 8);	printf("- 쾅                 ");
		}//enter if
		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 10);	printf("- 쾅");
		}//enter if
		keyy = _getch();
		if (keyy == 13) {
			gotoxy(20, 12);	printf("- 쾅");
		}//enter if

		nextScene();
		textColor(7);
		gotoxy(20, 10);	printf("끝났다 !!");
		textColor(10);
		gotoxy(20, 12);	printf("끝났다 !!");

		next();
		gotoxy(20, 10);	printf("축하드립니다 !! 피라미드를 찾아내어 깨버렸습니다!");
		gotoxy(20, 12);	printf("ENTER 키를 누르시면 캐슬 게임 메인으로 돌아갑니다 _");
	}//만약 피라미드를 찾았다면
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
	gotoxy(8, 4);	printf("ㅤㅤㅤ■■■■ㅤㅤㅤ■■■■■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤ■■■■ㅤ■ㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤㅤ");
	gotoxy(8, 5);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤㅤㅤㅤㅤㅤㅤ");
	gotoxy(8, 6);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤ");
	gotoxy(8, 7);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤ");
	gotoxy(8, 8);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤ");
	gotoxy(8, 9);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■■■ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ");
	gotoxy(8, 10);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■■■■■ㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤ■■■■ㅤ■ㅤ■ㅤㅤ■■■■■■■■■■■ㅤㅤㅤ");
	gotoxy(8, 11);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ");
	gotoxy(8, 12);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤ■■■■■■■■■ㅤㅤㅤㅤ");
	gotoxy(8, 13);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤ");
	gotoxy(8, 14);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤ■■■■■■■■■ㅤㅤㅤㅤ");
	gotoxy(8, 15);	printf("ㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ");
	gotoxy(8, 16);	printf("ㅤㅤㅤ■■■■ㅤㅤㅤ■ㅤㅤㅤㅤㅤㅤㅤㅤ■■■ㅤㅤㅤㅤㅤㅤㅤㅤ■ㅤ■ㅤ■ㅤㅤㅤ■■■■■■■■■ㅤㅤㅤㅤ");

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

	gotoxy(25, 27);  printf("피라미드");
	gotoxy(85, 27);  printf("범인찾기");

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
				printf("<┘      ");
			if (maze[y][x] == '6')
				printf("(ENTER) ");
			else if (maze[y][x] == '7' && qy == 1)
				printf("  차기준");
			else if (maze[y][x] == '7' && qy == 2)
				printf("  명탐정");
		}
		printf("\n");
	}
	return 0;
}// mainView();

int keyControl() {
	answer = 1;
	int x = 20, y = 5, end = 1;
	gotoxy(x, y);
	printf("▶");
	while (end) {
		keyy = _getch();
		if (keyy == UP) { //위
			y -= 4;
			if (y < 5) {
				y = 5;
				answer++;
			}
			gotoxy(x, y + 4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer--;
		} //UP if
		else if (keyy == DOWN) { //아래
			y += 4;
			if (y > 14) {
				y = 13;
				answer--;
			}
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
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
	printf("▶");
	while (end) {
		keyy = _getch();
		if (keyy == UP) { //위
			y -= 4;
			if (y < 5) y = 5;
			gotoxy(x, y + 4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer--;
		} //UP if
		else if (keyy == DOWN) { //아래
			y += 4;
			if (y > 14) y = 13;
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer++;
		} //DOWN if
		else if (keyy == RIGHT) { //오른쪽
			x += 40;
			if (x > 61) x = 60;
			gotoxy(x - 40, y);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer++;
		} //RIGHT IF
		else if (keyy == LEFT) { //왼쪽
			x -= 40;
			if (x < 19) x = 20;
			gotoxy(x + 40, y);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer++;
		} //RIGHT IF
		else if (keyy == 13) {
			//next = true;
			end = 0;
			return answer;
		} //else if
	} //while
} // keyControl()

int next() { //대화 창 없이 다음 화면으로 넘어가기 : 인트로와 엔딩에서 사용
	while (1) {
		keyy = _getch();
		if (keyy == 13) {
			system("cls");
			return 0;
		}
	}
} //next()

int nextScene() { //다음 화면으로 넘어가기 : 대화나 선택할 때 사용
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
	printf("▶");
	while (end) {
		keyy = _getch();
		if (keyy == UP) { //위
			y -= 4;
			if (y < 5) {
				y = 5;
				answer++;
			}
			gotoxy(x, y + 4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer--;
		} //UP if
		else if (keyy == DOWN) { //아래
			y += 4;
			if (y > 10) {
				y = 9;
				answer--;
			}
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer++;
		} //DOWN if
		else if (keyy == ENTER) {
			//next = true;
			end = 0;
			return answer;
		} //else if
	} //while
} // keyControl()