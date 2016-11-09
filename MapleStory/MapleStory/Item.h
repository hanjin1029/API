#pragma once
#include "Include.h"


class CBitBmp;
class CItem
{
protected:
	ITEM	m_tItem;
	int		m_iItemType;
	string		m_strKey;

	static	map<string, CBitBmp*>*		m_pBitMap;

public:
	void	SetStrName(wstring strName);
	void	SetOption(int iOption);
	void	SetPrice(int iPrice);
	void	SetPos(float _fX, float _fY);
	
	

public:
	virtual void Initialize(void)	PURE;
	virtual int Progress(void)		PURE;
	virtual void Render(HDC hdc)	PURE;
	virtual void Release(void)		PURE;

public:
	ITEM GetItem() { return m_tItem; }
	int GetType() { return m_iItemType; }
	static void SetBitMap(map<string, CBitBmp*>* pBitMap);

public:
	CItem(void);
	CItem(const CItem& rItem);
	CItem(wstring _strItName, int _iOption, int _iPrice, ITTYPE _eType);
	virtual ~CItem(void);
};

