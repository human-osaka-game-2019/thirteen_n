#ifndef STAR_H
#define STAR_H

#include"Engine.h"
#include"Device.h"
#include"GameScene.h"


class Star
{
public:
	float m_PosX;
	float m_PosY;
	float m_DrawSize = 40;
	float m_PosTu = (float)0 / 1024;
	float m_PosTu_Size = (float)40 / 1024;
	float m_PosTv = (float)80 / 512;
	float m_PosTv_Size = (float)120 / 512;
	bool DrawFlag = false;

};

void DrawStar(Star star[12], Count* count);

void HitBulletStar(MainCharacter* mainCara, Star star[12], Count* count, KeyState* keyState);

#endif // !