#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Scene.h"
#include "AnimationRenderer.h"
#include "SoundEvent.h"
#include "BulletManager.h"
class Player :
	public GameObject
{
public:
	float moveSpeed = 200.0f;

	AABBCollider col;

	AnimationRenderer* animRenderer;

	SoundEvent* se;		//사운드이벤트
	
	Player(BulletManager *bm);	
	~Player();
	virtual void Update();
	virtual void LateUpdate();

	BulletManager * bm;
	void Shoot();

	float dir = 0.25f;
	bool isMoving = false;
	bool isOnGround = false;
	AABBCollider* ground;

	Vector2 velocity;

	float jumpPower = 400.0f;
	int maxJumpCount = 2;
	int jumpCount = maxJumpCount;
	bool doJump = false;
	void Jump();

	bool isDie = false;
	bool isSaved = false;
	PP savePoint;
	void Save(PP point);
	bool canMoveStage = true;
};