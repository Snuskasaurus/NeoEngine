#include "SceneTest.h"
#include <iostream>

class Test1
{
	int vartest1;
};

class Test2 : public Test1
{
	int vartest2;
};

void SceneTest::OnLoad()
{
	//neo::Debug::Log("Scene test = On Load");

	Test1 test1;
	Test1 test1Bis;
	Test2 test2;

	std::cout << "test1 - test2 = " << (typeOf) << std::endl;
}

void SceneTest::OnLostFocus()
{
	//neo::Debug::Log("Scene test = OnLostFocus");
}

void SceneTest::OnGainedFocus()
{
	//neo::Debug::Log("Scene test = OnGainFocus");
}

void SceneTest::OnKeyPressed(const Input::KeyCode _keyCode)
{
	//std::cout << "Scene test = OnKeyReleased = KeyCode = " << (int)_keyCode << std::endl;
}

void SceneTest::OnKeyReleased(const Input::KeyCode _keyCode)
{
	//std::cout << "Scene test = OnKeyReleased = KeyCode = " << (int)_keyCode << std::endl;
}

void SceneTest::OnMouseButtonPressed(const Input::MouseCode _mouseCode, const Vector2D _mousePosition)
{
	//std::cout << "Scene test = OnMouseButtonPressed = MouseCode = " << (int)_mouseCode << std::endl;
	//std::cout << "Scene test = OnMouseButtonPressed = _mousePosition = " << _mousePosition << std::endl;
}

void SceneTest::OnMouseButtonReleased(const Input::MouseCode _mouseCode, const Vector2D _mousePosition)
{
	//std::cout << "Scene test = OnMouseButtonReleased = MouseCode = " << (int)_mouseCode << std::endl;
	//std::cout << "Scene test = OnMouseButtonReleased = _mousePosition = " << _mousePosition << std::endl;
}

void SceneTest::OnMouseMoved(const Vector2D _mousePosition)
{
	//std::cout << "Scene test = OnMouseMoved = _mousePosition = " << _mousePosition << std::endl;
}

void SceneTest::OnMouseWheelScrolled(const float _delta)
{
	//std::cout << "Scene test = OnMouseWheelScrolled = delta = " << _delta << std::endl;
}

void SceneTest::OnUpdate()
{
	//neo::Debug::Log("Scene test = On Update");
}

void SceneTest::OnDraw()
{
	//neo::Debug::Log("Scene test = On Draw");
}

void SceneTest::OnExit()
{
	//neo::Debug::Log("Scene test = On Exit");
}
