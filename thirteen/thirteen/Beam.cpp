#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include <random>
#include <iostream>


// ビーム描画位置入力関数(横)
void BeamSide::InputSidePosTv(float Tv, float TvSize)
{
	m_PosTv = Tv / 1024;
	m_PosTv_Size = TvSize / 1024;
}

// ビーム描画位置入力関数(縦)
void BeamVerticality::InputVerticalityPosTv(float Tv, float TvSize)
{
	m_PosTu = Tv / 1024;
	m_PosTu_Size = TvSize / 1024;
}

// ビーム描画(複数)
void SetBeams(Count* count, VariableNumber* var, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, int WithDarwNumber, int HeightDrawNumber)
{
	std::mt19937 mt{ std::random_device{}() };

	for (int WithDrawCount = 0; WithDrawCount < WithDarwNumber; WithDrawCount++)
	{
		std::uniform_int_distribution<int> r_with(1, 25); // 1 28
		int with = r_with(mt);

		for (int a = 0; a < 20; a++)
		{
			for (int c = 0; c < 3; c++)
			{
				MapChipList[a][with + c] = 2;

			}

		}
		beamVerticality->m_PosX = with * 40 + 80;

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

		beamSide->m_PosY = hight * 40 + 80;

		break;
	}

}

// ビーム(予兆)の描画設定(一本の時のみ)
void SetBeam_first(Count* count, VariableNumber* var, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, int BeamNnmber)
{
	if (count->Frame3 == (60 * 8))
	{
		std::mt19937 mt{ std::random_device{}() };

		std::uniform_int_distribution<int> swich(1, 2);
		std::uniform_int_distribution<int> r_with(1, 25); // 1 28
		std::uniform_int_distribution<int> r_hight(1, 17); // 1 20

		var->temp = swich(mt);
		int with = r_with(mt);
		int hight = r_hight(mt);

		switch (var->temp)
		{
		case 0:
			break;
		case 1: // with

			for (int a = 0; a < 20; a++)
			{
				for (int c = 0; c < 3; c++)
				{
					MapChipList[a][with + c] = 2;

				}

			}
			beamVerticality->m_PosX = with * 40 + 80;
			break;

		case 2: // hight

			for (int a = 0; a < 28; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					MapChipList[hight + b][a] = 2;
				}
			}
			beamSide->m_PosY = hight * 40 + 80;

			break;
		}
		var->BeamState = 1;
		count->Frame2 = 0;
		count->Frame3 = 0;

	}


	if (var->BeamState == 1)
	{
		if (count->Frame2 == (60 * 2))
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


	if (count->Frame2 == 120)
	{
		if (var->temp == 1)
		{
			beamVerticality->BeamVerticalityeFlag = true;
		}
		else
			if (var->temp == 2)
			{
				beamSide->BeamSideFlag = true;

			}
	}

	if ((beamVerticality->BeamVerticalityeFlag == true) || (beamSide->BeamSideFlag == true))
	{
		if (count->Frame2 % 12 == 0)
		{
			if (count->Frame2 == 126)// 二個目
			{
				beamSide->InputSidePosTv(240, 360);
				beamVerticality->InputVerticalityPosTv(240, 360);

			}
			else
				if (count->Frame2 == 132)// 三個目
				{
					beamSide->InputSidePosTv(360, 480);
					beamVerticality->InputVerticalityPosTv(360, 480);
				}
				else
					if (count->Frame2 == 138) // 四個目
					{
						beamSide->InputSidePosTv(480, 600);
						beamVerticality->InputVerticalityPosTv(480, 600);
					}
					else
						if (count->Frame2 == 144)// 五個目
						{
							beamSide->InputSidePosTv(600, 720);
							beamVerticality->InputVerticalityPosTv(600, 720);
						}
						else
							if (count->Frame2 == 216)// 六個目
							{
								beamSide->InputSidePosTv(480, 600);
								beamVerticality->InputVerticalityPosTv(480, 600);
							}
							else
								if (count->Frame2 == 222)// 七個目
								{
									beamSide->InputSidePosTv(360, 480);
									beamVerticality->InputVerticalityPosTv(360, 480);
								}
								else
									if (count->Frame2 == 228)// 八個目
									{
										beamSide->InputSidePosTv(240, 360);
										beamVerticality->InputVerticalityPosTv(240, 360);
									}
									else
										if (count->Frame2 == 234)// 九個目
										{
											beamSide->InputSidePosTv(120, 240);
											beamVerticality->InputVerticalityPosTv(120, 240);
										}
										else
											if (count->Frame2 == 228)// 十個目
											{
												beamSide->InputSidePosTv(0, 120);
												beamVerticality->InputVerticalityPosTv(0, 120);
											}
		}
	}

	if (count->Frame2 == 240)
	{
		var->BeamState = 0;
		beamSide->BeamSideFlag = false;
		beamVerticality->BeamVerticalityeFlag = false;
	}


}

// ビームの描画処理
void DrawBeam()
{



}
