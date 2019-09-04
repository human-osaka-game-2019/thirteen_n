#ifndef METEORITE_H
#define METEORITE_H


#include"Engine.h"
#include"Device.h"
#include"GameScene.h"


class Meteorite
{
public:
	float m_pos_x;
	float m_pos_y;
	float m_DrawSize = 40;
	float m_pos_tu = (float)80 / 1024;
	float m_Tu_Size = (float)120 / 1024;
	float m_pos_tv = (float)40 / 512;
	float m_tv_size = (float)80 / 512;

	int MeteoriteState;
	int MeteoriteDrawState;
	int MeteoriteDrawStateTwo;
};


void DrawMeteorite(Count* count  , int MapChipList[20][28], Meteorite meteorite[]);

void DrawMeteoriteTwo(Count* count  , int MapChipList[20][28], Meteorite meteorite[]);

void HitCharMeteorite(Meteorite meteorite[], MainCharacter* mainCara, Count* count, KeyState* keyState);



#endif // !