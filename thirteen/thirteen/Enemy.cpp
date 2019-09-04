﻿#include"Engine.h"
#include"Device.h"
#include"Enemy.h"
#include"Scene.h"

#include"Enemy.h"
#include"Bullet.h"
#include"InputKey.h"

#include <random>
#include <iostream>

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

	}
	if (e_green[1].m_pos_x == 80)
	{
		e_green[1].m_pos_y = 0;
		e_green[1].m_pos_y = 0;
		e_green[1].m_draw_flag = 2;

	}
	if (e_white[0].m_pos_y == 840)
	{
		e_white[0].m_pos_x = 0;
		e_white[0].m_pos_x = 0;
		e_white[0].m_draw_flag = 2;

	}
	if (e_white[1].m_pos_y == 80)
	{
		e_white[1].m_pos_y = 0;
		e_white[1].m_pos_y = 0;
		e_white[1].m_draw_flag = 2;
	}
	if (e_white[0].m_draw_flag == 2 && e_white[1].m_draw_flag == 2)
	{
		if (e_green[0].m_draw_flag == 2 && e_green[1].m_draw_flag == 2)
		{
			enemy->EnemyDrawState = 0;

		}
	}
}

// 敵と弾丸のあたり判定
void HitBulletEnemy(Bullet bullet[], Count* count, Enemy_Green e_green[], Enemy_White e_white[], KeyState ShotkeyState[])
{
	// 敵の数　緑＊２　白＊２
	for (int a = 0; a < 2; a++)
	{
		// 弾の数
		for (int b = 0; b < 5; b++)
		{
			if (ShotkeyState[b].m_shot > 0 && (e_green[a].m_draw_flag == 1 || e_white[a].m_draw_flag == 1))
			{
				if ((bullet[b].m_pos_x + 40 > e_green[a].m_pos_x /*弾の右のあたり判定*/) && (bullet[b].m_pos_x < e_green[a].m_pos_x + 40)/*弾の左のあたり判定*/)
				{

					if ((bullet[b].m_pos_y < e_green[a].m_pos_y + 40)/*弾が下から当たった時ののあたり判定*/ && (bullet[b].m_pos_y + 40 > e_green[a].m_pos_y/*弾が上から当たった時のあたり判定*/))
					{
						e_green[a].m_draw_flag = 2;

						e_green[a].m_pos_x= 0;
						e_green[a].m_pos_y= 0;

						if (count->BulletCount > 0 && count->BulletCount < 5)
						{
							count->BulletCount = 0;
							count->shotcount = 0;
						}
					}
				}

				if ((bullet[b].m_pos_x+ 40 > e_white[a].m_pos_x /*弾の右のあたり判定*/) && (bullet[b].m_pos_x < e_white[a].m_pos_x + 40)/*弾の左のあたり判定*/)
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
					}
				}
			}
		}
	}
}

