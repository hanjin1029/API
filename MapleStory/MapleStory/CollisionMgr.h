#pragma once
#include "Obj.h"

class CCollisionMgr
{
private:
	static DWORD	m_dwTime;

public:
	static void TileCollision(list<CObj*>* pTemp, vector<TILE*>*	Tile);
	static void SkillCollision(list<CObj*>* pSkill, list<CObj*>* pMonster);
	static void MonsterCollision(list<CObj*>* pPlayer, list<CObj*>* pMonster);

public:
	CCollisionMgr(void);
	~CCollisionMgr(void);
};
