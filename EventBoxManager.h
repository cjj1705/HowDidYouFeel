#pragma once
#include "GameObject.h"
#include "EventBox.h"
class EventBoxManager :
	public GameObject
{
public:
	std::list<EventBox*> eventBoxList;

	EventBox* PushBackEventBox(EventBox* eventBox);
	virtual void LateUpdate();

	void Destroy(EventBox* e);

private:
	std::list<EventBox*> destroyed;
	void RemoveDestroyed();
};