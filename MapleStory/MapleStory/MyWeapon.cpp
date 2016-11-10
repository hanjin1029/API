#include "StdAfx.h"
#include "MyWeapon.h"

CMyWeapon::CMyWeapon(void)
{
}

CMyWeapon::~CMyWeapon(void)
{
}

void CMyWeapon::Initialize(void)
{
		//m_tInfo = INFO(0.f , 0.f,32.f,32.f,0,0);
		m_tInfo.fCX = 32.f;
		m_tInfo.fCY = 32.f;
		m_strKey = "Arrow";

}

int CMyWeapon::Progress(void)
{

	return 0;
}

void CMyWeapon::Render(HDC hdc)
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

void CMyWeapon::Release(void)
{

}