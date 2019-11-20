#include "stdafx.h"
#include "ExplainButton.h"
#include "TitleScene.h"

ExplainButton::ExplainButton() : Button(L"image/button/explainButton.png") {
	TitleScene& nowScene = (TitleScene&)Scene::GetCurrentScene();
	explainImage = (ExplainingButton*)nowScene.PushBackGameObject(new ExplainingButton());
	explainImage->transform->SetPosition(480.0f, 180.0f);
	explainImage->renderer->alpha = 0.0f;
}

ExplainButton::~ExplainButton() {
}

void ExplainButton::onMouseHover() {

}

void ExplainButton::onMouseClick() {
	if (explainImage->renderer->alpha == 0.0f) {
		explainImage->renderer->alpha = 1.0f;
		isExplaining = true;
		explainImage->isShowing = true;
	}
}

void ExplainButton::onMouseOut() {

}