#include "StdAfx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "MySkill.h"
#include "Inventory.h"
#include "ObjFactory.h"
#include "DamageSkin.h"


CPlayer::CPlayer(void)
: m_dwKey(0)
, m_dwTime(GetTickCount())
, m_dwTime2(GetTickCount())
, m_bJump(false)
, m_fTime(0)
, m_bGravity(true)
, m_pSkill(NULL)
{
	
}

CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo = INFO(WINCX / 2.f, WINCY /2.f  , 50.f, 75.f, 2000.f,2000.f);

	m_strKey = "Player_RIGHT";
	m_iDrawID = 0;
	m_fSpeed = 10.f;
	
	m_dwState = ST_STAND;
	m_ptOffset.x = WINCX / 2;
	m_ptOffset.y = WINCY / 2;

	m_tFrame = FRAME(0, 4, 0, 80);

	

}

int CPlayer::Progress(void)
{
	KeyCheck();
	Direction();

	
if(m_bJump)
	{
		m_fTime += 0.2f;
		m_tInfo.fY += -9.f + (0.98f * m_fTime * m_fTime) / 2.f ;
		m_dwState = ST_JUMP;	
	}

else if(m_bGravity)
	{
		m_tInfo.fY += 11.f;
	
	}

	

	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();

		++m_tFrame.iStart;
	}

	if(m_tFrame.iStart >= m_tFrame.iLast)
	{
		if(m_dwState != ST_STAND && m_dwState != ST_DOWN && m_dwState != ST_JUMP  && m_dwState != ST_UP)
			m_dwState = ST_STAND;



		m_tFrame.iStart = 0;
	}

	SetState(ST_STAND, 5, 0, 80);	
	SetState(ST_WALK, 4, 5, 70);
	SetState(ST_JUMP, 1, 1, 60);
	SetState(ST_ATTACK, 3, 3, 90);
	SetState(ST_DOWN, 1, 6, 90);

	
	//SetState(ST_DAMAGE, 2, 3, 80);
	//SetState(ST_DEATH, 4, 4, 80);

	//ScrollX();
	//ScrollY();


	return 0;
}
void CPlayer::KeyCheck(void)
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();

	if(!m_dwKey && (m_dwState & ST_ATTACK))
		m_dwState = ST_ATTACK;

	if(m_dwKey && !(m_dwState & ST_ATTACK) && !(m_dwState&ST_UP))
		m_dwState = ST_WALK;
	
	


	if(m_dwState == ST_ATTACK)
		return;

	if(m_dwKey & KEY_LEFT)
		m_tInfo.fX -= m_fSpeed;

	if(m_dwKey & KEY_RIGHT)
		m_tInfo.fX += m_fSpeed;

	if(m_dwKey & KEY_UP)
	{
		//m_tInfo.fY -= m_fSpeed;
	}
	if(m_dwKey & KEY_DOWN)
	{
		m_dwState = ST_DOWN;
		/*m_tInfo.fY += m_fSpeed;*/
	}
	if(m_dwKey & KEY_CONTROL)

		m_dwState = ST_ATTACK;

	if(m_dwKey & KEY_RETURN)
		m_dwState = ST_DEATH;


	if(m_dwKey & KEY_A)

	{
		if(m_dwTime2 + 300 <GetTickCount())
		{
			
		if(m_strKey == "Player_LEFT")
		{
			
			m_strSkill = "Bolt_LEFT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY, 730.f, 427.f, 234, m_strSkill));
			
			
		}
		else
		{	
			
			m_strSkill = "Bolt_RIGHT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY,  730.f, 427.f, 234, m_strSkill));
		
		}
			m_dwTime2 = GetTickCount();
		}
		
	}

	if(m_dwKey & KEY_S)
	{
		if(m_dwTime2 + 500 < GetTickCount())
		{
	
		if(m_strKey == "Player_LEFT")
		{
			m_strSkill = "Skill3Effect_LEFT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY, 324.f, 350.f, 0,  m_strSkill));
				
	
			if(m_strSkill == "Skill3Effect_LEFT" )
			{
		
				m_strSkill = "Skill3Ball_LEFT";
				m_pSkill->push_back(CreateSkill(m_tInfo.fX - 100.f, m_tInfo.fY, 281.f, 116.f, 125 , m_strSkill));
			
				
			}
		
		}
		else
		{
			m_strSkill = "Skill3Effect_RIGHT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY, 324.f, 350.f, 0, m_strSkill));

			if(m_strSkill == "Skill3Effect_RIGHT")
			{	
				m_strSkill = "Skill3Ball_RIGHT";
			
				m_pSkill->push_back(CreateSkill(m_tInfo.fX + 100.f, m_tInfo.fY, 281.f, 116.f, 125 , m_strSkill));
			
			}
			
		
		}
		m_dwTime2 = GetTickCount();
		}
			

	}
		
	if(m_dwKey & KEY_D)
	{
		if(m_dwTime2 + 500 < GetTickCount())
		{
		if(m_strKey == "Player_LEFT")
		{
			m_strSkill = "Skill2_LEFT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY, 630.f,230.f, 143,  m_strSkill));
			
		}
		else
		{
			m_strSkill = "Skill2_RIGHT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY, 630.f,230.f, 143, m_strSkill));
		
		}
		m_dwTime2 = GetTickCount();
		}
	}

	if(m_dwKey & KEY_F)
	{
		if(m_dwTime2 + 300 < GetTickCount())
		{
		if(m_strKey == "Player_LEFT")
		{
			m_strSkill = "Skill1Effect_LEFT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY, 288.f, 270.f, 1,  m_strSkill));
				
	
			if(m_strSkill == "Skill1Effect_LEFT" )
			{
		
				m_strSkill = "Skill1Ball_LEFT";
				m_pSkill->push_back(CreateSkill(m_tInfo.fX - 100.f, m_tInfo.fY,303.f,57.f, 185 , m_strSkill));
			
				
			}
				
		
		}
		else
		{
			m_strSkill = "Skill1Effect_RIGHT";
			m_pSkill->push_back(CreateSkill(m_tInfo.fX, m_tInfo.fY, 288.f, 270.f, 1, m_strSkill));

			if(m_strSkill == "Skill1Effect_RIGHT")
			{	
				m_strSkill = "Skill1Ball_RIGHT";
				m_pSkill->push_back(CreateSkill(m_tInfo.fX + 100.f, m_tInfo.fY,303.f, 57.f, 185 , m_strSkill));
				
			}
			
		
		}
		m_dwTime2 = GetTickCount();
	}

	}


	if(m_dwKey & KEY_Z)
	{
		
		m_dwState = ST_JUMP;
		if(m_bJump)
			return;

		m_bJump = true;
		m_bGravity = false;
	
	}

}

void CPlayer::Direction(void)
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();

	if(m_dwKey & KEY_RIGHT)
	{
		m_strKey = "Player_RIGHT";
	
	}
	
	if(m_dwKey & KEY_LEFT)
	{
		m_strKey = "Player_LEFT";
		
	}
	
	if(m_dwKey & KEY_UP)
	{
		m_strKey = "Player_UP";
	}
	/*
	if(m_dwKey & KEY_DOWN)
		m_strKey = "Player_DOWN";

	if((m_dwKey & KEY_LEFT) && (m_dwKey & KEY_DOWN))
	{
		m_strKey = "Player_LD";
		return;
	}

	if((m_dwKey & KEY_LEFT) && (m_dwKey & KEY_UP))
	{
		m_strKey = "Player_LU";
		return;
	}

	if((m_dwKey & KEY_RIGHT) && (m_dwKey & KEY_DOWN))
	{
		m_strKey = "Player_RD";
		return;
	}

	if((m_dwKey & KEY_RIGHT) && (m_dwKey & KEY_UP))
	{
		m_strKey = "Player_RU";
		return;
	}*/


}	

void CPlayer::SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime)
{
	
	if(m_dwState & dwState)
	{
		if(m_tFrame.iScene != iScene)
			m_tFrame.iStart = 0;

		m_tFrame.iLast = iLast;
		m_tFrame.iScene = iScene;
		m_tFrame.dwTime = dwTime;
	}
	
}
//
//void CPlayer::ScrollX(void)
//{
//	// 좌측 끝
//	if(m_tInfo.fX < m_ptOffset.x)
//	{
//		if(m_ptScroll.x > 0 - m_fSpeed)
//		{
//			if(m_tInfo.fX < 0)
//				m_tInfo.fX = 0.f;
//
//			return;
//		}
//
//		m_ptScroll.x += (long)m_fSpeed;
//		m_ptOffset.x -= (long)m_fSpeed;
//	}
//
//	// 우측 끝
//	if(m_tInfo.fX > m_ptOffset.x)
//	{
//		if(m_ptScroll.x < WINCX - 3090.f + m_fSpeed)
//		{
//			if(m_tInfo.fX > 3090.f)
//				m_tInfo.fX = 3090.f;
//
//			return;
//		}
//
//		m_ptScroll.x -= (long)m_fSpeed;
//		m_ptOffset.x += (long)m_fSpeed;
//	}
//}
//
//void CPlayer::ScrollY(void)
//{
//	// 상단 끝
//	if(m_tInfo.fY < m_ptOffset.y)
//	{
//		if(m_ptScroll.y > 0 - m_fSpeed)
//		{
//			if(m_tInfo.fY < 0)
//				m_tInfo.fY = 0.f;
//
//			return;
//		}
//
//		m_ptScroll.y += (long)m_fSpeed;
//		m_ptOffset.y -= (long)m_fSpeed;
//	}
//
//	// 하단 끝
//	if(m_tInfo.fY > m_ptOffset.y)
//	{
//		if(m_ptScroll.y < WINCY - 600.f + m_fSpeed)
//		{
//			if(m_tInfo.fY > 600.f)
//				m_tInfo.fY = 600.f;
//
//			return;
//		}
//
//		m_ptScroll.y -= (long)m_fSpeed;
//		m_ptOffset.y += (long)m_fSpeed;
//	}
//}

void CPlayer::Render(HDC hdc)
{
	

	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f + m_ptScroll.x),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f + m_ptScroll.y),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.iStart), 
		int(m_tInfo.fCY * m_tFrame.iScene), 
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(255, 255, 255));

	
}

void CPlayer::Release(void)
{
	
}


void CPlayer::SetJump(bool bJump)
{
	m_bJump = bJump;
}

void CPlayer::SetGravity(bool bGravity)
{
	m_bGravity = bGravity;
}

void CPlayer::SetTime(float fTime)

{
	m_fTime = fTime;
}


void CPlayer::SetSkill(list<CObj*>* _pSkill)
{
	m_pSkill = _pSkill;
}



CObj* CPlayer::CreateSkill(float _fX, float _fY, float _fCX, float _fCY, int _iAttack, string _strSkillName)
{

	CObj* pSkill = CObjFactory<CMySkill>::CreateObj(_fX, _fY, _fCX, _fCY, _iAttack, _strSkillName);


	return pSkill;
}

string CPlayer::GetSkillDir(void)
{
	return m_strSkill;
}


void CPlayer::SetScrollX(float _fX)
{
		// 좌측 끝
	if(m_tInfo.fX < m_ptOffset.x)
	{
		if(m_ptScroll.x > 0 - m_fSpeed)
		{
			if(m_tInfo.fX < 0)
				m_tInfo.fX = 0.f;

			return;
		}

		m_ptScroll.x += (long)m_fSpeed;
		m_ptOffset.x -= (long)m_fSpeed;
	}

	// 우측 끝
	if(m_tInfo.fX > m_ptOffset.x)
	{
		if(m_ptScroll.x < WINCX - _fX + m_fSpeed)
		{
			if(m_tInfo.fX > _fX)
				m_tInfo.fX = _fX;

			return;
		}

		m_ptScroll.x -= (long)m_fSpeed;
		m_ptOffset.x += (long)m_fSpeed;
	}

}

void CPlayer::SetScrollY(float _fY)
{
		if(m_tInfo.fY < m_ptOffset.y)
	{
		if(m_ptScroll.y > 0 - m_fSpeed)
		{
			if(m_tInfo.fY < 0)
				m_tInfo.fY = 0.f;

			return;
		}

		m_ptScroll.y += (long)m_fSpeed;
		m_ptOffset.y -= (long)m_fSpeed;
	}

	// 하단 끝
	if(m_tInfo.fY > m_ptOffset.y)
	{
		if(m_ptScroll.y < WINCY - _fY + m_fSpeed)
		{
			if(m_tInfo.fY > _fY)
				m_tInfo.fY = _fY;

			return;
		}

		m_ptScroll.y -= (long)m_fSpeed;
		m_ptOffset.y += (long)m_fSpeed;
	}
}