#ifndef _RESULTSCENE_H_ 
#define _RESULTSCNEN_H_

SceneId ResultSceneMain(DirectX* directX, Count* count);

void DrawResultScene(DirectX* directX, Count* count);


class ResultTextureSize
{
public:
	int FlameCount = 0;
	float m_PosX = 0;
	float m_PosY = 0;
	float m_HightSize = 960;
	float m_widthSize = 1280;
	float m_Main_s_tu = 0;
	float m_Main_e_tu = 1;
	float m_Main_s_tv = 0;
	float m_Main_e_tv = 1;
};

enum ResultTextureList
{
	MainResultTexture,
	MainResultTexture2,
	MainResultTexture3,
	MainResultTexture4,
	MainResultTexture5,
	MainResultTexture6,
	MaxResultTexture,
};

#endif 
