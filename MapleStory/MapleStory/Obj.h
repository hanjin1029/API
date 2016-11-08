#pragma once

#include "Include.h"

class CBitBmp;
class CObj
{

private:

	DWORD		m_dwTime;

protected:
	INFO		m_tInfo;
	FRAME		m_tFrame;
	float		m_fSpeed;
	float		m_fAngle;
	string		m_strKey;
	int			m_iDrawID;
	bool		m_bHit;
	int			m_iCount;

	static	map<string, CBitBmp*>*		m_pBitMap;
	static  POINT m_ptScroll;
	static	POINT m_ptOffset;


public:
	static void SetBitMap(map<string, CBitBmp*>* pBitMap);
	void		SetDrawKey(string strKey);
	string		GetstrKey(void);
	bool		GetHit(void);
	void		Sethit(bool bHit);
	int			GetCount(void);
	void		SetCount(int iCount);

	

public:
	INFO		GetInfo(void);
	void		SetFrame(DWORD dwState, int iLast, int iScene, DWORD dwTime);
	RECT		GetRect(void);
	void		SetPos(float _fX, float _fY);
	void		SetSize(float _fCX, float _fCY);
	void		SetMinusY(int	iY);
	void		SetPlusY(int	iY);
	void		SetMinusX(int  iX);
	void		SetAttack(int iAttack);
	void		SetDamage(int iAttack);
	void		SetHP(float fHP);
	void		SetMP(float fMP);
	void		SetSpeed(float fSpeed);

public:
	virtual void Initialize(void)	PURE;
	virtual int Progress(void)		PURE;
	virtual void Render(HDC hdc)	PURE;
	virtual void Release(void)		PURE;

public:
	CObj(void);
	virtual ~CObj(void);
};
