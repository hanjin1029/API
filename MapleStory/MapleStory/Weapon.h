#pragma once
#include "item.h"

class CWeapon :
	public CItem
{
public:
	virtual void Initialize(void);
	virtual int	 Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

public:
	CWeapon(void);
	CWeapon(const CWeapon& rWeapon);
	CWeapon(wstring _strItName, int _iOption, int _iPrice, ITTYPE _eType, int _iItemType);
	~CWeapon(void);
};
