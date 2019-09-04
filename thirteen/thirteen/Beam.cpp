#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

#include"Beam.h"

#include <random>
#include <iostream>


// ビーム描画位置入力関数(横)
void BeamSide::InputSidePosTv(float Tv, float TvSize)
{
	m_pos_tv = Tv / 1024;
	m_pos_tv_size = TvSize / 1024;
}

// ビーム描画位置入力関数(縦)
void BeamVerticality::InputVerticalityPosTv(float Tv, float TvSize)
{
	m_pos_tu = Tv / 1024;
	m_pos_tu_size = TvSize / 1024;
}

// ビーム描画(複数)
void SetBeams(Count* count  , int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, int WidthDarwNumber, int HeightDrawNumber)
{
	std::mt19937 mt{ std::random_device{}() };

	for (int WidthDrawCount = 0; WidthDrawCount < WidthDarwNumber; WidthDrawCount++)
	{
		std::uniform_int_distribution<int> r_width(1, 25); // 1 28
		int width = r_width(mt);

		for (int a = 0; a < 20; a++)
		{
			for (int c = 0; c < 3; c++)
			{
				MapChipList[a][width + c] = 2;

			}

		}
		beamVerticality->m_pos_x = width * 40 + 80;

	}

	for (int HeightDrawCount = 0; HeightDrawCount < HeightDrawNumber; HeightDrawCount++)
	{
		std::uniform_int_distribution<int> r_hight(1, 17); // 1 20
		int hight = r_hight(mt);

		for (int a = 0; a < 28; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				MapChipList[hight + b][a] = 2;
			}
		}

		beamSide->m_pos_y = hight * 40 + 80;

		break;
	}

}

// ビーム(予兆)の描画設定(一本の時のみ)
void SetBeam_first(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, int BeamNnmber,Beam * beam)
{
	if (count->draw_beam_indication == (60 * 8))
	{
		std::mt19937 mt{ std::random_device{}() };

		std::uniform_int_distribution<int> swich(1, 2);
		std::uniform_int_distribution<int> r_Width(1, 25); // 1 28
		std::uniform_int_distribution<int> r_hight(1, 17); // 1 20

		beam->beam_direction = swich(mt);
		int width = r_Width(mt);
		int hight = r_hight(mt);

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
			beamVerticality->m_pos_x = width * 40 + 80;
			break;

		case 2: // hight

			for (int a = 0; a < 28; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					MapChipList[hight + b][a] = 2;
				}
			}
			beamSide->m_pos_y = hight * 40 + 80;

			break;
		}
		beam->draw_beam_state = 1;
		count->draw_beam = 0;
		count->draw_beam_indication= 0;

	}


	if (beam->draw_beam_state == 1)
	{
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
	}

	/////////////////////////////////////////////////////////////////////// 描画関連 /////////////////////////////////////////////////////////////////


	if (count->draw_beam == 120)
	{
		if (beam->beam_direction == 1)
		{
			beamVerticality->BeamVerticalityeFlag = true;
		}
		else
			if (beam->beam_direction == 2)
			{
				beamSide->BeamSideFlag = true;

			}
	}

	if ((beamVerticality->BeamVerticalityeFlag == true) || (beamSide->BeamSideFlag == true))
	{
		if (count->draw_beam % 12 == 0)
		{
			if (count->draw_beam == 126)// 二個目
			{
				beamSide->InputSidePosTv(240, 360);
				beamVerticality->InputVerticalityPosTv(240, 360);

			}
			else
				if (count->draw_beam == 132)// 三個目
				{
					beamSide->InputSidePosTv(360, 480);
					beamVerticality->InputVerticalityPosTv(360, 480);
				}
				else
					if (count->draw_beam == 138) // 四個目
					{
						beamSide->InputSidePosTv(480, 600);
						beamVerticality->InputVerticalityPosTv(480, 600);
					}
					else
						if (count->draw_beam == 144)// 五個目
						{
							beamSide->InputSidePosTv(600, 720);
							beamVerticality->InputVerticalityPosTv(600, 720);
						}
						else
							if (count->draw_beam == 216)// 六個目
							{
								beamSide->InputSidePosTv(480, 600);
								beamVerticality->InputVerticalityPosTv(480, 600);
							}
							else
								if (count->draw_beam == 222)// 七個目
								{
									beamSide->InputSidePosTv(360, 480);
									beamVerticality->InputVerticalityPosTv(360, 480);
								}
								else
									if (count->draw_beam == 228)// 八個目
									{
										beamSide->InputSidePosTv(240, 360);
										beamVerticality->InputVerticalityPosTv(240, 360);
									}
									else
										if (count->draw_beam == 234)// 九個目
										{
											beamSide->InputSidePosTv(120, 240);
											beamVerticality->InputVerticalityPosTv(120, 240);
										}
										else
											if (count->draw_beam == 228)// 十個目
											{
												beamSide->InputSidePosTv(0, 120);
												beamVerticality->InputVerticalityPosTv(0, 120);
											}
		}
	}

	if (count->draw_beam == 240)
	{
		beam->draw_beam_state = 0;
		beamSide->BeamSideFlag = false;
		beamVerticality->BeamVerticalityeFlag = false;
	}


}

// ビームの描画処理
void DrawBeam()
{



}
