#pragma once

#include "Include.h"

class CKeyMgr
{
private:
	static CKeyMgr*		m_pInst;
	DWORD				m_dwKey;

public:
	void		KeyCheck(void);
	DWORD		GetKey(void);

private:
	DWORD	m_dwPressed;
	DWORD	m_dwPresseds[3];

	DWORD	m_dwKeyDown;
	DWORD	m_dwKeyDowns[3];

public:
	bool KeyPressed(DWORD _dwKey);
	bool KeyPressed(DWORD _dwKey, BYTE byIndex);

	bool KeyDown(DWORD _dwKey);
	bool KeyDown(DWORD _dwKey, BYTE byIndex);

	bool KeyCombine(DWORD _dwFirstKey, DWORD _dwSecondKey);

public:
	static CKeyMgr*		GetInst(void)
	{
		if(m_pInst == NULL)
			m_pInst = new CKeyMgr;

		return m_pInst;
	}
	void DestroyInst(void)
	{
		delete m_pInst;
		m_pInst = NULL;
	}


private:
	CKeyMgr(void);
	~CKeyMgr(void);
};
