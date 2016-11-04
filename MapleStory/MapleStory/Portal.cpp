#include "StdAfx.h"
#include "Portal.h"

CPortal::CPortal(void)
: m_dwTime(GetTickCount())
{
}

CPortal::~CPortal(void)
{
	Release();
}

void CPortal::Initialize(void)
{
	m_tInfo = INFO(0,  0, 88.f,126.f,0,0);
	m_strKey = "Portal";
	m_tFrame = FRAME(0, 4, 0, 80);
}

int CPortal::Progress(void)
{
	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();

		++m_tFrame.iStart;
	}

	if(m_tFrame.iStart >= m_tFrame.iLast)
	{
		if(m_dwState != 1 && m_dwState != 1 )
			m_dwState = 0;

		m_tFrame.iStart = 0;
	}
	
	return 0;
}

void CPortal::Render(HDC hdc)
{
		TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y ),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.iStart),
		int(m_tInfo.fCY * m_tFrame.iScene),
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(255, 255, 255));
}

void CPortal::Release()
{

}
