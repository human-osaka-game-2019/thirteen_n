#ifndef BEAM_H
#define BEAM_H


#include"Engine.h"
#include"Device.h"
#include"GameScene.h"

// ビームに関するcode、関数で使用する変数などを保存するクラス
class Beam
{
public:
	int beam_direction;
	int draw_beam_state;
};

// 横方向に描画されるビームに関する情報を持ったクラス
class BeamSide
{
public:
	bool BeamSideFlag = false;
	float m_PosX;
	float m_PosY;
	float m_DrawSizeWidth = 1280;
	float m_DrawSizeHight = 120;
	float m_PosTu = 0 / 2048;
	float m_PosTu_Size = 1120 / 2048;

	float m_PosTv = (float)120 / 1024;
	float m_PosTv_Size = (float)240 / 1024;
	void InputSidePosTv(float Tv, float TvSize);

	float m_Add_Tv_Size = (float)120 / 1024;
};

// 縦方向に描画されるビームに関する情報を持つクラス
class BeamVerticality
{
public:
	bool BeamVerticalityeFlag = false;
	float m_PosX;
	float m_PosY;
	float m_DrawSizeWidth = 120;
	float m_DrawSizeHight = 960;

	float m_PosTu = (float)120 / 1024;
	float m_PosTu_Size = (float)240 / 1024;
	void InputVerticalityPosTv(float Tv, float TvSize);

	float m_Add_Tu_Size = (float)120 / 1024;
	float m_PosTv = 0;
	float m_PosTv_Size = 1;
};


void SetBeam_first(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, int beamNumbre,  Beam* beam);



#endif // !