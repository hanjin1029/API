#pragma once
#include "Include.h"

class CItem
{
protected:
	ITEM	m_tItem;
	int		m_iItemType;


public:
	virtual void Initialize(void)	PURE;
	virtual void Render() PURE;

public:
	ITEM GetItem() { return m_tItem; }
	int GetType() { return m_iItemType; }

public:
	CItem(void);
	CItem(const CItem& rItem);
	CItem(string _strItName, int _iOption, int _iPrice, ITTYPE _eType);
	virtual ~CItem(void);
};

