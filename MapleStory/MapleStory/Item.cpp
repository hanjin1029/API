#include "StdAfx.h"
#include "Item.h"

CItem::CItem(void) : m_iItemType(0)
{
}

CItem::CItem( string _strItName, int _iOption, int _iPrice, ITTYPE _eType )
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
