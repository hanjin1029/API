#pragma once
#include "obj.h"

class CBitBmp;
class CMapEdit :
	public CObj
{
private:
	vector<TILE*>			m_vecTile;
	vector<CBitBmp*>		m_vecBmp;
	float					m_fScrollX;
	float					m_fScrollY;
	

private:
	TILE*	CreateTile(float _fX, float _fY);
	void	Picking(void);
	void	KeyCheck(void);
	void	Scroll(void);
	
public:
	CMapEdit(void);
	~CMapEdit(void);

public:
	virtual void Initialize(void);
	virtual void Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
