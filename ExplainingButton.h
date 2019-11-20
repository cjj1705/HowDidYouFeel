#pragma once
#include "Button.h"
class ExplainingButton :
	public Button
{
public:
	ExplainingButton();
	~ExplainingButton();

	bool isShowing = false;

	virtual void onMouseHover();
	virtual void onMouseClick();
	virtual void onMouseOut();
};

