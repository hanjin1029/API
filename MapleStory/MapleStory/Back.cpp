#include "StdAfx.h"
#include "Back.h"

CBack::CBack(void)
{
}

CBack::~CBack(void)
{
	Release();
}

void CBack::Initialize(void)
{
	m_strKey = "town";
	m_tInfo = INFO(0.f, 0.f, 3090.f, 600.f,0,0);

}

int CBack::Progress(void)
{
	return 0;
}

void CBack::Render(HDC hdc)
{
	BitBlt(hdc, 
		int(m_tInfo.fX + m_ptScroll.x),
		int(m_tInfo.fY + m_ptScroll.y),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		0, 0, 
	SRCCOPY);
}

void CBack::Release(void)
{
	
}
