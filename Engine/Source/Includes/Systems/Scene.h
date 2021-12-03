#pragma once
#pragma warning( disable : 4100 )

#include "../Export.h"
#include <vector>
#include "../../Includes/Core/Input.h"

#define RESERVE_VEC_ROOT_ENTITIES 10

namespace neo
{
	class NEOENGINE_API Scene
	{
		friend class SceneManager;
	public:
		Scene();
		~Scene() = default;

		template<typename... Args>
		bool AttachEntity(Entity* entity) { m_rootsEntities.push_back(); };
		bool DettachEntity(Entity* entity);

		virtual void OnLoad() {};
		virtual void OnLostFocus() {};
		virtual void OnGainedFocus() {};
		virtual void OnKeyPressed(const Input::KeyCode _keyCode) {};
		virtual void OnKeyReleased(const Input::KeyCode _keyCode) {};
		virtual void OnMouseWheelScrolled(const float _delta) {};
		virtual void OnMouseButtonPressed(const Input::MouseCode _mouseCode, const Vector2D _mousePosition) {};
		virtual void OnMouseButtonReleased(const Input::MouseCode _mouseCode, const Vector2D _mousePosition) {};
		virtual void OnMouseMoved(const Vector2D _mousePosition) {};
		virtual void OnUpdate() {};
		virtual void OnDraw() {};
		virtual void OnExit() {};
	private:
		void Load();
		void Event();
		void Update();
		void Draw();
		void Exit();
		std::vector<Entity*> m_rootsEntities;
	};

}
