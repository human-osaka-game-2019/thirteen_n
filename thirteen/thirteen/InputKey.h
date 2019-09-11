#ifndef INPUTKEY_H
#define INPUTKEY_H

#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

class KeyState
{
public:
	int m_move;
	int m_shot;
};

enum KeyStatus
{
	CLEAR = 0x0000,
	UP = 0x0002,
	DOWN = 0x0004,
	LEFT = 0x0008,
	RIGHT = 0x0010,
};

void InputKeyState(Count* count, KeyState* keyState);

bool GetKeyDown(DWORD key_code);

#endif // !
