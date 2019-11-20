#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "AnimationRenderer.h"
class SavePoint :
	public GameObject
{
public:
	SavePoint(const wchar_t* path, int stageX, int stageY, int pointX, int pointY);
	~SavePoint();

	AABBCollider* col;
	PP point;

	AnimationRenderer* animRenderer;

	bool isCollided = false;
	int count = 0;

	virtual void Update();
};