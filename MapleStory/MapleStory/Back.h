#pragma once
#include "obj.h"

class CBack :
	public CObj
{
public:
	CBack(void);
	~CBack(void);

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
