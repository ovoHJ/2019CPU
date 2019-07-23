#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void intro_game(void);
void display_text(int count, int r_count);
void game_control(int *r_c, int rnd, int *bar);
void horizontal_slide2(int x, int y, char *c2);

void horizontal_slide(int x, int y, char *c2);
void draw_rectangle(int r, int c);
void gotoxy(int x, int y);
// void first();
void box2();
//void textcolor2(int color_number);