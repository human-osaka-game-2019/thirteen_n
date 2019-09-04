#ifndef SOUND_H_
#define SOUND_H_

#include <SoundsManager.h>
#include <tchar.h>

SoundLib::SoundsManager m_soundsManager;


enum SoundType {
	TYPE_NONE,
	BGM,
	SE
};

struct SoundKey {

	const char* Key;

	SoundType Type;

};

// 初期化
// SoundsManagerインスタンス生成後に1度のみ行う。


bool isSuccess = m_soundsManager.Initialize();


class SoundPlay
{

public:

	bool SoundState();

};

class SoundVolume
{

public:

	bool VolumeSet();

};

class SoundPitch
{

public:

	float SoundRatio();

};

class Foo
{

public:

	void Play() {
		bool isSuccess = m_soundsManager.Start(_T("bgm"), this);
	}

	void OnPlayedToEnd(std::basic_string<TCHAR> key) {
		// 再生終了後に行う処理
	}
};

#endif