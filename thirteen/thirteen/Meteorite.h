#ifndef METEORITE_H
#define METEORITE_H


#include"Engine.h"
#include"Device.h"
#include"GameScene.h"


class Meteorite
{
public:
	float m_PosX;
	float m_PosY;
	float m_DrawSize = 40;
	float m_PosTu = (float)80 / 1024;
	float m_Tu_Size = (float)120 / 1024;
	float m_Postv = (float)40 / 512;
	float m_Tv_Size = (float)80 / 512;
};


void DrawMeteorite(Count* count, VariableNumber* var, int MapChipList[20][28], Meteorite meteorite[]);

void DrawMeteoriteTwo(Count* count, VariableNumber* var, int MapChipList[20][28], Meteorite meteorite[]);

void HitCharMeteorite(Meteorite meteorite[], MainCharacter* mainCara, Count* count, KeyState* keyState);



#endif // !