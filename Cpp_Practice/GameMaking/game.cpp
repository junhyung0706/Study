#include "game.h"
#include "util.h"

char c_tempMap[14][58]; // 맵 임시저장할 배열

//쉬운 맵
char cMap1[14][58] = {
	//가로 56개 세로 14줄
	{"11111111111111111111111111111111111111111111111111111111"},
	{"10000000000000000000000000000000000000000000000000010001"},
	{"10000000000000000000000000000000000000000000000000010q01"},
	{"10000000000000000000000000000000000000000000000000010001"},
	{"10001000000000000000000000000000000000000000000000010001"},
	{"10001000000000000000000000000000000000000000000000010001"},
	{"10001000000000000000000000000000000000000000000000010001"},
	{"10001000000000000000000000000000000000000000000000010001"},
	{"10001000000000000000000000000000000000000000000000010001"},
	{"10001000000000000000000000000000000000000000000000011l11"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10s010k0000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111111111"}
};

//어려운 맵
char cMap2[14][58] = {
	//가로 56개 세로 14줄
	{"11111111111111111111111111111111111111111111111111111111"},
	{"1000000010000100000000000000000000000000000kk10000010001"},
	{"1000000010k001111l11111111111111111111111111110000010q01"},
	{"1000000011l111000l0000000000000l000100000000010000010001"},
	{"10001000100000011110000111101101kl000llll111k10101111l11"},
	{"10001000100000100010011101000101l1lll101l10111010001lll1"},
	{"1000100011011100101l1000001100000k0000000100100111011l11"},
	{"10001000100000010010010000000000011011111000101100010001"},
	{"1000100011111110010000100l111011100000000010100101110k01"},
	{"1000100010000010100110010k10000011l110101010010100010001"},
	{"10001000000000000010000k101001001k010000100l010111l10001"},
	{"10s01000111111110111111110100110111011111101110100010001"},
	{"100010001k00000l0l00000000100000l00000000000000100000001"},
	{"11111111111111111111111111111111111111111111111111111111"}
};

void TitleDraw()
{
	printf("\n\n\n\n");
	std::cout << "                #####   ###   #   #  #####	" << std::endl;
	std::cout << "                #      #   #  ## ##  #		" << std::endl;
	std::cout << "                #  ##  #####  # # #  #####	" << std::endl;
	std::cout << "                #   #  #   #  #   #  #		" << std::endl;
	std::cout << "                #####  #   #  #   #  #####	" << std::endl;
}


int MenuDraw()
{
	int nX = 24;
	int nY = 12;
	Gotoxy(nX - 2, nY);
	std::cout << "> 게 임 시 작";
	Gotoxy(nX, nY + 1);
	std::cout << "게 임 정 보";
	Gotoxy(nX, nY + 2);
	std::cout << "   종 료";

	while (true)
	{
		int nKeyControl = KeyControl();
		switch (nKeyControl)
		{
		case UP:
		{
			if (nY > 12)
			{
				Gotoxy(nX - 2, nY);
				std::cout << " " << std::endl;
				Gotoxy(nX - 2, --nY);
				std::cout << ">";
			}
			break;
		}
		case DOWN:
		{
			if (nY < 14)
			{
				Gotoxy(nX - 2, nY);
				std::cout << " " << std::endl;
				Gotoxy(nX - 2, ++nY);
				std::cout << ">";
			}
			break;
		}
		case SUBMIT:
			return nY - 12;
		}
	}
}

int KeyControl()
{
	char cTemp = _getch();

	if (cTemp == 'w' || cTemp == 'W')
		return KEY::UP;
	else if (cTemp == 'a' || cTemp == 'A')
		return LEFT;
	else if (cTemp == 's' || cTemp == 'S')
		return DOWN;
	else if (cTemp == 'd' || cTemp == 'D')
		return RIGHT;
	else if (cTemp == ' ')
		return SUBMIT;
}

void InfoDraw()
{
	system("cls");
	printf("\n\n");
	std::cout << "                 [ 조작법 ]\n\n";
	std::cout << "             이 동 : W, A ,S ,D\n";
	std::cout << "             선 택 : 스페이스바 \n\n\n\n\n\n\n";
	std::cout << "             개 발 자: 김 준 형\n\n";
	std::cout << " 스페이스바를 누르면 메인화면으로 이동합니다. ";

	while (true)
	{
		if (KeyControl() == SUBMIT)
			break;
	}
}

int MaplistDraw()
{
	int nX = 24;
	int nY = 6;
	system("cls");
	printf("\n\n");
	printf("                         [맵 선택]\n\n");

	Gotoxy(nX - 2, nY);
	printf(">   쉬  움");
	Gotoxy(nX, nY + 1);
	printf(" 어 려 움");
	Gotoxy(nX, nY + 2);
	printf("  뒤  로 ");

	while (true)
	{
		
		int nKeyControl = KeyControl();
		switch (nKeyControl)
		{
		case UP:
		{
			if (nY > 6)
			{
				Gotoxy(nX - 2, nY);
				printf(" ");
				Gotoxy(nX - 2, --nY);
				printf(">");
			}
			break;
		}
		case DOWN:
		{
			if (nY < 9)
			{
				Gotoxy(nX - 2, nY);
				printf(" ");
				Gotoxy(nX - 2, ++nY);
				printf(">");
			}
			break;
		}
		case SUBMIT:
			return nY - 6;
		}
	}
}

void DrawMap(int* nX, int* nY)
{
	system("cls");
	int nHeight, nWidth; // 가로와 세로 길이
	for (nHeight = 0; nHeight < 14; nHeight++)
	{
		for (nWidth = 0; nWidth < 56; nWidth++)
		{
			char cTempMap = c_tempMap[nHeight][nWidth];
			if (cTempMap == '0')
			{
				SetColor(black, black);
				printf(" ");
			}
			else if (cTempMap == '1')
			{
				SetColor(white, white);
				printf("#");
			}
			else if (cTempMap == 's')
			{
				*nX = nWidth;
				*nY = nHeight;
				SetColor(cyan, cyan);
				printf("@");
			}
			else if (cTempMap == 'q')
			{
				SetColor(lightgreen, lightgreen);
				printf("0");
			}
			else if (cTempMap == 'k')
			{
				SetColor(yellow, black);
				printf("*");
			}
			else if (cTempMap == 'l')
			{
				SetColor(brown, black);
				printf("+");
			}
		}
		printf("\n");
	}
	SetColor(white, black);
}

void GameLoop(int nMapCode)
{
	int nX, nY;
	int nKey = 0;
	int playing = true;	//게임중일 때
	if (nMapCode == 0)
	{
		memcpy(c_tempMap, cMap1, sizeof(c_tempMap));
	}
	else if (nMapCode == 1)
	{
		memcpy(c_tempMap, cMap2, sizeof(c_tempMap));
	}

	DrawMap(&nX ,&nY);

	// 게임 루프
	while (playing)
	{
		DrawUi(&nX, &nY, &nKey);

		switch (KeyControl())
		{
		case UP:
		{
			Move(&nX, &nY, 0, -1, &nKey, &playing);
			break;
		}
		case DOWN:
		{
			Move(&nX, &nY, 0, 1, &nKey, &playing);
			break;
		}
		case LEFT:
		{
			Move(&nX, &nY, -1, 0, &nKey, &playing);
			break;
		}
		case RIGHT:
		{
			Move(&nX, &nY, 1, 0, &nKey, &playing);
			break;
		}
		case SUBMIT:
			playing = 0;
		}
	}
}

void Move(int* pX, int* pY, int nX, int nY, int* nKey, int* playing)
{
	char MapObject = c_tempMap[*pY + nY][*pX + nX];
	SetColor(white, black);
	if (MapObject == '0')
	{
		Gotoxy(*pX, *pY);
		printf(" ");

		SetColor(cyan, cyan);
		Gotoxy(*pX + nX, *pY + nY);
		printf("@");

		*pX += nX;
		*pY += nY;
	}
	else if (MapObject == 'k')
	{
		*nKey += 1;
		c_tempMap[*pY + nY][*pX + nX] = '0';
		SetColor(black, black);
		Gotoxy(*pX + nX, *pY + nY);
		printf(" ");
	}
	else if (MapObject == 'l')
	{
		if (*nKey > 0)
		{
			*nKey -= 1;
			c_tempMap[*pY + nY][*pX + nX] = '0';
			SetColor(black, black);
			Gotoxy(*pX + nX, *pY + nY);
			printf(" ");
		}
	}
	else if (MapObject == 'q')
	{
		*playing = 0;
		system("cls");
		Gotoxy(22, 8);
		printf("Game Clear!");
		Sleep(1500);
	}
}



void DrawUi(int* pX, int* pY, int* key)
{
	SetColor(white, black);
	Gotoxy(3, 16);
	printf("위치: %02d, %02d, *x, *y",*pX, *pY);

	SetColor(yellow, black);
	Gotoxy(34, 16);
	printf("아이템 ");
	printf("열쇠: %d개", *key);
}