#include "StdAfx.h"
#include "RenderMgr.h"

CRenderMgr* CRenderMgr::m_pInst = NULL; 

CRenderMgr::CRenderMgr(void)
{
}

CRenderMgr::~CRenderMgr(void)
{
}
void CRenderMgr::AddObject(CObj* pObj)
{
	m_MapRenderObj.insert(make_pair(float(pObj->GetRect().bottom), pObj));
}

void CRenderMgr::RenderObj(HDC hdc)
{
	for(multimap<float, CObj*>::iterator iter = m_MapRenderObj.begin();
		iter != m_MapRenderObj.end(); ++iter)
	{
		iter->second->Render(hdc);
	}
}

void CRenderMgr::ObjClear(void)
{
	m_MapRenderObj.clear();
}
