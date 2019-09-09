#include"Engine.h"
#include"Device.h"
#include <SoundsManager.h>

#include"Bullet.h"
#include"InputKey.h"
#include"TitleSystem.h"

#include <random>
#include <iostream>

void InputTextureStatus(float x, float y, float x_size, float y_size, float tu, float tv, float tu_size, float tv_size, SelectTexture selectTexture[],int a)
{
	selectTexture[a].m_pos_x = x;
	selectTexture[a].m_x_size  = x_size;
	selectTexture[a].m_pos_y   = y;
	selectTexture[a].m_y_size  = y_size;
	selectTexture[a].m_pos_tu  = tu / 512;
	selectTexture[a].m_tu_size = (tu_size + tu) / 512;
	selectTexture[a].m_pos_tv  = tv / 512;
	selectTexture[a].m_tv_size = (tv_size + tv) / 512;

}

void SelectTexture::InputTu(float tu, float tu_size)
{

	float m_pos_tu =  (float) tu / 512;
	float m_tu_size = (float)(tu_size + tu) / 512;

}

void TextureDataSet(SelectTexture selectTexture[])
{
	InputTextureStatus(832, 620, 256, 90, 256, 0, 256, 90, selectTexture,0);
	InputTextureStatus(884, 711, 256, 90, 0, 90, 256, 90, selectTexture,1);
	InputTextureStatus(956, 792, 256, 90, 0, 180, 256, 90, selectTexture,2);
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

void SelectMenu(TitleSystem* titleSystem, KeyState* keyState,SelectTexture selectTexture[], FlameCount flamCount[])
{
	if (titleSystem->KeyState == 0)
	{

	}

	if (flamCount[1].m_count == 30)
	{
		switch (titleSystem->KeyState)
		{
		case Up:
			if (selectTexture[2].m_pos_tu == 0.5)
			{
				selectTexture[1].m_pos_tu = (float)256 / 512;
				selectTexture[1].m_tu_size = (float)512 / 512;
				selectTexture[2].m_pos_tu = (float)0 / 512;
				selectTexture[2].m_tu_size = (float)256 / 512;
			}else
				if (selectTexture[0].m_pos_tu == 0.5)
				{
					selectTexture[2].m_pos_tu = (float)256 / 512;
					selectTexture[2].m_tu_size = (float)512 / 512;
					selectTexture[0].m_pos_tu = (float)0 / 512;
					selectTexture[0].m_tu_size = (float)256 / 512;
				}
				else
					if (selectTexture[1].m_pos_tu == 0.5)
					{
						selectTexture[0].m_pos_tu = (float)256 / 512;
						selectTexture[0].m_tu_size = (float)512 / 512;
						selectTexture[1].m_pos_tu = (float)0 / 512;
						selectTexture[1].m_tu_size = (float)256 / 512;
					}
			flamCount[1].m_count = 0;
			titleSystem->KeyState = 0;
			break;

		case Down:
			if (selectTexture[2].m_pos_tu == 0.5)
			{
				selectTexture[0].m_pos_tu = (float)256 / 512;
				selectTexture[0].m_tu_size = (float)512 / 512;
				selectTexture[2].m_pos_tu = (float)0 / 512;
				selectTexture[2].m_tu_size = (float)256 / 512;
			}
			else
				if (selectTexture[1].m_pos_tu == 0.5)
				{
					selectTexture[2].m_pos_tu = (float)256 / 512;
					selectTexture[2].m_tu_size = (float)512 / 512;
					selectTexture[1].m_pos_tu = (float)0 / 512;
					selectTexture[1].m_tu_size = (float)256 / 512;
				}
				else
					if (selectTexture[0].m_pos_tu == 0.5)
					{
						selectTexture[1].m_pos_tu = (float)256 / 512;
						selectTexture[1].m_tu_size = (float)512 / 512;
						selectTexture[0].m_pos_tu = (float)0 / 512;
						selectTexture[0].m_tu_size = (float)256 / 512;
					}
			flamCount[1].m_count = 0;
			titleSystem->KeyState = 0;
			break;
		}

		flamCount[1].m_count = 0;
	}

}