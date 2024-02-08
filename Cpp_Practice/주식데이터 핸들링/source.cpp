#include "header.h"

CCategory::CCategory(int nMarket, int nCodeNum, std::string strFullCode, std::string strShortCode, std::string strCategoryName, int nPrice)
{
	m_nMarket = nMarket;
	m_nCodeNum = nCodeNum;
	m_strFullCode = strFullCode;
	m_strShortCode = strShortCode;
	m_strCategoryName = strCategoryName;
	m_nPrice = nPrice;
}
CCategory::~CCategory()
{

}

void CCategory::GetMarketData(std::vector<CCategory>& marketinfo, int nMarket, int nVectorSize)
{
	for (std::vector<int>::size_type i = 0; i < nVectorSize; i++)
	{
		if (marketinfo[i].m_nMarket == nMarket)
		{
			std::cout << marketinfo[i].m_nMarket << "| ";
			std::cout << marketinfo[i].m_nCodeNum << "| ";
			std::cout << marketinfo[i].m_strFullCode << "| ";
			std::cout << marketinfo[i].m_strShortCode << "| ";
			std::cout << marketinfo[i].m_strCategoryName << "| ";
			std::cout << marketinfo[i].m_nPrice << std::endl;
		}
	}
}

void CCategory::GetSpecificInfo(std::vector<CCategory>& marketinfo, int nMarket, int nCodeNum, int nVectorSize)
{
	for (std::vector<int>::size_type i = 0; i < nVectorSize; i++)
	{
		if (marketinfo[i].m_nMarket == nMarket && marketinfo[i].m_nCodeNum == nCodeNum)
		{
			std::cout << marketinfo[i].m_nMarket << "| ";
			std::cout << marketinfo[i].m_nCodeNum << "| ";
			std::cout << marketinfo[i].m_strFullCode << "| ";
			std::cout << marketinfo[i].m_strShortCode << "| ";
			std::cout << marketinfo[i].m_strCategoryName << "| ";
			std::cout << marketinfo[i].m_nPrice << std::endl;
		}
	}
}

void CCategory::SetLineData(CCategory& tempMarketData, std::string strTxtLine)
{
	//5|1|KR5701000014|F70100001|한투글로벌신성장2호(A)|999
	std::stringstream sstream(strTxtLine);
	std::string strToken;

	getline(sstream, strToken, '|');
	tempMarketData.m_nMarket = std::atoi(strToken.c_str());

	getline(sstream, strToken, '|');
	tempMarketData.m_nCodeNum = std::atoi(strToken.c_str());

	getline(sstream, strToken, '|');
	tempMarketData.m_strFullCode = strToken;

	getline(sstream, strToken, '|');
	tempMarketData.m_strShortCode = strToken;

	getline(sstream, strToken, '|');
	tempMarketData.m_strCategoryName = strToken;

	getline(sstream, strToken, '|');
	tempMarketData.m_nPrice = std::atoi(strToken.c_str());
}


int main()
{
	//데이터를 저장할 공간
	std::vector<CCategory> vMarketInfo;	//종목정보를 저장할 벡터 객체
	std::string strTxtLine;				//파일을 한 줄씩 읽어오기 위한 변수

	//파일입력
	std::ifstream txtfile("C:\\investment_category_data.txt");
	if (!txtfile.is_open())	//파일을 불러오지 못한 경우
	{
		std::cout << "파일을 찾을 수 없습니다." << std::endl;
		return 0;
	}
	//파일을 불러온 경우
	while (txtfile)
	{
		getline(txtfile, strTxtLine);	//파일에서 한 줄을 읽는다
		CCategory tempMarketData(0, 0, "0", "0", "0", 0);		//tempMarketData라는 객체 생성

		//strTxtLine 한 줄을 읽어와서 tempMarketData 객체에 해당하는 값 저장
		CCategory* temp = nullptr;
		temp->SetLineData(tempMarketData, strTxtLine);
		vMarketInfo.push_back(tempMarketData);	//vMarketInfo 벡터에 각 줄에 해당하는 정보를 객체로 받아와서 입력
	}

	int nVectorSize = vMarketInfo.size();	//종목 데이터의 수

	while (true)
	{
		int nInputMarketNum = 0;
		int nInputCodeNum = 0;

		std::cout << "마켓 번호를 입력하세요: " << std::endl;
		std::cin >> nInputMarketNum;

		//특정 마켓에 있는 모든 종목 정보를 가져옴
		CCategory* temp1 = nullptr;
		temp1->GetMarketData(vMarketInfo, nInputMarketNum, nVectorSize);

		std::cout << "코드 일련번호를 입력하세요: " << std::endl;
		std::cin >> nInputCodeNum;

		//특정 마켓과 코드 일련번호에 해당하는 종목정보를 보여줌
		CCategory* temp2 = nullptr;
		temp2->GetSpecificInfo(vMarketInfo, nInputMarketNum, nInputCodeNum, nVectorSize);

		return 0;
	}
}