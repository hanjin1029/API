#pragma once

#include "Include.h"

class CObj;
class CBitBmp;
class CScene
{
protected:
	map<string, CBitBmp*>		m_BitMap;
	static CObj*				m_pPlayer;
	static CObj*				m_pInven;
	static CObj*				m_pEquip;


public:
	virtual void Initialize(void)	PURE;
	virtual int Progress(void)		PURE;
	virtual void Render(HDC hdc)	PURE;
	virtual void Release(void)		PURE;

public:
	CScene(void);
	virtual ~CScene(void);
};
