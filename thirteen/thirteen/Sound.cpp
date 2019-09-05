#include "Sound.h"

using namespace SoundLib;

const TCHAR* filePath = _T("Sound/");

bool SoundPlay::SoundState()
{
	m_soundsManager.AddFile("thirteen/Sound/BGM.mp3", _T("BGM")); // Or BGM

	m_soundsManager.Start(_T("BGM"), true); // Or BGM

	m_soundsManager.Stop(_T("bgm")); // Or BGM

	return 0;

}

// 再生状態を取得
SoundLib::PlayingStatus status = m_soundsManager.GetStatus(_T("bgm"));

/// 再生状況を示すステータス
enum SoundStatus
{

	/// <summary>停止中</summary>
	Stopped,
	/// <summary>再生中</summary>
	Playing,
	/// <summary>一時停止中</summary>
	Pausing

};


bool SoundVolume::VolumeSet()
{

	//Volume Setting ( 0(無音) ~ 100(原音量) )
	m_soundsManager.SetVolume(_T("bgm"), 50);

	//Volume 情報収得
	m_soundsManager.GetVolume(_T("bgm"));

	return 0;

}

float SoundPitch::SoundRatio()
{

	//Sound Speed 調節
	m_soundsManager.SetFrequencyRatio(_T("bgm"), 1.0f);

	//Sound Speed 収得
	m_soundsManager.GetFrequencyRatio(_T("bgm"));

	return 0;

}


