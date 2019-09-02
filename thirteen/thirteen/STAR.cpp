#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include <random>
#include <iostream>

// 星の描画
void StarDraw(Star star[12], Count* count)
{
	if (count->StarDrawCount == (5 * 60))
	{
		for (int a = 0; a < 4; a++)
		{
			if (star[a].DrawFlag == false)
			{
				std::mt19937 mt{ std::random_device{}() };

				std::uniform_int_distribution<int> With(0, 27);
				std::uniform_int_distribution<int> Height(0, 19);

				int with = With(mt);
				int height = Height(mt);

				star[a].m_PosX = with * 40 + 80;
				star[a].m_PosY = height * 40 + 80;

				star[a].DrawFlag = true;
			}

		}

		count->StarDrawCountReset();
	}


}

// 星と弾丸のあたり判定
void HitBulletStar(MainChar* mainChar, Star star[12], Count* count, KeyState* keyState)
{

	for (int a = 0; a < 12; a++)
	{

		if ((mainChar->m_PosX + 40 > star[a].m_PosX /*玉の右のあたり判定*/) && (mainChar->m_PosX < star[a].m_PosX + 40)/*玉の左のあたり判定*/)
		{

			if ((mainChar->m_PosY < star[a].m_PosY + 40)/*玉が下から当たった時ののあたり判定*/ && (mainChar->m_PosY + 40 > star[a].m_PosY/*玉が上から当たった時のあたり判定*/))
			{
				count->StarCount = count->StarCount + 1;
				star[a].DrawFlag = false;

				star[a].m_PosX = 0;
				star[a].m_PosY = 0;

				if (count->BulletCount > 0 && count->BulletCount < 5)
				{
					count->BulletCount = count->BulletCount - 1;
				}
			}
		}
	}
}

