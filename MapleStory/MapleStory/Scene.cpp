#include "StdAfx.h"
#include "Scene.h"
#include "ObjFactory.h"
#include "Player.h"

CObj*	CScene::m_pPlayer(NULL);
CObj*	CScene::m_pInven(NULL);
CObj*	CScene::m_pEquip(NULL);
CScene::CScene(void)
{
	
}

CScene::~CScene(void)
{

	for(map<string, CBitBmp*>::iterator	iter = m_BitMap.begin();
		iter != m_BitMap.end(); ++iter)
	{
		::Safe_Delete(iter->second);
	}
	m_BitMap.clear();
}


