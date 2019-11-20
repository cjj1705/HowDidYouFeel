#pragma once
#include "Button.h"
#include "ExplainingButton.h"
class ExplainButton :
	public Button
{
public:
	ExplainButton();
	~ExplainButton();

	ExplainingButton* explainImage;
	bool isExplaining = false;

	virtual void onMouseHover();
	virtual void onMouseClick();
	virtual void onMouseOut();
};