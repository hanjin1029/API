#include "StdAfx.h"
#include "Equip.h"

CEquip::CEquip(void)
: m_bClick(false)
{
}

CEquip::~CEquip(void)
{
}

void CEquip::Initialize(void)
{
	m_tInfo = INFO(WINCX/1.3f, WINCY/2.f , 184.f, 290.f,0,0);
	m_strKey = "Equip";
}

int CEquip::Progress(void)
{
	

	return 0;
}

void CEquip::Render(HDC hdc)
{
	BitBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fCX), int(m_tInfo.fCY),
		(*m_pBitMap)[m_strKey]->GetMemDC(),
		0,0,SRCCOPY);

}

void CEquip::Release(void)
{

}

void CEquip::Picking(void)
{
	m_tInfo.fX = (float)GetMouse().x ;
	m_tInfo.fY = (float)GetMouse().y ;
	
}

void CEquip::AddItem(void)
{


}