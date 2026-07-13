#pragma once

#include <windows.h>

#include <d2d1.h>
#include <vector>
#include <queue>

#include <functional>
#include <mutex>
#include <memory>

#include <thread>

#include "Shared_data.h"

#include "Entity.h"

extern bool Pausing;

class Game
{

	ID2D1Factory* factory = nullptr;

	ID2D1HwndRenderTarget* target = nullptr;
	ID2D1SolidColorBrush* brush = nullptr;
	ID2D1SolidColorBrush* white = nullptr;

	HINSTANCE hInst;
	HRESULT CreateGraphicResource();

public:

	HWND ParentWnd;
	HWND GameWnd;
	
	Game(HINSTANCE hInstance, ID2D1Factory* factory);
	~Game();

	void WindowCreate(int x, int y, int width, int height, HWND Parent);

	void Activate();

	void Render();
	void Think(float deltatime);

	static LRESULT CALLBACK GameProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

};