#include<stdio.h>
#include"Scene.h"
#include"HelpScene.h"
#include"DrawTexture.h"
#include"Device.h"

void InitHelpScene(DirectX* directX);
void UpdateHelpScene();
SceneId FinisHelpScene();

TEXTUREDATA HelpTextureData;

SceneId HelpSceneMain(DirectX* directX)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitHelpScene(directX);
		break;

		// 本編
	case SceneStep::MainStep:
		UpdateHelpScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisHelpScene();
		break;
	}
	return SceneId::HelpScene;
}

// 描画設定等
void DrawHelpScene(DirectX* directX)
{
	DrawEx(0, 0, 1280, 960, &HelpTextureData.m_pTexture[HelpTextureList::MainBacktexture], *directX);
}

// テクスチャ読み込み
void InitHelpScene(DirectX* directX)
{
	LoadTexture("Texture/HelpBack.png", &HelpTextureData.m_pTexture[HelpTextureList::MainBacktexture], 0, directX);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateHelpScene()
{
	if (GetKeyStatus(DIK_RETURN))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

}

// 次に飛ぶシーン先の設定
SceneId FinisHelpScene()
{
	for (int a = 0; a < HelpTextureList::MaxHelpTexture; a++)
	{
		HelpTextureData.m_pTexture[a]->Release();
		HelpTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す
	return SceneId::TitleScene;
}

