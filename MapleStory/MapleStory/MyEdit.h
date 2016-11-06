#pragma once
#include "scene.h"



class CBitBmp;
class CMyEdit :
	public CScene
{
private:
	vector<TILE*>			m_vecTile;
	vector<CBitBmp*>		m_vecBmp;
	float					m_fScrollX;
	float					m_fScrollY;
	float					m_fSpeed;

	
private:
	TILE*	CreateTile(float _fX, float _fY);
	void	Picking(void);
	void	PickingOff(void);
	void	KeyCheck(void);
	void	Scroll(void);

public:	
	void	SaveData(void);
	void	LoadData(void);
	void	SetTile(vector<TILE*>	pTile);

	
public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);


public:
	CMyEdit(void);
	~CMyEdit(void);
};
