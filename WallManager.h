#pragma once
#include "GameObject.h"
#include "Wall.h"
class WallManager :
	public GameObject
{
public:
	std::list<Wall*> wallList;

	Wall* PushBackWall(Wall* wall);
	virtual void LateUpdate();

	void Destroy(Wall* w);

private:
	std::list<Wall*> destroyed;
	void RemoveDestroyed();
};