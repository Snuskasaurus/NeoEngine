#pragma once
#include "../Export.h"

#include <vector>

#include "Entity.h"

#define RESERVE_VEC_ROOT_ENTITIES 10

namespace neo
{
	class NEOENGINE_API Scene
	{
		friend class SceneManager;
	public:
		Scene();
		inline void AttachEntity(Entity& entity);
		bool DetachEntity(Entity& entity);
		virtual void OnLoad() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDraw() = 0;
		virtual void OnExit() = 0;
	private:
		void Load();
		void Update();
		void Draw();
		void Exit();
		std::vector<Entity*> m_rootsEntities;
	};
}
