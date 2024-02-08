#include <iostream>
using namespace std;

//N차 마방진을 출력하는 함수
void ShowMabangjin(int nNcha) 
{
	//2차원 배열 동적할당
	int** nMabangjin;
	nMabangjin = (int**)malloc(nNcha * sizeof(int*));
	for (int i = 0; i < nNcha; i++)
		nMabangjin[i] = (int*)malloc(nNcha * sizeof(int));

	//N*N 마방진의 값을 모두 0으로 초기화
	for (int i = 0; i < nNcha; i++)
	{
		for (int j = 0; j < nNcha; j++)
		{
			nMabangjin[i][j] = 0;
		}
	}
	
	//마방진을 채워나가는 조건
	int nNowNumber = 1;
	int nNowCol = 0;
	int nNowRow = nNcha / 2;
	nMabangjin[nNowCol][nNowRow] = nNowNumber;
	nNowNumber += 1;

	while (nNowNumber <= nNcha * nNcha)
	{
		//우측상단 대각선 이동
		nNowCol -= 1;
		nNowRow += 1;

		//우측상단 대각선 이동시 n*n배열을 탈출한다면 원래자리 아래에 값 입력
		if(nNowCol < 0 && nNowRow >= nNcha)
		{
			nNowCol += 2;
			nNowRow -= 1;
			nMabangjin[nNowCol][nNowRow] = nNowNumber;
			nNowNumber += 1;
		}

		//우측상단 대각선 이동시 우측으로 튀어나갔다면 가장 왼쪽으로 이동
		else if (nNowRow >= nNcha)
		{
			nNowRow = 0;
			nMabangjin[nNowCol][nNowRow] = nNowNumber;
			nNowNumber += 1;
		}

		//우측상단 대각선 이동시 상단으로 튀어나갔다면 가장 아래로 이동
		else if (nNowCol < 0)
		{
			nNowCol = nNcha - 1;
			nMabangjin[nNowCol][nNowRow] = nNowNumber;
			nNowNumber += 1;
		}

		//이제 우측상단으로 이동해도 N*N을 벗어나지 않는다.
		//우측상단 대각선 이동시 이미 값이 들어가있다면 원래자리 아래에 값 입력
		else if (nMabangjin[nNowCol][nNowRow] != 0)
		{
			nNowCol += 2;
			nNowRow -= 1;
			nMabangjin[nNowCol][nNowRow] = nNowNumber;
			nNowNumber += 1;
		}

		// 우측상단 대각선 이동 후, 값을 입력.
		else
		{
			nMabangjin[nNowCol][nNowRow] = nNowNumber;
			nNowNumber += 1;
		}
	}

	//N*N의 자릿수를 구하기 (출력할 때의 width를 정하기 위함)
	int n2Ncount = 0; //N^2의 자리수를 count한다.
	int n2Ncha = nNcha * nNcha;
	while (n2Ncha != 0)
	{
		n2Ncha = n2Ncha / 10;
		n2Ncount += 1;
	}

	//N*N 마방진출력
	for (int i = 0; i < nNcha; i++)
	{
		for (int j = 0; j < nNcha; j++)
		{
			cout.width(n2Ncount + 1);	//출력할 때 하나의 여유를 두고싶으므로 +1
			cout << right << nMabangjin[i][j];
		}
		printf("\n");
	}

	//2차원 배열 할당 해제
	for (int i = 0; i < nNcha; i++)
		free(nMabangjin[i]);
	free(nMabangjin);
}


int main()
{
	cout << "N * N의 마방진을 생성합니다." << endl;
	cout << "N을 입력하세요: ";

	while (true)
	{
		int nNthOrder;
		cin >> nNthOrder;

		if (nNthOrder % 2 == 1)
		{
			ShowMabangjin(nNthOrder);
			break;
		}
		else
		{
			cout << "홀수만 입력해야합니다." << endl;
			cout << "N을 다시 입력하세요: ";
		}
	}
	return 0;
}