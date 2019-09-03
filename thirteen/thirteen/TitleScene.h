#ifndef _TIRLESCENE_H_ 
#define _TIRLESCENE_H_

enum TitleTextureList
{
	MainTitleTexture,
	LogoTexture,
	MaxTitleTexture,

};

SceneId TitleSceneMain(DirectX* directX, Count* count);

void DrawTitleScene(DirectX* directX, Count* count);

#endif 