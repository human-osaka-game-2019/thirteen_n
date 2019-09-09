#include<stdio.h>
#include"Scene.h"
#include"ResultSceneTwo.h"
#include"DrawTexture.h"
#include"Device.h"

ResultTwoTextureSize ResultTexTwo;
TEXTUREDATA ResultTwoTextureData;
FinishGameRankTexture RankTexture;
ResultUITexture ResultUi;

void DrawResultSceneTwo(DirectX* directX, Count* count  );
void InitResultSceneTwo(DirectX* directX);
void UpdateResultSceneTwo(ResultTwoTextureSize *ResultTexTwo);
void FlameRank(FlameCount flamCount[], FinishGameRankTexture *RankTexture);
SceneId FinishResultSceneTwo();

static bool KeyFlag = false;



void FinishGameRankTexture::InputTv(float Tv, float TvSize)
{
	m_pos_tv = Tv / 512;
	m_tv_size = (Tv + TvSize) / 512;
}

SceneId ResultSceneTwoMain(DirectX* directX, Count* count ,FlameCount flamCount[])
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitResultSceneTwo(directX);
		FlameRank(flamCount, &RankTexture);
		break;
		// 本編
	case SceneStep::MainStep:
		UpdateResultSceneTwo(&ResultTexTwo);
		break;
		// 終了
	case SceneStep::EndStep:
		return FinishResultSceneTwo();
	}
	return SceneId::ResultSceneTwo;
}

void ResultTwoTextureSize::InputTu(int Tu, int TuSize)
{
	m_pos_tu = (float)Tu / 2560;
	m_tu_size = (float)TuSize / 2560;
}

// 描画設定等
void DrawResultSceneTwo(DirectX* directX, Count* count  )
{
	DrawTest(0, 0, 1280, 960, ResultTexTwo.m_pos_tu, 0, ResultTexTwo.m_tu_size, 1, &ResultTwoTextureData.m_pTexture[ResultTwoTextureList::MainbackTexture], *directX);
	DrawTest(ResultUi.m_pos_x, ResultUi.m_pos_y, ResultUi.m_x_size, ResultUi.m_y_size, ResultUi.m_pos_tu, ResultUi.m_pos_tv, ResultUi.m_tu_size, ResultUi.m_tv_size, &ResultTwoTextureData.m_pTexture[ResultTwoTextureList::UiTexture], *directX);
	DrawTest(RankTexture.m_pos_x, RankTexture.m_pos_y, RankTexture.m_x_size, RankTexture.m_y_size, RankTexture.m_pos_tu, RankTexture.m_pos_tv, RankTexture.m_tu_size, RankTexture.m_tv_size, &ResultTwoTextureData.m_pTexture[ResultTwoTextureList::UiTexture], *directX);
}

void InitResultSceneTwo(DirectX* directX)
{
	LoadTexture("Texture/result_2.png", &ResultTwoTextureData.m_pTexture[ResultTwoTextureList::MainbackTexture], 0, directX);
	LoadTexture("Texture/result_ui.png", &ResultTwoTextureData.m_pTexture[ResultTwoTextureList::UiTexture], 0, directX);


	ChangeSceneStep(SceneStep::MainStep);
}


// 次のシーンに行くための条件記入
void UpdateResultSceneTwo(ResultTwoTextureSize *p_ResultTexTwo)
{

	p_ResultTexTwo->m_input_tu_left += 1;
	p_ResultTexTwo->m_input_tu_right += 1;
	ResultTexTwo.InputTu(p_ResultTexTwo->m_input_tu_left, p_ResultTexTwo->m_input_tu_right);

	if (GetKeyStatus(DIK_RETURN))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

	
// 次に飛ぶシーン先の設定
SceneId FinishResultSceneTwo()
{

	for (int a = 0; a < ResultTwoTextureList::MaxResultTwoTexture; a++)
	{
		ResultTwoTextureData.m_pTexture[a]->Release();
		ResultTwoTextureData.m_pTexture[a] = nullptr;
	}

	return SceneId::TitleScene;

}

void FlameRank(FlameCount flamCount[], FinishGameRankTexture *RankTexture)
{
	if (flamCount[0].m_count < ( 60 * 150))
	{
		RankTexture->InputTv(0, 80);
	}else
		if (flamCount[0].m_count < ( 60 * 180))
		{
			RankTexture->InputTv(80, 80);
		}else
			if(flamCount[0].m_count < ( 60 * 240))
			{
				RankTexture->InputTv(160, 80);
			}else
				if (flamCount[0].m_count < ( 60 * 300))
				{
					RankTexture->InputTv(240, 80);
				}
}