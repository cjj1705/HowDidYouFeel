#pragma once
#include "GameObject.h"
#include "SavePoint.h"
class SavePointManager :
	public GameObject
{
public:
	std::list<SavePoint*> savePointList;

	SavePoint* PushBackSavePoint(SavePoint* savePoint);
	virtual void LateUpdate();

	void Destroy(SavePoint* s);

private:
	std::list<SavePoint*> destroyed;
	void RemoveDestroyed();
};