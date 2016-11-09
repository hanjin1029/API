#include "StdAfx.h"
#include "Weapon.h"

CWeapon::CWeapon(void)
{
}

CWeapon::CWeapon( string _strItName, int _iOption, int _iPrice, ITTYPE _eType , int _iItemType)
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

}

void CWeapon::Render()
{
	
} 
