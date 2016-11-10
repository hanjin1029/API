#pragma once
#include "Obj.h"

class CCollisionMgr
{
private:
	static DWORD	m_dwTime;


public:
	static void SkillCollision(list<CObj*>* pSkill, list<CObj*>* pMonster);
	static void MonsterCollision(CObj* pPlayer, list<CObj*>* pMonster);
	static void TileCollision(CObj* pPlayer, vector<TILE*>*	pTile);


public:
	CCollisionMgr(void);
	~CCollisionMgr(void);
};
