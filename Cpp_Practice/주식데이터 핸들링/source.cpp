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
	//5|1|KR5701000014|F70100001|�����۷ι��ż���2ȣ(A)|999
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
	//�����͸� ������ ����
	std::vector<CCategory> vMarketInfo;	//���������� ������ ���� ��ü
	std::string strTxtLine;				//������ �� �پ� �о���� ���� ����

	//�����Է�
	std::ifstream txtfile("C:\\investment_category_data.txt");
	if (!txtfile.is_open())	//������ �ҷ����� ���� ���
	{
		std::cout << "������ ã�� �� �����ϴ�." << std::endl;
		return 0;
	}
	//������ �ҷ��� ���
	while (txtfile)
	{
		getline(txtfile, strTxtLine);	//���Ͽ��� �� ���� �д´�
		CCategory tempMarketData(0, 0, "0", "0", "0", 0);		//tempMarketData��� ��ü ����

		//strTxtLine �� ���� �о�ͼ� tempMarketData ��ü�� �ش��ϴ� �� ����
		CCategory* temp = nullptr;
		temp->SetLineData(tempMarketData, strTxtLine);
		vMarketInfo.push_back(tempMarketData);	//vMarketInfo ���Ϳ� �� �ٿ� �ش��ϴ� ������ ��ü�� �޾ƿͼ� �Է�
	}

	int nVectorSize = vMarketInfo.size();	//���� �������� ��

	while (true)
	{
		int nInputMarketNum = 0;
		int nInputCodeNum = 0;

		std::cout << "���� ��ȣ�� �Է��ϼ���: " << std::endl;
		std::cin >> nInputMarketNum;

		//Ư�� ���Ͽ� �ִ� ��� ���� ������ ������
		CCategory* temp1 = nullptr;
		temp1->GetMarketData(vMarketInfo, nInputMarketNum, nVectorSize);

		std::cout << "�ڵ� �Ϸù�ȣ�� �Է��ϼ���: " << std::endl;
		std::cin >> nInputCodeNum;

		//Ư�� ���ϰ� �ڵ� �Ϸù�ȣ�� �ش��ϴ� ���������� ������
		CCategory* temp2 = nullptr;
		temp2->GetSpecificInfo(vMarketInfo, nInputMarketNum, nInputCodeNum, nVectorSize);

		return 0;
	}
}