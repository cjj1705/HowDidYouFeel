#include "stdafx.h"
#include "BossManager.h"
#include "Scene.h"

Boss* BossManager::PushBackBoss(Boss* boss) {
	Scene::GetCurrentScene().PushBackGameObject(boss);
	bossList.push_back(boss);
	return boss;
}

void BossManager::Hit(Boss* boss, float damage)
{
	boss->Hit(damage);
	if (boss->hp <= 0.0f)
	{
		for (auto& i : boss->bm->bulletList) {
			if (i->type == 0) {
				boss->bm->Destroy(i);
			}
		}
		Destroy(boss);
	}
}

void BossManager::LateUpdate()
{
	RemoveDestroyed();
}

void BossManager::Destroy(Boss* b)
{
	destroyed.push_back(b);
}

void BossManager::RemoveDestroyed()
{
	for (auto& i : destroyed) {
		bossList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}