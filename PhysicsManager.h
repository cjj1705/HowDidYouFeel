#pragma once
#include "GameObject.h"
#include "Player.h"
#include "EnemyManager.h"
#include "WallManager.h"
#include "TrampolineManager.h"
#include "TrapManager.h"
#include "SavePointManager.h"
#include "JumpAdderManager.h"
#include "BossManager.h"
class PhysicsManager :
	public GameObject
{
public:
	PhysicsManager(Player* p, EnemyManager* em, BulletManager* bm, WallManager* wm, TrampolineManager* tm, TrapManager* trm, SavePointManager* sm, JumpAdderManager* jm, BossManager* bsm);
	~PhysicsManager();
	Player* p;
	EnemyManager* em;
	BulletManager* bm;
	WallManager* wm;
	TrampolineManager* tm;
	TrapManager* trm;
	SavePointManager* sm;
	JumpAdderManager* jm;
	BossManager* bsm;
	virtual void LateUpdate();

	float gravity = 1000.0f;
};