#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include<SoundsManager.h>

#include"InputKey.h"
#include"MainCaracter.h"
#include"Meteorite.h"

#include <random>
#include <iostream>

extern SoundLib::SoundsManager m_soundsManager;

// 隕石の描画(一段階目)
void DrawMeteorite(Count* count  , int MapChipList[20][28], Meteorite meteorite[])
{
	// if(GetKeyStatus(DIK_M))
	if (count->Frame0 == (60 * 12))
	{
		m_soundsManager.AddFile("Sound/MeteorLanding.wav", "MeteorLand");
		m_soundsManager.SetVolume("MeteorLand", 20);
		
		std::mt19937 mt{ std::random_device{}() };

		// 右上
		std::uniform_int_distribution<int> LeftUp_width(0, 13);
		std::uniform_int_distribution<int> LeftUp_Hight(0, 9);

		int a = LeftUp_width(mt);
		int b = LeftUp_Hight(mt);

		// MapChipList[LeftUp_Hight(mt)][LeftUp_width(mt)] = 3;
		MapChipList[b][a] = 3;
		meteorite[0].m_pos_x= (a) * 40 + 80;
		meteorite[0].m_pos_y = (b) * 40 + 80;
		// 左上	
		std::uniform_int_distribution<int> RightUp_width(14, 27);
		std::uniform_int_distribution<int> RightUp_Hight(0, 9);

		int c = RightUp_width(mt);
		int d = RightUp_Hight(mt);

		// MapChipList[RightUp_width(mt)][RightUp_Hight(mt)] = 3;
		MapChipList[d][c] = 3;
		meteorite[1].m_pos_x = (c) * 40 + 80;
		meteorite[1].m_pos_y = (d) * 40 + 80;
		// 右下
		std::uniform_int_distribution<int> LeftDown_width(0, 13);
		std::uniform_int_distribution<int> LeftDown_Hight(10, 19);

		int e = LeftDown_width(mt);
		int f = LeftDown_Hight(mt);

		// MapChipList[LeftDown_width(mt)][LeftDown_Hight(mt)] = 3;
		MapChipList[f][e] = 3;
		meteorite[2].m_pos_x = (e) * 40 + 80;
		meteorite[2].m_pos_y = (f) * 40 + 80;
		// 左下
		std::uniform_int_distribution<int> RightDown_width(14, 27);
		std::uniform_int_distribution<int> RightDown_Hight(10, 19);

		int g = RightDown_width(mt);
		int h = RightDown_Hight(mt);

		// MapChipList[RightDown_width(mt)][RightDown_Hight(mt)] = 3;
		MapChipList[h][g] = 3;
		meteorite[3].m_pos_x = (g) * 40 + 80;
		meteorite[3].m_pos_y = (h) * 40 + 80;

		meteorite->MeteoriteDrawState = 0;
		meteorite->MeteoriteState = 1;
		count->draw_meteorite_two_indication = 0;
		count->draw_meteorite_indication = 0;

	}

	if (meteorite->MeteoriteState == 1)
	{
		if (count->draw_meteorite_indication == (60 * 2))
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
				meteorite->MeteoriteState = 0;
				meteorite->MeteoriteDrawState = 1;

				m_soundsManager.Start("MeteorLand", TRUE);

				m_soundsManager.Stop(_T("MeteorLand"));
			}
		}
	}
}

// 隕石の描画(二段階目)
void DrawMeteoriteTwo(Count* count  , int MapChipList[20][28], Meteorite meteorite[])
{
	// 
	// if(GetKeyStatus(DIK_M))
	if (count->draw_meteorite_two_indication == (60 * 12))
	{

		m_soundsManager.AddFile("Sound/MeteorLanding.wav", "MeteorLand");
		m_soundsManager.SetVolume("MeteorLand", 20);

		std::mt19937 mt{ std::random_device{}() };

		// 右上
		std::uniform_int_distribution<int> LeftUp_width(0, 13);
		std::uniform_int_distribution<int> LeftUp_Hight(0, 9);

		int LeftUpwidth = LeftUp_width(mt);
		int LeftUpHight = LeftUp_Hight(mt);

		// MapChipList[LeftUp_Hight(mt)][LeftUp_width(mt)] = 3;
		MapChipList[LeftUpHight][LeftUpwidth] = 3;
		meteorite[4].m_pos_x = (LeftUpwidth) * 40 + 80;
		meteorite[4].m_pos_y = (LeftUpHight) * 40 + 80;
		// 左上	
		std::uniform_int_distribution<int> RightUp_width(14, 27);
		std::uniform_int_distribution<int> RightUp_Hight(0, 9);

		int c = RightUp_width(mt);
		int d = RightUp_Hight(mt);

		// MapChipList[RightUp_width(mt)][RightUp_Hight(mt)] = 3;
		MapChipList[d][c] = 3;
		meteorite[5].m_pos_x = (c) * 40 + 80;
		meteorite[5].m_pos_y = (d) * 40 + 80;
		// 右下
		std::uniform_int_distribution<int> LeftDown_width(0, 13);
		std::uniform_int_distribution<int> LeftDown_Hight(10, 19);

		int e = LeftDown_width(mt);
		int f = LeftDown_Hight(mt);

		// MapChipList[LeftDown_width(mt)][LeftDown_Hight(mt)] = 3;
		MapChipList[f][e] = 3;
		meteorite[6].m_pos_x = (e) * 40 + 80;
		meteorite[6].m_pos_y = (f) * 40 + 80;
		// 左下
		std::uniform_int_distribution<int> RightDown_width(14, 27);
		std::uniform_int_distribution<int> RightDown_Hight(10, 19);

		int g = RightDown_width(mt);
		int h = RightDown_Hight(mt);

		// MapChipList[RightDown_width(mt)][RightDown_Hight(mt)] = 3;
		MapChipList[h][g] = 3;
		meteorite[7].m_pos_x = (g) * 40 + 80;
		meteorite[7].m_pos_y = (h) * 40 + 80;

		meteorite->MeteoriteDrawStateTwo = 0;
		meteorite->MeteoriteState = 1;
		count->draw_meteorite_two = 0;
		count->Frame0 = 0;

	}

	if (meteorite->MeteoriteState == 1)
	{
		if (count->draw_meteorite_two == (60 * 2))
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
				meteorite->MeteoriteState = 0;
				meteorite->MeteoriteDrawStateTwo = 1;

				m_soundsManager.Start("MeteorLand", TRUE);

				m_soundsManager.Stop(_T("MeteorLand"));
			}
		}
	}
}

void HitCharMeteorite(Meteorite meteorite[], MainCharacter* mainCara, Count* count, KeyState* keyState)
{
	for (int a = 0; a < 8; a++)
	{
		if (((mainCara->m_pos_x + 40 > meteorite[a].m_pos_x /*自キャラの右のあたり判定*/) && (mainCara->m_pos_x < meteorite[a].m_pos_x + 40)/*自キャラの左のあたり判定*/))
		{
			if ((mainCara->m_pos_y < meteorite[a].m_pos_y + 40)/*自キャラが下から当たった時ののあたり判定*/ && (mainCara->m_pos_y + 40 > meteorite[a].m_pos_y/*自キャラが上から当たった時のあたり判定*/))
			{

				switch (keyState->m_move)
				{
				case 0:
					break;
				case 1:
					// down
					mainCara->m_pos_y = mainCara->m_pos_y - 4;
					break;
				case 2:
					// up
					mainCara->m_pos_y = mainCara->m_pos_y + 4;
					break;
				case 3:
					// lkeft
					mainCara->m_pos_x = mainCara->m_pos_x + 4;
					break;
				case 4:
					// right
					mainCara->m_pos_x = mainCara->m_pos_x - 4;
					break;
				}

			}
		}
	}
}
