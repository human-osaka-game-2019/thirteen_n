#ifndef _TIRLESCENE_H_ 
#define _TIRLESCENE_H_

enum TitleTextureList
{
	MainTitleTexture,
	LogoTexture0,
	LogoTexture1,
	LogoTexture2,
	LogoTexture3,
	LogoTexture4,
	LogoTexture5,
	LogoTexture6,
	LogoTexture7,
	MaxTitleTexture,

};

class TitleDrawState
{
public:
	int m_draw_state = 0; 
};
SceneId TitleSceneMain(DirectX* directX, Count* count);

void DrawTitleScene(DirectX* directX, Count* count);

#endif 