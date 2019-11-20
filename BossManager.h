#pragma once
#include "GameObject.h"
#include "Boss.h"
class BossManager :
	public GameObject
{
public:
	std::list<Boss*> bossList;

	Boss* PushBackBoss(Boss* enemy);
	void Hit(Boss* boss, float damage);
	virtual void LateUpdate();

	void Destroy(Boss* b);

private:
	std::list<Boss*> destroyed;
	void RemoveDestroyed();
};