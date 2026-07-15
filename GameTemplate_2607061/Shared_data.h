#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>

#include "miniaudio.h"

#include <vector>

class Entity;

class Shared_data {
	friend class Game;

	static std::vector<Entity*> p_Entities;
	static HWND p_Window;

public:

	static ID2D1HwndRenderTarget* Rendertarget;

	inline const static std::vector<Entity*> &Entities = p_Entities;
	inline const static HWND &Window = p_Window;

	class Input {
		friend class Game;
		static bool p_keys[256];
	public:
		class Mouse {
			friend class Game;

			static bool p_LButton;
			static bool p_RButton;
		public:
			inline static const bool& LButton = p_LButton;
			inline static const bool& RButton = p_RButton;
		};

		inline static const bool *keys = p_keys;

	};
	class DWrite {
		friend class Game;

		static IDWriteFactory* p_WriteFactory;
		static IDWriteTextFormat* p_MSGothic;
	public:
		inline static const IDWriteFactory*& WriteFactory = p_WriteFactory;
		inline static const IDWriteTextFormat*& MSGothic = p_MSGothic;
	};
	class Sound {
		friend class Game;
	public:
		static ma_engine& engine;
	};

};

