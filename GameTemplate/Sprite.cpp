#include "Sprite.h"
#include "Shared_data.h"

Sprite::Sprite() {}

Sprite::Sprite(std::wstring path) {
	PaiUtil::GetBitmapFromFilename(path);
}

Sprite::operator ID2D1Bitmap* () {
	return bitmap;
}

void Sprite::Render() {
	if (bitmap && Width > 0 && Height > 0) {
		Shared_data::Rendertarget->DrawBitmap(bitmap, D2D1::RectF(x, y, (Width + x) * scale, (Height + y) * scale));
	}
}

ID2D1Bitmap* Sprite::GetSprite() {
	return bitmap;
}

void Sprite::SetSprite(ID2D1Bitmap* bm) {
	bitmap = bm;
}

void Sprite::LoadSpriteFromResource(HINSTANCE hInst, int resourceID, const wchar_t* resourceType) {
	bitmap = PaiUtil::GetBitmapFromResource(
		hInst, resourceID, resourceType
	);
}

void Sprite::LoadSpriteFromFile(std::wstring path) {
	bitmap = PaiUtil::GetBitmapFromFilename(
		path
	);
}