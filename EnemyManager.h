#pragma once
#include "GameObject.h"
#include "Enemy.h"
class EnemyManager :
	public GameObject
{
public:
	std::list<Enemy*> enemyList;

	Enemy* PushBackEnemy(Enemy* enemy);
	void Hit(Enemy* enemy, float damage);
	virtual void LateUpdate();

	void Destroy(Enemy* e);

private:
	std::list<Enemy*> destroyed;
	void RemoveDestroyed();
};