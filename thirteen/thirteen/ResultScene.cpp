#include<stdio.h>
#include"Scene.h"
#include"DrawTexture.h"
#include"Device.h"
#include"ResultScene.h"



void InitResultScene(DirectX* directX);
void UpdateResultScene();
SceneId FinisResultScene();
void DrawResultScene(DirectX* directX, Count* count);
void FlameCountState(Count* count, ResultTextureSize* rts);

TEXTUREDATA ResultTextureData;
ResultTextureSize rts;

SceneId ResultSceneMain(DirectX* directX, Count* count)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitResultScene(directX);
		count->AllReset();
		break;

		// 本編
	case SceneStep::MainStep:
		UpdateResultScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisResultScene();
	}
	return SceneId::ResultScene;
}

// 描画設定等
void DrawResultScene(DirectX* directX, Count* count)
{
	FlameCountState(count, &rts);

	switch (rts.FlameCount)
	{
	case 0:
		break;
	case 1:
		DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture], *directX);
		break;
	case 2:
		DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture2], *directX);
		break;
	case 3:
		DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture3], *directX);
		break;
	case 4:
		DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture4], *directX);
		break;
	case 5:
		DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture5], *directX);
		break;
	case 6:
		DrawTest(0, 0, 1280, 960, 0, 0, 1, 1, &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture6], *directX);
		break;
	}
}

void InitResultScene(DirectX* directX)
{
	LoadTexture("Texture/ResultSceneBack.png",  &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture], 0, directX);
	LoadTexture("Texture/ResultSceneBack2.png", &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture2], 0, directX);
	LoadTexture("Texture/ResultSceneBack3.png", &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture3], 0, directX);
	LoadTexture("Texture/ResultSceneBack4.png", &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture4], 0, directX);
	LoadTexture("Texture/ResultSceneBack5.png", &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture5], 0, directX);
	LoadTexture("Texture/ResultSceneBack6.png", &ResultTextureData.m_pTexture[ResultTextureList::MainResultTexture6], 0, directX);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateResultScene()
{
	if (GetKeyStatus(DIK_RETURN))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}


}

// 次に飛ぶシーン先の設定
SceneId FinisResultScene()
{
	for (int a = 0; a < ResultTextureList::MaxResultTexture; a++)
	{
		ResultTextureData.m_pTexture[a]->Release();
		ResultTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す
	return SceneId::TitleScene;
}

void FlameCountState(Count* count, ResultTextureSize* rts)
{
	if (count->Frame0 == 10)
	{
		rts->FlameCount = 1;
	}
	else
		if (count->Frame0 == 20)
		{
			rts->FlameCount = 2;
		}

		else
			if (count->Frame0 == 30)
			{
				rts->FlameCount = 3;
			}
			else
				if (count->Frame0 == 40)
				{
					rts->FlameCount = 4;
				}
				else
					if (count->Frame0 == 50)
					{
						rts->FlameCount = 5;
					}
					else
						if (count->Frame0 == 60)
						{
							rts->FlameCount = 6;
						}


	if (count->Frame0 == 60)
	{
		count->Frame0 = 0;
	}

}
