#include"Engine.h"
#include"Device.h"
#include"Enemy.h"
#include"Scene.h"
#include <SoundsManager.h>

#include"Enemy.h"
#include"Bullet.h"
#include"MainCaracter.h"
#include"InputKey.h"

#include <random>
#include <iostream>

extern SoundLib::SoundsManager m_soundsManager;

void Enemy_Green::InputTu(float tu, float tuSize) 
{

	m_pos_tu = (float)tu / 1024;
	m_pos_tu_size = (float)(tu + tuSize) / 1024;
};

void Enemy_White::InputTu(float tu, float tuSize)
{
	m_pos_tu = (float)tu / 1024;
	m_pos_tu_size = (float)(tu + tuSize) / 1024;
}

// 敵の描画
void DrawEnemy(Count* count  , int MapChipList[20][28], Enemy_Green e_green[], Enemy_White e_white[],Enemy * enemy)
{

	std::mt19937 mt{ std::random_device{}() };

	if (count->draw_enemy_indication == (60 * 15))
	{

		std::uniform_int_distribution<int> a(1, 4);

		// 左壁
		std::uniform_int_distribution<int> LeftHight(0, 19);
		int left_height = LeftHight(mt);
		MapChipList[left_height][0] = 5;
		e_green[0].m_pos_x = 80;
		e_green[0].m_pos_y = (left_height) * 40 + 80;
		e_green[0].m_draw_flag = 1;

		// 右壁
		std::uniform_int_distribution<int> RightHight(0, 19);
		int right_hight = RightHight(mt);
		MapChipList[right_hight][27] = 5;
		e_green[1].m_pos_x = 1160;
		e_green[1].m_pos_y = (right_hight) * 40 + 80;
		e_green[1].m_draw_flag = 1;

		// 上壁
		std::uniform_int_distribution<int> Upwidth(0, 27);
		int up_width = Upwidth(mt);
		MapChipList[0][up_width] = 4;
		e_white[0].m_pos_x = (up_width) * 40 + 80;
		e_white[0].m_pos_y = 80;
		e_white[0].m_draw_flag = 1;

		// 下壁
		std::uniform_int_distribution<int> Downwidth(0, 27);
		int dorw_width = Downwidth(mt);
		MapChipList[19][dorw_width] = 4;
		e_white[1].m_pos_x = (dorw_width) * 40 + 80;
		e_white[1].m_pos_y = 840;
		e_white[1].m_draw_flag = 1;

		enemy->EnemyState = 1;
		count->draw_enemy = 0;
		count->draw_enemy_indication = 0;

	}

	if (enemy->EnemyState == 1)
	{
		if (count->draw_enemy == (60 * 2))
		{

			for (int a = 0; a < 20; a++)
			{
				for (int b = 0; b < 28; b++)
				{
					if (MapChipList[a][b] == 4)
					{
						MapChipList[a][b] = 1;
					}
					if (MapChipList[a][b] == 5)
					{
						MapChipList[a][b] = 1;
					}
				}
				enemy->EnemyState = 0;
			}
			enemy->EnemyDrawState = 1;
			count->EnemyGreenMotion = 0;
			count->EnemyWhiteMotion = 0;
		}
	}
}

// 敵の動き
void EnemyMove(Count* count  , Enemy_Green e_green[], Enemy_White e_white[],Enemy* enemy)
{
	if (enemy->EnemyDrawState == 1)
	{
		e_green[0].m_pos_x = e_green[0].m_pos_x + 4;
		e_green[1].m_pos_x = e_green[1].m_pos_x - 4;
		e_white[0].m_pos_y = e_white[0].m_pos_y + 2;
		e_white[1].m_pos_y = e_white[1].m_pos_y - 2;
	}


	if (e_green[0].m_pos_x == 1160)
	{
		e_green[0].m_pos_x = 0;
		e_green[0].m_pos_x = 0;
		e_green[0].m_draw_flag = 2;
		e_green[0].MainCharacterHItFlag = 0;

	}
	if (e_green[1].m_pos_x == 80)
	{
		e_green[1].m_pos_y = 0;
		e_green[1].m_pos_y = 0;
		e_green[1].m_draw_flag = 2;
		e_green[1].MainCharacterHItFlag = 0;
	}
	if (e_white[0].m_pos_y == 840)
	{
		e_white[0].m_pos_x = 0;
		e_white[0].m_pos_x = 0;
		e_white[0].m_draw_flag = 2;
		e_white[0].MainCharacterHItFlag = 0;
	}
	if (e_white[1].m_pos_y == 80)
	{
		e_white[1].m_pos_y = 0;
		e_white[1].m_pos_y = 0;
		e_white[1].m_draw_flag = 2;
		e_white[1].MainCharacterHItFlag = 0;
	}
	if (e_white[0].m_draw_flag == 2 && e_white[1].m_draw_flag == 2)
	{
		if (e_green[0].m_draw_flag == 2 && e_green[1].m_draw_flag == 2)
		{
			enemy->EnemyDrawState = 0;

		}
	}
}

void EnemyMotion(Count* count, Enemy_Green e_green[], Enemy_White e_white[], Enemy* enemy)
{
	if (enemy->EnemyDrawState == 1)
	{
		for (int a = 0; a < 2; a++)
		{
			switch (count->EnemyGreenMotion)
			{
			case 10:
				e_green[a].InputTu(40, 40);
				break;
			case 20: 
				e_green[a].InputTu(80, 40);
				break;
			case 30:
				e_green[a].InputTu(120, 40);
				break;
			case 40:
				e_green[a].InputTu(160, 40);
				break;
			case 50:
				e_green[a].InputTu(200, 40);
				break;
			case 60:
				e_green[a].InputTu(240, 40);
				break;
			case 70:
				e_green[a].InputTu(280, 40);
				break;
			case 80:
				e_green[a].InputTu(0, 40);
				count->EnemyGreenMotion = 0;
				break;
			}

			switch (count->EnemyWhiteMotion)
			{
			case 10:
				e_white[a].InputTu(40, 40);
				break;
			case 20:
				e_white[a].InputTu(80, 40);
				break;
			case 30:
				e_white[a].InputTu(120, 40);
				break;
			case 40:
				e_white[a].InputTu(160, 40);
				break;
			case 50:
				e_white[a].InputTu(200, 40);
				break;
			case 60:
				e_white[a].InputTu(0, 40);
				count->EnemyWhiteMotion = 0;
				break;
			}

		}
	}
}

// 弾丸と敵のあたり判定
void HitBulletEnemy(Bullet bullet[], Count* count, Enemy_Green e_green[], Enemy_White e_white[], KeyState ShotkeyState[], Enemy enemy)
{
	m_soundsManager.AddFile("Sound/AlienDestroy.wav", "AlienDeadA");
	m_soundsManager.AddFile("Sound/AlienDestroy.wav", "AlienDeadB");
	m_soundsManager.SetVolume("AlienDeadA", 15);
	m_soundsManager.SetVolume("AlienDeadB", 15);

	m_soundsManager.AddFile("Sound/HealMax.wav", "RecoveryA");
	m_soundsManager.AddFile("Sound/HealMax.wav", "RecoveryB");
	m_soundsManager.SetVolume("RecoveryA", 3);
	m_soundsManager.SetVolume("RecoveryB", 3);

	if (enemy.EnemyDrawState == 1)
	{
		// 敵の数　緑＊２　白＊２
		for (int a = 0; a < 2; a++)
		{
			// 弾の数
			for (int b = 0; b < 12; b++)
			{

				if (ShotkeyState[b].m_shot > 0 && e_green[a].m_draw_flag == 1)
				{

					if ((bullet[b].m_pos_x + 40 > e_green[a].m_pos_x /*弾の右のあたり判定*/) && (bullet[b].m_pos_x < e_green[a].m_pos_x + 40)/*弾の左のあたり判定*/)
					{

						if ((bullet[b].m_pos_y < e_green[a].m_pos_y + 40)/*弾が下から当たった時ののあたり判定*/ && (bullet[b].m_pos_y + 40 > e_green[a].m_pos_y/*弾が上から当たった時のあたり判定*/))
						{
							e_green[a].m_draw_flag = 2;

							e_green[a].m_pos_x = 0;
							e_green[a].m_pos_y = 0;

							if (count->BulletCount > 0 && count->BulletCount < 5)
							{
								count->BulletCount = 0;
								count->shotcount = 0;

							}

							m_soundsManager.Start("AlienDeadA");

							m_soundsManager.Start("RecoveryA");

						}
					}
				}
			}
		}

		for (int a = 0; a < 2; a++)
		{

			for (int b = 0; b < 12; b++)
			{

				if (ShotkeyState[b].m_shot > 0 && e_white[a].m_draw_flag == 1)
				{

					if ((bullet[b].m_pos_x + 40 > e_white[a].m_pos_x /*弾の右のあたり判定*/) && (bullet[b].m_pos_x < e_white[a].m_pos_x + 40)/*弾の左のあたり判定*/)
					{

						if ((bullet[b].m_pos_y < e_white[a].m_pos_y + 40)/*弾が下から当たった時ののあたり判定*/ && (bullet[b].m_pos_y + 40 > e_white[a].m_pos_y/*弾が上から当たった時のあたり判定*/))
						{
							e_white[a].m_draw_flag = 2;

							e_white[a].m_pos_x = 0;
							e_white[a].m_pos_y = 0;

							if (count->BulletCount > 0 && count->BulletCount < 5)
							{
								count->BulletCount = 0;
								count->shotcount = 0;

							}

							m_soundsManager.Start("AlienDeadB");

							m_soundsManager.Start("RecoveryB");

						}
					}
				}
			}
		}
	}
}

// 操作キャラと敵のあたり判定
void HitMainCaraEnemy(MainCharacter* mainCharacter, Count* count, Enemy_Green e_green[], Enemy_White e_white[], KeyState ShotkeyState[], Enemy enemy)
{
	m_soundsManager.AddFile("Sound/Damage.wav", "DamageC");
	m_soundsManager.SetVolume("DamageC", 50);
	m_soundsManager.AddFile("Sound/Damage.wav", "DamageD");
	m_soundsManager.SetVolume("DamageD", 50);

	if (enemy.EnemyDrawState == 1)
	{
		// 敵の数　緑＊２　白＊２
		for (int a = 0; a < 2; a++)
		{

			if (e_green[a].MainCharacterHItFlag == 0)
			{

				if ((mainCharacter->m_pos_x + 40 > e_green[a].m_pos_x /*弾の右のあたり判定*/) && (mainCharacter->m_pos_x < e_green[a].m_pos_x + 40)/*弾の左のあたり判定*/)
				{

					if ((mainCharacter->m_pos_y < e_green[a].m_pos_y + 40)/*弾が下から当たった時ののあたり判定*/ && (mainCharacter->m_pos_y + 40 > e_green[a].m_pos_y/*弾が上から当たった時のあたり判定*/))
					{
						e_green[a].MainCharacterHItFlag = 1;

						m_soundsManager.Start("DamageC");

						if (count->BulletCount < 4)
						{
							count->BulletCount += 1;
						}
						else
						{
							mainCharacter->DeathFlag = 1;
						}
					}
				}
			}
		}

		for (int a = 0; a < 2; a++)
		{

			if (e_white[a].MainCharacterHItFlag == 0)
			{

				if ((mainCharacter->m_pos_x + 40 > e_white[a].m_pos_x /*弾の右のあたり判定*/) && (mainCharacter->m_pos_x < e_white[a].m_pos_x + 40)/*弾の左のあたり判定*/)
				{

					if ((mainCharacter->m_pos_y < e_white[a].m_pos_y + 40)/*弾が下から当たった時ののあたり判定*/ && (mainCharacter->m_pos_y + 40 > e_white[a].m_pos_y/*弾が上から当たった時のあたり判定*/))
					{
						e_white[a].MainCharacterHItFlag = 1;

						m_soundsManager.Start("DamageD");

						if (count->BulletCount < 4)
						{
							count->BulletCount += 1;
						}
						else
						{
							mainCharacter->DeathFlag = 1;
						}
					}
				}
			}
		}
	}
}
