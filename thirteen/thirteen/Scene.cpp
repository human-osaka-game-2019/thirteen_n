#include <stdio.h>
#include <windows.h>
#include <d3d9.h>

#include "Engine.h"

#include "Scene.h"
#include "TitleScene.h"
#include "ResultSceneTwo.h"
#include "Option.h"
#include "GameScene.h"
#include "ResultScene.h"
#include"Meteorite.h"

//Pointa point;

void FrameCount(Count* count);
static SceneId g_CurrentSceneId = SceneId::TitleScene;		// 動作中シーンID
static SceneStep g_CurrentSceneStep = SceneStep::InitStep;	// 動作中シーンのステップ

void MeteoMotion::FramCountAdd()
{
	FramCount += 1;
}

SceneId GetCurrentSceneId()
{
	return g_CurrentSceneId;
}

SceneStep GetCurrentSceneStep()
{
	return g_CurrentSceneStep;
}

void ChangeSceneStep(SceneStep next_step)
{
	g_CurrentSceneStep = next_step;
}

void Count::AllReset()
{
	Frame0 = 0;
	draw_beam = 0;
	draw_beam_indication = 0;
	re_input_move_key = 0;
	draw_meteorite_indication = 0;
	draw_enemy_indication = 0;
	draw_enemy = 0;
	draw_meteorite_two_indication = 0;
	draw_meteorite_two = 0;
	draw_main_caracter= 0;
	re_shot_count = 0;
	StarMotion = 0;
	DrawStarCount = 0;
}


void UpdateScene(DirectX* directX, MapChipData MapData  , Count* count)
{
	int current_scene_id = SceneId::TitleScene;


		UpdateInput(directX);
		SceneId result_id = g_CurrentSceneId;

		switch (g_CurrentSceneId)
		{
			// タイトルシーン
		case SceneId::TitleScene:
			result_id = TitleSceneMain(directX, count);
			break;
			// 難易度設定シーン
		case SceneId::ResultSceneTwo:
			result_id = ResultSceneTwoMain(directX, count );
			break;
			// 設定、ヘルプシーン
		case SceneId::OptionScene:
			result_id = OptionSceneMain(directX);
			break;
			// メインゲームシーン
		case SceneId::GameScene:
			result_id = GameSceneMain(directX , count);
			break;
			// リザルトシーン
		case SceneId::ResultScene:
			result_id = ResultSceneMain(directX, count);
			break;

		}

		DrawScene(directX, MapData, count );

		FrameCount(count);

		if (result_id != g_CurrentSceneId)
		{
			g_CurrentSceneId = result_id;
			ChangeSceneStep(SceneStep::InitStep);
		}
	
}

void DrawScene(DirectX* directX, MapChipData MapData, Count* count  )
{
	if (DrawStart(directX) == false)
	{
		return;
	}
	if (g_CurrentSceneStep == SceneStep::MainStep)
	{
		switch (g_CurrentSceneId)
		{
		case SceneId::TitleScene:
			DrawTitleScene(directX, count);
			break;
		case SceneId::ResultSceneTwo:
			DrawResultSceneTwo(directX, count );
			break;
		case SceneId::OptionScene:
			DrawOptionScene(directX);
			break;
		case SceneId::GameScene:
			DrawGameScene(directX, MapData ,count);
			break;
		case SceneId::ResultScene:
			DrawResultScene(directX, count);
			break;
		}
	}


	directX->pDevice->EndScene();
	directX->pDevice->Present(NULL, NULL, NULL, NULL);
}

void FrameCount(Count* count)
{
	count->Frame0 = count->Frame0 + 1;
	count->draw_beam = count->draw_beam + 1;
	count->draw_beam_indication = count->draw_beam_indication + 1;
	count->re_input_move_key = count->re_input_move_key + 1;
	count->draw_meteorite_indication = count->draw_meteorite_indication + 1;
	count->draw_enemy_indication = count->draw_enemy_indication + 1;
	count->draw_enemy = count->draw_enemy + 1;
	count->draw_meteorite_two_indication = count->draw_meteorite_two_indication + 1;
	count->draw_meteorite_two = count->draw_meteorite_two + 1;
	count->draw_main_caracter = count->draw_main_caracter + 1;
	count->DrawStarCount = count->DrawStarCount + 1;
	count->re_shot_count += 1;
	count->StarMotion += 1;
	count->TitleScene += 1;
	count->EnemyGreenMotion += 1;
	count->EnemyWhiteMotion += 1;
	count->DrawSmallStar += 1;
}
