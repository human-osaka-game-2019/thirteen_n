#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

#include"Bullet.h"
#include"InputKey.h"
#include"MainCaracter.h"

/*
void Shot(Bullet bullet[5], KeyState* keyState)
{
	switch (keyState->m_shot)
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
		if (((int)mainCara->m_pos_x % 40 == 0) && ((int)mainCara->m_pos_y % 40 == 0))
		{
			bullet[0].m_pos_x = mainCara->m_pos_x;
			bullet[0].m_pos_y = mainCara->m_pos_y;
		}
		else
		{
			bullet[0].m_pos_x = (int)((int)mainCara->m_pos_x / 40) * 40;
			bullet[0].m_pos_y = (int)((int)mainCara->m_pos_y / 40) * 40;
		}

	}

	if (bullet[0].ShotFlag == true)
	{
		switch (keyState->m_shot)
		{
		case 0:
			break;
		case 1:
			bullet[0].m_pos_y = bullet[0].m_pos_y + 5;
			break;
		case 2:
			bullet[0].m_pos_y = bullet[0].m_pos_y - 5;
			break;
		case 3:
			bullet[0].m_pos_x = bullet[0].m_pos_x - 5;
			break;
		case 4:
			bullet[0].m_pos_x = bullet[0].m_pos_x + 5;
			break;
		}
	}

}

// 弾丸のあたり判定
void ShotHitJudge(Bullet bullet[5], KeyState* keyState, MainCharacter* mainCara)
{
	if (bullet[0].m_pos_x < 80)
	{
		bullet[0].ShotFlag = false;
		keyState->m_shot = 0;
		bullet[0].m_pos_x = mainCara->m_pos_x;
		bullet[0].m_pos_y = mainCara->m_pos_y;
	}
	else
		if (bullet->m_pos_x > 1160)
		{
			bullet[0].ShotFlag = false;
			keyState->m_shot = 0;
			bullet[0].m_pos_x = mainCara->m_pos_x;
			bullet[0].m_pos_y = mainCara->m_pos_y;
		}
		else
			if (bullet->m_pos_y < 80)
			{
				bullet[0].ShotFlag = false;
				keyState->m_shot = 0;
				bullet[0].m_pos_x = mainCara->m_pos_x;
				bullet[0].m_pos_y = mainCara->m_pos_y;
			}
			else
				if (bullet->m_pos_y > 840)
				{
					bullet[0].ShotFlag = false;
					keyState->m_shot = 0;
					bullet[0].m_pos_x = mainCara->m_pos_x;
					bullet[0].m_pos_y = mainCara->m_pos_y;
				}
}
