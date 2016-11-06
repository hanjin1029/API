#pragma once
#include "Obj.h"

class CCollisionMgr
{


public:
	static void TileCollision(list<CObj*>* pTemp, vector<TILE*>*	Tile);
	static void SkillCollision(list<CObj*>* pSkill, list<CObj*>* pMonster);
	static void MonsterCollision(list<CObj*>* pPlayer, list<CObj*>* pMonster);
	static void TileCollision(CObj* pPlayer, vector<TILE*>*	pTile);

public:
	CCollisionMgr(void);
	~CCollisionMgr(void);
};
