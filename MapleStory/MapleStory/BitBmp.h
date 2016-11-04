#pragma once

#include "Include.h"

class CBitBmp
{
private:
	HDC			m_hdc;
	HDC			m_MemDC;
	HBITMAP		m_bitmap;
	HBITMAP		m_oldmap;

public:
	CBitBmp*		LoadBmp(TCHAR* pFileName);
	void			Release(void);
	HDC				GetMemDC(void);

public:
	CBitBmp(void);
	~CBitBmp(void);
};
