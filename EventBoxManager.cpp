#include "stdafx.h"
#include "EventBoxManager.h"
#include "Scene.h"

EventBox* EventBoxManager::PushBackEventBox(EventBox* eventBox) {
	eventBoxList.push_back(eventBox);
	return eventBox;
}

void EventBoxManager::LateUpdate() {
	RemoveDestroyed();
}

void EventBoxManager::Destroy(EventBox* w) {
	destroyed.push_back(w);
}

void EventBoxManager::RemoveDestroyed() {
	for (auto& i : destroyed)
	{
		eventBoxList.front()->~EventBox();
		eventBoxList.pop_front();
	}
	destroyed.clear();
}