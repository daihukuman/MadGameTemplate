#pragma once
#include <Windows.h>
#include "miniaudio.h"

namespace MediaUtil {
	void CreateSoundFromMemory(ma_engine& engine,const void* pData, int size, ma_decoder*, ma_sound*);
	void CreateSoundFromFile(ma_engine& engine, const wchar_t* filename, ma_sound*);
}