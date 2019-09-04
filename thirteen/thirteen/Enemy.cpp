#include"Engine.h"
#include"Device.h"
#include"Enemy.h"
#include"Scene.h"

#include"Enemy.h"

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

		// 右壁
		std::uniform_int_distribution<int> RightHight(0, 19);
		int right_hight = RightHight(mt);
		MapChipList[right_hight][27] = 5;
		e_green[1].m_pos_x = 1160;
		e_green[1].m_pos_y = (right_hight) * 40 + 80;

		// 上壁
		std::uniform_int_distribution<int> Upwidth(0, 27);
		int up_width = Upwidth(mt);
		MapChipList[0][up_width] = 4;
		e_white[0].m_pos_x = (up_width) * 40 + 80;
		e_white[0].m_pos_y = 80;

		// 下壁
		std::uniform_int_distribution<int> Downwidth(0, 27);
		int dorw_width = Downwidth(mt);
		MapChipList[19][dorw_width] = 4;
		e_white[1].m_pos_x = (dorw_width) * 40 + 80;
		e_white[1].m_pos_y = 840;

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
		e_green[0].m_pos_x= 2000;
		e_green[1].m_pos_y = 2000;
		e_green[0].m_pos_x = 2000;
		e_green[1].m_pos_y = 2000;


	}
	if (e_white[0].m_pos_y == 840)
	{
		e_white[0].m_pos_x = 2000;
		e_white[1].m_pos_y = 2000;
		e_white[0].m_pos_x = 2000;
		e_white[1].m_pos_y = 2000;

		enemy->EnemyDrawState = 0;
	}
}
