#pragma once
#include "GameObject.h"
#include "Trampoline.h"
class TrampolineManager :
	public GameObject
{
public:
	std::list<Trampoline*> trampolineList;

	Trampoline* PushBackTrampoline(Trampoline* trampoline);
	virtual void LateUpdate();

	void Destroy(Trampoline* t);

private:
	std::list<Trampoline*> destroyed;
	void RemoveDestroyed();
};