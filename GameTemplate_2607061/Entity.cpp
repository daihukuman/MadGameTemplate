#include "Entity.h"

Entity::Entity() {};

void Entity::LoadSprite(int ResourceID, const wchar_t *ResourceType) {
	if (EntitySprite && hInst) {
		EntitySprite.LoadSpriteFromResource(
			hInst, ResourceID, ResourceType
		);

		D2D1_SIZE_F size = EntitySprite.GetSprite()->GetSize();

		Width = size.width;
		Height = size.height;

	}
}

void Entity::LoadSpriteFromFile(const wchar_t *FilePath) {
	if (target) {
		EntitySprite.SetSprite(
			PaiUtil::GetBitmapFromFilename(
				FilePath
			)
		);
	}
}

void Entity::Spawn(HINSTANCE hInstance) {
	hInst = hInstance;
	Activate();
}

void Entity::Activate() {};

void Entity::Think(float deltatime) {

}

void Entity::Render() {
	if (EntitySprite && Width > 0 && Height > 0) {
		(*target)->DrawBitmap(EntitySprite, D2D1::RectF(x, y, Width + x, Height + y));
	}
}