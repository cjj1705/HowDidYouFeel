#pragma once
#include "GameObject.h"
class RestartText :
	public GameObject
{
public:
	RestartText();
	~RestartText();

	int dir = 1;

	virtual void Update();
};