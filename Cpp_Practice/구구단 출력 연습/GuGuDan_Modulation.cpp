#include <iostream>
using namespace std;


//단 최소값
#define MIN_DAN		1

//해당 단까지만 출력
#define MAX_DAN		9

//해당 곱 까지
#define MAX_MULTI	9

void DisplayMulti(int nInputDan)	//입력받은 값의 단수 만큼 같은 행에 구구단을 출력한다.
{
	int nResult = 0;

	for (int nDan = MIN_DAN; nDan <= MAX_DAN; nDan += nInputDan)		// 같은 열에는 입력받은 값만큼 차이나는 단수의 구구단을 출력하기 위한 반복문.
	{
		for (int i = 1; i <= MAX_MULTI; i++)	//특정 단수의 구구단을 1부터 9까지 곱한 값을 출력하기 위한 반복문.
		{
			for (int j = 0; j < nInputDan; j++)		//같은 행에 입력받은 단수까지의 곱을 출력하기 위한 반복문.
			{
				if (nDan + j <= MAX_DAN)		//1~10단의 경우 템플릿에 따라 구구단을 출력한다.
				{
					nResult = (nDan + j) * i;

					printf("  %d * %d = %2d", nDan + j, i, nResult);
				}
				else					//11단 이상의 구구단은 출력하지 않는다.
				{
					printf("");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}


//입력 값을 검증하는 함수
bool CheckInputDan(int nInputDan)
{
	bool bRet = false;

	if (nInputDan >= 1 && nInputDan <= 9)
	{
		bRet = true;
	}
	
	return bRet;
}

//몇 단까지 같은 열에 출력할 것인가를 입력받는다.
int GetInputDan(void)
{
	int nUserInputDan = 0;

	cout << "몇 단까지 같은 열에 출력할 것입니까: ";
	cin >> nUserInputDan;
	
	return nUserInputDan;
}

int Re_execute(void)
{
	while (true)
	{
		int work_mode = 0;
		cout << "1. 구구단 출력" << endl;
		cout << "2. 종료" << endl;
		cout << "작업번호 입력: ";
		cin >> work_mode;
		cout << endl;

		if (work_mode == 1)
		{
			int nInputDan = GetInputDan();

			if (CheckInputDan(nInputDan) == true)
			{
				DisplayMulti(nInputDan);
			}
			else
			{
				cout << "다시 입력해주세요";
				return 0;
			}
			work_mode = 0;
		}
		else if (work_mode == 2)
		{
			cout << "프로그램 종료" << endl;
			break;
		}
		else
		{
			cout << "1, 2만 입력하세요" << endl;
			Re_execute();
		}
	}
}

int main()
{
	Re_execute();
	return 0;
}




/*

1. 구구단 출력
2. 종료

작업번호 입력 : 1

1번 구구단 출력 '1' 입력시
구구단 배열 값을 입력하세요 : 2
구구단 출력

출력 후 
상단 1~2번 출력


2번 종료 입력시
프로그램 종료

* 
*/