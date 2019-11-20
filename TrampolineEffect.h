#pragma once
#include "GameObject.h"
#include "AnimationRenderer.h"
class TrampolineEffect
	: public GameObject
{
public:
	TrampolineEffect();
	~TrampolineEffect();

	AnimationRenderer* animRenderer;
};