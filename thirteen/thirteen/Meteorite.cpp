﻿#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include <random>
#include <iostream>

// 隕石の描画(一段階目)
void DrawMeteorite(Count* count, VariableNumber* var, int MapChipList[20][28], Meteorite meteorite[])
{
	// if(GetKeyStatus(DIK_M))
	if (count->Frame == (60 * 12))
	{
		std::mt19937 mt{ std::random_device{}() };

		// 右上
		std::uniform_int_distribution<int> LeftUp_With(0, 13);
		std::uniform_int_distribution<int> LeftUp_Hight(0, 9);

		int a = LeftUp_With(mt);
		int b = LeftUp_Hight(mt);

		// MapChipList[LeftUp_Hight(mt)][LeftUp_With(mt)] = 3;
		MapChipList[b][a] = 3;
		meteorite[0].m_PosX = (a) * 40 + 80;
		meteorite[0].m_PosY = (b) * 40 + 80;
		// 左上	
		std::uniform_int_distribution<int> RightUp_With(14, 27);
		std::uniform_int_distribution<int> RightUp_Hight(0, 9);

		int c = RightUp_With(mt);
		int d = RightUp_Hight(mt);

		// MapChipList[RightUp_With(mt)][RightUp_Hight(mt)] = 3;
		MapChipList[d][c] = 3;
		meteorite[1].m_PosX = (c) * 40 + 80;
		meteorite[1].m_PosY = (d) * 40 + 80;
		// 右下
		std::uniform_int_distribution<int> LeftDown_With(0, 13);
		std::uniform_int_distribution<int> LeftDown_Hight(10, 19);

		int e = LeftDown_With(mt);
		int f = LeftDown_Hight(mt);

		// MapChipList[LeftDown_With(mt)][LeftDown_Hight(mt)] = 3;
		MapChipList[f][e] = 3;
		meteorite[2].m_PosX = (e) * 40 + 80;
		meteorite[2].m_PosY = (f) * 40 + 80;
		// 左下
		std::uniform_int_distribution<int> RightDown_With(14, 27);
		std::uniform_int_distribution<int> RightDown_Hight(10, 19);

		int g = RightDown_With(mt);
		int h = RightDown_Hight(mt);

		// MapChipList[RightDown_With(mt)][RightDown_Hight(mt)] = 3;
		MapChipList[h][g] = 3;
		meteorite[3].m_PosX = (g) * 40 + 80;
		meteorite[3].m_PosY = (h) * 40 + 80;

		var->MeteoriteDrawState = 0;
		var->MeteoriteState = 1;
		count->Frame5 = 0;
		count->Frame8 = 0;
	}

	if (var->MeteoriteState == 1)
	{
		if (count->Frame5 == (60 * 2))
		{

			for (int a = 0; a < 20; a++)
			{
				for (int b = 0; b < 28; b++)
				{
					if (MapChipList[a][b] == 3)
					{
						MapChipList[a][b] = 1;
					}
				}
				var->MeteoriteState = 0;
				var->MeteoriteDrawState = 1;
			}
		}
	}
}

// 隕石の描画(二段階目)
void DrawMeteoriteTwo(Count* count, VariableNumber* var, int MapChipList[20][28], Meteorite meteorite[])
{
	// 
	// if(GetKeyStatus(DIK_M))
	if (count->Frame8 == (60 * 12))
	{
		std::mt19937 mt{ std::random_device{}() };

		// 右上
		std::uniform_int_distribution<int> LeftUp_With(0, 13);
		std::uniform_int_distribution<int> LeftUp_Hight(0, 9);

		int LeftUpWith = LeftUp_With(mt);
		int LeftUpHight = LeftUp_Hight(mt);

		// MapChipList[LeftUp_Hight(mt)][LeftUp_With(mt)] = 3;
		MapChipList[LeftUpHight][LeftUpWith] = 3;
		meteorite[4].m_PosX = (LeftUpWith) * 40 + 80;
		meteorite[4].m_PosY = (LeftUpHight) * 40 + 80;
		// 左上	
		std::uniform_int_distribution<int> RightUp_With(14, 27);
		std::uniform_int_distribution<int> RightUp_Hight(0, 9);

		int c = RightUp_With(mt);
		int d = RightUp_Hight(mt);

		// MapChipList[RightUp_With(mt)][RightUp_Hight(mt)] = 3;
		MapChipList[d][c] = 3;
		meteorite[5].m_PosX = (c) * 40 + 80;
		meteorite[5].m_PosY = (d) * 40 + 80;
		// 右下
		std::uniform_int_distribution<int> LeftDown_With(0, 13);
		std::uniform_int_distribution<int> LeftDown_Hight(10, 19);

		int e = LeftDown_With(mt);
		int f = LeftDown_Hight(mt);

		// MapChipList[LeftDown_With(mt)][LeftDown_Hight(mt)] = 3;
		MapChipList[f][e] = 3;
		meteorite[6].m_PosX = (e) * 40 + 80;
		meteorite[6].m_PosY = (f) * 40 + 80;
		// 左下
		std::uniform_int_distribution<int> RightDown_With(14, 27);
		std::uniform_int_distribution<int> RightDown_Hight(10, 19);

		int g = RightDown_With(mt);
		int h = RightDown_Hight(mt);

		// MapChipList[RightDown_With(mt)][RightDown_Hight(mt)] = 3;
		MapChipList[h][g] = 3;
		meteorite[7].m_PosX = (g) * 40 + 80;
		meteorite[7].m_PosY = (h) * 40 + 80;

		var->MeteoriteDrawState2 = 0;
		var->MeteoriteState = 1;
		count->Frame9 = 0;
		count->Frame = 0;
	}

	if (var->MeteoriteState == 1)
	{
		if (count->Frame9 == (60 * 2))
		{

			for (int a = 0; a < 20; a++)
			{
				for (int b = 0; b < 28; b++)
				{
					if (MapChipList[a][b] == 3)
					{
						MapChipList[a][b] = 1;
					}
				}
				var->MeteoriteState = 0;
				var->MeteoriteDrawState2 = 1;
			}
		}
	}
}

void HitCharMeteorite(Meteorite meteorite[], MainChar* mainChar, Count* count, KeyState* keyState)
{
	for (int a = 0; a < 8; a++)
	{
		if (((mainChar->m_PosX + 40 > meteorite[a].m_PosX /*自キャラの右のあたり判定*/) && (mainChar->m_PosX < meteorite[a].m_PosX + 40)/*自キャラの左のあたり判定*/))
		{
			if ((mainChar->m_PosY < meteorite[a].m_PosY + 40)/*自キャラが下から当たった時ののあたり判定*/ && (mainChar->m_PosY + 40 > meteorite[a].m_PosY/*自キャラが上から当たった時のあたり判定*/))
			{

				switch (keyState->Move)
				{
				case 0:
					break;
				case 1:
					// down
					mainChar->m_PosY = mainChar->m_PosY - 4;
					break;
				case 2:
					// up
					mainChar->m_PosY = mainChar->m_PosY + 4;
					break;
				case 3:
					// lkeft
					mainChar->m_PosX = mainChar->m_PosX + 4;
					break;
				case 4:
					// right
					mainChar->m_PosX = mainChar->m_PosX - 4;
					break;
				}

			}
		}
	}
}
