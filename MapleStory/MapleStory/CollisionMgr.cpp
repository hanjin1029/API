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
					int iHeight = rcCol.bottom  - rcCol.top;
					int iWidth = rcCol.right  - rcCol.left; 

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
							
							(*iter2)->SetDamage((*iter)->GetInfo().iAttack);
							((CMonster*)(*iter2))->MonsterHit();
							(*iter)->SetCount((*iter2)->GetCount());

								pSkill->push_back(CObjFactory<CMySkill>::CreateObj((*iter2)->GetInfo().fX,(*iter2)->GetInfo().fY,303.f,201.f,(*iter)->GetInfo().iAttack,"Bolt_Hit"));
								if(pSkill->back()->GetstrKey() == "Bolt_Hit")
								{
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX, (*iter2)->GetInfo().fY,33.f,38.f,iThousand,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 33, (*iter2)->GetInfo().fY,33.f,38.f,iHundred,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 66.f, (*iter2)->GetInfo().fY,33.f,38.f,iTen,"Damage"));
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
								}

							((CMonster*)(*iter2))->SetState(ST_DAMAGE);
							if((*iter)->GetCount() == 3)
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
							
							if((*iter)->GetCount() == 3 )
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
								pSkill->push_back(CObjFactory<CDamageSkin>::CreateObj((*iter2)->GetInfo().fX + 99.f, (*iter2)->GetInfo().fY,33.f,38.f,iOne,"Damage"));
	
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
			{
		
				++iter2;
				
		
			}

			
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
					int iHundred =(((*iter)->GetInfo().fHP)/10) / 100;
					int	iTen =((*iter)->GetInfo().iAttack - (iHundred * 100) )/ 10;
					int iOne = (*iter)->GetInfo().iAttack - ((iHundred*100) + (iTen*10));
			
					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 

					if(iWidth > iHeight) // 상하충돌
					{
						if(!pPlayer->GetHit())				
						pPlayer->SetDamage(100);
									
					}

					else // 좌우
					{
					if(!pPlayer->GetHit())	
					{
						pPlayer->SetDamage(100);
					
						pMonster->push_back(CObjFactory<CDamageSkin>::CreateObj(pPlayer->GetInfo().fX , pPlayer->GetInfo().fY,33.f,38.f, iHundred,"Damage"));
					
						pPlayer->Sethit(true);
						if(pPlayer->GetInfo().fX < (*iter)->GetInfo().fX)
						{
							pPlayer->SetMinusX(iWidth);	
						}
						if(pPlayer->GetInfo().fX > (*iter)->GetInfo().fX)
						{
							pPlayer->SetPlusY(iWidth);
						}
						
					}
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

			if((*iter)->iDrawID == 2)
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

						/*	if(pPlayer->GetInfo().fY < (*iter)->fY &&
								((CPlayer*)pPlayer)->GetstrKey() == "Player_DOWN" &&
								((CPlayer*)pPlayer)->GetJump() == true)
							{
								pPlayer->SetPlusY(10);
								
							}*/
					/*
							if(((CPlayer*)pPlayer)->GetstrKey() == "Player_DOWN")
							{
								if(((CPlayer*)pPlayer)->GetJump() == true)
								{								
									pPlayer->SetPlusY(10);
									((CPlayer*)(pPlayer))->SetGravity(false);
								}

							}*/
					}
				
			
				}

		
			}

			if((*iter)->iDrawID == 3 && (*iter)->iDrawID != 0)
			{
				
				if(IntersectRect(&rcCol, &(pPlayer)->GetRect(), &(*iter)->GetRect()))
				{
					
					int iHeight = rcCol.bottom  - rcCol.top ;
					int iWidth = rcCol.right  - rcCol.left ; 
					
					if(iWidth > iHeight) // 상하충돌
					{

						if(pPlayer->GetInfo().fX + pPlayer->GetInfo().fCX/2.f < (*iter)->fX + (*iter)->fCX/2.f 	
							&& pPlayer->GetInfo().fX + pPlayer->GetInfo().fCX/2.f > (*iter)->fX - (*iter)->fCX/2.f 	)
						{
						if(((CPlayer*)pPlayer)->GetRope() == true)
						if(GetAsyncKeyState(VK_UP) && pPlayer->GetInfo().fX <= (*iter)->fX +10 && pPlayer->GetInfo().fX >= (*iter)->fX -10)
						{
						((CPlayer*)(pPlayer))->SetGravity(false);
						((CPlayer*)pPlayer)->SetState(ST_UP,2,2,80);
										
						pPlayer->SetMinusY(5);		
						}
						}
						else if(GetAsyncKeyState(VK_DOWN))
						{
							if(((CPlayer*)pPlayer)->GetRope() == true)
							{
							((CPlayer*)pPlayer)->SetState(ST_UP,2,2,80);
							pPlayer->SetPlusY(2);
							}
							
						}
										
					}
					else // 좌우충돌
					{
						if(((CPlayer*)pPlayer)->GetRope() == true)
						{
							if(GetAsyncKeyState(VK_UP) && pPlayer->GetInfo().fX <= (*iter)->fX +10 && pPlayer->GetInfo().fX >= (*iter)->fX -10)
						{

							((CPlayer*)(pPlayer))->SetGravity(false);
							((CPlayer*)pPlayer)->SetState(ST_UP,2,2,80);
							pPlayer->SetMinusY(5);
		
						
						}
						
						else if(GetAsyncKeyState(VK_DOWN))
						{
							if(((CPlayer*)pPlayer)->GetRope() == true)
							{
							((CPlayer*)pPlayer)->SetState(ST_UP,2,2,80);
							pPlayer->SetPlusY(2);
							}
						}
						}
					}
					
				}

			

				else
					++iter;
			}
		}		
}



