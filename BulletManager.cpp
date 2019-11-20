#include "stdafx.h"
#include "BulletManager.h"
#include "Scene.h"

Bullet* BulletManager::PushBackPlayerBullet(Bullet* b) {
	Scene::GetCurrentScene().PushBackGameObject(b);
	bulletList.push_back(b);
	return b;
}

void BulletManager::Destroy(Bullet* b) {
	b->isDestroyed = true;
	destroyed.push_back(b);
}

void BulletManager::LateUpdate() {
	for (auto& i : bulletList) {
		if (i->isOutOfScreen) {
			Destroy(i);
		}
	}
	RemoveDestroyed();
}

void BulletManager::RemoveDestroyed() {
	for (auto& i : destroyed) {
		bulletList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}