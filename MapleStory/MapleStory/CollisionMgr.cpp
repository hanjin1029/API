#include "StdAfx.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "Monster.h"
#include "DamageSkin.h"
#include "MyEdit.h"
#include "ObjFactory.h"
#include "MySkill.h"


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
				if(IntersectRect(&rcCol, &(*iter)->GetRect( ), &(*iter2)->GetRect()))
				{
					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 

					int iThousand = (*iter)->GetInfo().iAttack / 1000;
					int iHundred = ((*iter)->GetInfo().iAttack - (iThousand * 1000))/100 ;
					int	iTen =((*iter)->GetInfo().iAttack  - iThousand * 1000 - (iHundred*100)) / 10;
					int iOne = (*iter)->GetInfo().iAttack - (iThousand * 1000) - (iHundred*100) - (iTen*10);
					
				
					if(iWidth > iHeight) // 상하충돌
					{
						
						if(!(*iter)->GetHit())
						{
						
							if((*iter)->GetstrKey() == "Bolt_RIGHT" ||  (*iter)->GetstrKey() =="Bolt_LEFT")						
							{
								(*iter)->SetCount((*iter2)->GetCount());
							
							for(int i = (*iter)->GetCount(); i<3; ++i)
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();
							
								pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,303.f,201.f,(*iter)->GetInfo().iAttack,"Bolt_Hit"));
								if(pSkill->back()->GetstrKey() == "Bolt_Hit")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}
							
							
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							if((*iter)->GetCount() == 5)
							{
							(*iter)->Sethit(true);
							}
							}
								
							}
							
							if((*iter)->GetstrKey() == "Skill2_LEFT" ||  (*iter)->GetstrKey() =="Skill2_RIGHT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();			
							(*iter)->SetCount((*iter2)->GetCount());
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,239.f,278.f,0,"Skill2_Hit"));
								if(pSkill->back()->GetstrKey() == "Skill2_Hit")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	

								}
								if((*iter)->GetCount() == 3)
								{
								(*iter)->Sethit(true);
								}
							}

							if((*iter)->GetstrKey() == "Skill3Ball_LEFT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,212.f,205.f,0,"Skill3Hit_LEFT"));
								if(pSkill->back()->GetstrKey() == "Skill3Hit_LEFT")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	

								}
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}

							else if((*iter)->GetstrKey() == "Skill3Ball_RIGHT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,212.f,205.f,0,"Skill3Hit_RIGHT"));
								if(pSkill->back()->GetstrKey() == "Skill3Hit_RIGHT")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}

							if((*iter)->GetstrKey() == "Skill1Ball_RIGHT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitR"));
								if(pSkill->back()->GetstrKey() == "Skill1HitR")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}
							
							else if((*iter)->GetstrKey() == "Skill1Ball_LEFT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitL"));
								if(pSkill->back()->GetstrKey() == "Skill1HitL")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}
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
																

							(*iter)->SetCount((*iter2)->GetCount());

							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							
							((CMonster*)(*iter2))->MonsterHit();
							
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,303.f,201.f,20,"Bolt_Hit"));
							if(pSkill->back()->GetstrKey() == "Bolt_Hit")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							if((*iter)->GetCount()==5)
							{
							(*iter)->Sethit(true);
							}
							}
						
							if((*iter)->GetstrKey() == "Skill2_LEFT" ||  (*iter)->GetstrKey() =="Skill2_RIGHT")						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();
							(*iter)->SetCount((*iter2)->GetCount());
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,239.f,278.f,0,"Skill2_Hit"));
								if(pSkill->back()->GetstrKey() == "Skill2_Hit")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_bacdk(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							if((*iter)->GetCount() == 3)
							{
							(*iter)->Sethit(true);
							}
							}
							if((*iter)->GetstrKey() == "Skill3Ball_LEFT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,212.f,205.f,0,"Skill3Hit_LEFT"));
								if(pSkill->back()->GetstrKey() == "Skill3Hit_LEFT")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	

								}
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}

							else if((*iter)->GetstrKey() == "Skill3Ball_RIGHT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,212.f,205.f,0,"Skill3Hit_RIGHT"));
								if(pSkill->back()->GetstrKey() == "Skill3Hit_RIGHT")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							(*iter)->Sethit(true);
							}
							
							if((*iter)->GetstrKey() == "Skill1Ball_RIGHT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();		
							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitR"));
								if(pSkill->back()->GetstrKey() == "Skill1HitR")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	

								}
							
							(*iter)->Sethit(true);
							}
							
							else if((*iter)->GetstrKey() == "Skill1Ball_LEFT" )						
							{
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();						
							pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,373.f,224.f,0,"Skill1HitL"));
							if(pSkill->back()->GetstrKey() == "Skill1HitL")
							{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	

							}
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
		}	
	}
}

void CCollisionMgr::MonsterCollision(CObj* pPlayer, list<CObj*>* pMonster)
{
	RECT		rcCol;

		for(list<CObj*>::iterator iter = pMonster->begin();
			iter != pMonster->end(); )

		{

		
				if(IntersectRect(&rcCol, &(pPlayer)->GetRect(), &(*iter)->GetRect()))
				{
					int iHundred = (*iter)->GetInfo().iAttack / 100;
					int	iTen =((*iter)->GetInfo().iAttack - (iHundred * 100) )/ 10;
					int iOne = (*iter)->GetInfo().iAttack - ((iHundred*100) + (iTen*10));
					
				
					
	
					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 

					if(iWidth > iHeight) // 상하충돌
					{
										
						pPlayer->SetDamage(100);
									
					}

					else // 좌우
					{
						
						pPlayer->SetDamage(100);
						pPlayer->SetMinusX(iWidth);	
						pMonster->push_back(CObjFactory<CDamageSkin>::CreateObj(pPlayer->GetInfo().fX , pPlayer->GetInfo().fY,33.f,38.f, iHundred,"Damage"));
					
					
					}
					
				
				}
				else
					++iter;

		
			
		}
	

}

void CCollisionMgr::TileCollision(CObj* pPlayer, vector<TILE*>* pTile)
{
	RECT		rcCol;


		for(vector<TILE*>::iterator	iter = pTile->begin();
			iter != pTile->end(); ++iter)
		{
			
			if((*iter)->iDrawID == 1)
			{
				if(IntersectRect(&rcCol, &(pPlayer)->GetRect(), &(*iter)->GetRect()))
				{
					

					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 

					if(iWidth > iHeight) // 상하충돌
					{
				
							pPlayer->SetMinusY(iHeight);
							((CPlayer*)(pPlayer))->SetJump(false);
							((CPlayer*)(pPlayer))->SetGravity(true);
							((CPlayer*)(pPlayer))->SetTime(0.f);
							
									
					}
					
				
				}
		
			}
		}
	
}