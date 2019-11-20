#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "AnimationRenderer.h"
#include "ListAnimation.h"
#include "SheetAnimation.h"
#include "TimeManager.h"
#include "GameScene.h"

enum {
	STAY_RIGHT = 0, STAY_LEFT, MOVE_RIGHT, MOVE_LEFT
};

Player::Player(BulletManager *bm) : GameObject(animRenderer = new AnimationRenderer()), col(*transform, Vector2(32.0f, 32.0f)), bm(bm) {
	ListAnimation* stayAni_right = new ListAnimation(STAY_RIGHT, 1.0f);
	stayAni_right->PushBackSprite(L"image/player/stay_right.png");
	ListAnimation* stayAni_left = new ListAnimation(STAY_LEFT, 1.0f);
	stayAni_left->PushBackSprite(L"image/player/stay_left.png");
	SheetAnimation* moveAni_right = new SheetAnimation(MOVE_RIGHT, 16.0f,L"image/player/moveSheet_right.png", 32, 32, 2);
	SheetAnimation* moveAni_left = new SheetAnimation(MOVE_LEFT, 16.0f, L"image/player/moveSheet_left.png", 32, 32, 2);

	animRenderer->PushBackAnimation(stayAni_right);
	animRenderer->PushBackAnimation(stayAni_left);
	animRenderer->PushBackAnimation(moveAni_right);
	animRenderer->PushBackAnimation(moveAni_left);

	animRenderer->ChangeAnimation(STAY_RIGHT);

	//사운드 사용하기
	//SoundEvent클래스를 생성합니다.
	//SoundEvent객체 하나는 하나의 음악 파일을 담당합니다.
	se = new SoundEvent();		//se = new SoundEvent(L"test.wav"); 처럼 사용할 수도 있습니다.
	se->LoadFile(L"test.wav");
}

Player::~Player(){
}

void Player::Update()
{
	velocity.x = 0;
	if (!isDie) {
		if (InputManager::GetMyKeyState(VK_RIGHT)) {
			velocity.x += moveSpeed;
			dir = 0.25f;
			isMoving = true;
		}
		else if (InputManager::GetMyKeyState(VK_LEFT)) {
			velocity.x -= moveSpeed;
			dir = -0.25f;
			isMoving = true;
		}
		else {
			isMoving = false;
		}
		if (InputManager::GetKeyDown(VK_SPACE) && jumpCount > 0)
			Jump();
		if (InputManager::GetKeyDown('Z'))
			Shoot();
	}
	if (InputManager::GetKeyDown('R')) {
		GameScene& nowScene = (GameScene&)Scene::GetCurrentScene();
		nowScene.restart();
	}

	transform->position.x += velocity.x * TimeManager::GetDeltaTime();

	//Scene 전환
	/*if (InputManager::GetMyKeyState(VK_SPACE))
		Scene::ChangeScene(new GameScene());*/

	if (isMoving) {
		if (dir == 0.25f) {
			if (animRenderer->currentState != MOVE_RIGHT) {
				animRenderer->ChangeAnimation(MOVE_RIGHT);
			}
		}
		else {
			if (animRenderer->currentState != MOVE_LEFT) {
				animRenderer->ChangeAnimation(MOVE_LEFT);
			}
		}
	}
	else {
		if (dir == 0.25f) {
			if (animRenderer->currentState != STAY_RIGHT) {
				animRenderer->ChangeAnimation(STAY_RIGHT);
			}
		}
		else {
			if (animRenderer->currentState != STAY_LEFT) {
				animRenderer->ChangeAnimation(STAY_LEFT);
			}
		}
	}

	//if (InputManager::GetKeyDown('S'))		//S키가 막 눌렸을 경우 재생 시작
	//{
	//	se->Play();
	//}
	//if (InputManager::GetKeyUp('S'))		//S키가 막 눌렸을 경우 재생 멈춤
	//{
	//	se->Stop();							//se->Pause()함수 사용시 일시정지
	//}

	if (transform->position.x < 0) {
		if (canMoveStage) {
			GameScene& nowScene = (GameScene&)Scene::GetCurrentScene();
			nowScene.nextStage(Stage::LEFT);
		}
		else {
			transform->position.x = 0.0f;
		}
	}
	else if (transform->position.x > 960) {
		if (canMoveStage) {
			GameScene& nowScene = (GameScene&)Scene::GetCurrentScene();
			nowScene.nextStage(Stage::RIGHT);
		}
		else {
			transform->position.x = 960.0f;
		}
	}
	else if (transform->position.y < 0) {
		if (canMoveStage) {
			GameScene& nowScene = (GameScene&)Scene::GetCurrentScene();
			nowScene.nextStage(Stage::TOP);
		}
		else {
			transform->position.y = 0.0f;
		}
	}
	else if (transform->position.y > 640) {
		if (canMoveStage) {
			GameScene& nowScene = (GameScene&)Scene::GetCurrentScene();
			nowScene.nextStage(Stage::BOTTOM);
		}
		else {
			transform->position.y = 640.0f;
		}
	}
}

void Player::LateUpdate()
{
	static int count = 0;
	//충돌처리는 Update에서 이동이 다 끝난 후 LateUpdate에서 시행해주어야 안전합니다.
	//(GameObject의 Update 실행 순서에 따라 오류 발생 가능성O)

	//객체에 CircleCollider 혹은 AABBCollider를 등록한 후, 충돌처리를 해줍니다.
	//OBB, 캡슐 등 다른 형태의 충돌체를 사용하고 싶으신 경우 직접 구현해주셔야 합니다.
	//물체의 충돌만을 담당할 객체를 생성하여 충돌을 관리하는 것도 추천드립니다.
	//collider의 intersected함수를 호출하여 충돌 여부를 확인할 수 있습니다.
}
void Player::Shoot() {
	Bullet* b = bm->PushBackPlayerBullet(new Bullet(L"image/player/bullet.png", 750.0f, 0.0f, 0.75f + dir, 0.00f, 15.0f, 1));
	b->transform->position = transform->position;
}

void Player::Jump() {
	doJump = true;
}

void Player::Save(PP point) {
	isSaved = true;
	savePoint = point;
}