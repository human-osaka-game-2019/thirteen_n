#ifndef _GAMESCENE_H_ 
#define _GAMESCENE_H_

#include"DrawTexture.h"
#include"Scene.h"

SceneId GameSceneMain(DirectX* directX, Count* count);

void DrawGameScene(DirectX* directX, MapChipData Mapdata  );

enum GameTextureList
{
	BackTexture,
	CharTexture,
	MapChipTexture,
	BeamSideTextutre,
	BeamVerticalityTexture,
	MaxGameTexture,
};

#endif
