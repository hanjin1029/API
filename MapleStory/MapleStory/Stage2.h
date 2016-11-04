#pragma once
#include "scene.h"

class CStage2 :
	public CScene
{
public:
	CStage2(void);
	~CStage2(void);

public:
	virtual void Initialize(void);
	virtual void Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
