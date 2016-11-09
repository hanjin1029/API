#pragma once
#include "obj.h"

class CItem;
class CInventory :
	public CObj
{
private:
	
	list<CItem*>		m_pItemsloat;
	int					m_iPotionCnt[ITEND];
	multimap<int, CItem*>		m_MapSloat;
	int			m_iStartX;
	int			m_iStartY;
	int			m_iEndX;
	int			m_iEndY;

public:
	void AddItem(CItem* pItem, ITTYPE eType);
	void SetItem(CItem* pItem, int iMaxSize);
	void MapSort();
	void MouseMove();
	
public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);


public:
	CInventory(void);
	~CInventory(void);
};
