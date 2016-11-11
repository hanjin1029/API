#include "StdAfx.h"
#include "Field2.h"
#include "Back.h"
#include "Player.h"
#include "ObjFactory.h"
#include "Monster.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "RenderMgr.h"
#include "MySkill.h"
#include "PlayerUI.h"
#include "CollisionMgr.h"
#include "Portal.h"
#include "Inventory.h"
#include "Equip.h"
#include "Device.h"


CField2::CField2(void)
: m_fCX(1510.f)
, m_fCY(768.f)
{
}

CField2::~CField2(void)
{
	Release();
}


void CField2::Initialize(void)
{
	LoadData();

	CDevice::GetInstance()->LoadWave(L"../Sound/Boss.wav");
	CDevice::GetInstance()->SoundStop(2);
	CDevice::GetInstance()->SoundPlay(8,1);


	m_BitMap["back"] = (new CBitBmp)->LoadBmp(L"../Texture/BackBuffer.bmp");
	
	m_BitMap["Portal"] = (new CBitBmp)->LoadBmp(L"../Texture/Portal.bmp");
	m_BitMap["DamageSkin1"] = (new CBitBmp)->LoadBmp(L"../Texture/DamageSkin00.bmp");
	m_BitMap["UI"] = (new CBitBmp)->LoadBmp(L"../Texture/UI/Info_56.bmp");
	m_BitMap["Inven"] = (new CBitBmp)->LoadBmp(L"../Texture/UI/Inven_1.bmp");
	m_BitMap["Equip"] = (new CBitBmp)->LoadBmp(L"../Texture/UI/Equip_0.bmp");
	
	
	m_BitMap["Player_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerRR.bmp");
	m_BitMap["Player_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerL.bmp");
	m_BitMap["Player_UP"]  = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerRR.bmp");
	m_BitMap["Bolt_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill2BoltR.bmp");
	m_BitMap["Bolt_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill2BoltL.bmp");
	m_BitMap["Bolt_Hit"] = (new CBitBmp)->LoadBmp(L"../Texture/SKill2/Skill2BoltHit.bmp");
	m_BitMap["Skill1Effect_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill1EffectL.bmp");
	m_BitMap["Skill1Effect_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill1EffectR.bmp");
	m_BitMap["Skill1Ball_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/SKill2/Skill1BallL.bmp");
	m_BitMap["Skill1Ball_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/SKill2/Skill1BallR.bmp");
	m_BitMap["Skill1HitR"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill1HitR.bmp");
	m_BitMap["Skill1HitL"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill1HitL.bmp");
	m_BitMap["Skill2_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Annihilation_LEFT.bmp");
	m_BitMap["Skill2_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Annihilation_RIGHT.bmp");
	m_BitMap["Skill2_Hit"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill2Hit.bmp");
	m_BitMap["Skill3Effect_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill3EffectR.bmp");
	m_BitMap["Skill3Effect_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill3EffectL.bmp");
	m_BitMap["Skill3Ball_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/SKill2/Skill3BallL.bmp");
	m_BitMap["Skill3Ball_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/SKill2/Skill3BallR.bmp");
	m_BitMap["Skill3Hit_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill3hitR.bmp");
	m_BitMap["Skill3Hit_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill3hitL.bmp");
	
	m_BitMap["Field2"] = (new CBitBmp)->LoadBmp(L"../Texture/Field2.bmp");

	m_BitMap["BossL"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/SaverTooth_L.bmp");
	m_BitMap["BossR"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/SaverTooth_R.bmp");

	m_BitMap["Arrow"] = (new CBitBmp)->LoadBmp(L"../Texture/Item/ITEM_Weapon_ID1_0.bmp");
	m_BitMap["Armor"] = (new CBitBmp)->LoadBmp(L"../Texture/Item/ITEM_Wear_ID2_0.bmp");

	m_pBack = CObjFactory<CBack>::CreateObj(0,0,m_fCX,m_fCY,"Field2");
	

	m_pPlayer->SetPos(320.f, 514.f);
	((CPlayer*)m_pPlayer)->SetSkill(&m_ObjList[OBJ_SKILL]);
	m_ObjList[OBJ_UI].push_back(CObjFactory<CPlayerUI>::CreateObj());

	
	

	((CPlayer*)m_pPlayer)->SetScrollX2(0.f);
	((CPlayer*)m_pPlayer)->SetScrollY2(-120.f);
	((CPlayer*)m_pPlayer)->SetOffsetX(400.f);
	((CPlayer*)m_pPlayer)->SetOffsetY(520.f);


	CObj*	pMonster = CreateMonster(800.f,414.f,553.f, 457.f, 60000.f,"BossL");
	m_ObjList[OBJ_MONSTER].push_back(pMonster);

	//CObjMgr::GetInst()->GetObj(OBJ_PLAYER);
	CObj::SetBitMap(&m_BitMap);

}

int CField2::Progress(void)
{
	m_pBack->Progress();
	m_pPlayer->Progress();

	//if(PtInRect(&(m_pInven->GetRect()), GetMouse()))
	//{
	//	if(GetAsyncKeyState(VK_LBUTTON))
	//	{
	//		m_pInven->SetPos((float)GetMouse().x, (float)GetMouse().y);
	//	}
	//	if(GetAsyncKeyState(VK_RBUTTON))
	//	{
	//		
	//	}

	//}

	//if(PtInRect(&(m_pEquip->GetRect()), GetMouse()))
	//{
	//	if(GetAsyncKeyState(VK_LBUTTON))
	//	{
	//		m_pEquip->SetPos((float)GetMouse().x, (float)GetMouse().y);
	//	}

//	}
	m_pInven->Progress();
	m_pEquip->Progress();

	((CPlayer*)m_pPlayer)->SetScrollX(m_fCX);
	((CPlayer*)m_pPlayer)->SetScrollY(m_fCY);
	
	if(GetAsyncKeyState(VK_RETURN))
		CDevice::GetInstance()->SoundStop(8);

	m_iX = (int)m_pPlayer->GetInfo().fX;
	m_iY = (int)m_pPlayer->GetInfo().fY;
	m_iScrollX = (int)(((CPlayer*)m_pPlayer)->GetScrollX());
	m_iScrollY = (int)(((CPlayer*)m_pPlayer)->GetScrollY());
	m_iOffsetX = (int)(((CPlayer*)m_pPlayer)->GetOffSetX());
	m_iOffsetY = (int)(((CPlayer*)m_pPlayer)->GetOffSetY());

	for(size_t i = 0; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			(*iter)->Progress();

		
			CRenderMgr::GetInst()->AddObject(*iter);

			
		}
	}

	if(m_ObjList[OBJ_MONSTER].empty())
	{
		//Release();
		DestroyWindow(g_hWnd);
	}
			CCollisionMgr::TileCollision(m_pPlayer,&m_vecTile);
			CCollisionMgr::SkillCollision(&m_ObjList[OBJ_SKILL], &m_ObjList[OBJ_MONSTER]);
			return 0;

}

void CField2::Render(HDC hdc)
{
	
	m_pBack->Render(m_BitMap["back"]->GetMemDC());

	m_pPlayer->Render(m_BitMap["back"]->GetMemDC());

	
	if((GetKeyState('I') & 0x0001))
	{
		m_pInven->Render(m_BitMap["back"]->GetMemDC());
		

	}

	if((GetKeyState('E') & 0x0001))
	{
		m_pEquip->Render(m_BitMap["back"]->GetMemDC());
		

	}
	
	
	for(size_t i = 0; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_BitMap["back"]->GetMemDC());
		}

	}


				
BitBlt(hdc, 
		0, 0, 
		WINCX , WINCY, 
		m_BitMap["back"]->GetMemDC(), 
		0, 0, SRCCOPY);
}

void CField2::Release(void)
{

		::Safe_Delete(m_pBack);
		::Safe_Delete(m_pPlayer);
		::Safe_Delete(m_pInven);
		::Safe_Delete(m_pEquip);


	for(size_t i = 0; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			::Safe_Delete(*iter);
		}
		m_ObjList[i].clear();
	}

	for(vector<TILE*>::iterator	iter = m_vecTile.begin();
		iter != m_vecTile.end(); ++iter)
	{
		::Safe_Delete(*iter);
	
	}
	
}


void CField2::LoadData(void)
{
	HANDLE		hFile = NULL;
	DWORD		dwByte = 0;

	
	hFile = CreateFile(L"../Data/Map7.dat", 
		GENERIC_READ, 
		0, 
		NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		NULL);

	while(true)
	{
		TILE*		pTile = new TILE;

		ReadFile(hFile, pTile, sizeof(TILE), &dwByte, NULL);

		if(dwByte == 0)
		{
			::Safe_Delete(pTile);
			break;
		}

		m_vecTile.push_back(pTile);
	}

	

	CloseHandle(hFile);
}

CObj* CField2::CreateMonster(float _fX, float _fY, float _fCX, float _fCY, float _fHP, string _strMonster)
{
	CObj* pMonster = CObjFactory<CMonster>::CreateObj(_fX, _fY, _fCX, _fCY, _fHP, _strMonster);
	return pMonster;

}