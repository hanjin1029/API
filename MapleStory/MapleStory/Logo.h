#pragma once
#include "scene.h"

class CLogo :
	public CScene
{
private:
	HWND		m_hVideo;

public:
	CLogo(void);
	~CLogo(void);

public:
	virtual void Initialize(void);
	virtual int  Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
