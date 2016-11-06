#pragma once
#include "scene.h"



class CObj;
class CTown :
	public CScene
{
private:
	list<CObj*>		m_ObjList[OBJ_END];
	vector<TILE*>	m_vecTile;
	CObj*			m_pBack;
	CObj*			m_pInven;
	CObj*			m_pEquip;
	string			m_strMonsterName;
	float			m_fCX;
	float			m_fCY;

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
