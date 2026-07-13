#include "Entity.h"

Entity::Entity() {};

void Entity::LoadSprite(int ResourceID, const wchar_t *ResourceType) {
	if (target && hInst) {
		Sprite = PaiUtil::GetBitmapFromResource(
			hInst,
			*target,
			ResourceID,
			ResourceType
		);

		D2D1_SIZE_F size = Sprite->GetSize();

		Width = size.width;
		Height = size.height;

	}
}

void Entity::LoadSpriteFromFile(const wchar_t *FilePath) {
	if (target) {
		Sprite = PaiUtil::GetBitmapFromFilename(
			FilePath,
			*target
		);
	}
}

void Entity::Spawn(ID2D1HwndRenderTarget** Rendertarget, HINSTANCE hInstance, Shared_data* dataset) {
	hInst = hInstance;
	target = Rendertarget;
	data = dataset;
	Activate();
}

void Entity::Activate() {};

void Entity::Think(float deltatime) {

}

void Entity::Render() {
	if (Sprite && Width > 0 && Height > 0) {
		(*target)->DrawBitmap(Sprite, D2D1::RectF(x, y, Width + x, Height + y));
	}
}