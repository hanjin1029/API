#include "StdAfx.h"
#include "MyEdit.h"
#include "BitBmp.h"

CMyEdit::CMyEdit(void)
{
	m_fScrollX = 0.f;
	m_fScrollY = 0.f;
	
}

CMyEdit::~CMyEdit(void)
{
	Release();
}


void	CMyEdit::Initialize(void)
{
	m_fSpeed   = 10.f;

	LoadData();

	//m_BitMap["Back"] = (new CBitBmp)->LoadBmp(L"../Texture/BackBuffer.bmp");
	//m_BitMap["Tile"] = (new CBitBmp)->LoadBmp(L"../Texture/Tile.bmp");
	
	if (m_vecTile.size() == 0)
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
	}

	m_vecBmp.push_back((new CBitBmp)->LoadBmp(L"../Texture/BackBuffer.bmp"));
	m_vecBmp.push_back((new CBitBmp)->LoadBmp(L"../Texture/Tile.bmp"));
	m_vecBmp.push_back((new CBitBmp)->LoadBmp(L"../Texture/town.bmp"));
	

	

}

int	CMyEdit::Progress(void)
{
	KeyCheck();	
	Scroll();

	if(GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SaveData();
		MessageBox(g_hWnd,L"확인", L"메세지", MB_OK);
		return 0;
	}

	return 0;

}

void	CMyEdit::Render(HDC	hdc)
{
	TCHAR szBuf[128] = L"";

	BitBlt(m_vecBmp[0]->GetMemDC(), (int)(0 + m_fScrollX) , (int)0, (int)3090.f, (int)600.f,
	m_vecBmp[2]->GetMemDC(), (int)0 , (int)0, SRCCOPY);

	int iCountX = WINCX / TILECX +1;
	int iCountY = WINCY/ TILECY + 1;


	for(int i = 0; i < iCountY; ++i)
	{
		for(int j = 0; j < iCountX; ++j)
		{
			int iCullX = int (-m_fScrollX) / TILECX;
			int iCullY = int (-m_fScrollY) / TILECY;

			int iIndex = (i + iCullY) * TILEX + (j + iCullX);

				if(iIndex < 0 || iIndex >= TILEX * TILEY)
					break;

					/*BitBlt(m_vecBmp[0]->GetMemDC(), 
						int((m_vecTile[iIndex]->fX - TILECX / 2.f) + m_fScrollX),
						int((m_vecTile[iIndex]->fY - TILECY / 2.f) + m_fScrollY),
						TILECX, 
						TILECY,
						m_vecBmp[1]->GetMemDC(),
						m_vecTile[iIndex]->iDrawID * TILECX, 
						0, SRCCOPY);*/

					TransparentBlt(m_vecBmp[0]->GetMemDC(),
						int((m_vecTile[iIndex]->fX - TILECX / 2.f) + m_fScrollX),
						int((m_vecTile[iIndex]->fY - TILECY / 2.f) + m_fScrollY),
						TILECX, 
						TILECY,
						m_vecBmp[1]->GetMemDC(),
						m_vecTile[iIndex]->iDrawID * TILECX,
						0,
						TILECX, 
						TILECY,
						RGB(0,255,0));
						


					wsprintf(szBuf, L"%d", iIndex);
					TextOut(m_vecBmp[0]->GetMemDC(), 
						int((m_vecTile[iIndex]->fX - TILECX / 2.f) + m_fScrollX),
						int((m_vecTile[iIndex]->fY - TILECY / 2.f) + m_fScrollY),
						szBuf, lstrlen(szBuf));
				
		}
	}


	BitBlt(hdc, 0 , 0, WINCX, WINCY,
	m_vecBmp[0]->GetMemDC(), 0, 0, SRCCOPY);

}

void CMyEdit::Release(void)
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


TILE* CMyEdit::CreateTile(float _fX, float _fY)
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

void CMyEdit::Picking(void)
{
	int		iX = (GetMouse().x -(int)m_fScrollX) / TILECX;
	int		iY = (GetMouse().y -(int)m_fScrollY) / TILECY;

	int		iIndex = iY * TILEX + iX;

	if(iIndex < 0 || iIndex >= TILEX * TILEY)
		return;

	m_vecTile[iIndex]->iOption = 1;
	m_vecTile[iIndex]->iDrawID = 1;


	
}

void CMyEdit::PickingOff(void)
{
	int		iX = (GetMouse().x -(int)m_fScrollX) / TILECX;
	int		iY = (GetMouse().y -(int)m_fScrollY) / TILECY;

	int		iIndex = iY * TILEX + iX;


	if(iIndex < 0 || iIndex >= TILEX * TILEY)
		return;

	m_vecTile[iIndex]->iOption = 0;
	m_vecTile[iIndex]->iDrawID = 0;

	
	
}



void CMyEdit::KeyCheck(void)
{
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		Picking();
		return;
	}
	if (GetAsyncKeyState(VK_RBUTTON))
	{
		PickingOff();
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

void CMyEdit::Scroll(void)
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

void CMyEdit::SaveData(void)
{
	HANDLE		hFile  = NULL;
	DWORD		dwByte = 0;

	hFile = CreateFile(L"../Data/Map.dat",		// 파일이 저장되는 경로
						GENERIC_WRITE,			// 쓰기 전용 모드
						0,						// 공유 모드 설정 값
						NULL,					// 보안 상태 설정 값
						CREATE_ALWAYS,			// 만드는 상태 지정 값
						FILE_ATTRIBUTE_NORMAL,	// 파일의 특정 정보를 삽입(일반 파일 지정상태)			
						NULL);					// 기존에 존재하는 파일과 동등한 특성을 가진 새파일을 생성(필요 없음)

	for(vector<TILE*>::iterator	iter = m_vecTile.begin();
		iter != m_vecTile.end(); ++iter)
	{
		WriteFile(hFile, (*iter), sizeof(TILE), &dwByte, NULL);
	}

	CloseHandle(hFile);

}



void CMyEdit::LoadData(void)
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

void CMyEdit::SetTile(vector<TILE*> pTile)
{
	m_vecTile = pTile;
}