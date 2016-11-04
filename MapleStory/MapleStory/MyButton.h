#pragma once
#include "obj.h"

class CMyButton :
	public CObj
{
private:
	
public:
	CMyButton(void);
	~CMyButton(void);

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
