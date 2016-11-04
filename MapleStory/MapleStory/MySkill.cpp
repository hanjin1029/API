#include "StdAfx.h"
#include "MySkill.h"



CMySkill::CMySkill(void)
: m_dwTime(GetTickCount())
, m_dwTime2(GetTickCount())
{
}

CMySkill::~CMySkill(void)
{
}


void CMySkill::Initialize(void)
{
	
	m_tFrame = FRAME(0, 4, 0, 80);
	m_fSpeed = 15.f;
}

int CMySkill::Progress(void)
{

	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();

		++m_tFrame.iStart;
	}

	if(m_strKey == "Bolt_RIGHT" || m_strKey == "Bolt_LEFT")
	{
		m_tFrame.dwTime = 60;
	}
	


	if(m_strKey == "Skill1Effect_RIGHT" || m_strKey == "Skill1Effect_LEFT")
	{
		m_tFrame.dwTime = 20;
	}
	
	

	if(m_strKey == "Skill1Ball_LEFT")
	{
			m_fSpeed = 30.f;
			m_tInfo.fX -= m_fSpeed;
			m_tFrame.dwTime = 100;

			
	}
	else if(m_strKey == "Skill1Ball_RIGHT")
	{
			m_fSpeed = 30.f;
			m_tInfo.fX += m_fSpeed;
			m_tFrame.dwTime = 100;
	}

	if(m_strKey == "Skill3Effect_RIGHT" || m_strKey == "Skill3Effect_LEFT")
	{
		m_tFrame.dwTime = 15;
	}

	if(m_strKey == "Skill3Ball_LEFT")
	{
			m_fSpeed = 20.f;
			m_tInfo.fX -= m_fSpeed;
			m_tFrame.dwTime = 100;
			
	}
	else if(m_strKey == "Skill3Ball_RIGHT")
	{
			m_fSpeed = 20.f;
			m_tInfo.fX += m_fSpeed;
			m_tFrame.dwTime = 100;
	}



	return 0;

}

void CMySkill::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f+ m_ptScroll.y),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.iStart),
		int(m_tInfo.fCY * m_tFrame.iScene),
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(255, 255, 255));

}

void CMySkill::Release(void)
{

}


