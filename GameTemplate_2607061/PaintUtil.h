#pragma once

#include <Windows.h>

#include <d2d1.h>
#include <dwrite.h>

#include <filesystem>

namespace PaiUtil {
	
	ID2D1Bitmap* GetBitmapFromFilename(std::filesystem::path filepath);
	ID2D1Bitmap* GetBitmapFromResource(HINSTANCE hInst, int resourceID, const wchar_t* resourceType);

	IDWriteTextFormat* CreateTextFormat(IDWriteFactory* factory, const wchar_t* FontName, float FontSize);

}