#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "BulletManager.h"
class Boss :
	public GameObject
{
public:
	Boss(const wchar_t* path, BulletManager* bm, float hp);
	~Boss();

	float hp;
	void Hit(float damage);

	AABBCollider* col;
	BulletManager* bm;

	int time = 0;
	float angle = 0.0f;
	int pattern = 0;
	int count = 0;
	virtual void Update();
};