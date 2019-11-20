#include "stdafx.h"
#include "TrampolineEffect.h"
#include "SheetAnimation.h"

TrampolineEffect::TrampolineEffect() : GameObject(animRenderer = new AnimationRenderer()) {
	SheetAnimation* effectAni = new SheetAnimation(0, 16.0f, L"image/object/trampolineEffect.png", 32, 64, 3);
	animRenderer->PushBackAnimation(effectAni);
	animRenderer->ChangeAnimation(0);
}

TrampolineEffect::~TrampolineEffect()
{
}