#ifndef SCENE_H_
#define SCENE_H_

#include"DrawTexture.h"

// Step 数
enum SceneStep
{
	InitStep,			//!< 初期化
	MainStep,			//!< メイン
	EndStep,			//!< 終了
};

// SceneId の数
enum SceneId
{
	TitleScene,			//!< タイトルシーン
	SetScene,			//!< 難易度設定シーン
	OptionScene,        //!< ヘルプ(遊戯説明画面)シーン
	GameScene,			//!< ゲーム本編シーン
	ResultScene,		//!< リザルトシーン
	SceneIdMax,			//!< シーンID最大
};

class Count
{
public:
	int Frame0 = 0;
	void FrameReset() { Frame0 = 0; }

	int draw_beam = 0;
	void draw_beamReset() { draw_beam = 0; }

	int draw_beam_indication = 0;
	void draw_beam_indicationReset() { draw_beam_indication = 0; }

	int re_input_move_key = 0;
	void re_input_move_keyReset() { re_input_move_key = 0; }

	int draw_meteorite_indication = 0;
	void draw_meteoriteReset() { draw_meteorite_indication = 0; }

	int draw_enemy_indication = 0;
	void draw_enemy_indicationReset() { draw_enemy_indication = 0; }

	int draw_enemy = 0;
	void draw_enemyReset() { draw_enemy = 0; }

	int draw_meteorite_two_indication = 0;
	void draw_meteorite_two_indicationReset() { draw_meteorite_two_indication = 0; }

	int draw_meteorite_two = 0;
	void draw_meteorite_twoReset() { draw_meteorite_two = 0; }

	int draw_main_caracter = 0;
	void draw_main_caracterReset() { draw_main_caracter = 0; }

	int DrawStarCount = 0;
	void DrawStarCountReset() { DrawStarCount = 0; }

	int BeamCount = 6;

	float StarCount = 0;// 取った星の数

	float BulletCount = 0;

	int shotcount = 0;
	int re_shot_count = 0;

	void AllReset();
};


/**
* @brief 現在のシーンIDを戻り値で取得する
* @return 現在のシーンID
*/
SceneId GetCurrentSceneId();

/**
* @brief 現在のステップを戻り値で取得する
* @return 現在のステップ
*/
SceneStep GetCurrentSceneStep();

/**
* @brief 次のステップへ移動させる
* @param (SceneStep next_step) 次のステップ
*/
void ChangeSceneStep(SceneStep next_step);

void UpdateScene(DirectX* directX, MapChipData MapData, Count* count);

void DrawScene(DirectX* directX, MapChipData MapData, Count* count);

#endif // !