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

public:

	Sprite EntitySprite;

	float x = 0.f;
	float y = 0.f;

	Entity();

	void Spawn(HINSTANCE hInstance);
	virtual void Activate();

	virtual void Think(const float deltatime);
	virtual void Render();

};

