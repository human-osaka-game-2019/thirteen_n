#ifndef _RESULTSCENETWO_H_ 
#define _RESULTSCENETWO_H_

SceneId ResultSceneTwoMain(DirectX* directX, Count* count, FlameCount flamCount[]);

void DrawResultSceneTwo(DirectX* directX, Count* count  );

class ResultTwoTextureSize
{
public:

	int m_input_tu_left = 0;
	int m_input_tu_right = 1260;

	float m_pos_tu  = (float) 0 / 3840;
	float m_tu_size = (float) 1260 / 3840;
	void InputTu(int Tu, int TuSize);

	float m_pos_tv;
	float m_tv_size;

};

class ResultUITexture
{
public:
	float m_pos_x  	 = 960;
	float m_x_size 	 = 320;
	float m_pos_y  	 = 0;
	float m_y_size 	 = 80;
	float m_pos_tu 	 = (float) 0 / 512 ;
	float m_tu_size  = (float) 320 / 512 ;
	float m_pos_tv   = (float) 320 / 512 ;
	float m_tv_size  = (float) 400 / 512 ;
};

class FinishGameRankTexture
{

public:
	float m_pos_x = 480 ;
	float m_x_size = 320;
	float m_pos_y = 845;
	float m_y_size = 80;
	float m_pos_tu = (float)0 / 512;
	float m_tu_size = (float)320 / 512;
	float m_pos_tv = (float) 0 / 512;
	float m_tv_size = (float) 80 / 512;
	void InputTv(float Tv,float TvSize);
};

class ResultRank
{
public:
	int m_rank = 0;
};

enum ResultTwoTextureList
{
	MainbackTextureS,
	MainbackTextureA,
	MainbackTextureB,
	MainbackTextureC,
	UiTexture,
	MaxResultTwoTexture,
};

#endif