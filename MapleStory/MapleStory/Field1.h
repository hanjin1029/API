#pragma once
#include "scene.h"

class CField1 :
	public CScene
{

public:
	virtual void Initialize(void);
	virtual int Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);


public:
	CField1(void);
	~CField1(void);
};
