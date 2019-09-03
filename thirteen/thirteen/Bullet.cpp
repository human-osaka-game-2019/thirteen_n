#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

#include"Bullet.h"
#include"InputKey.h"
#include"MainCaracter.h"

/*
void Shot(Bullet bullet[5], KeyState* keyState)
{
	switch (keyState->Shot)
	{
	case 0:
		break;
	case 1: // 一個目

		break;
	case 2: // 二個目

		break;
	case 3: // 三個目

		break;
	case 4: // 四個目

		break;
	case 5: // 五個目

		break;
	}
}
*/

// 弾丸の移動描画
void ShotMove(KeyState* keyState, Bullet bullet[5], MainCharacter* mainCara)
{

	if (bullet[0].ShotFlag == false)
	{
		if (((int)mainCara->m_PosX % 40 == 0) && ((int)mainCara->m_PosY % 40 == 0))
		{
			bullet[0].m_PosX = mainCara->m_PosX;
			bullet[0].m_PosY = mainCara->m_PosY;
		}
		else
		{
			bullet[0].m_PosX = (int)((int)mainCara->m_PosX / 40) * 40;
			bullet[0].m_PosY = (int)((int)mainCara->m_PosY / 40) * 40;
		}

	}

	if (bullet[0].ShotFlag == true)
	{
		switch (keyState->Shot)
		{
		case 0:
			break;
		case 1:
			bullet[0].m_PosY = bullet[0].m_PosY + 5;
			break;
		case 2:
			bullet[0].m_PosY = bullet[0].m_PosY - 5;
			break;
		case 3:
			bullet[0].m_PosX = bullet[0].m_PosX - 5;
			break;
		case 4:
			bullet[0].m_PosX = bullet[0].m_PosX + 5;
			break;
		}
	}

}

// 弾丸のあたり判定
void ShotHitJudge(Bullet bullet[5], KeyState* keyState, MainCharacter* mainCara)
{
	if (bullet[0].m_PosX < 80)
	{
		bullet[0].ShotFlag = false;
		keyState->Shot = 0;
		bullet[0].m_PosX = mainCara->m_PosX;
		bullet[0].m_PosY = mainCara->m_PosY;
	}
	else
		if (bullet->m_PosX > 1160)
		{
			bullet[0].ShotFlag = false;
			keyState->Shot = 0;
			bullet[0].m_PosX = mainCara->m_PosX;
			bullet[0].m_PosY = mainCara->m_PosY;
		}
		else
			if (bullet->m_PosY < 80)
			{
				bullet[0].ShotFlag = false;
				keyState->Shot = 0;
				bullet[0].m_PosX = mainCara->m_PosX;
				bullet[0].m_PosY = mainCara->m_PosY;
			}
			else
				if (bullet->m_PosY > 840)
				{
					bullet[0].ShotFlag = false;
					keyState->Shot = 0;
					bullet[0].m_PosX = mainCara->m_PosX;
					bullet[0].m_PosY = mainCara->m_PosY;
				}
}
