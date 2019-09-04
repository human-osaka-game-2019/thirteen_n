#include <random>
#include <iostream>

#include"Engine.h"
#include"Device.h"
#include"Scene.h"

#include"Bullet.h"
#include"InputKey.h"
#include"MainCaracter.h"


void MainCharacter::InputTv(int Tu, int Tu_Size)
{
	m_pos_tu= (float)Tu / 1024;
	m_pos_tu_size = (float)Tu_Size / 1024;
}

// 10フレーム経たないと動かない(合計10フレーム,1フレーム X座標 +- 4 )

void MoveCharacter(Count* count, KeyState* keyState, MainCharacter* mainCara)
{
	if (count->re_input_move_key < 10)
	{
		switch (keyState->Move)
		{
		case 0:
			break;
		case 1:
			mainCara->m_pos_y = mainCara->m_pos_y + 4;
			break;
		case 2:
			mainCara->m_pos_y = mainCara->m_pos_y - 4;
			break;
		case 3:
			mainCara->m_pos_x= mainCara->m_pos_x - 4;
			break;
		case 4:
			mainCara->m_pos_x = mainCara->m_pos_x + 4;
			break;
		}
	}
}

// 自キャラのモーション
void CharTextureChange(Count* count, MainCharacter* mainCara, Bullet* bullet)
{
	mainCara->Add_TvSize = 160 * count->BulletCount;

	if (count->draw_main_caracter == 10)
	{
		mainCara->InputTv(80 + mainCara->Add_TvSize, 120 + mainCara->Add_TvSize);
	}
	else
		if (count->draw_main_caracter == 20)
		{
			mainCara->InputTv(120 + mainCara->Add_TvSize, 160 + mainCara->Add_TvSize);
		}
		else
			if (count->draw_main_caracter == 30)
			{
				mainCara->InputTv(160 + mainCara->Add_TvSize, 200 + mainCara->Add_TvSize);
			}
			else
				if (count->draw_main_caracter == 40)
				{
					mainCara->InputTv(120 + mainCara->Add_TvSize, 160 + mainCara->Add_TvSize);
				}
				else
					if (count->draw_main_caracter == 50)
					{
						mainCara->InputTv(80 + mainCara->Add_TvSize, 120 + mainCara->Add_TvSize);
					}
					else
						if (count->draw_main_caracter == 60)
						{
							mainCara->InputTv(40 + mainCara->Add_TvSize, 80 + mainCara->Add_TvSize);
						}

	if (count->draw_main_caracter > 60)
	{
		count->draw_main_caracter = 0;
	}

}


// 10フレームたったら再度キー入力できるようになる
void FrameCount(Count* count, KeyState* keyState)
{
	if (count->re_input_move_key > 10)
	{
		count->re_input_move_key = 0;
		keyState->Move = 0;
	}
}

// ゲーム画面の当たり判定
void HitJudge(MainCharacter* mainCara)
{

	if (mainCara->m_pos_x < 80)
	{
		mainCara->m_pos_x = mainCara->m_pos_x + 4;
	}
	else
		if (mainCara->m_pos_x > 1160)
		{
			mainCara->m_pos_x = mainCara->m_pos_x - 4;
		}
		else
			if (mainCara->m_pos_y < 80)
			{
				mainCara->m_pos_y = mainCara->m_pos_y + 4;
			}
			else
				if (mainCara->m_pos_y > 840)
				{
					mainCara->m_pos_y = mainCara->m_pos_y - 4;
				}

}
