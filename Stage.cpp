#include "stdafx.h"
#include "Stage.h"
#include "GameScene.h"

Stage::Stage(PhysicsManager *pm) : pm(pm){

}


Stage::~Stage()
{
}

void Stage::clear() {
	GameScene &nowScene = (GameScene&)Scene::GetCurrentScene();
	for (auto& i : nowScene.pm->wm->wallList) {
		nowScene.pm->wm->Destroy(i);
	}
	nowScene.pm->wm->wallList.clear();
	for (auto& i : nowScene.pm->bm->bulletList) {
		nowScene.pm->bm->Destroy(i);
	}
	nowScene.pm->bm->bulletList.clear();
	for (auto& i : nowScene.pm->em->enemyList) {
		nowScene.pm->em->Destroy(i);
	}
	nowScene.pm->em->enemyList.clear();
	for (auto& i : nowScene.pm->tm->trampolineList) {
		nowScene.pm->tm->Destroy(i);
	}
	nowScene.pm->tm->trampolineList.clear();
	for (auto& i : nowScene.pm->trm->trapList) {
		nowScene.pm->trm->Destroy(i);
	}
	nowScene.pm->trm->trapList.clear();
	for (auto& i : nowScene.pm->sm->savePointList) {
		nowScene.pm->sm->Destroy(i);
	}
	nowScene.pm->sm->savePointList.clear();
	for (auto& i : nowScene.pm->jm->jumpAdderList) {
		nowScene.pm->jm->Destroy(i);
	}
	nowScene.pm->jm->jumpAdderList.clear();
	for (auto& i : nowScene.pm->bsm->bossList) {
		nowScene.pm->bsm->Destroy(i);
	}
	nowScene.pm->bsm->bossList.clear();
}

void Stage::render() {
	if (nextPlayerPos == Stage::TOP) {
		pm->p->transform->position.y = 640.0f;
		nowStage.first--;
		nextPlayerPos = 0;
	}
	else if (nextPlayerPos == Stage::LEFT) {
		pm->p->transform->position.x = 960.0f;
		nowStage.second--;
		nextPlayerPos = 0;
	}
	else if (nextPlayerPos == Stage::BOTTOM) {
		pm->p->transform->position.y = 0.0f;
		nowStage.first++;
		nextPlayerPos = 0;
	}
	else if (nextPlayerPos == Stage::RIGHT) {
		pm->p->transform->position.x = 0.0f;
		nowStage.second++;
		nextPlayerPos = 0;
	}
	else if (pm->p->isSaved && !nextPlayerPos) {
		pm->p->transform->SetPosition(16.0f + 32.0f * pm->p->savePoint.second.first, 16.0f + 32.0f * (pm->p->savePoint.second.second + 1));
	}
	else {
		pm->p->transform->SetPosition(112.0f, 592.0f);
		nowStage.first = 0;
		nowStage.second = 0;
	}
	
	pm->p->isOnGround = false;
	pm->p->doJump = false;

	int pos = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			switch (stageInfo[nowStage.first][nowStage.second][i][j]) {
			case '1' :
				pm->wm->PushBackWall(new Wall(L"image/object/wall.png"))->transform->SetPosition(16.0f + 32.0f * j, 16.0f + 32.0f * i); break;
			case '2' :
				pm->tm->PushBackTrampoline(new Trampoline(L"image/object/trampoline.png"))->transform->SetPosition(16.0f + 32.0f * j, 24.0f + 32.0f * i); break;
			case '3' : 
				pm->trm->PushBackTrap(new Trap(L"image/object/trap.png"))->transform->SetPosition(16.0f + 32.0f * j, 16.0f + 32.0f * i); break;
			case '4' :
				pm->sm->PushBackSavePoint(new SavePoint(L"image/object/savePoint_off.png", nowStage.first, nowStage.second, j, i))->transform->SetPosition(16.0f + 32.0f * j, 16.0f + 32.0f * i); break;
			case '5' :
				pm->jm->PushBackJumpAddder(new JumpAdder(L"image/item/jumpAdder.png"))->transform->SetPosition(16.0f + 32.0f * j, 16.0f + 32.0f * i); break;
			case '8' :
				pm->bsm->PushBackBoss(new Boss(L"image/boss.png", pm->bm, 100.0f))->transform->SetPosition(32.0f + 32.0f * j, 16.0f + 32.0f * i); pm->p->canMoveStage = false; break;
			}
		}
	}
}

void Stage::start() {
	clear();
	render();
}

void Stage::LateUpdate() {
	if (doRestart) {
		doRestart = false;
		pm->p->canMoveStage = true;
		pm->p->isDie = false;
		pm->p->animRenderer->alpha = 1.0f;
		start();
	}
}