#ifndef ENEMY_H
#define ENEMY_H

#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"


void DrawEnemy(Count* count, VariableNumber* var, int MapChipList[20][28], Enemy_Green e_green[], Enemy_White e_white[]);

void EnemyMove(Count* count, VariableNumber* var, Enemy_Green e_green[], Enemy_White e_white[]);


#endif // !