#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>

#include "miniaudio.h"

#include <vector>

class Entity;

class Shared_data {
	friend class Game;

	inline static std::vector<Entity*> p_Entities = {};
	inline static HWND p_Window = NULL;

public:

	inline static ID2D1HwndRenderTarget* Rendertarget = nullptr;

	inline const static std::vector<Entity*> &Entities = p_Entities;
	inline const static HWND &Window = p_Window;

	class Input {
		friend class Game;
		inline static bool p_keys[256] = {};
	public:
		class Mouse {
			friend class Game;

			inline static bool p_LButton = false;
			inline static bool p_RButton = false;
		public:
			inline static const bool& LButton = p_LButton;
			inline static const bool& RButton = p_RButton;
		};

		inline static const bool *keys = p_keys;

	};
	class DWrite {
	public:
		inline static IDWriteFactory* WriteFactory = nullptr;
		inline static const IDWriteTextFormat* MSGothic = nullptr;
	};
	class Sound {
	public:
		inline static ma_engine engine{};
	};

};

