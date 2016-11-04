#include "StdAfx.h"
#include "MapEdit.h"
#include "BitBmp.h"



CMapEdit::CMapEdit(void)
{
	m_fScrollX = 0.f;
	m_fScrollY = 0.f;

}

CMapEdit::~CMapEdit(void)
{
	Release();
}

void CMapEdit::Initialize(void)
{
	for(int i = 0; i < TILEY; ++i)
	{
		for(int j = 0; j < TILEX; ++j)
		{
			float fX = float((TILECX * j) + (TILECX / 2));
			float fY = float((TILECY * i) + (TILECY / 2));

			m_vecTile.push_back(CreateTile(fX, fY));
		}
	}

	m_vecBmp.push_back((new CBitBmp)->LoadBmp(L"../Texture/back.bmp"));
	m_vecBmp.push_back((new CBitBmp)->LoadBmp(L"../Texture/Tile.bmp"));

	

	m_fSpeed   = 10.f;
	
}

void CMapEdit::Progress(void)
{
	KeyCheck();	
	Scroll();
}

void CMapEdit::Render(HDC hdc)
{
	TCHAR szBuf[128] = L"";


	for(int i = 0; i < TILEY; ++i)
	{
		for(int j = 0; j < TILEX; ++j)
		{
			int iIndex = i * TILEX + j;

			BitBlt(m_vecBmp[0]->GetMemDC(), 
				int((m_vecTile[iIndex]->fX - TILECX / 2.f) + m_fScrollX),
				int((m_vecTile[iIndex]->fY - TILECY / 2.f) + m_fScrollY),
				TILECX, 
				TILECY,
				m_vecBmp[1]->GetMemDC(),
				m_vecTile[iIndex]->iDrawID * TILECX, 
				0, SRCCOPY);

			wsprintf(szBuf, L"%d", iIndex);
			TextOut(m_vecBmp[0]->GetMemDC(), 
				int((m_vecTile[iIndex]->fX - TILECX / 2.f) + m_fScrollX),
				int((m_vecTile[iIndex]->fY - TILECY / 2.f) + m_fScrollY),
				szBuf, lstrlen(szBuf));

		}
	}

	BitBlt(hdc, 0, 0, WINCX, WINCY, m_vecBmp[0]->GetMemDC(), 0, 0, SRCCOPY);

}
void CMapEdit::Release(void)
{
	for(size_t i = 0; i < m_vecBmp.size(); ++i)
	{
		::Safe_Delete(m_vecBmp[i]);
	}
	m_vecBmp.clear();
	vector<CBitBmp*>().swap(m_vecBmp);

	for(size_t i = 0; i < m_vecTile.size(); ++i)
	{
		::Safe_Delete(m_vecTile[i]);
	}
	m_vecTile.clear();
	vector<TILE*>().swap(m_vecTile);
	
}
TILE* CMapEdit::CreateTile(float _fX, float _fY)
{
	TILE*		pTile = new TILE;

	pTile->fX = _fX;
	pTile->fY = _fY;
	pTile->fCX = TILECX;
	pTile->fCY = TILECY;
	pTile->iOption  = 0;
	pTile->iDrawID  = 0;

	return pTile;
}

void CMapEdit::Picking(void)
{
	int		iX = (GetMouse().x -(int)m_fScrollX) / TILECX;
	int		iY = (GetMouse().y -(int)m_fScrollY) / TILECY;

	int		iIndex = iY * TILEX + iX;

	if(iIndex < 0 || iIndex >= TILEX * TILEY)
		return;

	m_vecTile[iIndex]->iOption = 1;
	m_vecTile[iIndex]->iDrawID = 1;

}

void CMapEdit::KeyCheck(void)
{
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		Picking();
		return;
	}

	if(GetAsyncKeyState(VK_LEFT))
		m_fScrollX += m_fSpeed;

	if(GetAsyncKeyState(VK_RIGHT))
		m_fScrollX -= m_fSpeed;

	if(GetAsyncKeyState(VK_UP))
		m_fScrollY += m_fSpeed;

	if(GetAsyncKeyState(VK_DOWN))
		m_fScrollY -= m_fSpeed;

}

void CMapEdit::Scroll(void)
{
	if(m_fScrollX > 0)
		m_fScrollX = 0.f;

	if(m_fScrollY > 0)
		m_fScrollY = 0.f;

	if(m_fScrollX < WINCX - (TILECX * TILEX))
		m_fScrollX = WINCX - (TILECX * TILEX);

	if(m_fScrollY < WINCY - (TILECY * TILEY))
		m_fScrollY = WINCY - (TILECY * TILEY);
}
