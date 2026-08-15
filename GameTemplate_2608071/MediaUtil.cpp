#include "MediaUtil.h"

#include "miniaudio.h"

#include "Shared_data.h"

#include <string>
#include <format>

void MediaUtil::CreateSoundFromMemory(const void* pData, int size, ma_decoder *decoder, ma_sound* sound) {

    if (pData && decoder) {

        ma_result result = ma_decoder_init_memory(
            pData,
            size,
            NULL,
            decoder
        );

        if (result != MA_SUCCESS) {
            OutputDebugStringW(L"decoder init error\n");
            ZeroMemory(sound, sizeof(*sound));
        }

        result = ma_sound_init_from_data_source(
            &Shared_data::Sound::engine,
            decoder,
            0,
            nullptr,
            sound
        );

        if (result != MA_SUCCESS) {
            OutputDebugStringW(L"sound init error\n");
            OutputDebugStringW(
                std::format(
                    L"result={}\n",
                    static_cast<int>(result)
                ).c_str()
            );
            ZeroMemory(sound, sizeof(*sound));
        }
    }
}

void MediaUtil::CreateSoundFromFile(const wchar_t* filepath, ma_sound* sound) {

     int size = WideCharToMultiByte(
        CP_UTF8,
        0,
        filepath,
        -1,
        NULL,
        0,
        NULL,
        NULL
    );

    std::string result(size, 0);

    WideCharToMultiByte(
        CP_UTF8,
        0,
        filepath,
        -1,
        result.data(),
        size,
        NULL,
        NULL
    );

    ma_sound_init_from_file(
        &Shared_data::Sound::engine,
        result.c_str(),
        0,
        NULL,
        NULL,
        sound
    );
}