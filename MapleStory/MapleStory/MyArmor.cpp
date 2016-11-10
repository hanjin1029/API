#include "StdAfx.h"
#include "MyArmor.h"

CMyArmor::CMyArmor(void)
{
}

CMyArmor::~CMyArmor(void)
{
}


void CMyArmor::Initialize(void)
{
		m_tInfo.fCX = 32.f;
		m_tInfo.fCX = 32.f;
		m_strKey = "Armor";

}

int CMyArmor::Progress(void)
{
	return 0;
}

void CMyArmor::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX ),
		int(m_tInfo.fY - m_tInfo.fCY ),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		0,
		0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(255, 255, 255));


}

void CMyArmor::Release(void)
{

}