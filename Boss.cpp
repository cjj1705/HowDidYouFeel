#include "stdafx.h"
#include "Boss.h"


Boss::Boss(const wchar_t* path, BulletManager* bm, float hp) : GameObject(path), bm(bm), hp(hp) {
	col = new AABBCollider(*transform, renderer->GetWidth(), renderer->GetHeight());
}

Boss::~Boss() {
	SAFE_DELETE(col);
}

void Boss::Hit(float damage) {
	hp -= damage;
}

void Boss::Update() {
	time++;
	if (pattern == 0) {
		if (time == 60) {
			for (int i = 0; i < 12; i++) {
				Bullet* b = bm->PushBackPlayerBullet(new Bullet(L"image/player/bullet.png", 300.0f, 0.0f, i * 0.1f, 0.00f, 15.0f, 0));
				b->transform->position = transform->position;
			}
			time = 0;
			if (++count == 5) {
				pattern++;
				count = 0;
			}
		}
	}
	else if (pattern == 1) {
		if (time == 30) {
			angle += 0.03f;
			for (int i = 0; i < 18; i++) {
				Bullet* b = bm->PushBackPlayerBullet(new Bullet(L"image/player/bullet.png", 50.0f, 1.5f, i * 0.1f + angle, 0.00f, 15.0f, 0));
				b->transform->position = transform->position;
			}
			time = 0;
			if (++count == 10) {
				pattern++;
				count = 0;
				angle = 0;
			}
		}
	}
	else if (pattern == 2) {
		if (time == 60) {
			time = 0;
			pattern++;
		}
	}
	else if (pattern == 3) {
		if (time == 30) {
			angle -= 0.03f;
			for (int i = 0; i < 18; i++) {
				Bullet* b = bm->PushBackPlayerBullet(new Bullet(L"image/player/bullet.png", 50.0f, 1.5f, i * 0.1f + angle, 0.00f, 15.0f, 0));
				b->transform->position = transform->position;
			}
			time = 0;
			if (++count == 10) {
				pattern++;
				count = 0;
			}
		}
	}
	else if (pattern == 4) {
		if (time == 120) {
			time = 0;
			pattern++;
		}
	}
	else if (pattern == 5) {
		if (time == 10) {
			angle += 0.02f;
			for (int i = 0; i < 4; i++) {
				Bullet* b = bm->PushBackPlayerBullet(new Bullet(L"image/player/bullet.png", 300.0f, 0.0f, i * 0.25f + angle, 0.00f, 15.0f, 0));
				b->transform->position = transform->position;
			}
			time = 0;
			if (++count == 50) {
				pattern = 0;
				count = 0;
			}
		}
	}
}