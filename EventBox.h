#pragma once
#include "AABBCollider.h"
#include "Trap.h"
#include "Transform.h"
class EventBox
{
public:
	EventBox(float x, float y);
	~EventBox();

	AABBCollider* col;
	Transform* transform;
	
	std::list<Trap&> trapList;

	void addTrap(Trap& trap);
	void setTrapVelocity(Trap& trap, float x, float y);
	void activate();
};