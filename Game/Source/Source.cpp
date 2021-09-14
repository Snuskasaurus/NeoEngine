#include "NeoEngine.h"
#include "SceneTest.h"

int main()
{
	SceneTest sceneTest;
	neo::Game::Load(sceneTest);
	neo::Game::Run();
	neo::Game::Exit();
	return 0;
}