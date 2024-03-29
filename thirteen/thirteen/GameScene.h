﻿#ifndef _GAMESCENE_H_ 
#define _GAMESCENE_H_

#include"DrawTexture.h"
#include"Scene.h"

SceneId GameSceneMain(DirectX* directX, Count* count, FlameCount flamCount[]);

void DrawGameScene(DirectX* directX, MapChipData Mapdata, Count* count);

enum GameTextureList
{
	BackTexture,
	ConstellationTexture,
	CharTexture,
	MapChipTexture,
	BeamSideTextutre,
	BeamVerticalityTexture,
	MaxGameTexture,
};

#endif
