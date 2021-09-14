#include "SceneTest.h"
#include <iostream>


void SceneTest::OnLoad()
{
	std::cout << "Scene test = On Load" << std::endl;
}

void SceneTest::OnUpdate()
{
	std::cout << "Scene test = On Update" << std::endl;
}

void SceneTest::OnDraw()
{
	std::cout << "Scene test = On Draw" << std::endl;
}

void SceneTest::OnExit()
{
	std::cout << "Scene test = On Exit" << std::endl;
}
