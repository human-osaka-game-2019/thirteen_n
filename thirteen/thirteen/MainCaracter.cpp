#include <SoundsManager.h>
#include <random>
#include <iostream>

#include"Engine.h"
#include"Device.h"
#include"Scene.h"

#include"Bullet.h"
#include"InputKey.h"
#include"MainCaracter.h"
#include"Enemy.h"

extern SoundLib::SoundsManager m_soundsManager;

void MainCharacter::InputTv(int Tu, int Tu_Size)
{
	m_pos_tu= (float)Tu / 1024;
	m_pos_tu_size = (float)Tu_Size / 1024;
}

void CheckBulletDirectionKey(Count* count, KeyState ShotkeyState[5], Bullet bullet[5])
{
	m_soundsManager.AddFile("Sound/Bullet.wav", "Bullet");
	m_soundsManager.AddFile("Sound/Bullet.wav", "Bullet2");
	m_soundsManager.AddFile("Sound/Bullet.wav", "Bullet3");
	m_soundsManager.AddFile("Sound/Bullet.wav", "Bullet4");
	m_soundsManager.AddFile("Sound/Bullet.wav", "Bullet5");

	m_soundsManager.SetVolume("Bullet", 15);
	m_soundsManager.SetVolume("Bullet2", 15);
	m_soundsManager.SetVolume("Bullet3", 15);
	m_soundsManager.SetVolume("Bullet4", 15);
	m_soundsManager.SetVolume("Bullet5", 15);

	bullet->ReShot = 0;

	if ( count->BulletCount < 4 && (GetKeyDown(DOWN) == true || GetKeyDown(UP) == true || GetKeyDown(LEFT) == true || GetKeyDown(RIGHT) == true ))
	{
		switch (bullet->count_sound_num)
		{
		case 0:
			m_soundsManager.Start("Bullet");
			bullet->count_sound_num = 1;
			break;
		case 1:
			m_soundsManager.Start("Bullet2");
			bullet->count_sound_num = 2;
			break;
		case 2:
			m_soundsManager.Start("Bullet3");
			bullet->count_sound_num = 3;
			break;
		case 3:
			m_soundsManager.Start("Bullet4");
			bullet->count_sound_num = 4;
			break;
		case 4:
			m_soundsManager.Start("Bullet5");
			bullet->count_sound_num = 0;
			break;
		}
	}

	for (int a = 0; a < 12; a++)
	{
		if (ShotkeyState[a].m_shot == 0)
		{
			if (bullet->ReShot == 0)
			{
				if (count->BulletCount < 4)
				{
					if (GetKeyDown(DOWN) == true)
					{
						bullet->ReShot = 1;
						ShotkeyState[a].m_shot = 1;
						bullet[a].ShotFlag = true;
						count->BulletCount += 1;
						break;
					}

					if (GetKeyDown(UP) == true)
					{
						bullet->ReShot = 1;
						ShotkeyState[a].m_shot = 2;
						bullet[a].ShotFlag = true;
						count->BulletCount += 1;
						break;
					}

					if (GetKeyDown(LEFT) == true)
					{
						bullet->ReShot = 1;
						ShotkeyState[a].m_shot = 3;
						bullet[a].ShotFlag = true;
						count->BulletCount += 1;
						break;
					}

					if (GetKeyDown(RIGHT) == true)
					{
						bullet->ReShot = 1;
						ShotkeyState[a].m_shot = 4;
						bullet[a].ShotFlag = true;
						count->BulletCount += 1;
						break;
					}
				}
			}
		}
	}
}

// 10フレーム経たないと動かない(合計10フレーム,1フレーム X座標 +- 4 )
void MoveCharacter(Count* count, KeyState* keyState, MainCharacter* mainCara)
{
	if (count->re_input_move_key < 10)
	{
		switch (keyState->m_move)
		{
		case 0:
			break;
		case 1:
			mainCara->m_pos_y = mainCara->m_pos_y + mainCara->m_move_speed;
			break;
		case 2:
			mainCara->m_pos_y = mainCara->m_pos_y - mainCara->m_move_speed;
			break;
		case 3:
			mainCara->m_pos_x= mainCara->m_pos_x - mainCara->m_move_speed;
			break;
		case 4:
			mainCara->m_pos_x = mainCara->m_pos_x + mainCara->m_move_speed;
			break;
		}
	}
}

// 自キャラのモーション
void CharTextureChange(Count* count, MainCharacter* mainCara, Bullet* bullet)
{
	mainCara->Add_TvSize = 160 * count->BulletCount;

	if (count->draw_main_caracter == 10)
	{
		mainCara->InputTv(80 + mainCara->Add_TvSize, 120 + mainCara->Add_TvSize);
	}
	else
		if (count->draw_main_caracter == 20)
		{
			mainCara->InputTv(120 + mainCara->Add_TvSize, 160 + mainCara->Add_TvSize);
		}
		else
			if (count->draw_main_caracter == 30)
			{
				mainCara->InputTv(160 + mainCara->Add_TvSize, 200 + mainCara->Add_TvSize);
			}
			else
				if (count->draw_main_caracter == 40)
				{
					mainCara->InputTv(120 + mainCara->Add_TvSize, 160 + mainCara->Add_TvSize);
				}
				else
					if (count->draw_main_caracter == 50)
					{
						mainCara->InputTv(80 + mainCara->Add_TvSize, 120 + mainCara->Add_TvSize);
					}
					else
						if (count->draw_main_caracter == 60)
						{
							mainCara->InputTv(40 + mainCara->Add_TvSize, 80 + mainCara->Add_TvSize);
						}

	if (count->draw_main_caracter > 60)
	{
		count->draw_main_caracter = 0;
	}

}


// 10フレームたったら再度キー入力できるようになる
void FrameCount(Count* count, KeyState* keyState)
{
	if (count->re_input_move_key > 10)
	{
		count->re_input_move_key = 0;
		keyState->m_move = 0;
	}
}

// ゲーム画面の当たり判定
void HitJudge(MainCharacter* mainCara)
{
	if (mainCara->m_pos_x < 80)
	{
		mainCara->m_pos_x = mainCara->m_pos_x + mainCara->m_move_speed;
	}
	else
		if (mainCara->m_pos_x > 1160)
		{
			mainCara->m_pos_x = mainCara->m_pos_x - mainCara->m_move_speed;
		}
		else
			if (mainCara->m_pos_y < 80)
			{
				mainCara->m_pos_y = mainCara->m_pos_y + mainCara->m_move_speed;
			}
			else
				if (mainCara->m_pos_y > 840)
				{
					mainCara->m_pos_y = mainCara->m_pos_y - mainCara->m_move_speed;
				}

}
