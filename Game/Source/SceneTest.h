#pragma once
#include "NeoEngine.h"

using namespace neo;

class SceneTest : public neo::Scene
{
private:
	virtual void OnLoad() override;
	virtual void OnLostFocus() override;
	virtual void OnGainedFocus() override;
	virtual void OnKeyPressed(const Input::KeyCode _keyCode) override;
	virtual void OnKeyReleased(const Input::KeyCode _keyCode) override;
	virtual void OnMouseButtonPressed(const Input::MouseCode _mouseCode, const Vector2D _mousePosition) override;
	virtual void OnMouseButtonReleased(const Input::MouseCode _mouseCode, const Vector2D _mousePosition) override;
	virtual void OnMouseMoved(const Vector2D _mousePosition) override;
	virtual void OnMouseWheelScrolled(const float _delta) override;
	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnExit() override;
};

