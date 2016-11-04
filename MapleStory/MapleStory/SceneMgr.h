#pragma once

#include "Include.h"

class CScene;
class CSceneMgr
{
private:
	static CSceneMgr*		m_pInst;
	CScene*					m_pScene;

public:
	void		SetScene(SCENEID eScene);
	void		Progress(void);
	void		Render(HDC hdc);
	void		Release(void);

public:
	static CSceneMgr*		GetInst(void)
	{
		if(m_pInst == NULL)
			m_pInst = new CSceneMgr;

		return m_pInst;
	}
	void DestroyInst(void)
	{
		delete m_pInst;
		m_pInst = NULL;
	}


private:
	CSceneMgr(void);
	~CSceneMgr(void);
};

