#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Enemy :
	public GameObject
{
public:
	Enemy(const wchar_t* path);
	~Enemy();
	float hp;
	void Hit(float damage);
	AABBCollider* col;
};