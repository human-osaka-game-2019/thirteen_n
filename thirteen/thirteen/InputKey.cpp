﻿#include"Engine.h"
#include"Device.h"

#include"Bullet.h"
#include"InputKey.h"

#include <random>
#include <iostream>

/*
Bullet bullet[5];
Meteorite meteorite[8];
Enemy_Green e_green[2];
Enemy_White e_white[2];
*/

// キーの入力情報設定
void InputKeyState(Count* count, KeyState* keyState, Bullet bullet[5])
{
	if (keyState->m_move == 0)
	{
		count->re_input_move_key = 0;

		if (GetKeyStatus(DIK_S))
		{
			keyState->m_move = 1;
		}
		else
			if (GetKeyStatus(DIK_W))
			{
				keyState->m_move = 2;
			}
		if (GetKeyStatus(DIK_A))
		{
			keyState->m_move = 3;
		}
		else
			if (GetKeyStatus(DIK_D))
			{
				keyState->m_move = 4;
			}
	}

	if (keyState->m_shot == 0)
	{
		if (GetKeyStatus(DIK_DOWN))
		{
			keyState->m_shot = 1;
			bullet[0].ShotFlag = true;

			if (count->BulletCount < 4)
			{
				count->BulletCount = count->BulletCount + 1;
			}

		}
		else
			if (GetKeyStatus(DIK_UP))
			{
				keyState->m_shot = 2;
				bullet[0].ShotFlag = true;

				if (count->BulletCount < 4)
				{
					count->BulletCount = count->BulletCount + 1;
				}
			}
		if (GetKeyStatus(DIK_LEFT))
		{
			keyState->m_shot = 3;
			bullet[0].ShotFlag = true;

			if (count->BulletCount < 4)
			{
				count->BulletCount = count->BulletCount + 1;
			}
		}
		else
			if (GetKeyStatus(DIK_RIGHT))
			{
				keyState->m_shot = 4;
				bullet[0].ShotFlag = true;

				if (count->BulletCount < 4)
				{
					count->BulletCount = count->BulletCount + 1;
				}
			}
	}

	if (GetKeyStatus(DIK_R))
	{
		bullet->BulletCount = 0;
	}

}