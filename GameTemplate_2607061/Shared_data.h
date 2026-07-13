#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>

#include "miniaudio.h"

#include <vector>

class Entity;
class Enemy;

class Shared_data
{
public:

	bool Lbutton = false;
	bool RButton = false;

	IDWriteFactory* WriteFactory = nullptr;
	IDWriteTextFormat* MSGothic = nullptr;

	bool keys[256] = {};

	std::vector<Entity*> Entities = {};

	HWND Window = NULL;

	ma_engine engine;

};

