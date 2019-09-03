#ifndef ENGINE_H
#define ENGINE_H

#include<windows.h>
#include<d3dx9.h>
#include<tchar.h>
#include<dinput.h>

class DirectX
{
public:

	LPDIRECT3D9 pDirect3d;
	LPDIRECT3DDEVICE9 pDevice;
	LPDIRECTINPUT8 pDinput;
	LPDIRECTINPUTDEVICE8 pkey;


};

//Pointa Point;

HWND* InitEngine(int width, int height, HINSTANCE hInst, DirectX* directX);

void EndEngine(DirectX directX);

bool DrawStart(DirectX* directX);

void UpdateInput(DirectX* directX);

#endif // !1