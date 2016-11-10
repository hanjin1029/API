#pragma once
#include "obj.h"

class CMyItem :
	public CObj
{


public:
	virtual void Initialize(void) PURE;
	virtual int Progress(void) PURE;
	virtual void Render(HDC hdc) PURE;
	virtual void Release(void) PURE;

public:
	CMyItem(void);
	~CMyItem(void);
};
