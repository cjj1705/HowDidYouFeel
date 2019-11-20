#include "stdafx.h"
#include "TrapManager.h"
#include "Scene.h"

Trap* TrapManager::PushBackTrap(Trap* trap) {
	Scene::GetCurrentScene().PushBackGameObject(trap);
	trapList.push_back(trap);
	return trap;
}

void TrapManager::LateUpdate() {
	RemoveDestroyed();
}

void TrapManager::Destroy(Trap* t) {
	destroyed.push_back(t);
}

void TrapManager::RemoveDestroyed() {
	for (auto& i : destroyed)
	{
		trapList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}