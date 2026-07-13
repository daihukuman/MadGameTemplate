#pragma once

#include <Windows.h>
#include <d2d1.h>

#include "PaintUtil.h"
#include "resource.h"
#include "Shared_data.h"

class Entity
{

protected:

	HINSTANCE hInst;
	ID2D1HwndRenderTarget** target = nullptr;
	Shared_data *data = nullptr;

public:

	ID2D1Bitmap* Sprite = nullptr;

	float x = 0.f;
	float y = 0.f;
	float Width = 0.f;
	float Height = 0.f;

	Entity();

	void Spawn(ID2D1HwndRenderTarget** Rendertarget, HINSTANCE hInstance, Shared_data *dataset);
	virtual void Activate();

	void LoadSprite(int ResourceID, const wchar_t *ResourceType);
	void LoadSpriteFromFile(const wchar_t* FilePath);

	virtual void Think(const float deltatime);
	virtual void Render();

};

