#pragma once

#include "Obj.h"

class CRenderMgr
{
private:
	static CRenderMgr*		m_pInst;
	multimap<float, CObj*>	m_MapRenderObj;

public:
	void	AddObject(CObj* pObj);
	void	RenderObj(HDC hdc);
	void	ObjClear(void);

public:
	static CRenderMgr*		GetInst(void)
	{
		if(m_pInst == NULL)
			m_pInst = new CRenderMgr;

		return m_pInst;
	}
	void DestroyInst(void)
	{
		delete m_pInst;
		m_pInst = NULL;
	}

private:
	CRenderMgr(void);
	~CRenderMgr(void);
};
