#pragma once
#include "main.h"

//Ű���� ��
/*
#define UP		0	// W
#define DOWN	1	// A
#define LEFT	2	// S
#define RIGHT	4	// D
#define SUBMIT	5	// �����̽���
*/
enum KEY
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	SUBMIT
};


//�Լ� ����
void TitleDraw();
int MenuDraw();
int KeyControl();
void InfoDraw();
int MaplistDraw();
void DrawMap(int*, int*);
void GameLoop(int);
void Move(int*, int*, int, int, int*, int*);
void DrawUi(int*, int*,int*);