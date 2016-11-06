#pragma once
#include "obj.h"

class CInventory :
	public CObj
{

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);


public:
	CInventory(void);
	~CInventory(void);
};
