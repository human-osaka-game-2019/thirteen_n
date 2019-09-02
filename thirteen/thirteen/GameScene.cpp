﻿#include<stdio.h>
#include<time.h>
#include<random>
#include <random>
#include <iostream>

#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
#include"GameScene.h"

#include"InputKey.h"
#include"MainCara.h"
#include"Enemy.h"
#include"Meteorite.h"
#include"Beam.h"
#include"Bullet.h"
#include"Star.h"

extern int g_SceneStep;
void DrawGameScene(DirectX* directX, MapChipData MapData, VariableNumber* var);
void InitGameScene(DirectX* directX);
void UpdateGameScene(Count* count, VariableNumber* var);
SceneId FinisGameScene();
int* MAPR[22];

TEXTUREDATA GameTextureData;

#define MAP_SIZE_WIDTH (28)	
#define MAP_SIZE_HEIGHT (20)

int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]
{

	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

};



SceneId GameSceneMain(DirectX* directX, VariableNumber* var, Count* count)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		count->AllReset();
		InitGameScene(directX);
		break;
		// 本編
	case SceneStep::MainStep:
		UpdateGameScene(count, var);
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisGameScene();
	}
	return SceneId::GameScene;
}

BeamSide beamSide;
BeamVerticality  beamVerticality;
Bullet bullet[5];
Meteorite meteorite[8];
Enemy_Green e_green[2];
Enemy_White e_white[2];
MainChar mainChar;
KeyState keyState;
Star star[12];

void DrawGameScene(DirectX* directX, MapChipData MapData, VariableNumber* var)
{
	// 背景
	DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &GameTextureData.m_pTexture[GameTextureList::BackTexture], *directX);
	// マップチップ
	DrawMapChip(directX, MapData, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], MapChipList);
	// 自キャラ 操作キャラ
	DrawTest(mainChar.m_PosX, mainChar.m_PosY, mainChar.DrawSize, mainChar.DrawSize, mainChar.m_PosTu, mainChar.m_PosTv, mainChar.m_PosTu_Size, mainChar.m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);

	if (var->EnemyDrawState == 1)
	{
		// 敵1 緑敵
		DrawTest(e_green[0].m_PosX, e_green[0].m_PosY, e_green[0].m_DrawSize, e_green[0].m_DrawSize, e_green[0].m_PosTu, e_green[0].m_PosTv, e_green[0].m_PosTu_Size, e_green[0].m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
		DrawTest(e_green[1].m_PosX, e_green[1].m_PosY, e_green[1].m_DrawSize, e_green[1].m_DrawSize, e_green[1].m_PosTu, e_green[1].m_PosTv, e_green[1].m_PosTu_Size, e_green[1].m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
		// 敵2 紫敵
		DrawTest(e_white[0].m_PosX, e_white[0].m_PosY, e_white[0].m_DrawSize, e_white[0].m_DrawSize, e_white[0].m_PosTu, e_white[0].m_PosTv, e_white[0].m_PosTu_Size, e_white[0].m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
		DrawTest(e_white[1].m_PosX, e_white[1].m_PosY, e_white[1].m_DrawSize, e_white[1].m_DrawSize, e_white[1].m_PosTu, e_white[1].m_PosTv, e_white[1].m_PosTu_Size, e_white[1].m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
	}

	// メテオ(第一弾)
	if (var->MeteoriteDrawState == 1)
	{
		for (int a = 0; a < 4; a++)
		{
			DrawTest(meteorite[a].m_PosX, meteorite[a].m_PosY, meteorite[a].m_DrawSize, meteorite[a].m_DrawSize, meteorite[a].m_PosTu, meteorite[a].m_Postv, meteorite[a].m_Tu_Size, meteorite[a].m_Tv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
		}

	}

	// メテオ(第二弾)
	if (var->MeteoriteDrawState2 == 1)
	{
		for (int a = 4; a < 8; a++)
		{
			DrawTest(meteorite[a].m_PosX, meteorite[a].m_PosY, meteorite[a].m_DrawSize, meteorite[a].m_DrawSize, meteorite[a].m_PosTu, meteorite[a].m_Postv, meteorite[a].m_Tu_Size, meteorite[a].m_Tv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
		}

	}

	// ソゲキッ
	for (int a = 0; a < 5; a++)
	{
		if (bullet[a].ShotFlag == true)
		{
			DrawTest(bullet[a].m_PosX, bullet[a].m_PosY, bullet->m_DrawSize, bullet->m_DrawSize, bullet->m_PosTu, bullet->m_PosTv, bullet->m_PosTu_Size, bullet->m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
		}
	}

	// ビーム横描画
	if (beamSide.BeamSideFlag == true)
	{
		DrawTest(beamSide.m_PosX, /**/beamSide.m_PosY, beamSide.m_DrawSizeWidth, beamSide.m_DrawSizeHight, beamSide.m_PosTu, beamSide.m_PosTv, beamSide.m_PosTu_Size, beamSide.m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::BeamSideTextutre], *directX);
	}

	// ビーム縦描画
	if (beamVerticality.BeamVerticalityeFlag == true)
	{
		DrawTest(/**/beamVerticality.m_PosX, beamVerticality.m_PosY, beamVerticality.m_DrawSizeWidth, beamVerticality.m_DrawSizeHight, beamVerticality.m_PosTu, beamVerticality.m_PosTv, beamVerticality.m_PosTu_Size, beamVerticality.m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::BeamVerticalityTexture], *directX);
	}

	// 星の描画(基本4つ、最大12)
	for (int a = 0; a < 12; a++)
	{
		if (star[a].DrawFlag == true)
		{
			DrawTest(star[a].m_PosX, star[a].m_PosY, star->m_DrawSize, star->m_DrawSize, star->m_PosTu, star->m_PosTv, star->m_PosTu_Size, star->m_PosTv_Size, &GameTextureData.m_pTexture[GameTextureList::ChraTexture], *directX);
		}
	}
}


// テクスチャ読み込み
void InitGameScene(DirectX* directX)
{
	LoadTexture("Texture/main_back.png", &GameTextureData.m_pTexture[GameTextureList::BackTexture], 0, directX);
	LoadTexture("Texture/map_chip2.png", &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], 0, directX);
	LoadTexture("Texture/character.png", &GameTextureData.m_pTexture[GameTextureList::ChraTexture], 0, directX);
	LoadTexture("Texture/beam_Side.png", &GameTextureData.m_pTexture[GameTextureList::BeamSideTextutre], 0, directX);
	LoadTexture("Texture/beam_Ver.png", &GameTextureData.m_pTexture[GameTextureList::BeamVerticalityTexture], 0, directX);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene(Count* count, VariableNumber* var)
{
	InptKeystate(count, &keyState, bullet);

	void ChraMove(Count * count, KeyState * keyState, MainChar * mainChar);

	void CharTextureChange(Count * count, MainChar * mainChar, Bullet * bullet);

	void FrameCount(Count * count, KeyState * keyState);

	void HitJudge(MainChar * mainChar);

	void DrawEnemy(Count * count, VariableNumber * var, int MapChipList[20][28], Enemy_Green e_green[], Enemy_White e_white[]);

	void EnemyMove(Count * count, VariableNumber * var, Enemy_Green e_green[], Enemy_White e_white[]);

	void DrawMeteorite(Count * count, VariableNumber * var, int MapChipList[20][28], Meteorite meteorite[]);

	void DrawMeteoriteTwo(Count * count, VariableNumber * var, int MapChipList[20][28], Meteorite meteorite[]);

	void HitCharMeteorite(Meteorite meteorite[], MainChar * mainChar, Count * count, KeyState * keyState);

	void SetBeam_first(Count * count, VariableNumber * var, int MapChipList[20][28], BeamSide * beamSide, BeamVerticality * beamVerticality, int beamNumbre);

	void HitBulletStar(MainChar * mainChar, Star star[12], Count * count, KeyState * keyState);

	void Shot(Bullet bullet[5], KeyState * keyState);

	void ShotMove(KeyState * keyState, Bullet bullet[5], MainChar * mainChar);

	void ShotHitJudge(Bullet bullet[5], KeyState * keyState, MainChar * mainChar);

	void StarDraw(Star star[12], Count * count);


	if (GetKeyStatus(DIK_RETURN))
	{

		ChangeSceneStep(SceneStep::EndStep);
	}
}

// 次に飛ぶシーン先の設定
SceneId FinisGameScene()
{
	for (int a = 0; a < GameTextureList::MaxGameTexture; a++)
	{
		GameTextureData.m_pTexture[a]->Release();
		GameTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す
	return SceneId::ResultScene;

}
