#include "stdafx.h"
#include "SavePointManager.h"
#include "Scene.h"

SavePoint* SavePointManager::PushBackSavePoint(SavePoint* savePoint) {
	Scene::GetCurrentScene().PushBackGameObject(savePoint);
	savePointList.push_back(savePoint);
	return savePoint;
}

void SavePointManager::LateUpdate() {
	RemoveDestroyed();
}

void SavePointManager::Destroy(SavePoint* s) {
	destroyed.push_back(s);
}

void SavePointManager::RemoveDestroyed() {
	for (auto& i : destroyed)
	{
		savePointList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}