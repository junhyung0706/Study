#include "main.h"
#include "game.h"
#include "util.h"

void Init();
void Gotoxy(int, int);

int main()
{
	Init();
	while (true)
	{
		TitleDraw();
		int nMenuCode = MenuDraw();
		if (nMenuCode == 0)
		{
			int nLevelSelect = MaplistDraw();

			if (nLevelSelect == 0)
			{
				GameLoop(0); //0: 쉬운 맵
			}
			else if (nLevelSelect == 1)
			{
				GameLoop(1); //1: 어려운 맵
			}
		}
		else if (nMenuCode == 1)
		{
			InfoDraw();
		}
		else if (nMenuCode == 2)
			return 0; // 게임 종료
		system("cls");
		SetColor(white, black);
	}
	return 0;
}