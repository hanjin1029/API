#include "StdAfx.h"
#include "Login.h"
#include "MyButton.h"
#include "ObjFactory.h"
#include "SceneMgr.h"



CLogin::CLogin(void)
{
}

CLogin::~CLogin(void)
{
	Release();
}

void CLogin::Initialize(void)
{
	m_BitMap["back"] = (new CBitBmp)->LoadBmp(L"../Texture/BackBuffer.bmp");
	m_BitMap["menu"] = (new CBitBmp)->LoadBmp(L"../Texture/menu1.bmp");

	/*m_BitMap["Start"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Start.bmp");
	m_BitMap["Edit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Edit.bmp");
	m_BitMap["Exit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Exit.bmp");*/
	
	m_BitMap["Start"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Start2.bmp");
	m_BitMap["Edit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Edit2.bmp");
	m_BitMap["Exit"] = (new CBitBmp)->LoadBmp(L"../Texture/Button/Exit2.bmp");
	


	m_ButtonList.push_back(CreateButton(200.f, 400.f, "Start"));
	m_ButtonList.push_back(CreateButton(400.f, 400.f, "Edit"));
	m_ButtonList.push_back(CreateButton(600.f, 400.f, "Exit"));

	CObj::SetBitMap(&m_BitMap);

}
CObj* CLogin::CreateButton(float _fX, float _fY, string _strKey)
{
	CObj*		pButton = CObjFactory<CMyButton>::CreateObj(_fX, _fY);

	pButton->SetDrawKey(_strKey);

	return pButton;

}
int CLogin::Progress(void)
{
	int iSelect = 0;

	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		iSelect = (*iter)->Progress();

		switch(iSelect)
		{
		case 1:
			CSceneMgr::GetInst()->SetScene(SC_TOWN);
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

void CLogin::Render(HDC hdc)
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

void CLogin::Release(void)
{
	for(list<CObj*>::iterator	iter = m_ButtonList.begin();
		iter != m_ButtonList.end(); ++iter)
	{
		::Safe_Delete(*iter);
	}
	m_ButtonList.clear();
}
