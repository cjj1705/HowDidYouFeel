#include "stdafx.h"
#include "JumpAdderManager.h"
#include "Scene.h"

JumpAdder* JumpAdderManager::PushBackJumpAddder(JumpAdder* jumpAdder) {
	Scene::GetCurrentScene().PushBackGameObject(jumpAdder);
	jumpAdderList.push_back(jumpAdder);
	return jumpAdder;
}

void JumpAdderManager::LateUpdate() {
	RemoveDestroyed();
}

void JumpAdderManager::Destroy(JumpAdder* j) {
	destroyed.push_back(j);
}

void JumpAdderManager::RemoveDestroyed() {
	for (auto& i : destroyed)
	{
		jumpAdderList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}