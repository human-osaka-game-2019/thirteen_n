#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
	bool ShotFlag = false;
	float m_PosX;
	float m_PosY;
	float m_DrawSize = 40;
	float m_PosTu = (float)0 / 1024;
	float m_PosTu_Size = (float)40 / 1024;
	float m_PosTv = (float)0 / 512;
	float m_PosTv_Size = (float)40 / 512;

	float BulletCount = 0;

};

//void ShotMove(KeyState* keyState, Bullet bullet[5], MainCaracter* MainCara);
//
//void ShotHitJudge(Bullet bullet[5], KeyState* keyState, MainCara* MainCara);

#endif // !

