#include "StdAfx.h"
#include "Item.h"


map<string, CBitBmp*>*		CItem::m_pBitMap = NULL;
CItem::CItem(void) : m_iItemType(0)
{
}

CItem::CItem(wstring _strItName, int _iOption, int _iPrice, ITTYPE _eType )
: m_tItem(_strItName, _iOption, _iPrice, _eType)
, m_iItemType(0)
{
	
}

CItem::CItem( const CItem& rItem )
{
	m_tItem		= rItem.m_tItem;
	m_iItemType = rItem.m_iItemType;
}

CItem::~CItem(void)
{
}

void CItem::SetBitMap(map<string, CBitBmp*>* pBitMap)
{
	m_pBitMap = pBitMap;
}

void CItem::SetStrName(wstring strName)
{
	m_tItem.strItName = strName;	
}

void CItem::SetOption(int iOption)
{
	m_tItem.iOption = iOption;
}

void CItem::SetPrice(int iPrice)
{
	m_tItem.iPrice = iPrice;
}

void CItem::SetPos(float _fX, float _fY)
{
	m_tItem.fX = _fX;
	m_tItem.fY = _fY;
}