#pragma once
#include "scene.h"

class CObj;
class CMyMenu :
	public CScene
{
private:
	list<CObj*>		m_ButtonList;

private:
	CObj*		CreateButton(float _fX, float _fY, string _strKey);

public:
	CMyMenu(void);
	~CMyMenu(void);

public:
	virtual void Initialize(void);
	virtual int  Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
