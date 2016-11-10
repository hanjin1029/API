#pragma once
#include "scene.h"

class CObj;
class CField2 :
	public CScene
{
private:
	list<CObj*>		m_ObjList[OBJ_END];
	vector<TILE*>	m_vecTile;
	CObj*			m_pBack;
	list<CObj*>		m_pMonster;
	DWORD			m_dwTime;
	float			m_fCX;
	float			m_fCY;
	int				m_iX;
	int				m_iY;
	int				m_iScrollX;	
	int				m_iScrollY;
	int				m_iOffsetX;
	int				m_iOffsetY;

public:
	void	LoadData(void);
	CObj*	SetPlayer(void);
	CObj* CreateMonster(float _fX, float _fY, float _fCX, float _fCY, float _fHP, string _strMonster);


public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

public:
	CField2(void);
	~CField2(void);
};
