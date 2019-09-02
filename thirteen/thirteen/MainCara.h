#ifndef MAINCARA_H
#define MAINCARA_H

#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

void ChraMove(Count* count, KeyState* keyState, MainChar* mainChar);

void CharTextureChange(Count* count, MainChar* mainChar, Bullet* bullet);

void FrameCount(Count* count, KeyState* keyState);

void HitJudge(MainChar* mainChar);


#endif // !