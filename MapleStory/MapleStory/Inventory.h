#pragma once
#include "obj.h"

class CItem;
class CInventory :
	public CObj
{
private:
	
	list<CObj*>		m_pItemslot;

	bool			m_bClick;
	
public:
	void AddItem();
	void Picking();
	CObj* CreateWeapon(float _fX, float _fY,float _fCX, float _fCY, string _strITname);
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
