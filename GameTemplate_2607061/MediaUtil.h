#pragma once
#include <Windows.h>
#include "miniaudio.h"

namespace MediaUtil {
	void CreateSoundFromMemory(const void* pData, int size, ma_decoder*, ma_sound*);
	void CreateSoundFromFile(const wchar_t* filename, ma_sound*);
}