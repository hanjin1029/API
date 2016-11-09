#include "StdAfx.h"
#include "Inventory.h"
#include "Weapon.h"
#include "ItemFactory.h"


CInventory::CInventory(void)
{
	m_bClick = false;
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
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		Picking();
		m_bClick = true;
	}
	if(m_bClick)
	{
		
		m_bClick = false;
	}
	
	if(GetAsyncKeyState('1'))
	{	
	m_pItem = CItemFactory<CWeapon>::CreateItem(L"Ȱ",m_tInfo.fX,m_tInfo.fY,10,100);
	AddItem(m_pItem);
	}

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

void CInventory::Picking(void)
{
	m_tInfo.fX = (float)GetMouse().x ;
	m_tInfo.fY = (float)GetMouse().y ;
	
}

void CInventory::AddItem(CItem* pItem)
{
	pItem = NULL;

	switch(pItem->GetItem().eType)
	{
	case ITWEAPON:
		m_pItemslot[ITWEAPON]->push_back(pItem);

		break;

	case ITARMOR:
		m_pItemslot[ITARMOR]->push_back(pItem);
		break;


	case ITPOTION:
		break;

	}

}

void CInventory::SetItem(vector<CItem*>* pItem)
{
	m_pItemslot[ITEND] = pItem;
}