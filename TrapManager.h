#pragma once
#include "GameObject.h"
#include "Trap.h"
class TrapManager :
	public GameObject
{
public:
	std::list<Trap*> trapList;

	Trap* PushBackTrap(Trap* trap);
	virtual void LateUpdate();

	void Destroy(Trap* t);

private:
	std::list<Trap*> destroyed;
	void RemoveDestroyed();
};