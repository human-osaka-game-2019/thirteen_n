#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include<SoundsManager.h>

#include"Beam.h"


#include <random>
#include <iostream>


extern SoundLib::SoundsManager m_soundsManager;


// ビーム描画位置入力関数(横)
void BeamSide::InputSidePosTv(float Tv, float TvSize)
{
	m_pos_tv = (float)Tv / 2048;
	m_pos_tv_size = (float)TvSize / 2048;
}

// ビーム描画位置入力関数(縦)
void BeamVerticality::InputVerticalityPosTu(float Tu, float TuSize)
{
	m_pos_tu = (float)Tu / 2048;
	m_pos_tu_size =(float) TuSize / 2048;
}

// ビーム描画(3*3)
void SetBeam_six(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, Beam* beam)
{
	if (beam->GameLevel == 3)
	{
		if (count->draw_beam_indication == (60 * 8))
		{
			std::mt19937 mt{ std::random_device{}() };

			std::uniform_int_distribution<int> f_Width(1, 8); // 1 28
			std::uniform_int_distribution<int> f_Hight(8, 16); // 1 20
			std::uniform_int_distribution<int> s_Width(16, 25); // 1 28
			std::uniform_int_distribution<int> s_Hight(1, 6); // 1 20
			std::uniform_int_distribution<int> t_Width(6, 12); // 1 28
			std::uniform_int_distribution<int> t_Hight(12, 17); // 1 20

			int f_width = f_Width(mt);
			int f_hight = f_Hight(mt);
			int s_width = s_Width(mt);
			int s_hight = s_Hight(mt);
			int t_width = t_Width(mt);
			int t_hight = t_Hight(mt);


			for (int a = 0; a < 20; a++)
			{
				for (int c = 0; c < 3; c++)
				{
					MapChipList[a][f_width + c] = 2;
					MapChipList[a][s_width + c] = 2;
					MapChipList[a][t_width + c] = 2;
				}

			}

			beamVerticality[0].m_pos_x = f_width * 40 + 80;
			beamVerticality[1].m_pos_x = s_width * 40 + 80;
			beamVerticality[2].m_pos_x = t_width * 40 + 80;

			for (int a = 0; a < 28; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					MapChipList[f_hight + b][a] = 2;
					MapChipList[s_hight + b][a] = 2;
					MapChipList[t_hight + b][a] = 2;
				}
			}

			beamSide[0].m_pos_y = f_hight * 40 + 80;
			beamSide[1].m_pos_y = s_hight * 40 + 80;
			beamSide[2].m_pos_y = t_hight * 40 + 80;

			count->draw_beam = 0;
			count->draw_beam_indication = 0;
			beam->DrawStatus = 2;


		}



		if (count->draw_beam == (60 * 2))
		{
			for (int a = 0; a < 20; a++)
			{
				for (int b = 0; b < 28; b++)
				{
					if (MapChipList[a][b] == 2)
					{
						MapChipList[a][b] = 1;
					}
				}
			}
		}



		/////////////////////////////////////////////////////////////////////// 描画関連 /////////////////////////////////////////////////////////////////


		if (count->draw_beam == 120)
		{
			for (int a = 0; a < 3; a++)
			{
				beamVerticality[a].BeamVerticalityeFlag = true;
				beamSide[a].BeamSideFlag = true;
			}
			
			beam->DrawStatus = 0;
		}

	}
}

// ビーム描画(2*2)
void SetBeam_four(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, Beam* beam)
{
	if (beam->GameLevel == 2)
	{
		if (count->draw_beam_indication == (60 * 8))
		{
			std::mt19937 mt{ std::random_device{}() };

			std::uniform_int_distribution<int> f_Width(1, 12); // 1 28
			std::uniform_int_distribution<int> f_Hight(1, 8); // 1 20
			std::uniform_int_distribution<int> s_Width(13, 25); // 1 28
			std::uniform_int_distribution<int> s_Hight(9, 17); // 1 20

			int f_width = f_Width(mt);
			int f_hight = f_Hight(mt);
			int s_width = s_Width(mt);
			int s_hight = s_Hight(mt);


			for (int a = 0; a < 20; a++)
			{
				for (int c = 0; c < 3; c++)
				{
					MapChipList[a][f_width + c] = 2;
					MapChipList[a][s_width + c] = 2;
				}

			}

			beamVerticality[0].m_pos_x = f_width * 40 + 80;
			beamVerticality[1].m_pos_x = s_width * 40 + 80;

			for (int a = 0; a < 28; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					MapChipList[f_hight + b][a] = 2;
					MapChipList[s_hight + b][a] = 2;
				}
			}

			beamSide[0].m_pos_y = f_hight * 40 + 80;
			beamSide[1].m_pos_y = s_hight * 40 + 80;

			beam->draw_beam_state = 2;
			count->draw_beam = 0;
			count->draw_beam_indication = 0;
			beam->DrawStatus = 2;


		}



		if (count->draw_beam == (60 * 2))
		{

			for (int a = 0; a < 20; a++)
			{
				for (int b = 0; b < 28; b++)
				{
					if (MapChipList[a][b] == 2)
					{
						MapChipList[a][b] = 1;
					}
				}
			}
		}



		/////////////////////////////////////////////////////////////////////// 描画関連 /////////////////////////////////////////////////////////////////


		if (count->draw_beam == 120)
		{
			beamVerticality[0].BeamVerticalityeFlag = true;
			beamVerticality[1].BeamVerticalityeFlag = true;
			beamSide[0].BeamSideFlag = true;
			beamSide[1].BeamSideFlag = true;

			beam->DrawStatus = 0;
		}

	}
}

// ビーム描画(1*1)
void SetBeam_two(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, Beam* beam)
{
	if (beam->GameLevel == 1)
	{
		if (count->draw_beam_indication == (60 * 8))
		{
			std::mt19937 mt{ std::random_device{}() };

			std::uniform_int_distribution<int> r_Width(1, 25); // 1 28
			std::uniform_int_distribution<int> r_Hight(1, 17); // 1 20

			int width = r_Width(mt);
			int hight = r_Hight(mt);

			for (int a = 0; a < 20; a++)
			{
				for (int c = 0; c < 3; c++)
				{
					MapChipList[a][width + c] = 2;

				}

			}

			beamVerticality[0].m_pos_x = width * 40 + 80;


			for (int a = 0; a < 28; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					MapChipList[hight + b][a] = 2;
				}
			}

			beamSide[0].m_pos_y = hight * 40 + 80;

			beam->draw_beam_state = 1;
			count->draw_beam = 0;
			count->draw_beam_indication = 0;
			beam->DrawStatus = 2;

		}



		if (count->draw_beam == (60 * 2))
		{

			for (int a = 0; a < 20; a++)
			{
				for (int b = 0; b < 28; b++)
				{
					if (MapChipList[a][b] == 2)
					{
						MapChipList[a][b] = 1;
					}
				}
			}
		}


		/////////////////////////////////////////////////////////////////////// 描画関連 /////////////////////////////////////////////////////////////////


		if (count->draw_beam == 120)
		{
			beamVerticality[0].BeamVerticalityeFlag = true;

			beamSide[0].BeamSideFlag = true;

			beam->DrawStatus = 0;
		}

	}
}


// ビーム(予兆)の描画設定(一本の時のみ)
void SetBeam_first(Count* count, int MapChipList[20][28], BeamSide beamSide[], BeamVerticality beamVerticality[], int BeamNnmber,Beam * beam)
{
	if (beam->GameLevel == 0)
	{
		if (count->draw_beam_indication == (60 * 8))
		{
			std::mt19937 mt{ std::random_device{}() };

			std::uniform_int_distribution<int> swich(1, 2);
			std::uniform_int_distribution<int> r_Width(1, 25); // 1 28
			std::uniform_int_distribution<int> r_Hight(1, 17); // 1 20

			beam->beam_direction = swich(mt);
			int width = r_Width(mt);
			int hight = r_Hight(mt);

			switch (beam->beam_direction)
			{
			case 0:
				break;
			case 1: //widht

				for (int a = 0; a < 20; a++)
				{
					for (int c = 0; c < 3; c++)
					{
						MapChipList[a][width + c] = 2;

					}

				}
				beamVerticality[0].m_pos_x = width * 40 + 80;
				break;

			case 2: // hight

				for (int a = 0; a < 28; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						MapChipList[hight + b][a] = 2;
					}
				}
				beamSide[0].m_pos_y = hight * 40 + 80;

				break;
			}
			beam->draw_beam_state = 1;
			count->draw_beam = 0;
			count->draw_beam_indication = 0;
			beam->DrawStatus = 1;

		}



		if (count->draw_beam == (60 * 2))
		{

			for (int a = 0; a < 20; a++)
			{
				for (int b = 0; b < 28; b++)
				{
					if (MapChipList[a][b] == 2)
					{
						MapChipList[a][b] = 1;
					}
				}
			}
		}


		/////////////////////////////////////////////////////////////////////// 描画関連 /////////////////////////////////////////////////////////////////



		if (count->draw_beam == 120)
		{

			if (beam->beam_direction == 1)
			{
				beamVerticality[0].BeamVerticalityeFlag = true;
				beam->DrawStatus = 0;
			}
			else if (beam->beam_direction == 2)
			{
				beamSide[0].BeamSideFlag = true;
				beam->DrawStatus = 0;
			}

		}

	}

}

// ビームのモーション設定
void BeamMotio(Count* count, BeamSide beamSide[], BeamVerticality beamVerticality[],Beam* beam)
{

	if ((beamVerticality[0].BeamVerticalityeFlag == true) || (beamSide[0].BeamSideFlag == true))
	{
		for (int a = 0; a < 3; a++)
		{
			switch (count->draw_beam)
			{
			case 125:
				beamSide[a].InputSidePosTv(120, 240);
				beamVerticality[a].InputVerticalityPosTu(120, 240);
				break;
			case 130:
				beamSide[a].InputSidePosTv(240, 360);
				beamVerticality[a].InputVerticalityPosTu(240, 360);
				break;
			case 135:
				beamSide[a].InputSidePosTv(360, 480);
				beamVerticality[a].InputVerticalityPosTu(360, 480);
				break;
			case 140:
				beamSide[a].InputSidePosTv(480, 600);
				beamVerticality[a].InputVerticalityPosTu(480, 600);
				break;
			case 145:
				beamSide[a].InputSidePosTv(600, 720);
				beamVerticality[a].InputVerticalityPosTu(600, 720);
				break;
			case 150:
				beamSide[a].InputSidePosTv(720, 840);
				beamVerticality[a].InputVerticalityPosTu(720, 840);
				break;
			case 160:
				beamSide[a].InputSidePosTv(840, 960);
				beamVerticality[a].InputVerticalityPosTu(840, 960);
				break;
			case 170:
				beamSide[a].InputSidePosTv(960, 1080);
				beamVerticality[a].InputVerticalityPosTu(960, 1080);
				break;
			case 180:
				beamSide[a].InputSidePosTv(840, 960);
				beamVerticality[a].InputVerticalityPosTu(840, 960);
				break;
			case 190:
				beamSide[a].InputSidePosTv(960, 1080);
				beamVerticality[a].InputVerticalityPosTu(960, 1080);
				break;
			case 200:
				beamSide[a].InputSidePosTv(840, 960);
				beamVerticality[a].InputVerticalityPosTu(840, 960);
				break;
			case 210:
				beamSide[a].InputSidePosTv(960, 1080);
				beamVerticality[a].InputVerticalityPosTu(960, 1080);
				break;
			case 220:
				beamSide[a].InputSidePosTv(840, 960);
				beamVerticality[a].InputVerticalityPosTu(840, 960);
				break;
			case 230:
				beamSide[a].InputSidePosTv(1080, 1200);
				beamVerticality[a].InputVerticalityPosTu(1080, 1200);
				break;
			case 240:
				beamSide[a].InputSidePosTv(0, 120);
				beamVerticality[a].InputVerticalityPosTu(0, 120);
				break;
			}

		}
	}

	if (count->draw_beam == 240)
	{
		for (int a = 0; a < 3; a++)
		{

			beam->draw_beam_state = 0;
			beamSide[a].BeamSideFlag = false;
			beamVerticality[a].BeamVerticalityeFlag = false;
		}
	}


}