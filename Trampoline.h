#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "AnimationRenderer.h"
class Trampoline :
	public GameObject
{
public:
	Trampoline(const wchar_t* path);
	~Trampoline();

	AABBCollider *col;
	float jumpPower = 500.0f;
};