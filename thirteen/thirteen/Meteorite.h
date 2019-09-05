#ifndef METEORITE_H
#define METEORITE_H


#include"Engine.h"
#include"Device.h"
#include"GameScene.h"
#include"Scene.h"
#include"MainCaracter.h"
#include"Bullet.h"

class Meteorite
{
public:
	float m_pos_x;
	float m_pos_y;
	float m_draw_size = 40;
	float m_pos_tu = (float)0 / 1024;
	float m_Tu_Size = (float)40 / 1024;
	float m_pos_tv = (float)40 / 512;
	float m_tv_size = (float)80 / 512;
	void InputTu(int Tu, int TuSize);

	int MeteoriteState;
	int MeteoriteDrawState;
	int MeteoriteDrawStateTwo;
	int MeteoriteBreakFlag = 0;
};


void DrawMeteorite(Count* count  , int MapChipList[20][28], Meteorite meteorite[]);

void DrawMeteoriteTwo(Count* count  , int MapChipList[20][28], Meteorite meteorite[]);

void HitCharMeteorite(Meteorite meteorite[], MainCharacter* mainCara, Count* count, KeyState* keyState);

void HiBulletMeteorite(Meteorite meteorite[], Bullet bullet[], Count* count, MeteoMotion  meteoMotion[], KeyState keyState[]);

void DrawBreakMeteorite(Meteorite meteorite[], MeteoMotion  meteoMotion[]);



#endif // !