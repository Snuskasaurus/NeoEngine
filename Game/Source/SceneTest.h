#pragma once
#include "NeoEngine.h"

class SceneTest : public neo::Scene
{
private:
	virtual void OnLoad() override;
	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnExit() override;
};

