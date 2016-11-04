#pragma once

#include "Include.h"

class CObj;
class CObjMgr
{
private:
	static CObjMgr*		m_pInst;
	list<CObj*>*		m_pObjList;

public:
	void	SetObjList(list<CObj*>* pObjList);
	const CObj* GetObj(OBJID _eID) const;

public:
	static CObjMgr*		GetInst(void)
	{
		if(m_pInst == NULL)
			m_pInst = new CObjMgr;

		return m_pInst;
	}
	void DestroyInst(void)
	{
		delete m_pInst;
		m_pInst = NULL;
	}

private:
	CObjMgr(void);
	~CObjMgr(void);
};
