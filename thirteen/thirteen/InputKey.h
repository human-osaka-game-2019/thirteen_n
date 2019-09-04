#ifndef INPUTKEY_H
#define INPUTKEY_H

#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include"Bullet.h"



class KeyState
{
public:
	int m_move;
	int m_shot;
};

void InputKeyState(Count* count, KeyState* keyState, KeyState ShotkeyState[5], Bullet bullet[5]);

#endif // !
