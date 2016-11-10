#include "StdAfx.h"
#include "Inventory.h"
#include "MyWeapon.h"
#include "ObjFactory.h"


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
		for(list<CObj*>::iterator iter = m_pItemslot.begin();
			iter != m_pItemslot.end(); ++iter)
		{
			for(int i = 0; i<6; )
			{
				for( int j= 0; j<4; )
				{
				(*iter)->SetPos(m_tInfo.fX - 45 + (j*35) ,m_tInfo.fY - 95 + (i*35));				
				
				++j;			
				}
				++i;
			}

		}
		
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		Picking();
		m_bClick = true;
	}
	if(m_bClick)
	{
		
		m_bClick = false;
	}

	AddItem();
	

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
	
		for(list<CObj*>::iterator iter = m_pItemslot.begin();
			iter != m_pItemslot.end(); ++iter)
		{
			(*iter)->Render(hdc);
		}
		


}

void CInventory::Release(void)
{
	
}

void CInventory::Picking(void)
{
	m_tInfo.fX = (float)GetMouse().x ;
	m_tInfo.fY = (float)GetMouse().y ;
	
}

void CInventory::AddItem()
{
	if(GetAsyncKeyState('1'))
	{
		m_pItemslot.push_back(CreateWeapon(0,0,32.f,32.f,"Arrow"));

	}
	

}



CObj* CInventory::CreateWeapon(float _fX, float _fY,float _fCX, float _fCY, string strITName)
{
	CObj*	pWeapon = CObjFactory<CMyWeapon>::CreateObj(_fX, _fY,_fCX, _fCY ,strITName);

	return pWeapon;

}	