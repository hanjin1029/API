#pragma once
#include "obj.h"


class CMySkill :
	public CObj
{
private:

	FRAME	m_tFrame;
	DWORD	m_dwState;
	DWORD	m_dwTime;
	DWORD	m_dwTime2;



public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

public:
	CMySkill(void);
	~CMySkill(void);
};
