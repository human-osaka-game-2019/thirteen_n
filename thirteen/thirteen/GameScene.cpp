#include<stdio.h>
#include<time.h>
#include<random>
#include <random>
#include <iostream>

#include"Scene.h"
#include"DrawTexture.h"
#include"Device.h"
#include"GameScene.h"

#include"InputKey.h"
#include"MainCaracter.h"
#include"Enemy.h"
#include"Meteorite.h"
#include"Beam.h"
#include"Bullet.h"
#include"Star.h"

extern int g_SceneStep;
void DrawGameScene(DirectX* directX, MapChipData MapData);
void InitGameScene(DirectX* directX);
void UpdateGameScene(Count* count);
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


SceneId GameSceneMain(DirectX* directX, Count* count)
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
		UpdateGameScene(count);
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
MainCharacter mainCara;
KeyState keyState;
Star star[12];
Beam beam;
Enemy enemy;

void DrawGameScene(DirectX* directX, MapChipData MapData)
{
	// 背景
	DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &GameTextureData.m_pTexture[GameTextureList::BackTexture], *directX);
	// マップチップ
	DrawMapChip(directX, MapData, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], MapChipList);
	// 自キャラ 操作キャラ
	DrawTest(mainCara.m_pos_x, mainCara.m_pos_y, mainCara.DrawSize, mainCara.DrawSize, mainCara.m_pos_tu, mainCara.m_pos_tv, mainCara.m_pos_tu_size, mainCara.m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);

	if (enemy.EnemyDrawState == 1)
	{
		// 敵1 緑敵
		DrawTest(e_green[0].m_pos_x, e_green[0].m_pos_y, e_green[0].m_DrawSize, e_green[0].m_DrawSize, e_green[0].m_pos_tu, e_green[0].m_pos_tv, e_green[0].m_pos_tu_size, e_green[0].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		DrawTest(e_green[1].m_pos_x, e_green[1].m_pos_y, e_green[1].m_DrawSize, e_green[1].m_DrawSize, e_green[1].m_pos_tu, e_green[1].m_pos_tv, e_green[1].m_pos_tu_size, e_green[1].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		// 敵2 紫敵
		DrawTest(e_white[0].m_pos_x, e_white[0].m_pos_y, e_white[0].m_DrawSize, e_white[0].m_DrawSize, e_white[0].m_pos_tu, e_white[0].m_pos_tv, e_white[0].m_pos_tu_size, e_white[0].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		DrawTest(e_white[1].m_pos_x, e_white[1].m_pos_y, e_white[1].m_DrawSize, e_white[1].m_DrawSize, e_white[1].m_pos_tu, e_white[1].m_pos_tv, e_white[1].m_pos_tu_size, e_white[1].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
	}

	// メテオ(第一弾)
	if (meteorite->MeteoriteDrawState == 1)
	{
		for (int a = 0; a < 4; a++)
		{
			DrawTest(meteorite[a].m_pos_x, meteorite[a].m_pos_y, meteorite[a].m_DrawSize, meteorite[a].m_DrawSize, meteorite[a].m_pos_tu, meteorite[a].m_pos_tv, meteorite[a].m_Tu_Size, meteorite[a].m_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}

	}

	// メテオ(第二弾)
	if (meteorite->MeteoriteDrawStateTwo == 1)
	{
		for (int a = 4; a < 8; a++)
		{
			DrawTest(meteorite[a].m_pos_x, meteorite[a].m_pos_y, meteorite[a].m_DrawSize, meteorite[a].m_DrawSize, meteorite[a].m_pos_tu, meteorite[a].m_pos_tv, meteorite[a].m_Tu_Size, meteorite[a].m_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}

	}

	// ソゲキッ
	for (int a = 0; a < 5; a++)
	{
		if (bullet[a].ShotFlag == true)
		{
			DrawTest(bullet[a].m_pos_x, bullet[a].m_pos_y, bullet->m_draw_size, bullet->m_draw_size, bullet->m_pos_tu, bullet->m_pos_tv, bullet->m_pos_tu_size, bullet->m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}
	}

	// ビーム横描画
	if (beamSide.BeamSideFlag == true)
	{
		DrawTest(beamSide.m_pos_x, /**/beamSide.m_pos_y, beamSide.m_draw_size_width, beamSide.m_draw_size_hight, beamSide.m_pos_tu, beamSide.m_pos_tv, beamSide.m_pos_tu_size, beamSide.m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::BeamSideTextutre], *directX);
	}

	// ビーム縦描画
	if (beamVerticality.BeamVerticalityeFlag == true)
	{
		DrawTest(/**/beamVerticality.m_pos_x, beamVerticality.m_pos_y, beamVerticality.m_draw_size_width, beamVerticality.m_draw_size_hight, beamVerticality.m_pos_tu, beamVerticality.m_pos_tv, beamVerticality.m_pos_tu_size, beamVerticality.m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::BeamVerticalityTexture], *directX);
	}

	// 星の描画(基本4つ、最大12)
	for (int a = 0; a < 12; a++)
	{
		if (star[a].DrawFlag == true)
		{
			DrawTest(star[a].m_pos_x, star[a].m_pos_y, star->m_DrawSize, star->m_DrawSize, star->m_pos_tu, star->m_pos_tv, star->m_pos_tu_size, star->m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}
	}
}


// テクスチャ読み込み
void InitGameScene(DirectX* directX)
{
	LoadTexture("Texture/main_back.png", &GameTextureData.m_pTexture[GameTextureList::BackTexture], 0, directX);
	LoadTexture("Texture/map_chip2.png", &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], 0, directX);
	LoadTexture("Texture/character.png", &GameTextureData.m_pTexture[GameTextureList::CharTexture], 0, directX);
	LoadTexture("Texture/beam_Side.png", &GameTextureData.m_pTexture[GameTextureList::BeamSideTextutre], 0, directX);
	LoadTexture("Texture/beam_Ver.png", &GameTextureData.m_pTexture[GameTextureList::BeamVerticalityTexture], 0, directX);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene(Count* count)
{
	FrameCount(count, &keyState);

	InputKeyState(count, &keyState, bullet);

	MoveCharacter(count, &keyState, &mainCara);

	CharTextureChange(count, &mainCara, bullet);

	HitJudge(&mainCara);

	SetBeam_first(count, MapChipList, &beamSide, &beamVerticality, 1,&beam);

	DrawMeteorite(count, MapChipList, meteorite);

	DrawMeteoriteTwo(count , MapChipList, meteorite);

	EnemyMove(count , e_green, e_white,&enemy);

	DrawEnemy(count , MapChipList, e_green, e_white,&enemy);

	ShotMove(&keyState,bullet,&mainCara);

	ShotHitJudge(bullet, &keyState, &mainCara);

	DrawStar(star, count);

	HitCharMeteorite(meteorite, &mainCara, count, &keyState);

	HitBulletStar(&mainCara,star,count,&keyState);


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
