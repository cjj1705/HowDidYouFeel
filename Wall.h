#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Wall :
	public GameObject
{
public:
	Wall(const wchar_t* path);
	~Wall();

	AABBCollider* col;
};