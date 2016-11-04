#include "StdAfx.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "Monster.h"
#include "DamageSkin.h"
#include "MyEdit.h"
#include "ObjFactory.h"
#include "MySkill.h"

DWORD	CCollisionMgr::m_dwTime(GetTickCount());

CCollisionMgr::CCollisionMgr(void)
{
}

CCollisionMgr::~CCollisionMgr(void)
{
}

void CCollisionMgr::TileCollision(list<CObj*>* pTemp, vector<TILE*>* Tile)
{
	RECT		rcCol;

	for(list<CObj*>::iterator iter = pTemp->begin();
			iter != pTemp->end(); ++iter )
	{
	
		for(vector<TILE*>::iterator	iter2 = Tile->begin();
			iter2 != Tile->end(); ++iter2)
		{
			

			if((*iter2)->iDrawID == 1)
			{
				if(IntersectRect(&rcCol, &(*iter)->GetRect(), &(*iter2)->GetRect()))
				{
					

					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 

					if(iWidth > iHeight) // 상하충돌
					{
				
							(*iter)->SetMinusY(iHeight);
							((CPlayer*)(*iter))->SetJump(false);
							((CPlayer*)(*iter))->SetGravity(true);
							((CPlayer*)(*iter))->SetTime(0.f);
							
									
					}
					
				
				}
		
			}
		}
	}
}


void CCollisionMgr::SkillCollision(list<CObj*>* pSkill, list<CObj*>* pMonster)
{
	RECT		rcCol;

	
	for(list<CObj*>::iterator iter = pSkill->begin();
			iter != pSkill->end(); ++iter )
	{
	
		for(list<CObj*>::iterator iter2 = pMonster->begin();
			iter2 != pMonster->end(); )

		{
		
				if(IntersectRect(&rcCol, &(*iter)->GetRect(), &(*iter2)->GetRect()))
				{
				
					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 
					
				
					if(iWidth > iHeight) // 상하충돌
					{
						if(!(*iter)->GetHit())
						{
							
							if((*iter)->GetstrKey() == "Bolt_RIGHT" ||  (*iter)->GetstrKey() =="Bolt_LEFT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,303.f,201.f,0,"Bolt_Hit"));
							(*iter)->Sethit(true);
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
					
							}

							
							if((*iter)->GetstrKey() == "Skill2_LEFT" ||  (*iter)->GetstrKey() =="Skill2_RIGHT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
						//	pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,301.f,201.f,0,"Bolt_Hit"));

							(*iter)->Sethit(true);
							}

							if((*iter)->GetstrKey() == "Skill3Ball_LEFT" ||  (*iter)->GetstrKey() =="Skill3Ball_RIGHT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							//pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,301.f,201.f,0,"Bolt_Hit"));
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}

							if((*iter)->GetstrKey() == "Skill1Ball_RIGHT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitR"));
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}
							
							else if((*iter)->GetstrKey() == "Skill1Ball_LEFT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitL"));
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}
							
							
						}
					
						if((*iter2)->GetInfo().fHP<=0)
						{
							::Safe_Delete(*iter2);
							iter2 = pMonster->erase(iter2);
						}
						else
						{
							++iter2;
						}
					}
		

					else // 좌우
					{
					
						
						
						if(!(*iter)->GetHit())
						{
							
							if((*iter)->GetstrKey() == "Bolt_RIGHT" ||  (*iter)->GetstrKey() =="Bolt_LEFT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,303.f,201.f,0,"Bolt_Hit"));
						
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}
					
							if((*iter)->GetstrKey() == "Skill2_LEFT" ||  (*iter)->GetstrKey() =="Skill2_RIGHT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							//pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,301.f,201.f,0,"Bolt_Hit"));
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}
							if((*iter)->GetstrKey() == "Skill3Ball_LEFT" ||  (*iter)->GetstrKey() =="Skill3Ball_RIGHT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							//pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,301.f,201.f,0,"Bolt_Hit"));
						
							(*iter)->Sethit(true);
							}
							
							if((*iter)->GetstrKey() == "Skill1Ball_RIGHT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();		
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitR"));
												
						
							(*iter)->Sethit(true);
							}
							
							else if((*iter)->GetstrKey() == "Skill1Ball_LEFT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitL"));
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}
							
							

						}
							
						if((*iter2)->GetInfo().fHP<=0)
						{
							::Safe_Delete(*iter2);
							iter2 = pMonster->erase(iter2);
						}
						else
						{
						
							++iter2;
						}

					
					
					}

				}
				else
					++iter2;
				
				if(iter == pSkill->end())
				break;
					
		}
			
			if(iter == pSkill->end())
				break;

	}

}

void CCollisionMgr::MonsterCollision(list<CObj*>* pPlayer, list<CObj*>* pMonster)
{
	RECT		rcCol;

	for(list<CObj*>::iterator iter = pPlayer->begin();
			iter != pPlayer->end(); ++iter )
	{
	
		for(list<CObj*>::iterator iter2 = pMonster->begin();
			iter2 != pMonster->end(); )

		{
		
				if(IntersectRect(&rcCol, &(*iter)->GetRect(), &(*iter2)->GetRect()))
				{
					
	
					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 

					if(iWidth > iHeight) // 상하충돌
					{
					
							
									
					}

					else // 좌우
					{
						
					

					}
					
				
				}
				else
					++iter2;

		
			
		}
	}

}