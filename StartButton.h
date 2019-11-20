#pragma once
#include "Button.h"
class StartButton :
	public Button
{
public:
	StartButton();
	~StartButton();

	void onMouseHover();
	void onMouseClick();
	void onMouseOut();
};