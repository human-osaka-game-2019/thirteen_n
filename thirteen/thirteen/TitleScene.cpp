#include<stdio.h>
#include"Scene.h"
#include"TitleScene.h"
#include"DrawTexture.h"
#include"Device.h"
#include<SoundsManager.h>

extern SoundLib::SoundsManager m_soundsManager;

void DrawTitleScene(DirectX* directX, Count* count);
void InitTitleScene(DirectX* directX, Count* count);
void UpdateTitleScene(DirectX* directX, Count* count, TitleDrawState* tds);
SceneId FinisTitleScene();

TEXTUREDATA TitleTextureData;

TitleDrawState tds;

SceneId TitleSceneMain(DirectX* directX, Count* count)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		count->AllReset();
		InitTitleScene(directX, count);
		break;
		// 本編
	case SceneStep::MainStep:

		UpdateTitleScene(directX,count,&tds);
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisTitleScene();
		break;
	}

	return SceneId::TitleScene;
}

void DrawTitleScene(DirectX* directX, Count* count)
{

	DrawEx(0, 0, 1280, 960, &TitleTextureData.m_pTexture[TitleTextureList::MainTitleTexture], *directX);

	switch (tds.m_draw_state)
	{
	case 0:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture7], *directX);
		break;
	case 1:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture0], *directX);
		break;
	case 2:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture1], *directX);
		break;
	case 3:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture2], *directX);
		break;
	case 4:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture3], *directX);
		break;
	case 5:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture4], *directX);
		break;
	case 6:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture5], *directX);
		break;
	case 7:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture6], *directX);
		break;
	case 8:
		DrawTest(48, 130, 730, 730, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture7], *directX);
		break;
		
	}
	
}

// 描画設定等
void InitTitleScene(DirectX* directX, Count* count)
{

	LoadTexture("Texture/Title.png", &TitleTextureData.m_pTexture[TitleTextureList::MainTitleTexture], 0, directX);
	LoadTexture("Texture/title1.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture0], 0, directX);
	LoadTexture("Texture/title2.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture1], 0, directX);
	LoadTexture("Texture/title3.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture2], 0, directX);
	LoadTexture("Texture/title4.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture3], 0, directX);
	LoadTexture("Texture/title5.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture4], 0, directX); 
	LoadTexture("Texture/title6.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture5], 0, directX);
	LoadTexture("Texture/title7.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture6], 0, directX);
	LoadTexture("Texture/title8.png", &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture7], 0, directX);

	count->Frame0 = 0;

	m_soundsManager.AddFile("Sound/BGM.mp3", "GameBGM");

	m_soundsManager.SetVolume("GameBGM", 100);

	m_soundsManager.Start("GameBGM", TRUE);

	   
	ChangeSceneStep(SceneStep::MainStep);

}

// 次のシーンに行くための条件記入
void UpdateTitleScene(DirectX* directX, Count* count, TitleDrawState *tds)
{
	switch (count->TitleScene)
	{
	case 10:
		tds->m_draw_state = 1;
		break;
	case 20:
		tds->m_draw_state = 2;
		break;
	case 30:
		tds->m_draw_state = 3;
		break;
	case 40:
		tds->m_draw_state = 4;
		break;
	case 50:
		tds->m_draw_state = 5;
		break;
	case 60:
		tds->m_draw_state = 6;
		break;
	case 70:
		tds->m_draw_state = 7;
		break;
	case 80:
		tds->m_draw_state = 8;
		count->TitleScene = 0;
		break;
	}

	if (GetKeyStatus(DIK_RETURN))
	{

		ChangeSceneStep(SceneStep::EndStep);
	}
}

// 次に飛ぶシーン先の設定
SceneId FinisTitleScene()
{
	for (int a = 0; a < TitleTextureList::MaxTitleTexture; a++)
	{


		TitleTextureData.m_pTexture[a]->Release();
		TitleTextureData.m_pTexture[a] = nullptr;
	}

	// 次のシーンの遷移先IDを返す
	return SceneId::GameScene;
}

