#pragma once
#include "obj.h"

class CEquip :
	public CObj
{
private:
	bool			m_bClick;

public:
	void AddItem();
	void Picking();
	void SetItem(vector<CObj*> p_vecSlot);


public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

public:
	CEquip(void);
	~CEquip(void);
};
