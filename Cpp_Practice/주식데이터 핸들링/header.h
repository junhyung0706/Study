#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


class CCategory
{
public:
	CCategory(int nMarket, int nCodeNum, std::string strFullCode, std::string strShortCode, std::string strCategoryName, int nPrice);
	virtual ~CCategory();
private:
	int m_nMarket;					//���ϱ���
	int m_nCodeNum;					//�ڵ� �Ϸù�ȣ
	std::string m_strFullCode;		//full �����ڵ�
	std::string m_strShortCode;		//���� �����ڵ�
	std::string m_strCategoryName;	//�����̸�
	int m_nPrice;					//���� ����
public:
	void GetMarketData(std::vector<CCategory>& marketinfo, int nMarket, int nVectorSize);	//Ư�� ���Ͽ� �ִ� ��� ���� ������ ���� �� �� �ִ� �������̽� ����
	void GetSpecificInfo(std::vector<CCategory>& marketinfo, int nMarket, int nCodeNum, int nVectorSize);	//������ ���� �������� ���� �Ϸ� ��ȣ�� Ư�� ���� ������ ���� �� �� �ִ� �������̽� ����

	//strTxtLine �� ���� �о�ͼ� |�� �������� tempMarketData ��ü�� �ش��ϴ� �� ����
	void SetLineData(CCategory& tempMarketData, std::string strTxtLine);
};

