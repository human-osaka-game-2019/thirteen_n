#ifndef MAINCARA_H
#define MAINCARA_H

#include"Engine.h"
#include"Device.h"

class MainCharacter
{
public:
	float m_pos_x= 80;
	float m_pos_y= 80;
	float DrawSize = 40;
	float m_pos_tu = (float)40 / 1024;
	float m_pos_tu_size = (float)80 / 1024;
	float m_pos_tv = (float)0 / 512;
	float m_pos_tv_size = (float)40 / 512;

	float m_move_speed = 4;

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