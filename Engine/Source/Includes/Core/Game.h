#pragma once
#include "../Export.h"

#include "../../Includes/Systems/Scene.h"

namespace neo
{
	class NEOENGINE_API Game
	{
	public:
		static void Load(Scene& _scene);
		static void Run();
		static void Exit();
	private:
		static Game* Instance();
		bool m_isRunning = false;
	};
}

