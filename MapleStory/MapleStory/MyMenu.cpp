#include "StdAfx.h"
#include "MyMenu.h"
#include "MyButton.h"
#include "ObjFactory.h"
#include "SceneMgr.h"


CMyMenu::CMyMenu(void)
{
}

CMyMenu::~CMyMenu(void)
{
}

void CMyMenu::Initialize(void)
{
	m_BitMap["back"] = (new CBitBmp)->LoadBmp(L"../Texture/back.bmp");
	m_BitMap["menu"] = (new CBitBmp)->LoadBmp(L"../Texture/menu.bmp");

	m_BitMap["Start"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Start.bmp");
	m_BitMap["Edit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Edit.bmp");
	m_BitMap["Exit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Exit.bmp");

	m_ButtonList.push_back(CreateButton(200.f, 400.f, "Start"));
	m_ButtonList.push_back(CreateButton(400.f, 400.f, "Edit"));
	m_ButtonList.push_back(CreateButton(600.f, 400.f, "Exit"));

	CObj::SetBitMap(&m_BitMap);

}
CObj* CMyMenu::CreateButton(float _fX, float _fY, string _strKey)
{
	CObj*		pButton = CObjFactory<CMyButton>::CreateObj(_fX, _fY);

	pButton->SetDrawKey(_strKey);

	return pButton;

}
int CMyMenu::Progress(void)
{
	int iSelect = 0;

	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		iSelect = (*iter)->Progress();

		switch(iSelect)
		{
		case 1:
			CSceneMgr::GetInst()->SetScene(SC_STAGE);
			return 0;

		case 2:
			CSceneMgr::GetInst()->SetScene(SC_EDIT);
			return 0;

		case 3:
			DestroyWindow(g_hWnd);
			break;
		}

	}

	return 0;
}

void CMyMenu::Render(HDC hdc)
{
	BitBlt(m_BitMap["back"]->GetMemDC(), 
		0, 0, 
		WINCX, WINCY, 
		m_BitMap["menu"]->GetMemDC(), 
		0, 0, SRCCOPY);

	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		(*iter)->Render(m_BitMap["back"]->GetMemDC());
	}


	BitBlt(hdc, 
		0, 0, 
		WINCX, WINCY, 
		m_BitMap["back"]->GetMemDC(), 
		0, 0, SRCCOPY);
}

void CMyMenu::Release(void)
{
	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		::Safe_Delete(*iter);
	}
	m_ButtonList.clear();
}
