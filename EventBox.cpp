#include "stdafx.h"
#include "EventBox.h"

EventBox::EventBox(float x, float y) {
	Vector2 vector;
	vector.SetVector(x, y);
	transform = new Transform(vector);
	col = new AABBCollider(*transform, 32.0f, 32.0f);
}


EventBox::~EventBox() {
	trapList.clear();
	SAFE_DELETE(col);
}

void EventBox::addTrap(Trap& trap) {
	trapList.push_back(trap);
}

void EventBox::setTrapVelocity(Trap& trap, float x, float y) {
	addTrap(trap);
	trap.setVelocity(x, y);
}

void EventBox::activate() {
	for (auto& i : trapList) {
		i.doMoving = true;
	}
}