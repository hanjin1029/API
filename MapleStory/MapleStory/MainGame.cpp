#include "StdAfx.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "RenderMgr.h"
#include "MyEdit.h"
#include "PlayerUI.h"
#include "Device.h"


CMainGame::CMainGame(void)
: m_pSceneMgr(CSceneMgr::GetInst())

{
}

CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hdc = GetDC(g_hWnd);
	
	CDevice::GetInstance()->Init();

	m_pSceneMgr->SetScene(SC_LOGO);


	
}

void CMainGame::Progress(void)
{
	CKeyMgr::GetInst()->KeyCheck();
	m_pSceneMgr->Progress();
	

	
}

void CMainGame::Render(void)
{
	m_pSceneMgr->Render(m_hdc);

	
}
	


void CMainGame::Release(void)
{
	m_pSceneMgr->DestroyInst();
	CKeyMgr::GetInst()->DestroyInst();
	CObjMgr::GetInst()->DestroyInst();
	CRenderMgr::GetInst()->DestroyInst();

	
	CDevice::GetInstance()->DestroyInst();
	ReleaseDC(g_hWnd, m_hdc);
}
