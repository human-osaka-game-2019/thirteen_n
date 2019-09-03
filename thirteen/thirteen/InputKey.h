#ifndef INPUTKEY_H
#define INPUTKEY_H

#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include"Bullet.h"



class KeyState
{
public:
	int Move;
	int Shot;
};

void InputKeyState(Count* count, KeyState* keyState, Bullet bullet[5]);

#endif // !
