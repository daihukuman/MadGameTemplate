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
	static std::vector<Entity*> &Entities;
	static HWND &Window;

	class Input {
		friend class Game;
		static bool p_keys[256];
	public:
		class Mouse {
			friend class Game;

			static bool p_Lbutton;
			static bool p_RButton;
		public:
			static const bool& LButton;
			static const bool& RButton;
		};

		static const bool(&keys)[256];

	};
	class DWrite {
		friend class Game;

		static IDWriteFactory* p_WriteFactory;
		static IDWriteTextFormat* p_MSGothic;
	public:
		static const IDWriteFactory*& WriteFactory;
		static const IDWriteTextFormat*& MSGothic;
	};
	class Sound {
		friend class Game;

		static ma_engine p_engine;
	public:
		static const ma_engine& engine;
	};

};

