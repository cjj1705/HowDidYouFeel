#pragma once
#include "GameObject.h"
#include "JumpAdder.h"
class JumpAdderManager :
	public GameObject
{
public:
	std::list<JumpAdder*> jumpAdderList;

	JumpAdder* PushBackJumpAddder(JumpAdder* jumpAdder);
	virtual void LateUpdate();

	void Destroy(JumpAdder* j);

private:
	std::list<JumpAdder*> destroyed;
	void RemoveDestroyed();
};