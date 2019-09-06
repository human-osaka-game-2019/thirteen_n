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
	int GameLevel = 0;
	int DrawStatus = 0;
};

// 横方向に描画されるビームに関する情報を持ったクラス
class BeamSide
{
public:
	bool BeamSideFlag = false;
	float m_pos_x;
	float m_pos_y;
	float m_draw_size_width = 1280;
	float m_draw_size_hight = 120;
	float m_pos_tu = (float)0 / 2048;
	float m_pos_tu_size = (float)1280 / 2048;

	float m_pos_tv = (float)0 / 2048;
	float m_pos_tv_size = (float)120 / 2048;
	void InputSidePosTv(float Tv, float TvSize);

	float m_add_tv_size = (float)120 / 1024;
};

// 縦方向に描画されるビームに関する情報を持つクラス
class BeamVerticality
{
public:
	bool BeamVerticalityeFlag = false;
	float m_pos_x;
	float m_pos_y;
	float m_draw_size_width = 120;
	float m_draw_size_hight = 960;

	float m_pos_tu = (float)120 / 1024;
	float m_pos_tu_size = (float)240 / 1024;
	void InputVerticalityPosTu(float Tu, float TuSize);

	float m_add_tu_size = (float)120 / 1024;
	float m_pos_tv = 0;
	float m_pos_tv_size = 1;
};


void SetBeam_first(Count* count, int MapChipList[20][28], BeamSide beamSide[], BeamVerticality beamVerticality[], int beamNumbre,  Beam* beam);

void SetBeam_two(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality,Beam* beam);

void BeamMotio(Count* count, BeamSide beamSide[], BeamVerticality beamVerticality[], Beam* beam);

void SetBeam_four(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, Beam* beam);

void SetBeam_six(Count* count, int MapChipList[20][28], BeamSide* beamSide, BeamVerticality* beamVerticality, Beam* beam);

#endif // !