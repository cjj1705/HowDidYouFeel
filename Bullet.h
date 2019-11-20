#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
class Bullet :
	public GameObject
{
public:
	Bullet(const wchar_t *path, float speed, float speedRate, float angle, float angleRate, float damage, int type);
	~Bullet();
	float speed, speedRate;
	float angle, angleRate;
	float damage;

	bool CheckOutOfScreen();
	bool isOutOfScreen = false;

	CircleCollider *col;

	virtual void Update();
	virtual void Move();

	int type;
};