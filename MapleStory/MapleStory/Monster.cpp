#include "StdAfx.h"
#include "Monster.h"
#include "ObjFactory.h"


CMonster::CMonster(void)
: m_dwTime(GetTickCount())
, m_dwTime2(GetTickCount())
, m_dwTime3(GetTickCount())

{
}

CMonster::~CMonster(void)
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tFrame = FRAME(0,3,3,100);
	m_strName = "SlimeL";
	
	m_fSpeed = 5.f;
}



int CMonster::Progress(void)
{

	if (m_dwState != ST_DAMAGE)
	{
		MonsterMove();
	}

	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
		{
			m_dwTime = GetTickCount();

			++m_tFrame.iStart;
		}

		
		if(m_tFrame.iStart >= m_tFrame.iLast)
		{
			if(m_dwState != 1 && m_dwState != 1 )
				m_dwState = ST_STAND;

			m_tFrame.iStart = 0;
		}

	
	

	return 0;
}

void CMonster::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.iStart),
		int(m_tInfo.fCY * m_tFrame.iScene),
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(255, 0, 255));
}

void CMonster::Release(void)
{
	
}

void CMonster::MonsterMove()
{
	
	m_tInfo.fX -= m_fSpeed;
	
	if(m_dwTime2 + 2000< GetTickCount())
	{
		m_dwTime2 = GetTickCount();
		m_fSpeed *= -1.f;
	
		if(m_strKey == "SlimeL")
		{
		m_strKey = "SlimeR";
	
		m_tFrame = FRAME(0,6,3,100);
		}
		else if(m_strKey == "SlimeR")
		{
		m_strKey = "SlimeL";
		m_tFrame = FRAME(0,6,3,100);
		}

		if(m_strKey == "BlueL")
		{
		m_strKey = "BlueR";
		m_tFrame = FRAME(0,3,3,80);
		}
		else if(m_strKey == "BlueR")
		{
			m_strKey = "BlueL";
			m_tFrame = FRAME(0,3,3,80);	
		}
					
	}

}

void CMonster::MonsterHit(void)
{
		if(m_strKey == "SlimeL")
		{
			m_tFrame = FRAME(0,1,1,1000);
			m_dwState = ST_DAMAGE;
	
			return ;
		}
		else if(m_strKey == "SlimeR")
		{
			
			m_tFrame = FRAME(0,1,1,1000);
			m_dwState = ST_DAMAGE;
	
			return;
		}

		if(m_strKey == "BlueL")
		{
			
			m_tFrame = FRAME(0,1,1,1000);
			m_dwState = ST_DAMAGE;
		
			return;
		}
		else if(m_strKey == "BlueR")
		{
			m_tFrame = FRAME(0,1,1,1000);
			m_dwState = ST_DAMAGE;
		
			return;

		}
		
		
	
	
}

void CMonster::SetState(DWORD	ST)
{
	m_dwState = ST;
}

