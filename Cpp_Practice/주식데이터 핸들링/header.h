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
	int m_nMarket;					//마켓구분
	int m_nCodeNum;					//코드 일련번호
	std::string m_strFullCode;		//full 종목코드
	std::string m_strShortCode;		//단축 종목코드
	std::string m_strCategoryName;	//종목이름
	int m_nPrice;					//종목 가격
public:
	void GetMarketData(std::vector<CCategory>& marketinfo, int nMarket, int nVectorSize);	//특정 마켓에 있는 모든 종목 정보를 가져 올 수 있는 인터페이스 구현
	void GetSpecificInfo(std::vector<CCategory>& marketinfo, int nMarket, int nCodeNum, int nVectorSize);	//가져온 마켓 정보에서 종목 일련 번호로 특정 종목 정보를 가져 올 수 있는 인터페이스 제공

	//strTxtLine 한 줄을 읽어와서 |를 기준으로 tempMarketData 객체에 해당하는 값 저장
	void SetLineData(CCategory& tempMarketData, std::string strTxtLine);
};

