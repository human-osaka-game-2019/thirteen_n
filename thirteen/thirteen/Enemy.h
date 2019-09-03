#ifndef ENEMY_H
#define ENEMY_H

#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

class Enemy
{
public:
	int EnemyState;
	int EnemyDrawState;
};

class Enemy_Green
{
public:

	float m_PosX;
	float m_PosY;
	float m_DrawSize = 40;
	float m_PosTu = (float)0 / 1024;
	float m_PosTu_Size = (float)40 / 1024;
	float m_PosTv = (float)40 / 512;
	float m_PosTv_Size = (float)80 / 512;

};

class Enemy_White
{
public:

	float m_PosX;
	float m_PosY;
	float m_DrawSize = 40;
	float m_PosTu = (float)40 / 1024;
	float m_PosTu_Size = (float)80 / 1024;
	float m_PosTv = (float)40 / 512;
	float m_PosTv_Size = (float)80 / 512;

};

void DrawEnemy(Count* count  , int MapChipList[20][28], Enemy_Green e_green[], Enemy_White e_white[], Enemy* enemy);

void EnemyMove(Count* count  , Enemy_Green e_green[], Enemy_White e_white[], Enemy* enemy);


#endif // !