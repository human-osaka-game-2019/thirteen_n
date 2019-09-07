#include"Engine.h"
#include"Device.h"
#include <SoundsManager.h>

#include"Bullet.h"
#include"InputKey.h"

#include <random>
#include <iostream>

extern SoundLib::SoundsManager m_soundsManager;

/*
Bullet bullet[5];
Meteorite meteorite[8];
Enemy_Green e_green[2];
Enemy_White e_white[2];
*/

// キーの入力情報設定
void InputKeyState(Count* count, KeyState* keyState, KeyState ShotkeyState[5], Bullet bullet[5])
{

	m_soundsManager.AddFile("Sound/Bullet.wav", "Bullet");
	m_soundsManager.SetVolume("Bullet", 15);


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

	if (count->re_shot_count > 10)
	{
		count->re_shot_count = 0;
		bullet->ReShot = 0;
	}

	if (count->re_shot_count == 0)
	{
		for(int a = 0; a < 12; a ++)
		{ 
			if (ShotkeyState[a].m_shot == 0)
			{
				if(bullet->ReShot == 0)
				{ 
					if (count->BulletCount < 4)
					{

						if (GetKeyStatus(DIK_DOWN))
						{
							bullet->ReShot = 1;
							ShotkeyState[a].m_shot = 1;
							bullet[a].ShotFlag = true;
							count->BulletCount += 1;
							m_soundsManager.Start("Bullet");
							m_soundsManager.Stop("Bullet");
							break;
						}
						else
							if (GetKeyStatus(DIK_UP))
							{
								bullet->ReShot = 1;
								ShotkeyState[a].m_shot = 2;
								bullet[a].ShotFlag = true;
								count->BulletCount += 1;
								m_soundsManager.Start("Bullet");
								m_soundsManager.Stop("Bullet");
								break;
							}

						if (GetKeyStatus(DIK_LEFT))
						{
							bullet->ReShot = 1;
							ShotkeyState[a].m_shot = 3;
							bullet[a].ShotFlag = true;
							count->BulletCount += 1;
							m_soundsManager.Start("Bullet");
							m_soundsManager.Stop("Bullet");
							break;
						}
						else
							if (GetKeyStatus(DIK_RIGHT))
							{
								bullet->ReShot = 1;
								ShotkeyState[a].m_shot = 4;
								bullet[a].ShotFlag = true;
								count->BulletCount += 1;
								m_soundsManager.Start("Bullet");
								m_soundsManager.Stop("Bullet");
								break;
							}
					}
				}
			}
		}
	}



}