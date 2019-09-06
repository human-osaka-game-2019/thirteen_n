#ifndef ENEMY_H
#define ENEMY_H

#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include"Bullet.h"

class Enemy
{
public:
	int EnemyState;
	int EnemyDrawState;
};

class Enemy_Green
{
public:

	float m_pos_x;
	float m_pos_y;
	float m_draw_size = 40;
	float m_pos_tu = (float)0 / 1024;
	float m_pos_tu_size = (float)40 / 1024;
	void InputTu(float tu, float tuSize);

	float m_pos_tv = (float)80 / 512;
	float m_pos_tv_size = (float)120 / 512;

	int m_draw_flag = 0;

};

class Enemy_White
{
public:

	float m_pos_x;
	float m_pos_y;
	float m_draw_size = 40;
	float m_pos_tu = (float)0 / 1024;
	float m_pos_tu_size = (float)40 / 1024;
	void InputTu(float tu, float tuSize);

	float m_pos_tv = (float)120 / 512;
	float m_pos_tv_size = (float)160 / 512;

	int m_draw_flag = 0;

};

void DrawEnemy(Count* count  , int MapChipList[20][28], Enemy_Green e_green[], Enemy_White e_white[], Enemy* enemy);

void EnemyMove(Count* count  , Enemy_Green e_green[], Enemy_White e_white[], Enemy* enemy);

void EnemyMotion(Count* count, Enemy_Green e_green[], Enemy_White e_white[], Enemy* enemy);

#endif // !