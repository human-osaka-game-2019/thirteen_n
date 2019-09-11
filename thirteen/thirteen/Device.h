#ifndef DEVICE_H
#define DEVICE_H

#include"Engine.h"

struct INPUTSTATE
{
	DWORD now;
	DWORD pushed;
};

HRESULT BuildDxDevice(HWND* hInst, DirectX* directX);

void UpdateKeyStatus(DirectX* directX);

bool GetKeyStatus(int KeyNumber);

#endif // !1