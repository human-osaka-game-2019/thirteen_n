#ifndef MAINCARA_H
#define MAINCARA_H

#include"Engine.h"
#include"Device.h"
#include"InputKey.h"
#include"Enemy.h"
#include"Beam.h"

class MainCharacter
{
public:
	float m_pos_x= 600;
	float m_pos_y= 440;
	float DrawSize = 40;
	float m_pos_tu = (float)40 / 1024;
	float m_pos_tu_size = (float)80 / 1024;
	float m_pos_tv = (float)0 / 512;
	float m_pos_tv_size = (float)40 / 512;

	float m_move_speed = 4;

	float Add_TvSize;
	void InputTv(int Tv, int Tv_Size);

	int DeathFlag = 0;
};

void CheckBulletDirectionKey(Count* count, KeyState ShotkeyState[5], Bullet bullet[5]);

void MoveCharacter(Count* count, KeyState* keyState, MainCharacter* mainCara);

void CharTextureChange(Count* count, MainCharacter* mainCara, Bullet* bullet);

void FrameCount(Count* count, KeyState* keyState);

void HitJudge(MainCharacter* mainCara);

void ShotMove(KeyState keyState[5], Bullet bullet[12], MainCharacter* mainCara);

void ShotHitJudge(Bullet bullet[12], KeyState keyState[5], MainCharacter* mainCara, Count* count);

void HitBulletEnemy(Bullet bullet[], Count* count, Enemy_Green e_green[], Enemy_White e_white[], KeyState ShotkeyState[], Enemy enemy);

void HitMainCaraEnemy(MainCharacter* mainCharacter, Count* count, Enemy_Green e_green[], Enemy_White e_white[], KeyState ShotkeyState[], Enemy enemy);

void HitCaraBeam(MainCharacter* mainCara, Count* count, BeamSide beamSide[], BeamVerticality beamVerticality[], KeyState ShotkeyState[]);

#endif // !