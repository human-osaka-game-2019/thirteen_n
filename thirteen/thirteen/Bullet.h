#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
	bool ShotFlag = false;
	float m_pos_x;
	float m_pos_y;
	float m_draw_size = 40;
	float m_pos_tu = (float)0 / 1024;
	float m_pos_tu_size = (float)40 / 1024;
	float m_pos_tv = (float)0 / 512;
	float m_pos_tv_size = (float)40 / 512;
	
	float BulletCount = 0;
	float ReShot = 0;
	int count_sound_num = 0;
};

#endif // !

