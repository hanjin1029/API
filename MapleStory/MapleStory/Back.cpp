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
