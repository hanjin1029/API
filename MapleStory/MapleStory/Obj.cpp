#include "StdAfx.h"
#include "Obj.h"

map<string, CBitBmp*>*		CObj::m_pBitMap = NULL;
POINT CObj::m_ptScroll = {};


CObj::CObj(void)
: m_bHit(false),
 m_dwTime(GetTickCount())
{
	
}

CObj::~CObj(void)
{
	
}

void CObj::SetBitMap(map<string, CBitBmp*>* pBitMap)
{
	m_pBitMap = pBitMap;
}

void CObj::SetDrawKey(string strKey)
{
	m_strKey = strKey;
}

INFO CObj::GetInfo(void)
{
	return m_tInfo;
}

void CObj::SetFrame(DWORD dwState, int iLast, int iScene, DWORD dwTime)
{
	m_tFrame.iStart = dwState;
	m_tFrame.iLast = iLast;
	m_tFrame.iScene = iScene;
	m_tFrame.dwTime = dwTime;

}


void CObj::SetPos(float _fX, float _fY)
{
	m_tInfo.fX  = _fX ;
	m_tInfo.fY  = _fY ;
}


void CObj::SetSize(float _fCX, float _fCY)
{
	m_tInfo.fCX = _fCX;
	m_tInfo.fCY = _fCY;
}

RECT CObj::GetRect(void)
{
	RECT	rc = {

		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fX + m_tInfo.fCX / 2.f),
		int(m_tInfo.fY + m_tInfo.fCY / 2.f)
	};

	return rc;
}

void CObj::SetMinusY(int iY)
{

	m_tInfo.fY -= iY  ;
}

void CObj::SetPlusY(int iY)
{
	m_tInfo.fY += iY;
}

string CObj::GetstrKey(void)
{
	return m_strKey;
}

void CObj::SetMinusX(int iX)
{
	m_tInfo.fX -= iX;
}

void CObj::SetHP(float fHP)
{
	m_tInfo.fHP = fHP;
}

void CObj::SetMP(float fMP)
{
	m_tInfo.fMP = fMP;

}

void CObj::SetDamage(int iAttack)
{

	m_tInfo.fHP -= iAttack;
	

	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();
		
		++m_tFrame.iStart;
	}

}

void CObj::SetAttack(int iAttack)
{
	m_tInfo.iAttack = iAttack;
}

bool CObj::GetHit(void)
{

	return m_bHit;
}

void CObj::Sethit(bool  bHit)
{
	m_bHit = bHit;
}

void CObj::SetSpeed(float fSpeed)
{
	m_fSpeed = fSpeed;
}

int CObj::GetCount(void)
{
	return m_iCount;
}

void CObj::SetCount(int iCount)
{
	m_iCount += iCount;
	
}

