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
	if (EntitySprite) {
		EntitySprite.Render();
	}
}