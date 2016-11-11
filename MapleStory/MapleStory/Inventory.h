#pragma once
#include "obj.h"


class CInventory :
	public CObj
{
private:
	DWORD			m_dwTime;
	vector<CObj*>		m_pItemslot;
	bool			m_bClick;
	int				m_iStartX;
	int				m_iStartY;
	int				m_iEndX;
	int				m_iEndY;
	POINT			m_pt;
	RECT			m_rc;
	bool			m_bDrag;

public:
	void AddItem();
	void Picking();
	CObj* CreateWeapon(float _fX, float _fY,float _fCX, float _fCY, string _strITname);
	CObj* CreateArmor(float _fX, float _fY,float _fCX, float _fCY, string _strITname);
	void Scroll(void);
	
public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);


public:
	CInventory(void);
	~CInventory(void);
};
