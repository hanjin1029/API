#include "StdAfx.h"
#include "Inventory.h"
#include "MyWeapon.h"
#include "MyArmor.h"
#include "ObjFactory.h"


CInventory::CInventory(void)
: m_dwTime(GetTickCount())
{
	m_bClick = false;
	m_bDrag  = false;
	
}

CInventory::~CInventory(void)
{
	Release();
}

void CInventory::Initialize(void)
{
	m_tInfo = INFO(WINCX/1.3f, WINCY/2.f , 172.f, 355.f, 0, 0);
	m_strKey = "Inven";	

	
	RECT m_rc = {

		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fX + m_tInfo.fCX / 2.f),
		int(m_tInfo.fY + m_tInfo.fCY / 2.f)
		};

}

int CInventory::Progress(void)
{
	



	AddItem();
	

		for(size_t i = 0; i< 6; ++i)
		{
			for(size_t j = 0; j < 4; ++j)
			{
				size_t iIndex = i * 6 + j;
				if(iIndex >= m_pItemslot.size())
				{
					break;
				}
				else
				m_pItemslot[iIndex]->SetPos((m_tInfo.fX - 45 ) + (j*35) , (m_tInfo.fY - 95) + (i*35) );
				
			}
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
	
		for(vector<CObj*>::iterator iter = m_pItemslot.begin();
			iter != m_pItemslot.end(); ++iter)
		{
			(*iter)->Render(hdc);
		}
		


}

void CInventory::Release(void)
{	
	for(vector<CObj*>::iterator iter = m_pItemslot.begin();
			iter != m_pItemslot.end(); ++iter)
		{
			::Safe_Delete(*iter);
			

		}
		
	
	
}

void CInventory::Picking(void)
{
	m_tInfo.fX = (float)GetMouse().x ;
	m_tInfo.fY = (float)GetMouse().y ;
	
}

void CInventory::AddItem()
{
	if(m_dwTime + 1000 < GetTickCount())
	{
	if(GetAsyncKeyState('1') & 0x8000)
	{
		m_pItemslot.push_back(CreateWeapon(0,0,32.f,32.f,"Arrow"));
		m_dwTime = GetTickCount();
	}
	

	if(GetAsyncKeyState('2')& 0x8000)
	{
		m_pItemslot.push_back(CreateArmor(0,0,32.f,32.f,"Armor"));
		m_dwTime = GetTickCount();
	}
	
	}


	
}



CObj* CInventory::CreateWeapon(float _fX, float _fY,float _fCX, float _fCY, string strITName)
{
	CObj*	pWeapon = CObjFactory<CMyWeapon>::CreateObj(_fX, _fY,_fCX, _fCY ,strITName);

	return pWeapon;

}



CObj* CInventory::CreateArmor(float _fX, float _fY,float _fCX, float _fCY, string strITName)
{
	CObj*	pArmor = CObjFactory<CMyArmor>::CreateObj(_fX, _fY,_fCX, _fCY ,strITName);

	return pArmor;

}	