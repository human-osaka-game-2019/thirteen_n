#ifndef STAR_H
#define STAR_H

#include"Engine.h"
#include"Device.h"
#include"GameScene.h"


class Star
{
public:
	float m_pos_x;
	float m_pos_y;
	float m_draw_size = 40;
	float m_pos_tu = (float)840 / 1024;
	float m_pos_tu_size = (float)880 / 1024;
	void InputTuSize(int tu,int TuSize);
	float m_pos_tv = (float)0 / 512;
	float m_pos_tv_size = (float)40 / 512;
	bool DrawFlag = false;

};

class Constellation
{
public:
	float m_pos_x;
	float m_pos_y;
	float m_x_size;
	float m_y_size;

	float m_tu;
	float m_tv;
	float m_tu_size;
	float m_tv_size;

	int DrawFlag = 0;

	void InputValue(float x, float y, float x_size, float y_size, float tu, float tv, float tu_size, float tv_size);

};

void DrawStar(Star star[12], Count* count);

void HitBulletStar(MainCharacter* mainCara, Star star[12], Count* count, KeyState* keyState);

void StarMotion(Count* count, Star star[]);

void Drawconstellation(DirectX* directX, TEXTUREDATA GameTextureData, Count* count, Constellation constellation[]);

#endif // !