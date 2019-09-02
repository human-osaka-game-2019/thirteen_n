#ifndef METEORITE_H
#define METEORITE_H

#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"


void DrawMeteorite(Count* count, VariableNumber* var, int MapChipList[20][28], Meteorite meteorite[]);

void DrawMeteoriteTwo(Count* count, VariableNumber* var, int MapChipList[20][28], Meteorite meteorite[]);

void HitCharMeteorite(Meteorite meteorite[], MainChar* mainChar, Count* count, KeyState* keyState);


#endif // !