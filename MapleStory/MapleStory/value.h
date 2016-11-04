#pragma once

extern HWND g_hWnd;

const int WINCX = 800;
const int WINCY = 600;

const int TILEX = 77;
const int TILEY = 15;

const int TILECX = 40;
const int TILECY = 40;



// Key °ª

const DWORD		KEY_LEFT	= 0x00000001;
const DWORD		KEY_RIGHT	= 0x00000002;
const DWORD		KEY_UP		= 0x00000004;
const DWORD		KEY_DOWN	= 0x00000008;
const DWORD		KEY_CONTROL	= 0x00000010;
const DWORD		KEY_RETURN	= 0x00000020;
const DWORD		KEY_A		= 0x00000040;
const DWORD		KEY_Z		= 0x00000080;
const DWORD		KEY_S		= 0x00000100;
const DWORD		KEY_D		= 0x00000200;
const DWORD		KEY_F		= 0x00000400;


// state °ª

const DWORD		ST_STAND	= 0x00000001;
const DWORD		ST_WALK		= 0x00000002;
const DWORD		ST_ATTACK	= 0x00000004;
const DWORD		ST_DAMAGE	= 0x00000008;
const DWORD		ST_DEATH	= 0x00000010;
const DWORD		ST_UP		= 0x00000020;
const DWORD		ST_SKILL	= 0x00000040;
const DWORD		ST_DOWN		= 0x00000080;
const DWORD		ST_JUMP		= 0x00000100;