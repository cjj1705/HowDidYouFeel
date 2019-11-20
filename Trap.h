#pragma once
#include "GameObject.h"
#include "TriangleCollider.h"
#include "AABBCollider.h"
class Trap :
	public GameObject
{
public:
	Trap(const wchar_t* path);
	~Trap();

	TriangleCollider* col;

	float moveSpeed = 100.0f;
	Vector2 velocity;

	bool doMoving = false;
	void setVelocity(float x, float y);

	bool CheckOutOfScreen();
	bool isOutOfScreen = false;

	virtual void Update();
	virtual void Move();
};