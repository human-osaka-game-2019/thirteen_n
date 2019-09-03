#ifndef DEVICE_H
#define DEVICE_H

#include"Engine.h"

HRESULT BuildDxDevice(HWND* hInst, DirectX* directX);

void UpdateKeyStatus(DirectX* directX);

bool GetKeyStatus(int KeyNumber);

#endif // !1