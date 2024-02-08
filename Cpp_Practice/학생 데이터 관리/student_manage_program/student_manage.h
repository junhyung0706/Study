#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#define SetMode_FindName    1
#define SetMode_ListNumber  2
#define SetMode_finish      3

#include <typeinfo>

//using namespace std;

//최대 데이터 입력 가능수(학생정보)
#define MAX_DATA_COUNT     10


//학생 데이터
typedef struct _STUDENT_DATA
{
    _STUDENT_DATA()
    {
        nGrade = 0;
        nClass = 0;
        nNumber = 0;
    }

    int nGrade;             //학년
    int nClass;             //반
    int nNumber;            //번호
    std::string strName;    //이름
}STUDENT_DATA;

