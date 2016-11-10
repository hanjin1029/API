#include "StdAfx.h"
#include "Weapon.h"

CWeapon::CWeapon(void)
{
}

CWeapon::CWeapon(wstring _strItName, int _iOption, int _iPrice, ITTYPE _eType , int _iItemType)
:CItem(_strItName, _iOption, _iPrice, _eType)
{
	m_iItemType = _iItemType;
}

CWeapon::CWeapon( const CWeapon& rWeapon )
{
	m_tItem = rWeapon.m_tItem;
	
}

CWeapon::~CWeapon(void)
{
}

void CWeapon::Initialize(void)
{
	
	m_tItem.fCX = 32.f;
	m_tItem.fCY = 32.f;
	m_strKey = "Arrow";
	m_tItem.eType = ITWEAPON;

}

int CWeapon::Progress(void)
{

	return 0;
}

void CWeapon::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tItem.fX - m_tItem.fCX / 2.f),
		int(m_tItem.fY - m_tItem.fCY / 2.f ),
		int(m_tItem.fCX), int(m_tItem.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		0, 
		0, 
		(int)m_tItem.fCX, (int)m_tItem.fCY, 
		RGB(255, 255, 255));
	
} 

void CWeapon::Release(void)
{

}