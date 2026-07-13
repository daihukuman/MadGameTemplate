#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>

#include "PaintUtil.h"
#include "Entity.h"

#define CLIENT false
#define SCREEN true

namespace GameUtil {
	D2D1_POINT_2F GetCursorPosition(bool isScreen, HWND);
	D2D1_POINT_2F GetEntityCenter(const Entity*);
}