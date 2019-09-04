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
	float m_pos_tu = (float)0 / 1024;
	float m_pos_tu_size = (float)40 / 1024;
	float m_pos_tv = (float)80 / 512;
	float m_pos_tv_size = (float)120 / 512;
	bool DrawFlag = false;

};

void DrawStar(Star star[12], Count* count);

void HitBulletStar(MainCharacter* mainCara, Star star[12], Count* count, KeyState* keyState);

#endif // !