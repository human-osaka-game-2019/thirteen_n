#include"Engine.h"
#include"Device.h"
#include <SoundsManager.h>

#include"Bullet.h"
#include"InputKey.h"
#include"TitleSystem.h"

#include <random>
#include <iostream>

void SelectTexture::InputTextureStatus(float x, float y, float x_size, float y_size, float tu, float tv, float tu_size, float tv_size)
{
	float m_pos_x = x;
	float m_x_size  = x_size;
	float m_pos_y   = y;
	float m_y_size  = y_size;
	float m_pos_tu  = tu / 512;
	float m_tu_size = (tu_size + tu) / 512;
	float m_pos_tv  = tv / 512;
	float m_tv_size = (tv_size + tv) / 512;

}

void SelectTexture::InputTu(float tu, float tu_size)
{

	float m_pos_tu = tu / 512;
	float m_tu_size = (tu_size + tu) / 512;

}

void InputSelectKey(TitleSystem *titleSystem, KeyState* keyState)
{
	if (GetKeyStatus(DIK_UP))
	{
		titleSystem->KeyState = Up;
	}else
		if (GetKeyStatus(DIK_DOWN))
		{
			titleSystem->KeyState = Down;
		}else
			if (GetKeyStatus(DIK_LEFT))
			{
				titleSystem->KeyState = Left;
			}else
				if (GetKeyStatus(DIK_RIGHT))
				{
					titleSystem->KeyState = Right;
				}

}

void SelectMenu(TitleSystem* titleSystem, KeyState* keyState,SelectTexture selectTexture[] )
{

	switch (titleSystem->KeyState)
	{
	case Up:
		if (selectTexture[2].m_pos_tu == 256)
		{
			selectTexture[1].InputTu(256, 256);
			selectTexture[2].InputTu(  0, 256);
		}
		if (selectTexture[1].m_pos_tu == 256)
		{
			selectTexture[0].InputTu(256, 256);
			selectTexture[1].InputTu(  0, 256);
		}
		break;
	case Down:
		selectTexture->InputTu();
		break;
	case Left:
		selectTexture->InputTu();
		break;
	case Right:
		selectTexture->InputTu();
		break;
	}




}