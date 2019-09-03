#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

#include"InputKey.h"
#include"MainCaracter.h"
#include"Star.h"

#include <random>
#include <iostream>

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

				star[a].m_PosX = width * 40 + 80;
				star[a].m_PosY = height * 40 + 80;

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

		if ((mainCara->m_PosX + 40 > star[a].m_PosX /*玉の右のあたり判定*/) && (mainCara->m_PosX < star[a].m_PosX + 40)/*玉の左のあたり判定*/)
		{

			if ((mainCara->m_PosY < star[a].m_PosY + 40)/*玉が下から当たった時ののあたり判定*/ && (mainCara->m_PosY + 40 > star[a].m_PosY/*玉が上から当たった時のあたり判定*/))
			{
				count->StarCount = count->StarCount + 1;
				star[a].DrawFlag = false;

				star[a].m_PosX = 0;
				star[a].m_PosY = 0;

			}
		}
	}
}

