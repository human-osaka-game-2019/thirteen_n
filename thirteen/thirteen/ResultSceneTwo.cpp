#include<stdio.h>
#include"Scene.h"
#include"ResultSceneTwo.h"
#include"DrawTexture.h"
#include"Device.h"

ResultTwoTextureSize ResultTexTwo;

void DrawResultSceneTwo(DirectX* directX, Count* count  );
void InitResultSceneTwo(DirectX* directX);
void UpdateResultSceneTwo(ResultTwoTextureSize *ResultTexTwo);
SceneId FinishResultSceneTwo();

static bool KeyFlag = false;

TEXTUREDATA ResultTwoTextureData;



SceneId ResultSceneTwoMain(DirectX* directX, Count* count  )
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitResultSceneTwo(directX);
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
}

void InitResultSceneTwo(DirectX* directX)
{
	LoadTexture("Texture/result_2.png", &ResultTwoTextureData.m_pTexture[ResultTwoTextureList::MainbackTexture], 0, directX);

	ChangeSceneStep(SceneStep::MainStep);
}


// 次のシーンに行くための条件記入
void UpdateResultSceneTwo(ResultTwoTextureSize *p_ResultTexTwo)
{
	p_ResultTexTwo->m_input_tu += 1;
	p_ResultTexTwo->m_input_tu_size += 1;
	ResultTexTwo.InputTu(p_ResultTexTwo->m_input_tu, p_ResultTexTwo->m_input_tu_size);

	if (GetKeyStatus(DIK_P))
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
