#include "util.h"

void Init()
{
	system("mode con cols=56 lines=20 | title Game");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//�ܼ� �ڵ� ��������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;	//Ŀ�� �����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void Gotoxy(int nX, int nY)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = nX;
	pos.Y = nY;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void SetColor(int nTextColor, int nBackgroundColor)
{
	HANDLE consoleHANDLE = GetStdHandle(STD_OUTPUT_HANDLE);	//�ܼ� �ڵ� ��������
	int code = nTextColor + nBackgroundColor * 16;
	SetConsoleTextAttribute(consoleHANDLE, code);
}