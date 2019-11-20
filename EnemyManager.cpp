#include "stdafx.h"
#include "EnemyManager.h"
#include "Scene.h"		//이거 추가

Enemy* EnemyManager::PushBackEnemy(Enemy* enemy) {
	Scene::GetCurrentScene().PushBackGameObject(enemy);
	enemyList.push_back(enemy);
	return enemy;
}

void EnemyManager::Hit(Enemy* enemy, float damage)
{
	enemy->Hit(damage);
	if (enemy->hp <= 0.0f)
	{
		Destroy(enemy);
	}
}

void EnemyManager::LateUpdate()
{
	RemoveDestroyed();
}

void EnemyManager::Destroy(Enemy* e)
{
	destroyed.push_back(e);
}

void EnemyManager::RemoveDestroyed()
{
	for (auto& i : destroyed) {
		enemyList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}