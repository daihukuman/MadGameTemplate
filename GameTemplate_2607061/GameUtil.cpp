#include "GameUtil.h"

D2D1_POINT_2F GameUtil::GetCursorPosition(bool isScreen, HWND Window) {

	POINT pos;
	GetCursorPos(&pos);

	if (!isScreen) {
		ScreenToClient(Window, &pos);
	}

	return D2D1::Point2F(pos.x, pos.y);

}

D2D1_POINT_2F GameUtil::GetEntityCenter(const Entity* ent) {
	return D2D1::Point2F(ent->x + (ent->Width * 0.5f), ent->y + (ent->Height * 0.5f));
}