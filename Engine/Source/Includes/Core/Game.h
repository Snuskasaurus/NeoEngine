#pragma once
#include "../Export.h"

namespace neo
{
	class Scene;

	class NEOENGINE_API Game
	{
	public:
		static void Run(Scene& _scene);
		static void Exit() { Instance()->m_isRunning = false; };
	private:
		static Game* Instance();
		bool m_isRunning = false;
	};
}

