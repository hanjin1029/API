#pragma once
#include "obj.h"

class CMonster :
	public CObj
{
private:
	FRAME	m_tFrame;
	DWORD	m_dwState;
	DWORD	m_dwTime;
	DWORD	m_dwTime2;
	DWORD	m_dwTime3;

	

	string	m_strName;
	list<CObj*>*		m_pMonster;


public:
	void	MonsterMove();
	CObj* CreateMonster(float _fX, float _fY, float _fCX, float _fCY, string _strMonster);
	void	MonsterHit(void);
	void	SetState(DWORD	ST);


public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

public:
	CMonster(void);
	~CMonster(void);
};
