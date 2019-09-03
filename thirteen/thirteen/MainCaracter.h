#ifndef MAINCARA_H
#define MAINCARA_H

#include"Engine.h"
#include"Device.h"

class MainCharacter
{
public:
	float m_PosX = 80;
	float m_PosY = 80;
	float DrawSize = 40;
	float m_PosTu = (float)40 / 1024;
	float m_PosTu_Size = (float)80 / 1024;
	float m_PosTv = (float)0 / 512;
	float m_PosTv_Size = (float)40 / 512;

	float Add_TvSize;
	void InputTv(int Tv, int Tv_Size);
};

void MoveCharacter(Count* count, KeyState* keyState, MainCharacter* mainCara);

void CharTextureChange(Count* count, MainCharacter* mainCara, Bullet* bullet);

void FrameCount(Count* count, KeyState* keyState);

void HitJudge(MainCharacter* mainCara);

void ShotMove(KeyState* keyState, Bullet bullet[5], MainCharacter* mainCara);

void ShotHitJudge(Bullet bullet[5], KeyState* keyState, MainCharacter* mainCara);

#endif // !