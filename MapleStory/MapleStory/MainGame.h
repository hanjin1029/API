#pragma once

#include "Include.h"

class CSceneMgr;
class CScene;
class CBitBmp;
class CMainGame
{
private:

	HDC			m_hdc;
	CSceneMgr*	m_pSceneMgr;
	map<string, CBitBmp*>		m_MapBit;

	


public:
	void	Initialize(void);
	void	Progress(void);
	void	Render(void);
	void	Release(void);


public:
	CMainGame(void);
	~CMainGame(void);
};
