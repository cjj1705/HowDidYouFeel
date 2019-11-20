#pragma once
#include "GameObject.h"
#include "Bullet.h"
class BulletManager :
	public GameObject
{
public:
	std::list<Bullet*> bulletList;

	Bullet* PushBackPlayerBullet(Bullet* b);
	void Destroy(Bullet* b);
	virtual void LateUpdate();

private:

	std::list<Bullet*> destroyed;
	void RemoveDestroyed();
};