#pragma once
#include "obj.h"

class CSlime :
	public CObj
{
	private:

	FRAME	m_tFrame;
	DWORD	m_dwState;
	DWORD	m_dwTime;

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);
public:
	CSlime(void);
	~CSlime(void);
};
