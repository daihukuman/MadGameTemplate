#pragma once
#include <Windows.h>
#include <d2d1.h>

#include <string>

#include "PaintUtil.h"

class Sprite
{

	ID2D1Bitmap* bitmap = nullptr;

public:

	Sprite();
	Sprite(std::wstring path);

	operator ID2D1Bitmap* ();
};

