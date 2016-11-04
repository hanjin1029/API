#include "StdAfx.h"
#include "PlayerUI.h"

CPlayerUI::CPlayerUI(void)
{
}

CPlayerUI::~CPlayerUI(void)
{
	Release();
}

void CPlayerUI::Initialize(void)
{
	m_tInfo = INFO(WINCX/2.f , WINCY-28, 800.f, 56.f,0,0);
	m_strKey = "UI";
}

int CPlayerUI::Progress(void)
{
	return 0;
}

void CPlayerUI::Render(HDC hdc)
{
	BitBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fCX), int(m_tInfo.fCY),
		(*m_pBitMap)[m_strKey]->GetMemDC(),
		0,0,SRCCOPY);
	


}

void CPlayerUI::Release()
{
	


}