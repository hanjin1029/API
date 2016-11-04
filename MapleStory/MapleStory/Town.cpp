#include "StdAfx.h"
#include "Town.h"
#include "ObjFactory.h"
#include "Back.h"
#include "Player.h"
#include "Monster.h"
#include "ObjMgr.h"
#include "RenderMgr.h"
#include "MySkill.h"
#include "PlayerUI.h"
#include "CollisionMgr.h"
#include "Portal.h"
#include "Device.h"

CTown::CTown(void)

{
}

CTown::~CTown(void)
{
	Release();
}

void	CTown::Initialize(void)
{

	LoadData();
	
	m_BitMap["UI"] = (new CBitBmp)->LoadBmp(L"../Texture/UI/Info_0.bmp");
	m_BitMap["Portal"] = (new CBitBmp)->LoadBmp(L"../Texture/Portal.bmp");
	m_BitMap["DamageSkin1"] = (new CBitBmp)->LoadBmp(L"../Texture/DamageNum.bmp");
	m_BitMap["DamageSkin2"] = (new CBitBmp)->LoadBmp(L"../Texture/DamageNum2.bmp");

	m_BitMap["back"] = (new CBitBmp)->LoadBmp(L"../Texture/BackBuffer.bmp");


	m_BitMap["Player_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerRR.bmp");
	m_BitMap["Player_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Player/PlayerL.bmp");
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
	m_BitMap["Skill3Effect_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill3EffectR.bmp");
	m_BitMap["Skill3Effect_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/Skill2/Skill3EffectL.bmp");
	m_BitMap["Skill3Ball_LEFT"] = (new CBitBmp)->LoadBmp(L"../Texture/SKill2/Skill3BallL.bmp");
	m_BitMap["Skill3Ball_RIGHT"] = (new CBitBmp)->LoadBmp(L"../Texture/SKill2/Skill3BallR.bmp");
	
	m_BitMap["town"] = (new CBitBmp)->LoadBmp(L"../Texture/town.bmp");
	m_BitMap["Filed1"] = (new CBitBmp)->LoadBmp(L"../Texture/04.Map/Field1.bmp");

	m_BitMap["SlimeL"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/SlimL.bmp");
	m_BitMap["SlimeR"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/SlimR.bmp");
	m_BitMap["BlueL"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/BlueL.bmp");
	m_BitMap["BlueR"] = (new CBitBmp)->LoadBmp(L"../Texture/Monster/BlueR.bmp");

	
	//사운드 파일 추가
	
	CDevice::GetInstance()->LoadWave(L"../Sound/Town.wav");

	
	//사운드 재생
	CDevice::GetInstance()->SoundPlay(1, 1);


	m_pBack = CObjFactory<CBack>::CreateObj();
	
	m_ObjList[OBJ_PLAYER].push_back(CObjFactory<CPlayer>::CreateObj());

	m_ObjList[OBJ_UI].push_back(CObjFactory<CPlayerUI>::CreateObj());


	m_ObjList[OBJ_PORTAL].push_back(CObjFactory<CPortal>::CreateObj(30.f,WINCY-160));
	m_ObjList[OBJ_PORTAL].push_back(CObjFactory<CPortal>::CreateObj(3000.f,WINCY-160));
	

	for(int i=0; i<6; ++i)
	{
	m_ObjList[OBJ_MONSTER].push_back(CObjFactory<CMonster>::CreateObj((i+1)*200, WINCY-150, 100.f, 100.f, 100.f,  "SlimeL"));
	}

	for(int i=0; i<3; ++i)
	{
		m_ObjList[OBJ_MONSTER].push_back(CObjFactory<CMonster>::CreateObj((i+1)*400, WINCY-300, 70.f, 70.f, 120.f, "BlueL"));
	
	}

	for(int i=0; i<3; ++i)
	{
		m_ObjList[OBJ_MONSTER].push_back(CObjFactory<CMonster>::CreateObj((i+1)*80, WINCY-300, 70.f, 70.f, 120.f, "BlueL"));
	
	}
	((CPlayer*)m_ObjList[OBJ_PLAYER].back())->SetSkill(&m_ObjList[OBJ_SKILL]);

	
	CObjMgr::GetInst()->SetObjList(m_ObjList);
	CObj::SetBitMap(&m_BitMap);
}

int CTown::Progress(void)
{
	m_pBack->Progress();
	
	
	if(GetAsyncKeyState(VK_RETURN))
		CDevice::GetInstance()->SoundStop(0);

	for(size_t i = 0; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			(*iter)->Progress();

		
			CRenderMgr::GetInst()->AddObject(*iter);
			
		}
	}


	
	CCollisionMgr::TileCollision(&m_ObjList[OBJ_PLAYER], &m_vecTile);
	

	CCollisionMgr::SkillCollision(&m_ObjList[OBJ_SKILL], &m_ObjList[OBJ_MONSTER]);
	
	

	//CCollisionMgr::MonsterCollision(&m_ObjList[OBJ_PLAYER], &m_ObjList[OBJ_MONSTER]);

	return 0;

}

void CTown::Render(HDC hdc)
{
	m_pBack->Render(m_BitMap["back"]->GetMemDC());
	
	

	for(size_t i = 0; i < OBJ_END; ++i)
	{
		for(list<CObj*>::iterator	iter = m_ObjList[i].begin();
			iter !=	m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_BitMap["back"]->GetMemDC());
		}
	}

	//CRenderMgr::GetInst()->RenderObj(m_BitMap["back"]->GetMemDC());



	BitBlt(hdc, 
		0, 0, 
		WINCX , WINCY, 
		m_BitMap["back"]->GetMemDC(), 
		0, 0, SRCCOPY);

	CRenderMgr::GetInst()->ObjClear();

}

void CTown::Release(void)
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

void CTown::LoadData(void)
{
	HANDLE		hFile = NULL;
	DWORD		dwByte = 0;

	
	hFile = CreateFile(L"../Data/Map.dat", 
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



CObj* CTown::CreateMonster(float _fX, float _fY, float _fCX, float _fCY, float _fHP, string _strMonster)
{
	CObj* pMonster = CObjFactory<CMonster>::CreateObj(_fX, _fY, _fCX, _fCY, _fHP, _strMonster);
	return pMonster;

}

