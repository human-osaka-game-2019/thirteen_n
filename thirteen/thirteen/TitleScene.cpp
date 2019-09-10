#include<stdio.h>
#include"Scene.h"
#include"TitleScene.h"
#include"DrawTexture.h"
#include"Device.h"
#include"TitleSystem.h"
#include<SoundsManager.h>

extern SoundLib::SoundsManager m_soundsManager;

void DrawTitleScene(DirectX* directX, Count* count);
void InitTitleScene(DirectX* directX, Count* count);
void UpdateTitleScene(DirectX* directX, Count* count, TitleDrawState* tds, FlameCount flamCount[]);
SceneId FinisTitleScene();

TEXTUREDATA TitleTextureData;
SceneSelect sceneSelct;
TitleDrawState tds;
WhiteSmallStar white_stra[11];
BlueSmallStar blue_stra[5];
PinkSmallStar pink_stra[3];
SelectTexture selectTexture[3];
TitleSystem titleSystem;
KeyState TitlekeyState;

void WhiteSmallStar::InputTu(float tu, float TuSize)
{
	m_pos_tu = (float)tu / 256;
	m_tu_size = (float)(tu + TuSize) / 256;
}
void BlueSmallStar::InputTu(float tu, float TuSize)
{
	m_pos_tu = (float)tu / 256;
	m_tu_size = (float)(tu + TuSize) / 256;
}

void PinkSmallStar::InputTu(float tu, float TuSize)
{
	m_pos_tu = (float)tu / 256;
	m_tu_size = (float)(tu + TuSize) / 256;
}

void FlamCountReset(FlameCount flamCount[])
{
	flamCount[1].m_count = 0;
}


SceneId TitleSceneMain(DirectX* directX, Count* count, FlameCount flamCount[])
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		count->AllReset();
		FlamCountReset(flamCount);
		TextureDataSet(selectTexture);
		InitTitleScene(directX, count);
		break;
		// 本編
	case SceneStep::MainStep:

		UpdateTitleScene(directX,count,&tds, flamCount);
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
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture7], *directX);
		break;
	case 1:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture0], *directX);
		break;
	case 2:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture1], *directX);
		break;
	case 3:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture2], *directX);
		break;
	case 4:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture3], *directX);
		break;
	case 5:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture4], *directX);
		break;
	case 6:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture5], *directX);
		break;
	case 7:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture6], *directX);
		break;
	case 8:
		DrawTest(78, 90, 780, 780, 0, 0, 1, 1, &TitleTextureData.m_pTexture[TitleTextureList::LogoTexture7], *directX);
		break;
		
	}
	
	DrawTest( 128, 116, white_stra[0].m_pos_x_size, white_stra[0].m_pos_y_size, white_stra[0].m_pos_tu, white_stra[0].m_pos_tv, white_stra[0].m_tu_size, white_stra[0].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(  54, 460, white_stra[1].m_pos_x_size, white_stra[1].m_pos_y_size, white_stra[1].m_pos_tu, white_stra[1].m_pos_tv, white_stra[1].m_tu_size, white_stra[1].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(  82, 666, white_stra[2].m_pos_x_size, white_stra[2].m_pos_y_size, white_stra[2].m_pos_tu, white_stra[2].m_pos_tv, white_stra[2].m_tu_size, white_stra[2].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 264, 888, white_stra[3].m_pos_x_size, white_stra[3].m_pos_y_size, white_stra[3].m_pos_tu, white_stra[3].m_pos_tv, white_stra[3].m_tu_size, white_stra[3].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 578, 852, white_stra[4].m_pos_x_size, white_stra[4].m_pos_y_size, white_stra[4].m_pos_tu, white_stra[4].m_pos_tv, white_stra[4].m_tu_size, white_stra[4].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 840, 174, white_stra[5].m_pos_x_size, white_stra[5].m_pos_y_size, white_stra[5].m_pos_tu, white_stra[5].m_pos_tv, white_stra[5].m_tu_size, white_stra[5].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(1082, 172, white_stra[6].m_pos_x_size, white_stra[6].m_pos_y_size, white_stra[6].m_pos_tu, white_stra[6].m_pos_tv, white_stra[6].m_tu_size, white_stra[6].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(1168, 390, white_stra[7].m_pos_x_size, white_stra[7].m_pos_y_size, white_stra[7].m_pos_tu, white_stra[7].m_pos_tv, white_stra[7].m_tu_size, white_stra[7].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 976, 464, white_stra[8].m_pos_x_size, white_stra[8].m_pos_y_size, white_stra[8].m_pos_tu, white_stra[8].m_pos_tv, white_stra[8].m_tu_size, white_stra[8].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(1100, 504, white_stra[9].m_pos_x_size, white_stra[9].m_pos_y_size, white_stra[9].m_pos_tu, white_stra[9].m_pos_tv, white_stra[9].m_tu_size, white_stra[9].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(1064, 898, white_stra[10].m_pos_x_size, white_stra[10].m_pos_y_size, white_stra[10].m_pos_tu, white_stra[10].m_pos_tv, white_stra[10].m_tu_size, white_stra[10].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	
	DrawTest(  96, 274, blue_stra[0].m_pos_x_size, blue_stra[0].m_pos_y_size, blue_stra[0].m_pos_tu, blue_stra[0].m_pos_tv, blue_stra[0].m_tu_size, blue_stra[0].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 118, 788, blue_stra[1].m_pos_x_size, blue_stra[1].m_pos_y_size, blue_stra[1].m_pos_tu, blue_stra[1].m_pos_tv, blue_stra[1].m_tu_size, blue_stra[1].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 934,  52, blue_stra[2].m_pos_x_size, blue_stra[2].m_pos_y_size, blue_stra[2].m_pos_tu, blue_stra[2].m_pos_tv, blue_stra[2].m_tu_size, blue_stra[2].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 916, 330, blue_stra[3].m_pos_x_size, blue_stra[3].m_pos_y_size, blue_stra[3].m_pos_tu, blue_stra[3].m_pos_tv, blue_stra[3].m_tu_size, blue_stra[3].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(1196, 876, blue_stra[4].m_pos_x_size, blue_stra[4].m_pos_y_size, blue_stra[4].m_pos_tu, blue_stra[4].m_pos_tv, blue_stra[4].m_tu_size, blue_stra[4].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);

	DrawTest( 324, 154, pink_stra[0].m_pos_x_size, pink_stra[0].m_pos_y_size, pink_stra[0].m_pos_tu, pink_stra[0].m_pos_tv, pink_stra[0].m_tu_size, pink_stra[0].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest( 240, 742, pink_stra[1].m_pos_x_size, pink_stra[1].m_pos_y_size, pink_stra[1].m_pos_tu, pink_stra[1].m_pos_tv, pink_stra[1].m_tu_size, pink_stra[1].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);
	DrawTest(1062, 276, pink_stra[2].m_pos_x_size, pink_stra[2].m_pos_y_size, pink_stra[2].m_pos_tu, pink_stra[2].m_pos_tv, pink_stra[2].m_tu_size, pink_stra[2].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], *directX);

	for (int a = 0 ; a < 3; a++)
	{
		DrawTest(selectTexture[a].m_pos_x, selectTexture[a].m_pos_y, selectTexture[a].m_x_size, selectTexture[a].m_y_size, selectTexture[a].m_pos_tu, selectTexture[a].m_pos_tv, selectTexture[a].m_tu_size, selectTexture[a].m_tv_size, &TitleTextureData.m_pTexture[TitleTextureList::TitleUiTexture], *directX);
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
	LoadTexture("Texture/hoshi.png", &TitleTextureData.m_pTexture[TitleTextureList::StarTexture], 0, directX);
	LoadTexture("Texture/title_ui.png", &TitleTextureData.m_pTexture[TitleTextureList::TitleUiTexture], 0, directX);

	count->Frame0 = 0;
	   
	ChangeSceneStep(SceneStep::MainStep);

}

// 次のシーンに行くための条件記入
void UpdateTitleScene(DirectX* directX, Count* count, TitleDrawState *tds, FlameCount flamCount[])
{
	m_soundsManager.AddFile("Sound/BGM.mp3", "GameBGM");

	m_soundsManager.SetVolume("GameBGM", 30);

	flamCount[1].m_count += 1;

	if (flamCount[2].m_count == 180)
	{
		m_soundsManager.Start("GameBGM", TRUE);
	}

	flamCount[2].m_count += 1;

	switch (count->TitleScene)
	{
	case 1:
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

	for (int c = 0; c < 3; c++)
	{
		switch (count->DrawSmallStar)
		{
		case 10:
			pink_stra[c].InputTu(40, 40);
			break;
		case 20:
			pink_stra[c].InputTu(80, 40);
			break;
		case 30:
			pink_stra[c].InputTu(120, 40);
			break;
		case 40:
			pink_stra[c].InputTu(160, 40);
			break;
		case 50:
			pink_stra[c].InputTu(0, 40);
			break;
		}
	}
	for (int b = 0; b < 5; b++)
	{
		switch (count->DrawSmallStar)
		{
		case 10:
			blue_stra[b].InputTu(40, 40);
			break;
		case 20:
			blue_stra[b].InputTu(80, 40);
			break;
		case 30:
			blue_stra[b].InputTu(120, 40);
			break;
		case 40:
			blue_stra[b].InputTu(160, 40);
			break;
		case 50:
			blue_stra[b].InputTu(0, 40);
			break;
		}
	}

	for (int a = 0; a < 10; a++)
	{
		switch (count->DrawSmallStar)
		{
		case 10:
			white_stra[a].InputTu(40,40);
			break;
		case 20:
			white_stra[a].InputTu(80, 40);
			break;
		case 30:
			white_stra[a].InputTu(120, 40);
			break;
		case 40:
			white_stra[a].InputTu(160, 40);
			break;
		case 50:
			white_stra[a].InputTu(0, 40);
			count->DrawSmallStar = 0;
			break;
		}
	}

	InputSelectKey(&titleSystem,&TitlekeyState);
	
	SelectMenu(&titleSystem,&TitlekeyState,selectTexture,flamCount);

	SelectScene(selectTexture,&sceneSelct);

	if (GetKeyStatus(DIK_RETURN))
	{
		m_soundsManager.AddFile("Sound/MenuPick.wav", "Select");
		m_soundsManager.SetVolume("Select", 15);
		m_soundsManager.Start("Select");
		m_soundsManager.Start("GameBGM", TRUE);

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

	switch (sceneSelct.SceneState)
	{
	case 0:
		break;
	case 1:
		return SceneId::GameScene;
		break;
	case 2:
		return SceneId::HelpScene;
		break;
	case 3:
		return SceneId::GameScene;
		break;
	}

}

