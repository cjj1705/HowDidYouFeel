#pragma once
#include "Scene.h"
#include "ExplainButton.h"
class TitleScene :
	public Scene
{
public:
	TitleScene();
	~TitleScene();

	ExplainButton* explainButton;
	GameObject* background;

	virtual void Initialize();
};