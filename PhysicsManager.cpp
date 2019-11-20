#include "stdafx.h"
#include "PhysicsManager.h"
#include "TimeManager.h"

PhysicsManager::PhysicsManager(Player* p, EnemyManager* em, BulletManager* bm, WallManager* wm, TrampolineManager* tm, TrapManager* trm, SavePointManager* sm, JumpAdderManager* jm, BossManager* bsm)
	:p(p), em(em), bm(bm), wm(wm), tm(tm), trm(trm), sm(sm), jm(jm), bsm(bsm)
{
}

void PhysicsManager::LateUpdate()
{
	if (!bm || !em || !wm || !tm || !trm || !sm || !jm || !bsm || !p)
		return;

	// bullet -> enemy, wall, trampoline, trap(¿À·ù...), savePoint
	for (auto& i : bm->bulletList) {
		if (i->type == 1) {
			for (auto& j : em->enemyList) {
				if (!i->isDestroyed && i->col->Intersected(*j->col)) {
					em->Hit(j, i->damage);
					bm->Destroy(i);
				}
			}
			for (auto& j : wm->wallList) {
				if (!i->isDestroyed && i->col->Intersected(*j->col)) {
					bm->Destroy(i);
				}
			}
			for (auto& j : tm->trampolineList) {
				if (!i->isDestroyed && i->col->Intersected(*j->col)) {
					bm->Destroy(i);
				}
			}

			for (auto& j : trm->trapList) {
				if (!i->isDestroyed && i->col->Intersected(*j->col)) {
					bm->Destroy(i);
				}
			}

			for (auto& j : sm->savePointList) {
				if (!i->isDestroyed && i->col->Intersected(*j->col)) {
					p->Save(j->point);
					bm->Destroy(i);
					j->isCollided = true;
					j->count = 0;
				}
			}

			for (auto& j : bsm->bossList) {
				if (!i->isDestroyed && i->col->Intersected(*j->col)) {
					bsm->Hit(j, i->damage);
					bm->Destroy(i);
				}
			}
		}
		else if(i->type == 0) {
			if (!i->isDestroyed && i->col->Intersected(p->col)) {
				p->isDie = true;
				p->animRenderer->alpha = 0.0f;
			}
		}
	}

	// player -> wall
	for (auto& i : wm->wallList) {
		if (i->col->Intersected(p->col)) {
			Vector2 vec = i->transform->position - p->transform->position;
			float angle = atan2(vec.x, vec.y);
			if (angle < 0.8f && angle >= -0.8f) {
				p->isOnGround = true;
				p->ground = i->col;
				p->velocity.y = 0;
				p->jumpCount = p->maxJumpCount;
				p->transform->position.y = i->transform->position.y - (float)i->renderer->GetHeight() / 2 - p->col.GetHeight() / 2;
			}
			else if (angle < -0.8f && angle >= -2.35f) {
				p->transform->position.x += p->moveSpeed * TimeManager::GetDeltaTime();
			}
			else if (angle < 2.35f && angle >= 0.8f) {
				p->transform->position.x -= p->moveSpeed * TimeManager::GetDeltaTime();
			}
			else {
				p->transform->position.y += p->moveSpeed * TimeManager::GetDeltaTime();
				p->velocity.y = 0;
			}
		}
		else if (i->col == p->ground) {
			Vector2 vec = i->transform->position - p->transform->position;
			float angle = atan2(vec.x, vec.y);
			p->isOnGround = false;
		}
	}

	// player -> trampoline
	for (auto& i : tm->trampolineList) {
		if (i->col->Intersected(p->col)) {
			Vector2 vec = i->transform->position - p->transform->position;
			float angle = atan2(vec.x, vec.y);
			if (angle > -0.8f && angle <= 0.8f) {
				p->isOnGround = true;
				p->ground = i->col;
				p->velocity.y = -i->jumpPower;
				p->jumpCount = p->maxJumpCount - 1;
				p->transform->position.y = i->transform->position.y - (float)i->renderer->GetHeight() / 2 - p->col.GetHeight() / 2;
			}
			else if (angle < -0.8f && angle >= -2.35f)
				p->transform->position.x += p->moveSpeed * TimeManager::GetDeltaTime();
			else if (angle < 2.35f && angle >= 0.8f)
				p->transform->position.x -= p->moveSpeed * TimeManager::GetDeltaTime();
			else {
				p->transform->position.y += p->moveSpeed * TimeManager::GetDeltaTime();
				p->velocity.y = 0;
			}
		}
		else if (i->col == p->ground) {
			Vector2 vec = i->transform->position - p->transform->position;
			float angle = atan2(vec.x, vec.y);
			p->isOnGround = false;
		}
	}

	// player -> trap
	for (auto& i : trm->trapList) {
		if (i->col->Intersected(p->col)) {
			p->isDie = true;
			p->animRenderer->alpha = 0.0f;
		}
	}

	// player -> savePoint
	for (auto& i : sm->savePointList) {
		if (i->col->Intersected(p->col)) {
			p->Save(i->point);
			i->isCollided = true;
			i->count = 0;
		}
	}

	// player -> jumpAdder
	for (auto& i : jm->jumpAdderList) {
		if (i->col->Intersected(p->col)) {
			if (++p->jumpCount > 2)
				p->jumpCount--;
			jm->Destroy(i);
		}
	}

	if (p->doJump) {
		p->velocity.y = -p->jumpPower;
		p->doJump = false;
		p->jumpCount--;
	}
	if(!p->isOnGround) {
		p->velocity.y += gravity * TimeManager::GetDeltaTime();
	}
	if (p->velocity.y >= 700.0f)
		p->velocity.y = 700.0f;
	p->transform->position.y += p->velocity.y * TimeManager::GetDeltaTime();
}

PhysicsManager::~PhysicsManager() {
}