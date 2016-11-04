#include "StdAfx.h"
#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInst = NULL; 

CKeyMgr::CKeyMgr(void)
: m_dwPressed(0)
, m_dwKeyDown(0)
, m_dwKey(0)
{
	ZeroMemory(m_dwKeyDowns, sizeof(m_dwKeyDowns));
	ZeroMemory(m_dwPresseds, sizeof(m_dwPresseds));
}

CKeyMgr::~CKeyMgr(void)
{
}
void CKeyMgr::KeyCheck(void)
{
	m_dwKey = 0;

	if(GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_dwKey |= KEY_LEFT;

	if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_dwKey |= KEY_RIGHT;

	if(GetAsyncKeyState(VK_UP) & 0x8000)
		m_dwKey |= KEY_UP;

	if(GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_dwKey |= KEY_DOWN;

	if(GetAsyncKeyState(VK_RETURN) & 0x8000)
		m_dwKey |= KEY_RETURN;

	if(GetAsyncKeyState(VK_CONTROL) & 0x8000)
		m_dwKey |= KEY_CONTROL;

	if(GetAsyncKeyState('A') & 0x8000)
		m_dwKey |= KEY_A;

	if(GetAsyncKeyState('Z') & 0x8000)
		m_dwKey |= KEY_Z;

	if(GetAsyncKeyState('S') & 0x8000)
		m_dwKey |= KEY_S;

	if(GetAsyncKeyState('D') & 0x8000)
		m_dwKey |= KEY_D;

	
	if(GetAsyncKeyState('F') & 0x8000)
		m_dwKey |= KEY_F;

	if(GetAsyncKeyState('I') & 0x8000)
		m_dwKey |= KEY_I;

	if(GetAsyncKeyState('E') & 0x8000)
		m_dwKey |= KEY_E;

	if(GetAsyncKeyState('K') & 0x8000)
		m_dwKey |= KEY_K;
}

DWORD CKeyMgr::GetKey(void)
{
	return m_dwKey;
}

bool CKeyMgr::KeyPressed(DWORD _dwKey)
{
	if(m_dwKey & _dwKey)
	{
		m_dwPressed |= _dwKey;
		return false;
	}

	else if(m_dwPressed & _dwKey)
	{
		m_dwPressed = m_dwKey;
		return true;
	}

	return false;
}

bool CKeyMgr::KeyPressed(DWORD _dwKey, BYTE byIndex)
{
	if(m_dwKey & _dwKey)
	{
		m_dwPresseds[byIndex] |= _dwKey;
		return false;
	}

	else if(m_dwPresseds[byIndex] & _dwKey)
	{
		m_dwPresseds[byIndex] = m_dwKey;
		return true;
	}

	return false;
}

bool CKeyMgr::KeyDown(DWORD _dwKey)
{
	if(KeyPressed(_dwKey))
		m_dwKeyDown ^= _dwKey;


	if(!(m_dwKeyDown & _dwKey))
	{
		if(m_dwKey & _dwKey)
		{
			m_dwKeyDown |= _dwKey;
			return true;
		}
	}

	return false;
}

bool CKeyMgr::KeyDown(DWORD _dwKey, BYTE byIndex)
{
	if(KeyPressed(_dwKey))
		m_dwKeyDowns[byIndex] ^= _dwKey;


	if(!(m_dwKeyDowns[byIndex] & _dwKey))
	{
		if(m_dwKey & _dwKey)
		{
			m_dwKeyDowns[byIndex] |= _dwKey;
			return true;
		}
	}

	return false;
}

bool CKeyMgr::KeyCombine(DWORD _dwFirstKey, DWORD _dwSecondKey)
{
	if(m_dwKey & _dwFirstKey)
	{
		if(KeyDown(_dwSecondKey))
		{
			return true;
		}
	}

	return false;
}
