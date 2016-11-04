#pragma once

#include "obj.h"

class CPlayerUI :
	public	CObj
{

public:
	void		Initialize(void);
	int			Progress(void);
	void		Render(HDC hdc);
	void		Release(void);

public:
	CPlayerUI(void);
	~CPlayerUI(void);
};
