#ifndef TITLESYSTEM_H
#define TITLESYSTEM_H


#include"InputKey.h"
enum 
{
	noKey,
	Up,
	Down,
	Left,
	Right
};

class TitleSystem
{
public:
	int TitleSceneFlag;
	int KeyState;
};

class SelectTexture
{
public:
	float m_pos_x;
	float m_x_size;
	float m_pos_y;
	float m_y_size;
	float m_pos_tu;
	float m_tu_size;
	float m_pos_tv;
	float m_tv_size;

	void InputTextureStatus(float x, float y, float x_size, float y_size, float tu, float tv, float tu_size, float tv_size);
	void InputTu(float tu, float tu_size);
};

void TextureDataSet(SelectTexture selectTexture[]);

void SelectMenu(TitleSystem* titleSystem, KeyState* keyState, SelectTexture selectTexture[], FlameCount flamCount[]);

void InputSelectKey(TitleSystem* titleSystem, KeyState* keyState);

#endif // !TITLEINPUTKEY
