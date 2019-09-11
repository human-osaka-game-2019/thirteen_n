#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include<SoundsManager.h>

#include"InputKey.h"
#include"MainCaracter.h"
#include"Meteorite.h"
#include"Scene.h"
#include"Star.h"

#include <random>
#include <iostream>

extern SoundLib::SoundsManager m_soundsManager;

void Meteorite::InputTu(int Tu, int TuSize)
{
	m_pos_tu = (float)Tu / 1024;
	m_Tu_Size = (float)(TuSize + Tu) / 1024;
}

// 隕石の描画(一段階目)
void DrawMeteorite(Count* count  , int MapChipList[20][28], Meteorite meteorite[])
{
	// if(GetKeyStatus(DIK_M))
	if (count->Frame0 == (60 * 12))
	{
		m_soundsManager.AddFile("Sound/MeteorLanding.wav", "MeteorLand");
		m_soundsManager.SetVolume("MeteorLand", 18);

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
		for (int b = 0; b < 4; b++)
		{
			meteorite[b].MeteoriteDrawState = 0;
		}
		meteorite->MeteoriteState = 1;
		count->draw_meteorite_two_indication = 0;
		count->draw_meteorite_indication = 0;

		for (int a = 0; a < 4; a++)
		{
			meteorite[a].DropStarFlag = 0;
		}

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

				for (int a = 0; a < 4; a++)
				{
					meteorite[a].MeteoriteDrawState = 1;
				}
			}

			m_soundsManager.Start("MeteorLand");
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
		m_soundsManager.SetVolume("MeteorLand", 18);

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

		for (int b = 4; b < 8; b++)
		{
			meteorite[b].MeteoriteDrawState = 0;
		}
		meteorite->MeteoriteState = 1;
		count->draw_meteorite_two = 0;
		count->Frame0 = 0;

		for (int a = 4; a < 8; a++)
		{
			meteorite[a].DropStarFlag = 0;
		}
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

				for (int a = 4; a < 8; a++)
				{
					meteorite[a].MeteoriteDrawState = 1;
				}	
			}
				
			m_soundsManager.Start("MeteorLand");
		}
	}
}

void MeteoriteMotion(Count* count, Meteorite meteorite[])
{
	for (int a = 0; a < 4; a++)
	{

		if (meteorite[a].MeteoriteDrawState == 1 && meteorite[a].MeteoriteBreakFlag == 0)
		{
			switch (count->draw_meteorite_indication)
			{
			case 120:
				meteorite[a].InputTu(240, 40);
				break;
			case 130:
				meteorite[a].InputTu(280, 40);
				break;
			case 140:
				meteorite[a].InputTu(320, 40);
				break;
			case 150:
				meteorite[a].InputTu(360, 40);
				break;
			case 160:
				meteorite[a].InputTu(400, 40);
				break;
			case 170:
				meteorite[a].InputTu(0, 40);
				break;
			}
		}
	}

	for (int b = 4; b <8 ; b ++)
	{
	
		if (meteorite[b].MeteoriteDrawState == 1 && meteorite[b].MeteoriteBreakFlag == 0)
		{
			switch (count->draw_meteorite_two)
			{
			case 120:
				meteorite[b].InputTu(240, 40);
				break;
			case 130:
				meteorite[b].InputTu(280, 40);
				break;
			case 140:
				meteorite[b].InputTu(320, 40);
				break;
			case 150:
				meteorite[b].InputTu(360, 40);
				break;
			case 160:
				meteorite[b].InputTu(400, 40);
				break;
			case 170:
				meteorite[b].InputTu(0, 40);
				break;
			}
		}
		
	}
}

void HitCharMeteorite(Meteorite meteorite[], MainCharacter* mainCara, Count* count, KeyState* keyState)
{
	for (int a = 0; a < 8; a++)
	{
		if (meteorite[a].MeteoriteDrawState == 1)
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
						count->re_input_move_key = 10;
						break;
					case 2:
						// up
						mainCara->m_pos_y = mainCara->m_pos_y + 4;
						count->re_input_move_key = 10;
						break;
					case 3:
						// lkeft
						mainCara->m_pos_x = mainCara->m_pos_x + 4;
						count->re_input_move_key = 10;
						break;
					case 4:
						// right
						mainCara->m_pos_x = mainCara->m_pos_x - 4;
						count->re_input_move_key = 10;
						break;
					}
				}
			}
		}
	}
}


void HiBulletMeteorite(Meteorite meteorite[], Bullet bullet[], Count* count, MeteoMotion  meteoMotion[], KeyState keyState[], Star star[])
{

	for (int a = 0; a < 12; a++)
	{
		if (keyState[a].m_shot != 0)
		{
			for (int b = 0; b < 8; b++)
			{
				if (meteorite[b].MeteoriteDrawState == 1)
				{
					if (((bullet[a].m_pos_x + 40 > meteorite[b].m_pos_x /*自キャラの右のあたり判定*/) && (bullet[a].m_pos_x < meteorite[b].m_pos_x + 40)/*自キャラの左のあたり判定*/))
					{
						if ((bullet[a].m_pos_y < meteorite[b].m_pos_y + 40)/*自キャラが下から当たった時ののあたり判定*/ && (bullet[a].m_pos_y + 40 > meteorite[b].m_pos_y/*自キャラが上から当たった時のあたり判定*/))
						{
							if (meteorite[b].MeteoriteBreakFlag == 0)
							{
								meteorite[b].MeteoriteBreakFlag = 1;
								meteoMotion[b].FramCount = 0;
								meteorite[b].InputTu(40, 40);
								meteorite[b].DropStarFlag = 1;
								star[b + 4].m_pos_x = meteorite[b].m_pos_x;
								star[b + 4].m_pos_y = meteorite[b].m_pos_y;
							}
						}
					}
				}
			}
		}
	}
}

void DrawBreakMeteorite(Meteorite meteorite[], MeteoMotion  meteoMotion[])
{
	m_soundsManager.AddFile("Sound/MeteorDestroy.wav", "MeteorDestroy");
	m_soundsManager.SetVolume("MeteorDestroy", 40);

	m_soundsManager.AddFile("Sound/MeteorDestroy.wav", "MeteorDestroy2");
	m_soundsManager.SetVolume("MeteorDestroy2", 40);

	m_soundsManager.AddFile("Sound/MeteorDestroy.wav", "MeteorDestroy3");
	m_soundsManager.SetVolume("MeteorDestroy3", 40);

	for (int a = 0; a < 8; a++)
	{
		if (meteorite[a].MeteoriteBreakFlag == 1 && meteoMotion[a].FramCount == 0)
		{
			switch (meteorite->count_sound_num)
			{
			case 0:
				m_soundsManager.Start("MeteorDestroy");
				meteorite->count_sound_num = 1;
				break;
			case 1:
				m_soundsManager.Start("MeteorDestroy2");
				meteorite->count_sound_num = 2;
				break;
			case 2:
				m_soundsManager.Start("MeteorDestroy3");
				meteorite->count_sound_num = 0;
				break;
			}
		}

		if (meteorite[a].MeteoriteBreakFlag == 1)
		{
			switch (meteoMotion[a].FramCount)
			{
			case 12:
				meteorite[a].InputTu(80, 40);
				break;
			case 24:
				meteorite[a].InputTu(120, 40);
				break;
			case 36:
				meteorite[a].InputTu(160, 40);
				break;
			case 48:
				meteorite[a].InputTu(200, 40);
				break;
			case 60:	
				meteorite[a].MeteoriteBreakFlag = 0;
				meteorite[a].InputTu(0, 40);
				
				if (a < 4)
				{
					meteorite[a].DropStarFlag = 2;
					meteorite[a].MeteoriteDrawState = 0;
					meteorite[a].m_pos_x = -100;
					meteorite[a].m_pos_y = -100;
				}
				
				if (a >= 4 && a < 8)
				{
					meteorite[a].DropStarFlag = 2;
					meteorite[a].MeteoriteDrawState = 0;
					meteorite[a].m_pos_x = -100;
					meteorite[a].m_pos_y = -100;
				}
				break;
			}
		}
	}
}

void StarDrop(Meteorite meteorite[], FlameCount flamCount[], Star star[])
{
	for (int a = 0; a < 8; a++)
	{
		if (meteorite[a].DropStarFlag == 2)
		{
			star[a + 4].DrawFlag = true;
			meteorite[a].DropStarFlag = 3;
		}else
			if (meteorite[a].DropStarFlag == 0)
			{
				star[a + 4].DrawFlag = false;
				star[a + 4].m_pos_x = 0;
				star[a + 4].m_pos_y = 0;
			}

	}

}