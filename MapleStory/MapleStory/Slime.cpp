#include "StdAfx.h"
#include "Slime.h"

CSlime::CSlime(void)
: m_dwTime(GetTickCount())
{
}

CSlime::~CSlime(void)
{
}

void CSlime::Initialize(void)
{
	m_tFrame = FRAME(0, 4, 0, 100);

}

int CSlime::Progress(void)
{
	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();

		++m_tFrame.iStart;
	}

	return 0;

}

void CSlime::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f+ m_ptScroll.y),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.iStart),
		int(m_tInfo.fCY * m_tFrame.iScene),
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(255, 0, 255));
	
}

void CSlime::Release(void)
{

}