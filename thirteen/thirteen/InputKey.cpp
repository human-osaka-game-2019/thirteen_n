#include"Engine.h"
#include"Device.h"
#include <Windows.h>

#include"Bullet.h"
#include"InputKey.h"

#include <random>
#include <iostream>

static INPUTSTATE g_InputState;

/*
Bullet bullet[5];
Meteorite meteorite[8];
Enemy_Green e_green[2];
Enemy_White e_white[2];
*/

// キーの入力情報設定(ゲームシーン用)
void InputKeyState(Count* count, KeyState* keyState)
{
	DWORD old = g_InputState.now;

	g_InputState.now = CLEAR;


	if (keyState->m_move == 0)
	{
		count->re_input_move_key = 0;

		if (GetKeyStatus(DIK_S))
		{
			keyState->m_move = 1;
		}

		if (GetKeyStatus(DIK_W))
		{
			keyState->m_move = 2;
		}

		if (GetKeyStatus(DIK_A))
		{
			keyState->m_move = 3;
		}

		if (GetKeyStatus(DIK_D))
		{
			keyState->m_move = 4;
		}
	}

	if (GetKeyStatus(DIK_DOWN))
	{
		g_InputState.now |= DOWN;
	}
	
	if (GetKeyStatus(DIK_UP))
	{
		g_InputState.now |= UP;
	}

	if (GetKeyStatus(DIK_LEFT))
	{
		g_InputState.now |= LEFT;
	}

	if (GetKeyStatus(DIK_RIGHT))
	{
		g_InputState.now |= RIGHT;
	}

	g_InputState.pushed = (g_InputState.now & (~old));

	if (count->BulletCount <= 4 && count->BulletCount >= 1)
	{
		if (count->HealTime == (1 * 1))
		{
			count->HealTime = 0;
			count->BulletCount -= 1;
		}
	}else
		if (count->HealTime == (1 * 1))
		{
			count->HealTime = 0;
		}
}

bool GetKeyDown(DWORD key_code)
{
	return g_InputState.pushed & key_code;
}