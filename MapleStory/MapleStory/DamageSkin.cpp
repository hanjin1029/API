#include "StdAfx.h"
#include "DamageSkin.h"

CDamageSkin::CDamageSkin(void)
: m_dwTime(GetTickCount())
{
}

CDamageSkin::~CDamageSkin(void)
{
}

void CDamageSkin::Initialize(void)
{
	m_tInfo = INFO(0, 0, 33.f, 38.f, 0, 0);
	m_strKey = "DamageSkin1";
	m_tFrame = FRAME(0,10,0, 100);
	
}

int CDamageSkin::Progress(void)
{
	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();

		m_tFrame.iStart = m_tInfo.iAttack;
	}
	
	if(m_strKey == "DamageSkin1")
	{
		m_tFrame.dwTime = 40;
		m_tInfo.fY -= 5.f;
		
	}


	return 0;
}

void CDamageSkin::Render(HDC hdc)
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

void CDamageSkin::Release()
{

}