#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
class JumpAdder :
	public GameObject
{
public:
	JumpAdder(const wchar_t* path);
	~JumpAdder();

	CircleCollider* col;
};