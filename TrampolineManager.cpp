#include "stdafx.h"
#include "TrampolineManager.h"
#include "Scene.h"

Trampoline* TrampolineManager::PushBackTrampoline(Trampoline* trampoline) {
	Scene::GetCurrentScene().PushBackGameObject(trampoline);
	trampolineList.push_back(trampoline);
	return trampoline;
}

void TrampolineManager::LateUpdate() {
	RemoveDestroyed();
}

void TrampolineManager::Destroy(Trampoline* t) {
	destroyed.push_back(t);
}

void TrampolineManager::RemoveDestroyed() {
	for (auto& i : destroyed)
	{
		trampolineList.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}