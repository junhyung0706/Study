#include "student_manage.h"

//이름을 찾는 함수. 이름을 입력 받고 학년,반,번호,이름을 찾아 출력한다.
void FindName(std::string strName, std::vector<STUDENT_DATA*>* studentInfo, int nVectorSize)
{
    std::cout << "찾는 학생의 이름을 입력해주세요: ";
    std::cin >> strName;

    STUDENT_DATA* pStData = NULL;

    for (int i = 0; i < nVectorSize; i++)
    {
        pStData = (*studentInfo)[i];
        if (pStData != NULL)
        {
            if (pStData->strName == strName)
            {
                std::cout << pStData->nGrade << "학년 " << pStData->nClass << "반 " << pStData->nNumber << "번 " << pStData->strName << "입니다." << std::endl;
            }
        }
    }
}

//한 학급의 구성원을 출력하는 함수. 학년과 반을 입력하면 해당 학급 데이터가 출력된다.
void ListNumber(int nGrades, int nClasses, std::vector<STUDENT_DATA*>* studentInfo, int nVectorSize)
{
    std::cout << "찾을 학년과 반을 입력해주세요: ";
    std::cin >> nGrades >> nClasses;

    STUDENT_DATA* pStData = NULL;

    for (std::vector<int>::size_type i = 0; i < nVectorSize; i++)
    {
        pStData = (*studentInfo)[i];
        if (pStData != NULL)
        {
            if (pStData->nGrade == nGrades && pStData->nClass == nClasses)
                std::cout << pStData->nGrade << "학년 " << pStData->nClass << "반 " << pStData->nNumber << "번 " << pStData->strName << "입니다." << std::endl;
        }
        
    }
}

//입력한 파일을 읽고 입력하는 함수
void MakeRecord(STUDENT_DATA* pStStudentData, std::string strLine)
{
    //1,1,1,kim
    std::stringstream sstream(strLine);
    std::string strToken;

    getline(sstream, strToken, ',');
    pStStudentData->nGrade = std::atoi(strToken.c_str());

    getline(sstream, strToken, ',');
    pStStudentData->nClass = std::atoi(strToken.c_str());

    getline(sstream, strToken, ',');
    pStStudentData->nNumber = std::atoi(strToken.c_str());

    getline(sstream, strToken, ',');
    pStStudentData->strName = strToken;
}

void ReadStudentData(std::vector<STUDENT_DATA*>* arr , int& nStudentDataSize)
{
    //파일 입력
    std::ifstream ifsFilePath("C:\\Users\\Dev02Notebook\\Desktop\\junhyung\\student_manage_program_2pointers\\student_list.txt");
   
    if (ifsFilePath.is_open() == true)
    {
        std::string strDataLine;

        //파일을 찾았을 경우.
        STUDENT_DATA* pStData = NULL;

        while (ifsFilePath)
        {
            getline(ifsFilePath, strDataLine);
            std::cout << strDataLine << std::endl;

            pStData = new STUDENT_DATA;

            MakeRecord(pStData, strDataLine);

            arr->push_back(pStData);      //학생 정보가 최종적으로 studentInfo에 저장된다.
            nStudentDataSize += 1;
        }
    }
    else
    {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
   
}

void DeleteStudentData(std::vector<STUDENT_DATA*>* arr)
{
    STUDENT_DATA* pStData = NULL;
    for (int i = 0; i < arr->size(); i++)
    {
        pStData = (*arr)[i];

        if (pStData != NULL)
        {
            delete pStData;
        }
    }

    arr->clear();
}


int main()
{
    //std::vector<STUDENT_DATA> studentInfo;
    std::vector<STUDENT_DATA*> ArrReferencedStudentInfo;
    std::vector<STUDENT_DATA*>* pArrStudentInfo = &ArrReferencedStudentInfo;


    //데이터 사이즈
    int nStudentDataSize = 0;

    //학생 데이터를 읽는다.
    ReadStudentData(pArrStudentInfo, nStudentDataSize);


    //사용자 입력에 따른 어떤 프로그램을 수행할 것인가를 결정
    while (true)
    {
        int nSetMode;
        std::cout << "\n이름찾기는 1를, 학년반에 따른 학급찾기는 2를, 종료는 3을 입력하세요: ";
        std::cin >> nSetMode;
        if (nSetMode == SetMode_FindName)
        {
            std::string strFindPerson;
            FindName(strFindPerson, pArrStudentInfo, nStudentDataSize);
        }
        else if (nSetMode == SetMode_ListNumber)
        {
            int nGrades = 0;
            int nclasses = 0;
            ListNumber(nGrades, nclasses, pArrStudentInfo, nStudentDataSize);
        }
        else if (nSetMode == SetMode_finish)
        {
            std::cout << "프로그램을 종료합니다.\n\n";
            break;
        }
        else
            std::cout << "1~3의 정수만 입력해주세요. \n";
    }

    DeleteStudentData(pArrStudentInfo);

    return 0;
}
