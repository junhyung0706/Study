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
				GameLoop(0); //0: ���� ��
			}
			else if (nLevelSelect == 1)
			{
				GameLoop(1); //1: ����� ��
			}
		}
		else if (nMenuCode == 1)
		{
			InfoDraw();
		}
		else if (nMenuCode == 2)
			return 0; // ���� ����
		system("cls");
		SetColor(white, black);
	}
	return 0;
}