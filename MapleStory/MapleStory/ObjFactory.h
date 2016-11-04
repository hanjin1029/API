#pragma once

#include "Obj.h"

template<typename T>
class CObjFactory
{
public:
	static CObj* CreateObj(void)
	{
		CObj* pObj = new T;

		pObj->Initialize();

		return pObj;
	}
	
	static CObj* CreateObj(float _fX, float _fY)
	{
		CObj* pObj = new T;


		pObj->Initialize();
		pObj->SetPos(_fX, _fY);

		return pObj;
	}
		static CObj* CreateObj(float _fX, float _fY, float _fCX, float _fCY, string _strName)
	{
		CObj* pObj = new T; 
		
		pObj->SetDrawKey(_strName);
		pObj->SetSize(_fCX, _fCY);	
		pObj->Initialize();
		pObj->SetPos(_fX, _fY);

		return pObj;

	}

	static CObj* CreateObj(float _fX, float _fY, float _fCX, float _fCY, float _fHP, string _strName)
	{
		CObj* pObj = new T; 
		
		pObj->SetDrawKey(_strName);
		pObj->SetSize(_fCX, _fCY);	
		pObj->SetHP(_fHP);
		pObj->Initialize();
		pObj->SetPos(_fX, _fY);

		return pObj;

	}

	
	static CObj* CreateObj(float _fX, float _fY, float _fCX, float _fCY, int _iAttack, string _strName)
	{
		CObj* pObj = new T; 
		
		pObj->SetDrawKey(_strName);
		pObj->SetSize(_fCX, _fCY);	
		pObj->Initialize();
		pObj->SetAttack(_iAttack);
		pObj->SetPos(_fX, _fY);

		return pObj;

	}

public:
	CObjFactory(void){	}
	~CObjFactory(void){	}
};
