#pragma once
#include <Windows.h>
#include <d2d1.h>

#include <string>

#include "PaintUtil.h"

class Sprite
{

	ID2D1Bitmap* bitmap = nullptr;

public:

	float Width = 0;
	float Height = 0;

	float x = 0;
	float y = 0;

	float scale = 1;

	Sprite();
	Sprite(std::wstring path);

	operator ID2D1Bitmap*();

	void Render();

	void SetSprite(ID2D1Bitmap*);
	ID2D1Bitmap* GetSprite();

	void LoadSpriteFromResource(HINSTANCE hInst, int resourceID, const wchar_t* resourceType);
	void LoadSpriteFromFile(std::wstring path);

};

