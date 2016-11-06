#include "StdAfx.h"
#include "SceneMgr.h"
#include "Logo.h"
#include "Login.h"
#include "MyEdit.h"
#include "Town.h"
#include "Field1.h"

CSceneMgr* CSceneMgr::m_pInst = NULL;

CSceneMgr::CSceneMgr(void)
: m_pScene(NULL)
{

}

CSceneMgr::~CSceneMgr(void)
{
	Release();
}

void CSceneMgr::SetScene(SCENEID eScene)
{
	if(m_pScene != NULL)
		Release();

	switch(eScene)
	{
	case SC_LOGO:
		m_pScene = new CLogo;
		break;

	case SC_LOGIN:
		m_pScene = new CLogin;
		break;

	case SC_EDIT:
		m_pScene = new CMyEdit;
		break;

	case SC_TOWN:
		m_pScene = new CTown; 
		break;

	case SC_FIELD1:
		m_pScene = new CField1;
		break;

	case SC_FIELD2:
		break;

	case SC_BOSSFIELD:
		break;
	}

	m_pScene->Initialize();
}

void CSceneMgr::Progress(void)
{
	if (m_pScene)
		m_pScene->Progress();
}

void CSceneMgr::Render(HDC hdc)
{
	if (m_pScene)
		m_pScene->Render(hdc);
}

void CSceneMgr::Release(void)
{	
	::Safe_Delete(m_pScene);
}

