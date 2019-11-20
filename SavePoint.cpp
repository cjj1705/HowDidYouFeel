#include "stdafx.h"
#include "SavePoint.h"
#include "ListAnimation.h"

SavePoint::SavePoint(const wchar_t* path, int stageX, int stageY, int pointX, int pointY) : GameObject(animRenderer = new AnimationRenderer()) {
	col = new AABBCollider(*transform, renderer->GetWidth(), renderer->GetHeight());
	point = { { stageX, stageY }, { pointX, pointY } };

	ListAnimation* active_off = new ListAnimation(0, 1.0f);
	active_off->PushBackSprite(L"image/object/savePoint_off.png");
	ListAnimation* active_on = new ListAnimation(1, 1.0f);
	active_on->PushBackSprite(L"image/object/savePoint_on.png");

	animRenderer->PushBackAnimation(active_off);
	animRenderer->PushBackAnimation(active_on);
	animRenderer->ChangeAnimation(0);
}

SavePoint::~SavePoint() {
	SAFE_DELETE(col);
}

void SavePoint::Update() {
	if (isCollided) {
		if (++count == 120) {
			animRenderer->ChangeAnimation(0);
			isCollided = false;
			count = 0;
		}
		else {
			animRenderer->ChangeAnimation(1);
		}
	}
}