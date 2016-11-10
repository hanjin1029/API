#pragma once
#include "myitem.h"

class CMyWeapon :
	public CMyItem
{

public:
	virtual void Initialize(void) ;
	virtual int Progress(void) ;
	virtual void Render(HDC hdc) ;
	virtual void Release(void) ;


public:
	CMyWeapon(void);
	~CMyWeapon(void);
};
