#pragma once

typedef struct tagInfo
{
	float fX; 
	float fY;
	float fCX; 
	float fCY;

	float fHP;
	float fMP;
	int	  iAttack;
	float fDefence;
	int		iGold;

	tagInfo(void){}
	tagInfo(float _fX, float _fY, float _fCX, float _fCY, float _fHP, float _fMP)
		: fX(_fX), fY(_fY), fCX(_fCX), fCY(_fCY), fHP(_fHP), fMP(_fMP)
	{

	}

}INFO;

typedef	 struct tagTile
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;
	int		iOption;
	int		iDrawID;

	RECT	GetRect(void)
	{
	RECT rc = 
	
		{int(fX - fCX / 2.f),
		 int(fY - fCY / 2.f),
		 int(fX + fCX / 2.f),
		 int(fY + fCY / 2.f)

		};
		return rc;
	}
	

	tagTile(void){}
	tagTile(float _fX, float _fY,float _fCX, float _fCY,int _iOption, int _iDrawID)
		: fX(_fX), fY(_fY), fCX(_fCX), fCY(_fCY), iOption(_iOption), iDrawID(_iDrawID)
	{

	}

}TILE;


typedef struct tagFrame
{
	int		iStart;
	int		iLast;
	int		iScene;
	DWORD	dwTime;

	tagFrame(){}
	tagFrame(int _iStart, int _iLast, int _iScene, DWORD _dwTime)
		: iStart(_iStart), iLast(_iLast), iScene(_iScene), dwTime(_dwTime) 
	{

	}

}FRAME;