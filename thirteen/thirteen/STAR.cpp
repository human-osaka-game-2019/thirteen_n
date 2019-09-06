#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include <SoundsManager.h>

#include"InputKey.h"
#include"MainCaracter.h"
#include"Star.h"

#include <random>
#include <iostream>

extern SoundLib::SoundsManager m_soundsManager;

void Star::InputTuSize(int Tu, int TuSize)
{
	m_pos_tu = (float)Tu / 1024;
	m_pos_tu_size = (float)TuSize / 1024;
}

// 星の描画
void DrawStar(Star star[12], Count* count)
{
	if (count->DrawStarCount == (5 * 60))
	{
		for (int a = 0; a < 4; a++)
		{
			if (star[a].DrawFlag == false)
			{
				std::mt19937 mt{ std::random_device{}() };

				std::uniform_int_distribution<int> Width(0, 27);
				std::uniform_int_distribution<int> Height(0, 19);

				int width = Width(mt);
				int height = Height(mt);

				star[a].m_pos_x = width * 40 + 80;
				star[a].m_pos_y = height * 40 + 80;

				star[a].DrawFlag = true;
			}

		}

		count->DrawStarCountReset();
	}


}

// 星と自キャラ(操作キャラ)のあたり判定
void HitBulletStar(MainCharacter* mainCara, Star star[12], Count* count, KeyState* keyState)
{

	m_soundsManager.AddFile("Sound/GetStar.wav", "GetStar");
	m_soundsManager.SetVolume("GetStar", 15);

	for (int a = 0; a < 12; a++)
	{

		if ((mainCara->m_pos_x+ 40 > star[a].m_pos_x /*弾の右のあたり判定*/) && (mainCara->m_pos_x < star[a].m_pos_x + 40)/*弾の左のあたり判定*/)
		{

			if ((mainCara->m_pos_y < star[a].m_pos_y + 40)/*弾が下から当たった時ののあたり判定*/ && (mainCara->m_pos_y + 40 > star[a].m_pos_y/*弾が上から当たった時のあたり判定*/))
			{
				count->StarCount = count->StarCount + 1;
				star[a].DrawFlag = false;

				star[a].m_pos_x = 0;
				star[a].m_pos_y = 0;

				m_soundsManager.Start("GetStar");

			}

		}

	}

}

void StarMotion(Count* count, Star star[])
{
	for (int a = 0; a < 4; a++)
	{
		if (count->StarMotion == 15)
		{
			star[a].InputTuSize(880,920);
		}else
			if (count->StarMotion == 30)
			{
				star[a].InputTuSize(920, 960);
			}else
				if (count->StarMotion == 45)
				{
					star[a].InputTuSize(960, 1000);
				}else
					if (count->StarMotion == 60)
					{
						star[a].InputTuSize(840, 880);
					}
	} 

	if (count->StarMotion >= 60)
	{
		count->StarMotion = 0;
	}

}


void Constellation::InputValue(float x, float y, float x_size, float y_size, float tu, float tv, float tu_size, float tv_size)
{
	m_pos_x = x;
	m_pos_y = y;
	m_x_size = x_size;
	m_y_size = y_size;

	m_tu = (float)tu / 2048;
	m_tv = (float)tv / 2048;
	m_tu_size = (float)tu_size / 2048;
	m_tv_size = (float)tv_size / 2048;
}

void Drawconstellation(DirectX *directX, TEXTUREDATA GameTextureData,Count *count, Constellation constellation[])
{

	switch (count->StarCount)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;
	case 8:

		break;
	case 9:

		break;
	case 10:

		break;
	case 11:

		break;
	case 12:

		break;
	}

	for (int a = 0; a < 12; a++)
	{
		DrawTest(constellation[a].m_pos_x, constellation[a].m_pos_y, constellation[a].m_x_size, constellation[a].m_y_size, constellation[a].m_tu, constellation[a].m_tv, constellation[a].m_tu_size, constellation[a].m_tv_size, &GameTextureData.m_pTexture[GameTextureList::ConstellationTexture], *directX);
	}
}