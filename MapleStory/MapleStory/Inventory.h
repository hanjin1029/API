#pragma once
#include "obj.h"

class CItem;
class CInventory :
	public CObj
{
private:
	
	vector<CItem*>*		m_pItemslot[ITEND];
	CItem*		m_pItem;
	bool		m_bClick;

public:
	void AddItem(CItem* pItem);
	void SetItem(vector<CItem*>* pItem);
	 
	void MapSort();
	void Picking();
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
