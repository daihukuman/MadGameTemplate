#pragma once

#include <Windows.h>
#include <d2d1.h>

#include "PaintUtil.h"
#include "resource.h"
#include "Shared_data.h"

#include "Sprite.h"

class Entity
{

protected:

	HINSTANCE hInst;
	ID2D1HwndRenderTarget** target = nullptr;

public:

	Sprite EntitySprite;

	float x = 0.f;
	float y = 0.f;
	float Width = 0.f;
	float Height = 0.f;

	Entity();

	void Spawn(HINSTANCE hInstance);
	virtual void Activate();

	void LoadSprite(int ResourceID, const wchar_t *ResourceType);
	void LoadSpriteFromFile(const wchar_t* FilePath);

	virtual void Think(const float deltatime);
	virtual void Render();

};

