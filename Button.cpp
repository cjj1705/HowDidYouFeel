#include "stdafx.h"
#include "Button.h"
#include "InputManager.h"

Button::Button(const wchar_t* path) : GameObject(path) {
}

Button::~Button() {
}

void Button::Update() {
	float x = InputManager::GetMouseX(), y = InputManager::GetMouseY();
	float left = transform->position.x - renderer->GetWidth() / 2;
	float right = transform->position.x + renderer->GetWidth() / 2;
	float top = transform->position.y - renderer->GetHeight() / 2;
	float bottom = transform->position.y + renderer->GetHeight() / 2;
	if (x > left && x < right && y > top && y < bottom) {
		if (InputManager::GetKeyDown(VK_LBUTTON)) { // 마우스 클릭
			onMouseClick();
		}
		else {
			isHover = true;
			onMouseHover();
		}
	}
	else if (isHover) {
		isHover = false;
		onMouseOut();
	}
}