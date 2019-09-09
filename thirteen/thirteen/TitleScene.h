#ifndef _TIRLESCENE_H_ 
#define _TIRLESCENE_H_

enum TitleTextureList
{
	MainTitleTexture,
	StarTexture,
	LogoTexture0,
	LogoTexture1,
	LogoTexture2,
	LogoTexture3,
	LogoTexture4,
	LogoTexture5,
	LogoTexture6,
	LogoTexture7,
	TitleUiTexture,
	MaxTitleTexture,

};

class TitleDrawState
{
public:
	int m_draw_state = 0; 
};

class WhiteSmallStar
{
public:
	float m_pos_x;
	float m_pos_y;
	float m_pos_x_size = 40;
	float m_pos_y_size = 40;

	float m_pos_tu = (float) 0 / 256;
	float m_tu_size = (float) 40 / 256;
	void InputTu(float Tu, float TuSize);

	float m_pos_tv = (float)  0 / 128;
	float m_tv_size =(float) 40 / 128;
	

};

class BlueSmallStar
{
public:
	float m_pos_x;
	float m_pos_y;
	float m_pos_x_size = 40;
	float m_pos_y_size = 40;

	float m_pos_tu = (float) 0 / 256;
	float m_tu_size = (float) 40 / 256;
	void InputTu(float Tu, float TuSize);

	float m_pos_tv   = (float)  80 / 128;
	float m_tv_size  = (float) 120 / 128;
	

};

class PinkSmallStar
{
public:
	float m_pos_x;
	float m_pos_y;
	float m_pos_x_size = 40;
	float m_pos_y_size = 40;

	float m_pos_tu = (float) 0 / 256;
	float m_tu_size = (float) 40/ 256;
	void InputTu(float Tu, float TuSize);

	float m_pos_tv  = (float)  40 / 128;
    float m_tv_size = (float) 80  / 128;

};
SceneId TitleSceneMain(DirectX* directX, Count* count, FlameCount flamCount[]);

void DrawTitleScene(DirectX* directX, Count* count);

#endif 