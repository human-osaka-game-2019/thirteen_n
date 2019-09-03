#include<stdio.h>
#include"Scene.h"
#include"SetScene.h"
#include"DrawTexture.h"
#include"Device.h"


void DrawSetScene(DirectX* directX, Count* count, VariableNumber* var);
void InitSetScene(DirectX* directX);
void ResetSetScene(Count* count, VariableNumber* var);
void UpdateSetScene();
SceneId FinishSetScene();

VariableNumber var;
static bool KeyFlag = false;

TEXTUREDATA SetTextureData;

SceneId SetSceneMain(DirectX* directX, Count* count, VariableNumber* var)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitSetScene(directX);
		break;
		// 本編
	case SceneStep::MainStep:
		UpdateSetScene();
		break;
		// 終了
	case SceneStep::EndStep:
		ResetSetScene(count, var);
		return FinishSetScene();
		break;
	}
	return SceneId::SetScene;
}

// 描画設定等
void DrawSetScene(DirectX* directX, Count* count, VariableNumber* var)
{
}
void ResetSetScene(Count* count, VariableNumber* var)
{
};

void InitSetScene(DirectX* directXt)
{
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateSetScene()
{
	if (GetKeyStatus(DIK_RETURN))
	{

	}

	ChangeSceneStep(SceneStep::EndStep);
}

// 次に飛ぶシーン先の設定
SceneId FinishSetScene()
{

	for (int a = 0; a < SetTextureList::MaxSetTexture; a++)
	{
		SetTextureData.m_pTexture[a]->Release();
		SetTextureData.m_pTexture[a] = nullptr;
	}

	return SceneId::GameScene;

}
