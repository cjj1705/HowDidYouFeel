#include "stdafx.h"
#include "WallManager.h"
#include "Scene.h"

Wall* WallManager::PushBackWall(Wall* wall) {
	Scene::GetCurrentScene().PushBackGameObject(wall);
	wallList.push_back(wall);
	return wall;
}

void WallManager::LateUpdate() {
	RemoveDestroyed();
}

void WallManager::Destroy(Wall* w) {
	destroyed.push_back(w);
}

void WallManager::RemoveDestroyed() {
	for (auto& i : destroyed)
	{
		wallList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}