#ifndef BULLET_H
#define BULLET_H

#include"class.h"
#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

void HitBulletStar(MainChar* mainChar, Star star[12], Count* count, KeyState* keyState);

void Shot(Bullet bullet[5], KeyState* keyState);

void ShotMove(KeyState* keyState, Bullet bullet[5], MainChar* mainChar);

void ShotHitJudge(Bullet bullet[5], KeyState* keyState, MainChar* mainChar);

#endif // !