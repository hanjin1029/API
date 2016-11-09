#pragma once

#include "Item.h"

template<typename T>
class CItemFactory
{
public:
	static CItem* CreateItem(void)
	{
		CItem* pItem = new T;

		pItem->Initialize();

		return pItem;
	}
	
	static CItem* CreateItem(wstring _strName, float _fX, float _fY, int _iOption, int _iPrice)
	{
		CItem* pItem = new T;
		pItem->Initialize();
		pItem->SetStrName(_strName);
		pItem->SetPos(_fX, _fY);
		pItem->SetOption(_iOption);
		pItem->SetPrice(_iPrice);

		return pItem;
	}
	
public:
	CItemFactory(void){	}
	~CItemFactory(void){	}
};
