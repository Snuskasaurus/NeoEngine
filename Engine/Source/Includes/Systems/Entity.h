#pragma once
#include "../Export.h"

#include <string>
#include <vector>

#include "Component.h"
#include "../Core/Vector2D.h"

namespace neo
{
	class NEOENGINE_API Entity
	{
	public:
		
		static Entity* Root;

		Entity(Entity* _parent, const std::string& _name);
		virtual ~Entity();

		Entity* GetChild(const std::string& _name) const;
		// This method is automatically called when creating a new entity
		inline void AttachChild(Entity& _child) { m_childs.push_back(&_child); }
		// Should only be called by this entity, if not, be careful with memory leak
		bool DetachChild(Entity& _child);
		// Delete and detach the child from this entity
		bool DeleteChild(const std::string& _name);
		// Delete and detach the child from this entity
		bool DeleteChild(Entity& _child);

		Component* GetComponent(const std::string& _name) const;
		// This method is automatically called when creating a new component
		inline void AttachComponent(Component& _component) { m_components.push_back(&_component); }
		// Should only be called by this entity, if not, be careful with memory leak
		bool DetachComponent(Component& _component);
		// Delete and detach the component from this entity
		bool DeleteComponent(const std::string& _name);
		// Delete and detach the component from this entity
		bool DeleteComponent(Component& _component);

		void Load();
		void Update();
		void Draw() const;
		void Exit() const;

		inline void LookAt(const Vector2D& _position) { m_localAngle = Vector2D::Angle(m_localPosition, _position); }
		inline void LookAt(const Entity& _entity) { m_localAngle = Vector2D::Angle(m_localPosition, _entity.m_localPosition); }
		//inline Vector2D GetForward() const { Vector2D::GetForward(m_localAngle); };
		//inline Vector2D GetRight() const { Vector2D::GetForward(m_localAngle).GetRight(); };
		//inline Vector2D GetLeft() const { Vector2D::GetForward(m_localAngle).GetLeft(); };*/
		inline std::string GetName() const { return m_name; }
		inline unsigned int GetTag() const { return m_tag; }

		Vector2D m_localPosition = Vector2D::Zero;
		Vector2D GetWorldPosition() const;
		void SetWorldPosition(const Vector2D& _position);

		float m_localAngle = 0.0f;
		float GetWorldAngle() const;
		void SetWorldAngle(const float& _angle);

	private:

		unsigned int m_tag = 0;
		std::string m_name;
		Entity* m_parent = nullptr;
		std::vector<Entity*> m_childs;
		std::vector<Component*> m_components;
	};
}