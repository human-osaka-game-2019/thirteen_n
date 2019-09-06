#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

#include"Bullet.h"
#include"InputKey.h"
#include"MainCaracter.h"


// 弾丸の移動描画
void ShotMove(KeyState keyState[5], Bullet bullet[5], MainCharacter* mainCara)
{

	for (int a = 0; a < 5; a++)
	{
	
		if (bullet[a].ShotFlag == false)
		{

			if (((int)mainCara->m_pos_x % 40 == 0) && ((int)mainCara->m_pos_y % 40 == 0))
			{
				bullet[a].m_pos_x = mainCara->m_pos_x;
				bullet[a].m_pos_y = mainCara->m_pos_y;
			}
			else
			{
				bullet[a].m_pos_x = (int)((int)mainCara->m_pos_x / 40) * 40;
				bullet[a].m_pos_y = (int)((int)mainCara->m_pos_y / 40) * 40;
			}

		}
	}
	
	for (int b = 0; b < 5; b++)
	{
		if (bullet[b].ShotFlag == true)
		{

			switch (keyState[b].m_shot)
			{
			case 0:
				break;
			case 1:
				bullet[b].m_pos_y = bullet[b].m_pos_y + 5;
				break;
			case 2:
				bullet[b].m_pos_y = bullet[b].m_pos_y - 5;
				break;
			case 3:
				bullet[b].m_pos_x = bullet[b].m_pos_x - 5;
				break;
			case 4:
				bullet[b].m_pos_x = bullet[b].m_pos_x + 5;
				break;
			}

		
		}
	}
}

// 弾丸のあたり判定
void ShotHitJudge(Bullet bullet[5], KeyState keyState[5], MainCharacter* mainCara,Count *count)
{
	for (int a = 0; a < 12; a++)
	{

		if (bullet[a].m_pos_x < 80)
		{
			bullet[a].ShotFlag = false;
			keyState[a].m_shot = 0;
			bullet[a].m_pos_x = mainCara->m_pos_x;
			bullet[a].m_pos_y = mainCara->m_pos_y;
		}
		else
			if (bullet[a].m_pos_x > 1160)
			{
				bullet[a].ShotFlag = false;
				keyState[a].m_shot = 0;
				bullet[a].m_pos_x = mainCara->m_pos_x;
				bullet[a].m_pos_y = mainCara->m_pos_y;
			}
			else
				if (bullet[a].m_pos_y < 80)
				{
					bullet[a].ShotFlag = false;
					keyState[a].m_shot = 0;
					bullet[a].m_pos_x = mainCara->m_pos_x;
					bullet[a].m_pos_y = mainCara->m_pos_y;
				}
				else
					if (bullet[a].m_pos_y > 840)
					{
						bullet[a].ShotFlag = false;
						keyState[a].m_shot = 0;
						bullet[a].m_pos_x = mainCara->m_pos_x;
						bullet[a].m_pos_y = mainCara->m_pos_y;
					}
	}
}
