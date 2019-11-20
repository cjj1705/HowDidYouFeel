#include "stdafx.h"
#include "StartButton.h"
#include "GameScene.h"

StartButton::StartButton() : Button(L"image/button/startButton.png") {
}


StartButton::~StartButton()
{
}

void StartButton::onMouseHover() {

}

void StartButton::onMouseClick() {
	Scene::ChangeScene(new GameScene());
}

void StartButton::onMouseOut() {

}