#include "StdAfx.h"
#include "Town.h"
#include "Field1.h"
#include "ObjFactory.h"
#include "Back.h"
#include "Player.h"
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

CField1::CField1(void)
: m_fCX(1502.f)
, m_fCY(1364.f)
, m_dwTime(GetTickCount())
{

}

CField1::~CField1(void)
{
	Release();
}

void CField1::Initialize(void)
{

	LoadData();
	

	
	CDevice::GetInstance()->LoadWave(L"../Sound/Field1.wav");
	CDevice::GetInstance()->SoundStop(1);
	CDevice::GetInstance()->SoundPlay(2, 1);
	
	m_BitMap["back"] = (new CBitBmp)->LoadBmp(L"../Texture/BackBuffer.bmp");
	
	m_BitMap["Portal"] = (new CBitBmp)->LoadBmp(L"../Texture/Portal.bmp");
	m_BitMap["DamageSkin1"] = (new CBitBmp)->LoadBmp(L"../Texture/DamageSkin00.bmp");
	m_BitMap["UI"] = (new CBitBmp)->LoadBmp(L"../Texture/UI/Info_56.bmp");
	
	
	m_BitMap["Player_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerRR.bmp");
	m_BitMap["Player_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerL.bmp");
	m_BitMap["Player_UP"]  = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerUP.bmp");
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
	
	m_BitMap["Field1"] = (new CBitBmp)->LoadBmp(L"../Texture/Field1.bmp");

	m_BitMap["SlimeL"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/SlimL.bmp");
	m_BitMap["SlimeR"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/SlimR.bmp");
	m_BitMap["BlueL"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/BlueL.bmp");
	m_BitMap["BlueR"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/BlueR.bmp");


	m_pBack = CObjFactory<CBack>::CreateObj(0,0,1502.f,1364.f,"Field1");
	
	m_pPlayer->SetPos(43.f,m_fCY-300);
	m_ObjList[OBJ_UI].push_back(CObjFactory<CPlayerUI>::CreateObj());

	m_ObjList[OBJ_PORTAL].push_back(CObjFactory<CPortal>::CreateObj(40.f,m_fCY-300));
	


	//CObjMgr::GetInst()->GetObj(OBJ_PLAYER);
	CObj::SetBitMap(&m_BitMap);

}

int CField1::Progress(void)
{

	m_pBack->Progress();
	m_pPlayer->Progress();

	((CPlayer*)m_pPlayer)->SetScrollX(m_fCX);
	((CPlayer*)m_pPlayer)->SetScrollY(m_fCY);
	
	if(m_dwTime + 10000 < GetTickCount())
	{
		m_dwTime = GetTickCount();
		for (int i= 0; i<3; ++i)
		{
		CObj*	pMonster = CreateMonster(300.f+((i+1)*50),m_fCY-270,100.f,100.f,1000.f,"SlimeL");
		m_ObjList[OBJ_MONSTER].push_back(pMonster);
		}

		for (int i= 0; i<3; ++i)
		{
		CObj*	pMonster = CreateMonster(700.f+((i+1)*30), m_fCY-270,70.f,70.f,800.f,"BlueL");
		m_ObjList[OBJ_MONSTER].push_back(pMonster);
		}
	}

	for(size_t i = 0; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			(*iter)->Progress();

		
			CRenderMgr::GetInst()->AddObject(*iter);
			
		}
	}

	
	if(m_pPlayer->GetInfo().fX <= 40.f)  
	{
		if(((CPlayer*)m_pPlayer)->GetstrKey() == "Player_UP")
		{	
		CSceneMgr::GetInst()->SetScene(SC_TOWN);	
		((CPlayer*)m_pPlayer)->SetPos(2999.f, WINCY-m_fCY);
		return 0;
		}
	}

	CCollisionMgr::TileCollision(m_pPlayer,&m_vecTile);
	CCollisionMgr::SkillCollision(&m_ObjList[OBJ_SKILL], &m_ObjList[OBJ_MONSTER]);
	
	return 0;
}

void CField1::Render(HDC hdc)
{
	m_pBack->Render(m_BitMap["back"]->GetMemDC());

	m_pPlayer->Render(m_BitMap["back"]->GetMemDC());
	
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

void CField1::Release(void)
{
::Safe_Delete(m_pBack);


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

void CField1::LoadData(void)
{
	HANDLE		hFile = NULL;
	DWORD		dwByte = 0;

	
	hFile = CreateFile(L"../Data/Map4.dat", 
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

CObj* CField1::CreateMonster(float _fX, float _fY, float _fCX, float _fCY, float _fHP, string _strMonster)
{
	CObj* pMonster = CObjFactory<CMonster>::CreateObj(_fX, _fY, _fCX, _fCY, _fHP, _strMonster);
	return pMonster;

}