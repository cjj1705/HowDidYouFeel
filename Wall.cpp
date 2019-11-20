#include "stdafx.h"
#include "Wall.h"


Wall::Wall(const wchar_t* path) : GameObject(path) {
	col = new AABBCollider(*transform, renderer->GetWidth(), renderer->GetHeight());
}


Wall::~Wall() {
	SAFE_DELETE(col);
}