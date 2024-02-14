#pragma once
#include "main.h"

//키보드 값
/*
#define UP		0	// W
#define DOWN	1	// A
#define LEFT	2	// S
#define RIGHT	4	// D
#define SUBMIT	5	// 스페이스바
*/
enum KEY
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	SUBMIT
};


//함수 선언
void TitleDraw();
int MenuDraw();
int KeyControl();
void InfoDraw();
int MaplistDraw();
void DrawMap(int*, int*);
void GameLoop(int);
void Move(int*, int*, int, int, int*, int*);
void DrawUi(int*, int*,int*);