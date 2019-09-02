#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include <random>
#include <iostream>

void MainChar::InputTv(int Tu, int Tu_Size)
{

	m_PosTu = (float)Tu / 1024;
	m_PosTu_Size = (float)Tu_Size / 1024;

}

// 10フレーム経たないと動かない(合計10フレーム,1フレーム X座標 +- 4 )

void ChraMove(Count* count, KeyState* keyState, MainChar* mainChar)
{
	if (count->Frame4 < 10)
	{
		switch (keyState->Move)
		{
		case 0:
			break;
		case 1:
			mainChar->m_PosY = mainChar->m_PosY + 4;
			break;
		case 2:
			mainChar->m_PosY = mainChar->m_PosY - 4;
			break;
		case 3:
			mainChar->m_PosX = mainChar->m_PosX - 4;
			break;
		case 4:
			mainChar->m_PosX = mainChar->m_PosX + 4;
			break;
		}
	}
}

// 自キャラのモーション
void CharTextureChange(Count* count, MainChar* mainChar, Bullet* bullet)
{
	mainChar->Add_TvSize = 160 * count->BulletCount;

	if (count->Frame10 == 10)
	{
		mainChar->InputTv(80 + mainChar->Add_TvSize, 120 + mainChar->Add_TvSize);
	}
	else
		if (count->Frame10 == 20)
		{
			mainChar->InputTv(120 + mainChar->Add_TvSize, 160 + mainChar->Add_TvSize);
		}
		else
			if (count->Frame10 == 30)
			{
				mainChar->InputTv(160 + mainChar->Add_TvSize, 200 + mainChar->Add_TvSize);
			}
			else
				if (count->Frame10 == 40)
				{
					mainChar->InputTv(120 + mainChar->Add_TvSize, 160 + mainChar->Add_TvSize);
				}
				else
					if (count->Frame10 == 50)
					{
						mainChar->InputTv(80 + mainChar->Add_TvSize, 120 + mainChar->Add_TvSize);
					}
					else
						if (count->Frame10 == 60)
						{
							mainChar->InputTv(40 + mainChar->Add_TvSize, 80 + mainChar->Add_TvSize);
						}

	if (count->Frame10 > 60)
	{
		count->Frame10 = 0;
	}

}


// 10フレームたったら再度キー入力できるようになる
void FrameCount(Count* count, KeyState* keyState)
{
	if (count->Frame4 > 10)
	{
		count->Frame4 = 0;
		keyState->Move = 0;
	}
}

// ゲーム画面の当たり判定
void HitJudge(MainChar* mainChar)
{

	if (mainChar->m_PosX < 80)
	{
		mainChar->m_PosX = mainChar->m_PosX + 4;
	}
	else
		if (mainChar->m_PosX > 1160)
		{
			mainChar->m_PosX = mainChar->m_PosX - 4;
		}
		else
			if (mainChar->m_PosY < 80)
			{
				mainChar->m_PosY = mainChar->m_PosY + 4;
			}
			else
				if (mainChar->m_PosY > 840)
				{
					mainChar->m_PosY = mainChar->m_PosY - 4;
				}

}
