#include "stdafx.h"
#include "JumpAdder.h"


JumpAdder::JumpAdder(const wchar_t* path) :GameObject(path) {
	col = new CircleCollider(*transform, renderer->GetWidth() * 0.5f);
}


JumpAdder::~JumpAdder() {
	SAFE_DELETE(col);
}