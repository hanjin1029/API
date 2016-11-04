#include "StdAfx.h"
#include "Stage1.h"
#include "SceneMgr.h"
#include "MapEdit.h"
#include "ObjFactory.h"

CStage1::CStage1(void)
{
}

CStage1::~CStage1(void)
{
	Release();
}

void CStage1::Initialize(void)
{
	m_pMyEdit = CObjFactory<CMapEdit>::CreateObj();
}

void CStage1::Progress(void)
{

	m_pMyEdit->Progress();

	if(GetAsyncKeyState('2'))
	{
		CSceneMgr::GetInstance()->SetScene(SC_STAGE2);
		return;
	}
}

void CStage1::Render(HDC hdc)
{
	//Rectangle(hdc, 100, 100, 200, 200);
	m_pMyEdit->Render(hdc);
}

void CStage1::Release(void)
{
	::Safe_Delete(m_pMyEdit);	
}
