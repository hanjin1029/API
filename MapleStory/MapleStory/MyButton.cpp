#include "StdAfx.h"
#include "MyButton.h"


CMyButton::CMyButton(void)
{
}

CMyButton::~CMyButton(void)
{
	Release();
}

void CMyButton::Initialize(void)
{
	m_tInfo.fCX = 150.f;
	m_tInfo.fCY = 60.f;
	m_iDrawID   = 0;
}

int CMyButton::Progress(void)
{
	if(PtInRect(&GetRect(), GetMouse()))
	{
		m_iDrawID = 1;

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if(m_strKey == "Start")
				return 1;

			else if(m_strKey == "Edit")
				return 2;

			else if(m_strKey == "Exit")
				return 3;
		}
	}
	else
		m_iDrawID = 0;


	return 0;
}

void CMyButton::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX / 2.f),
		int(m_tInfo.fY - m_tInfo.fCY / 2.f),
		int(m_tInfo.fCX), int(m_tInfo.fCY)
		, (*m_pBitMap)[m_strKey]->GetMemDC(),
		0, int(m_tInfo.fCY * m_iDrawID),  
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, 
		RGB(255, 0, 255));
}

void CMyButton::Release(void)
{

	
}
