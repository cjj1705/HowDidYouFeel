#pragma once
#include "GameObject.h"
class Button :
	public GameObject
{
public:
	Button(const wchar_t* path);
	~Button();

	bool isHover = false;

	virtual void onMouseHover() = 0;
	virtual void onMouseClick() = 0;
	virtual void onMouseOut() = 0;

	virtual void Update();
};