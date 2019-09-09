#include<stdio.h>
#include<time.h>
#include<random>
#include <random>
#include <iostream>

#include"Scene.h"
#include"DrawTexture.h"
#include"Device.h"
#include<SoundsManager.h>
#include"GameScene.h"

#include"InputKey.h"
#include"MainCaracter.h"
#include"Enemy.h"
#include"Meteorite.h"
#include"Beam.h"
#include"Bullet.h"
#include"Star.h"

extern SoundLib::SoundsManager m_soundsManager;

extern int g_SceneStep;
void DrawGameScene(DirectX* directX, MapChipData MapData,Count * count);
void InitGameScene(DirectX* directX);
void UpdateGameScene(Count* count, FlameCount flamCount[]);
SceneId FinisGameScene(Count* count);
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

MeteoMotion meteoMotion[8];
BeamSide beamSide[3];
BeamVerticality  beamVerticality[3];
Bullet bullet[12];
Meteorite meteorite[8];
Enemy_Green e_green[2];
Enemy_White e_white[2];
MainCharacter mainCara;
KeyState keyState;
KeyState ShotkeyState[12];
Star star[12];
Beam beam;
Enemy enemy;
Constellation constellation[12];

SceneId GameSceneMain(DirectX* directX, Count* count,FlameCount flamCount[])
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
		for (int a = 0; a < 8; a++)
		{
			meteoMotion[a].FramCountAdd();
		}
		UpdateGameScene(count, flamCount);
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisGameScene(count);
	}
	return SceneId::GameScene;
}



void DrawGameScene(DirectX* directX, MapChipData MapData,Count* count)
{
	// 背景
	DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &GameTextureData.m_pTexture[GameTextureList::BackTexture], *directX);

	Drawconstellation(directX, GameTextureData, count, constellation,&beam);

	// マップチップ
	DrawMapChip(directX, MapData, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], MapChipList);
	// 自キャラ 操作キャラ
	DrawTest(mainCara.m_pos_x, mainCara.m_pos_y, mainCara.DrawSize, mainCara.DrawSize, mainCara.m_pos_tu, mainCara.m_pos_tv, mainCara.m_pos_tu_size, mainCara.m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);

	if (enemy.EnemyDrawState == 1)
	{
		for (int a = 0; a < 2; a++)
		{
			if (e_green[a].m_draw_flag == 1)
			{
				// 敵1 緑敵
				DrawTest(e_green[a].m_pos_x, e_green[a].m_pos_y, e_green[a].m_draw_size, e_green[a].m_draw_size, e_green[a].m_pos_tu, e_green[a].m_pos_tv, e_green[a].m_pos_tu_size, e_green[a].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
			}
			if (e_white[a].m_draw_flag == 1)
			{
				// 敵2 紫敵
				DrawTest(e_white[a].m_pos_x, e_white[a].m_pos_y, e_white[a].m_draw_size, e_white[a].m_draw_size, e_white[a].m_pos_tu, e_white[a].m_pos_tv, e_white[a].m_pos_tu_size, e_white[a].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);

			}
		}
	}

	// メテオ(第一弾)

	for (int a = 0; a < 4; a++)
	{
		if (meteorite[a].MeteoriteDrawState == 1)
		{
			DrawTest(meteorite[a].m_pos_x, meteorite[a].m_pos_y, meteorite[a].m_draw_size, meteorite[a].m_draw_size, meteorite[a].m_pos_tu, meteorite[a].m_pos_tv, meteorite[a].m_Tu_Size, meteorite[a].m_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}

	}


	// メテオ(第二弾)
	
	for (int a = 4; a < 8; a++)
	{
		if (meteorite[a].MeteoriteDrawStateTwo == 1)
		{
			DrawTest(meteorite[a].m_pos_x, meteorite[a].m_pos_y, meteorite[a].m_draw_size, meteorite[a].m_draw_size, meteorite[a].m_pos_tu, meteorite[a].m_pos_tv, meteorite[a].m_Tu_Size, meteorite[a].m_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}
	}
	

	// ソゲキッ
	for (int a = 0; a < 12; a++)
	{
		if (bullet[a].ShotFlag == true)
		{
			DrawTest(bullet[a].m_pos_x, bullet[a].m_pos_y, bullet->m_draw_size, bullet[a].m_draw_size, bullet->m_pos_tu, bullet->m_pos_tv, bullet->m_pos_tu_size, bullet->m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}

	}

	// 星の描画(基本4つ、最大12)
	for (int a = 0; a < 12; a++)
	{
		if (star[a].DrawFlag == true)
		{
			DrawTest(star[a].m_pos_x, star[a].m_pos_y, star->m_draw_size, star->m_draw_size, star->m_pos_tu, star->m_pos_tv, star->m_pos_tu_size, star->m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::CharTexture], *directX);
		}
	}

	// ビーム横描画
	for (int a = 0; a < 3; a++)
	{

		if (  beamSide[a].BeamSideFlag == true)
		{
			DrawTest(  beamSide[a].m_pos_x, /**/   beamSide[a].m_pos_y,   beamSide[a].m_draw_size_width,   beamSide[a].m_draw_size_hight,   beamSide[a].m_pos_tu,   beamSide[a].m_pos_tv,   beamSide[a].m_pos_tu_size,   beamSide[a].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::BeamSideTextutre], *directX);
			m_soundsManager.Start("LaserBeam");

		}

		// ビーム縦描画
		if ( beamVerticality[a].BeamVerticalityeFlag == true)
		{

			DrawTest(/**/ beamVerticality[a].m_pos_x,  beamVerticality[a].m_pos_y,  beamVerticality[a].m_draw_size_width,  beamVerticality[a].m_draw_size_hight,  beamVerticality[a].m_pos_tu,  beamVerticality[a].m_pos_tv,  beamVerticality[a].m_pos_tu_size,  beamVerticality[a].m_pos_tv_size, &GameTextureData.m_pTexture[GameTextureList::BeamVerticalityTexture], *directX);
			m_soundsManager.Start("LaserBeam");

		}

	}
}


// テクスチャ読み込み
void InitGameScene(DirectX* directX)
{
	LoadTexture("Texture/main_back.png", &GameTextureData.m_pTexture[GameTextureList::BackTexture], 0, directX);
	LoadTexture("Texture/map_chip2.png", &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], 0, directX);
	LoadTexture("Texture/charactar.png", &GameTextureData.m_pTexture[GameTextureList::CharTexture], 0, directX);
	LoadTexture("Texture/beam_Side.png", &GameTextureData.m_pTexture[GameTextureList::BeamSideTextutre], 0, directX);
	LoadTexture("Texture/beam_Ver.png", &GameTextureData.m_pTexture[GameTextureList::BeamVerticalityTexture], 0, directX);
	LoadTexture("Texture/MainGameback1.png", &GameTextureData.m_pTexture[GameTextureList::ConstellationTexture], 0, directX);

	m_soundsManager.AddFile("Sound/Beam.wav", "LaserBeam");
	m_soundsManager.SetVolume("LaserBeam", 15);
	


	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene(Count* count, FlameCount flamCount[])
{
	FrameCount(count, &keyState);

	InputKeyState(count, &keyState,ShotkeyState, bullet);

	MoveCharacter(count, &keyState, &mainCara);

	CharTextureChange(count, &mainCara, bullet);

	HitJudge(&mainCara);

	SetBeam_first(count, MapChipList, beamSide, beamVerticality, 1,&beam);

	SetBeam_two(count,MapChipList, beamSide,beamVerticality,&beam);

	SetBeam_four(count, MapChipList, beamSide, beamVerticality, &beam);

	SetBeam_six(count, MapChipList, beamSide, beamVerticality, &beam);

	BeamMotio(count, beamSide, beamVerticality,&beam);

	DrawMeteorite(count, MapChipList, meteorite);

	DrawMeteoriteTwo(count , MapChipList, meteorite);

	MeteoriteMotion(count,meteorite);

	EnemyMove(count , e_green, e_white,&enemy);

	DrawEnemy(count , MapChipList, e_green, e_white,&enemy);

	EnemyMotion(count, e_green, e_white, &enemy);

	ShotMove(ShotkeyState,bullet,&mainCara);

	ShotHitJudge(bullet, ShotkeyState, &mainCara,count);

	DrawStar(star, count);

	HitCharMeteorite(meteorite, &mainCara, count, &keyState);

	HitBulletStar(&mainCara,star,count,&keyState);

	HitBulletEnemy(bullet, count, e_green, e_white, ShotkeyState);

	StarMotion(count,star);

	HiBulletMeteorite(meteorite,bullet,count, meteoMotion,ShotkeyState, star);

	StarDrop(meteorite,flamCount,star);

	HitMainCaraEnemy(&mainCara, count, e_green, e_white, ShotkeyState);

	HitCaraBeam(&mainCara, count, beamSide, beamVerticality, ShotkeyState);

	DrawBreakMeteorite(meteorite,meteoMotion);

	if (count->StarCount >= 12)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}else
		if (mainCara.DeathFlag == 1)
		{
			ChangeSceneStep(SceneStep::EndStep);
		}
}

// 次に飛ぶシーン先の設定
SceneId FinisGameScene(Count * count)
{
	for (int a = 0; a < GameTextureList::MaxGameTexture; a++)
	{
		GameTextureData.m_pTexture[a]->Release();
		GameTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す

	if (count->StarCount >= 12)
	{

		return SceneId::ResultScene;
	}
	else
		if (mainCara.DeathFlag == 1)
		{
			return SceneId::TitleScene;
		}
	

}
