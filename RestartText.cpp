#include "stdafx.h"
#include "RestartText.h"
#include "GameScene.h"

RestartText::RestartText() : GameObject(L"image/restartText.png") {
	transform->SetPosition(480.0f, 320.0f);
	renderer->alpha = 0.0f;
}


RestartText::~RestartText()
{
}

void RestartText::Update() {
	GameScene& nowScene = (GameScene&)Scene::GetCurrentScene();
	if (nowScene.player->isDie) {
		if ((renderer->alpha >= 1.0f && dir == 1) || (renderer->alpha <= 0.0f && dir == -1)) {
			dir *= -1;
		}
		renderer->alpha += 0.01f * dir;
	}
}