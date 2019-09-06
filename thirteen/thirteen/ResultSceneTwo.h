#ifndef _RESULTSCENETWO_H_ 
#define _RESULTSCENETWO_H_

SceneId ResultSceneTwoMain(DirectX* directX, Count* count  );

void DrawResultSceneTwo(DirectX* directX, Count* count  );

class ResultTwoTextureSize
{
public:

	int m_input_tu = 0;
	int m_input_tu_size = 1260;

	float m_pos_tu  = (float) 0 / 2560;
	float m_tu_size = (float) 1260 / 2560;
	void InputTu(int Tu, int TuSize);

	float m_pos_tv;
	float m_tv_size;

};

enum ResultTwoTextureList
{
	MainbackTexture,
	MaxResultTwoTexture,
};

#endif