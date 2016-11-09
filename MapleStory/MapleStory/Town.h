#pragma once
#include "scene.h"

class CItem;
class CObj;
class CTown :
	public CScene
{
private:
	list<CObj*>		m_ObjList[OBJ_END];
	vector<TILE*>	m_vecTile;
	CObj*			m_pBack;
	vector<CItem*>  m_vecItem;
	CItem*			m_pWeapon;
	string			m_strMonsterName;
	float			m_fCX;
	float			m_fCY;
	int				m_iX;
	int				m_iY;
	int				m_iScrollX;	
	int				m_iScrollY;
	int				m_iOffsetX;
	int				m_iOffsetY;
	bool			m_bClick;
	DWORD			m_dwTime;
	
public: 
	void	LoadData(void);
	CObj*	SetPlayer(void);
	CObj* CreateMonster(float _fX, float _fY, float _fCX, float _fCY, float _fHP, string _strMonster);


public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

public:
	CTown(void);
	~CTown(void);
};
