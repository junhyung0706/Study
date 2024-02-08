#include "student_manage.h"

//이름을 찾는 함수. 이름을 입력 받고 학년,반,번호,이름을 찾아 출력한다.
void FindName(std::string strName, std::vector<STUDENT_DATA>& studentInfo, int nVectorSize)
{
    std::cout << "찾는 학생의 이름을 입력해주세요: ";
    std::cin >> strName;

    STUDENT_DATA stStudent;

    for (int i = 0; i < nVectorSize; i++)
    {
        if (studentInfo[i].strName == strName)
        {
            stStudent = studentInfo[i];

            std::cout << stStudent.nGrade <<"학년 " << stStudent.nClass << "반 " << stStudent.nNumber << "번 " << stStudent.strName << "입니다." << std::endl;
        }
    }
}

//한 학급의 구성원을 출력하는 함수. 학년과 반을 입력하면 해당 학급 데이터가 출력된다.
void ListNumber(int nGrades, int nClasses, std::vector<STUDENT_DATA>& studentInfo, int nVectorSize)
{
    std::cout << "찾을 학년과 반을 입력해주세요: ";
    std::cin >> nGrades >> nClasses;

    for (std::vector<int>::size_type i = 0; i < nVectorSize; i++)
    {
        if (studentInfo[i].nGrade == nGrades && studentInfo[i].nClass == nClasses)
            std::cout << studentInfo[i].nGrade << "학년 " << studentInfo[i].nClass << "반 " << studentInfo[i].nNumber << "번 " << studentInfo[i].strName << "입니다." << std::endl;
    }
}

//입력한 파일을 읽고 입력하는 함수
void MakeRecord(STUDENT_DATA& stStudentData, std::string strLine)
{
    //1,1,1,kim
    std::stringstream sstream(strLine);
    std::string strToken;

    getline(sstream, strToken, ',');
    stStudentData.nGrade = std::atoi(strToken.c_str());

    getline(sstream, strToken, ',');
    stStudentData.nClass = std::atoi(strToken.c_str());

    getline(sstream, strToken, ',');
    stStudentData.nNumber = std::atoi(strToken.c_str());

    getline(sstream, strToken, ',');
    stStudentData.strName = strToken;
}


int main()
{
    std::vector<STUDENT_DATA> studentInfo;
    
    //파일 입력
    std::ifstream txtfile("C:\\Users\\Dev02Notebook\\Desktop\\junhyung\\student_manage_program\\student_list.txt");
    /*
    * 파일내용
    1,1,1,kim
    1,1,2,yoon
    1,1,3,park
    1,1,4,lee
    1,1,5,roh
    1,1,6,jang
    1,2,1,kim
    1,2,2,ahn
    1,2,3,um
    1,2,4,phone
    1,2,5,go
    1,2,6,lux
    1,3,1,choi
    1,3,2,park
    1,3,3,do
    1,3,4,dan
    1,3,5,angela
    1,3,6,hong
    1,3,7,bang
    2,1,1,max
    2,1,2,jessi
    2,1,3,joo
    2,1,4,mango
    2,1,5,melon
    2,1,6,apple
    2,2,1,ahn
    2,2,2,fiff
    2,2,3,kim
    2,2,4,giu
    2,2,5,rum
    2,2,6,jin
    2,3,1,mini
    2,3,2,bon
    2,3,3,xillix
    2,3,4,nona
    2,3,5,jiu
    2,3,6,ju
    3,1,1,one
    3,1,2,two
    3,1,3,three
    3,1,4,four
    3,1,5,five
    3,1,6,six
    */

    if (!txtfile.is_open())     //파일을 찾지 못할 경우
    {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        return 0;
    }
    std::string txtstring;
    
    //파일을 찾았을 경우.
    while (txtfile)             
    {
        getline(txtfile, txtstring);
        std::cout << txtstring << std::endl;

        STUDENT_DATA stData;
        MakeRecord(stData, txtstring);

        studentInfo.push_back(stData);      //학생 정보가 최종적으로 studentInfo에 저장된다.
    }

    int nVectorSize = studentInfo.size();

    //사용자 입력에 따른 어떤 프로그램을 수행할 것인가를 결정
    while (true)
    {
        int nSetMode;
        std::cout << "\n이름찾기는 1를, 학년반에 따른 학급찾기는 2를, 종료는 3을 입력하세요: ";
        std::cin >> nSetMode;
        if (nSetMode == SetMode_FindName)
        {
            std::string strFindPerson;
            FindName(strFindPerson, studentInfo, nVectorSize);
        }
        else if (nSetMode == SetMode_ListNumber)
        {
            int nGrades = 0;
            int nclasses = 0;
            ListNumber(nGrades, nclasses, studentInfo, nVectorSize);
        }
        else if (nSetMode == SetMode_finish)
        {
            std::cout << "프로그램을 종료합니다.\n\n";
            break;
        }
        else
            std::cout << "1~3의 정수만 입력해주세요. \n";
    }

    return 0;
}
