#pragma once
#include "obj.h"


class CPlayer :
	public CObj
{	
private:
	DWORD	m_dwKey;
	DWORD	m_dwTime;
	DWORD	m_dwTime2;
	DWORD	m_dwState;
	FRAME	m_tFrame;
	POINT	m_ptOffset;
	list<CObj*>*	m_pSkill;
	vector	<TILE*> m_pTile;
	float  _fX;
	float  _fY;


private:
	void	KeyCheck(void);
	void	Direction(void);
	void	ScrollX(void);
	void	ScrollY(void);
	
	bool	m_bJump;
	bool	m_bGravity;
	bool	m_bCollCheck;
	float	m_fGravity;
	float	m_fTime;
	string	m_strSkill;


public:
	void	SetState(DWORD dwState, int iLast, int iScene, DWORD dwTime);
	void	SetJump(bool bJump);
	void	SetGravity(bool bGravity);
	void	SetTime(float fTime);
	void    SetScrollX(float _fX);
	void	SetScrollY(float _fY);
	void	SetOffsetX(float _fX);
	void	SetOffsetY(float _fY);
	void	SetScrollX2(float _fX);
	void	SetScrollY2(float _fY);
	float	GetScrollX(void);
	float	GetScrollY(void);
	float	GetOffSetX(void);
	float	GetOffSetY(void);
	void	SetSkill(list <CObj*>* _pSkill);
	CObj*	CreateSkill(float _fX, float _fY, float _fCX, float _fCY, int _iAttack , string _strSkillName);
	string	GetSkillDir(void);

	bool	GetJump(void);
	bool	GetGravity(void);

public:
	CPlayer(void);
	~CPlayer(void);

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
