#include "stdafx.h"
#include "ExplainingButton.h"

ExplainingButton::ExplainingButton() : Button(L"image/button/explainInButton.png") {
}

ExplainingButton::~ExplainingButton() {
}

void ExplainingButton::onMouseHover() {

}

void ExplainingButton::onMouseClick() {
	if (isShowing) {
		isShowing = false;
		renderer->alpha = 0.0f;
	}
}

void ExplainingButton::onMouseOut() {

}