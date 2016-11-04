#pragma once
#include "scene.h"

class CObj;
class CLogin :
	public CScene
{
private:
	list<CObj*>		m_ButtonList;

private:
	CObj*		CreateButton(float _fX, float _fY, string _strKey);

public:
	CLogin(void);
	~CLogin(void);

public:
	virtual void Initialize(void);
	virtual int  Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
