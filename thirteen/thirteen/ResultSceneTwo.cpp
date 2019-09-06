#include<stdio.h>
#include"Scene.h"
#include"ResultSceneTwo.h"
#include"DrawTexture.h"
#include"Device.h"


void DrawResultSceneTwo(DirectX* directX, Count* count  );
void InitResultSceneTwo(DirectX* directX);
void ResetResultSceneTwo(Count* count  );
void UpdateResultSceneTwo();
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
		UpdateResultSceneTwo();
		break;
		// 終了
	case SceneStep::EndStep:
		ResetResultSceneTwo(count );
		return FinishResultSceneTwo();
		break;
	}
	return SceneId::ResultSceneTwo;
}

// 描画設定等
void DrawResultSceneTwo(DirectX* directX, Count* count  )
{
}
void ResetResultSceneTwo(Count* count  )
{
};

void InitResultSceneTwo(DirectX* directXt)
{
	ChangeSceneStep(SceneStep::MainStep);
}


// 次のシーンに行くための条件記入
void UpdateResultSceneTwo()
{
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
