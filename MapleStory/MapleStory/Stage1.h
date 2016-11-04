#pragma once
#include "scene.h"

class CObj;
class CStage1 :
	public CScene
{
private:
	CObj*		m_pMyEdit;

public:
	CStage1(void);
	~CStage1(void);

public:
	virtual void Initialize(void);
	virtual void Progress(void);
	virtual void Render(HDC hdc);
	virtual void Release(void);

};
