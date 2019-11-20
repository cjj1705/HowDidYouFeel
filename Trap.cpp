#include "stdafx.h"
#include "Trap.h"
#include "Framework.h"
#include "TimeManager.h"

Trap::Trap(const wchar_t* path) : GameObject(path) {
	Vector2 top, left, right;
	top.SetVector(transform->position.x, transform->position.y - renderer->GetHeight() / 2);
	left.SetVector(transform->position.x - renderer->GetWidth() / 2, transform->position.y + renderer->GetHeight() / 2);
	right.SetVector(transform->position.x + renderer->GetWidth() / 2, transform->position.y + renderer->GetHeight() / 2);
	col = new TriangleCollider(*transform, top, left, right);
}

Trap::~Trap() {
	SAFE_DELETE(col);
}

void Trap::setVelocity(float x, float y) {
	velocity.SetVector(x, y);
}

bool Trap::CheckOutOfScreen() {
	int sw = Framework::GetInstance().GetWinApp().GetScreenWidth();
	int sh = Framework::GetInstance().GetWinApp().GetScreenHeight();
	int bw = renderer->GetWidth();
	int bh = renderer->GetHeight();
	Vector2 pos = transform->position;
	Vector2 scale = transform->scale;
	return pos.x < scale.x * bw * (-1.0f) ||
		pos.x > scale.x * bw + sw ||
		pos.y < scale.y * bh * (-1.0f) ||
		pos.y > scale.y * bh + sh;
}

void Trap::Update() {
	if (doMoving) {
		Move();
		isOutOfScreen = CheckOutOfScreen();
	}
}

void Trap::Move() {
	transform->position.x += velocity.x * TimeManager::GetDeltaTime();
	transform->position.y += velocity.y * TimeManager::GetDeltaTime();
}