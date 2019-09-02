#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include <random>
#include <iostream>

// 敵の描画
void DrawEnemy(Count* count, VariableNumber* var, int MapChipList[20][28], Enemy_Green e_green[], Enemy_White e_white[])
{

	std::mt19937 mt{ std::random_device{}() };

	if (count->Frame6 == (60 * 15))
	{

		std::uniform_int_distribution<int> a(1, 4);

		// 左壁
		std::uniform_int_distribution<int> LeftHight(0, 19);
		int left_height = LeftHight(mt);
		MapChipList[left_height][0] = 5;
		e_green[0].m_PosX = 80;
		e_green[0].m_PosY = (left_height) * 40 + 80;

		// 右壁
		std::uniform_int_distribution<int> RightHight(0, 19);
		int right_hight = RightHight(mt);
		MapChipList[right_hight][27] = 5;
		e_green[1].m_PosX = 1160;
		e_green[1].m_PosY = (right_hight) * 40 + 80;

		// 上壁
		std::uniform_int_distribution<int> UpWith(0, 27);
		int up_with = UpWith(mt);
		MapChipList[0][up_with] = 4;
		e_white[0].m_PosX = (up_with) * 40 + 80;
		e_white[0].m_PosY = 80;

		// 下壁
		std::uniform_int_distribution<int> DownWith(0, 27);
		int dorw_with = DownWith(mt);
		MapChipList[19][dorw_with] = 4;
		e_white[1].m_PosX = (dorw_with) * 40 + 80;
		e_white[1].m_PosY = 840;


		var->EnemyState = 1;
		count->Frame7 = 0;
		count->Frame6 = 0;

	}

	if (var->EnemyState == 1)
	{
		if (count->Frame7 == (60 * 2))
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
				var->EnemyState = 0;
			}
			var->EnemyDrawState = 1;
		}
	}
}

// 敵の動き
void EnemyMove(Count* count, VariableNumber* var, Enemy_Green e_green[], Enemy_White e_white[])
{
	if (var->EnemyDrawState == 1)
	{
		e_green[0].m_PosX = e_green[0].m_PosX + 4;
		e_green[1].m_PosX = e_green[1].m_PosX - 4;
		e_white[0].m_PosY = e_white[0].m_PosY + 2;
		e_white[1].m_PosY = e_white[1].m_PosY - 2;
	}
	if (e_green[0].m_PosX == 1160)
	{
		e_green[0].m_PosX = 2000;
		e_green[1].m_PosY = 2000;
		e_green[0].m_PosX = 2000;
		e_green[1].m_PosY = 2000;


	}
	if (e_white[0].m_PosY == 840)
	{
		e_white[0].m_PosX = 2000;
		e_white[1].m_PosY = 2000;
		e_white[0].m_PosX = 2000;
		e_white[1].m_PosY = 2000;

		var->EnemyDrawState = 0;
	}
}
