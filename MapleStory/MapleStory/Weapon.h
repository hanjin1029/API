#pragma once
#include "item.h"

class CWeapon :
	public CItem
{
public:
	virtual void Initialize(void);
	virtual void Render();

public:
	CWeapon(void);
	CWeapon(const CWeapon& rWeapon);
	CWeapon(string _strItName, int _iOption, int _iPrice, ITTYPE _eType, int _iItemType);
	~CWeapon(void);
};
