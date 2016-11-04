#include "StdAfx.h"
#include "ObjMgr.h"

CObjMgr* CObjMgr::m_pInst = NULL; 



CObjMgr::CObjMgr(void)
{
}

CObjMgr::~CObjMgr(void)
{
}

void CObjMgr::SetObjList(list<CObj*>* pObjList)
{
	m_pObjList = pObjList;
}

const CObj* CObjMgr::GetObj(OBJID _eID) const
{
	list<CObj*>::iterator	iter = m_pObjList[_eID].begin();

	return (*iter);
}
