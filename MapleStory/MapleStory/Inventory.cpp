#include "StdAfx.h"
#include "Inventory.h"

CInventory::CInventory(void)
{
}

CInventory::~CInventory(void)
{
}

void CInventory::Initialize(void)
{
	m_tInfo = INFO(WINCX/1.3f, WINCY/2.f , 172.f, 355.f, 0, 0);
	m_strKey = "Inven";
	

}

int CInventory::Progress(void)
{


	return 0;
}

void CInventory::Render(HDC hdc)
{
		BitBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fCX), int(m_tInfo.fCY),
		(*m_pBitMap)[m_strKey]->GetMemDC(),
		0,0,SRCCOPY);
	

}

void CInventory::Release(void)
{

}