#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

#include"InputKey.h"
#include"MainCaracter.h"
#include"Star.h"

#include <random>
#include <iostream>

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