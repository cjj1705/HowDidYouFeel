#include "stdafx.h"
#include "TitleScene.h"
#include "StartButton.h"

TitleScene::TitleScene() {
}


TitleScene::~TitleScene()
{
}

void TitleScene::Initialize() {

	background = PushBackGameObject(new GameObject(L"image/background.png"));
	background->transform->SetPosition(480.0f, 320.0f);

	PushBackGameObject(new StartButton())->transform->SetPosition(480.0f, 360.0f);
	explainButton = (ExplainButton*)PushBackGameObject(new ExplainButton());
	explainButton->transform->SetPosition(480.0f, 480.0f);
}