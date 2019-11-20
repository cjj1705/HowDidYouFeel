#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Framework.h"
#define PI 3.141592f

Bullet::Bullet(const wchar_t *path, float speed, float speedRate, float angle, float angleRate, float damage, int type) :
	GameObject(path), speed(speed), speedRate(speedRate), angle(angle), angleRate(angleRate), damage(damage) {
	col = new CircleCollider(*transform, renderer->GetWidth() * 0.5f);
	this->type = type;
}


Bullet::~Bullet() {
	SAFE_DELETE(col);
}

bool Bullet::CheckOutOfScreen() {
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

void Bullet::Update() {
	Move();
	isOutOfScreen = CheckOutOfScreen();
}
void Bullet::Move() {
	float rad = PI * angle * 2.0f;
	transform->position.x += (speed * cosf(rad) * TimeManager::GetDeltaTime());
	transform->position.y += (speed * sinf(rad) * TimeManager::GetDeltaTime());
	speed += speedRate;
	angle += angleRate;
}