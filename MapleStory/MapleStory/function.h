#pragma once

template<typename T>
static void Safe_Delete(T& Temp)
{
	if(Temp)
	{
		delete Temp;
		Temp = NULL;
	}
}

static POINT GetMouse(void)
{
	POINT pt;

	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return pt;
}