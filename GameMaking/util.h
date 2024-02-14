#pragma once
#include "main.h"

enum
{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblus,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void Init();
void Gotoxy(int, int);
void SetColor(int, int);