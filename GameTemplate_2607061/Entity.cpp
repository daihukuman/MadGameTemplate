#include "Entity.h"

Entity::Entity() {};

void Entity::Spawn(HINSTANCE hInstance) {
	hInst = hInstance;
	Activate();
}

void Entity::Activate() {};

void Entity::Think(float deltatime) {

}

void Entity::Render() {
	if (EntitySprite && Width > 0 && Height > 0) {
		Shared_data::Rendertarget->DrawBitmap(EntitySprite, D2D1::RectF(x, y, Width + x, Height + y));
	}
}