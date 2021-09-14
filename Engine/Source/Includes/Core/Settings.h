#pragma once
#include "../Export.h"
#include "Vector2D.h"

namespace neo
{
	class NEOENGINE_API Settings
	{
		friend class Game; // Game is the only class needing the "LoadFromFile" method
	public:
		static Vector2D GetResolution() { return Instance()->m_resolution; }
	private:
		static Settings* Instance();
		static void LoadFromFile();
		Vector2D m_resolution = { 1280.0f, 720.0f };
	};
}

