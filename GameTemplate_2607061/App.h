#pragma once

#include <vector>
#include <string>

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>

#include <memory>

#include "Game.h"

class App
{

	ID2D1Factory* factory = nullptr;

	IDWriteFactory* writefactory = nullptr;
	IDWriteTextFormat* format = nullptr;

	float x = 0;
	float y = 0;

	HINSTANCE hInst;
	int showcode = 0;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

public:

	HWND MainWnd;

	std::unique_ptr<Game> game = nullptr;

	App(HINSTANCE, int nCmdShow);

};