#include "stdafx.h"
#include "Trampoline.h"

Trampoline::Trampoline(const wchar_t* path) : GameObject(path) {
	col = new AABBCollider(*transform, renderer->GetWidth(), renderer->GetHeight());
}


Trampoline::~Trampoline() {
	SAFE_DELETE(col);
}