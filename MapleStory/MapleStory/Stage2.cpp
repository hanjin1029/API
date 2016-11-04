#include "StdAfx.h"
#include "Stage2.h"
#include "SceneMgr.h"

CStage2::CStage2(void)
{
}

CStage2::~CStage2(void)
{
	Release();
}

void CStage2::Initialize(void)
{
	
}

void CStage2::Progress(void)
{
	if(GetAsyncKeyState('1'))
	{
		CSceneMgr::GetInstance()->SetScene(SC_STAGE1);
		return;
	}	
}

void CStage2::Render(HDC hdc)
{
	Ellipse(hdc, 300, 300, 400, 400);
}

void CStage2::Release(void)
{
	
}
