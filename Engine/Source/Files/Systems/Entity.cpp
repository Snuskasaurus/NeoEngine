#include "../../Includes/Systems/Entity.h"

namespace neo
{
	Entity* Entity::Root = nullptr;

	Entity::Entity(Entity* _parent, const std::string& _name)
		: m_name(_name)
	{
		if (_parent == nullptr && _name != "Root")
		{
			Root = new Entity(nullptr, "Root");
			return;
		}
		if (_parent == nullptr)
		{
			m_parent->AttachChild(*Root);
			return;
		}
		m_parent->AttachChild(*this);
	}

	Entity::~Entity()
	{
		if (nullptr != m_parent) DetachChild(*this);
		for (Entity* entity : m_childs) delete entity;
		for (Component* component : m_components) delete component;
	}

	Entity* Entity::GetChild(const std::string& _name) const
	{
		for (Entity* entity : m_childs)
		{
			if (entity->m_name == _name) return entity;
		}
		return nullptr;
	}

	bool Entity::DetachChild(Entity& _child)
	{
		Entity* childToDetach = &_child;
		for (size_t index = 0; index < m_childs.size(); index++)
		{
			if (m_childs[index] == childToDetach)
			{
				m_childs.erase(m_childs.begin() + index);
				return true;
			}
		}
		return false;
	}

	bool Entity::DeleteChild(const std::string& _name)
	{
		Entity* child = GetChild(_name);
		if (nullptr == child) return false;
		DetachChild(*child);
		delete&* child;
		return true;
	}

	bool Entity::DeleteChild(Entity& _child)
	{
		if (false == DetachChild(_child)) return false;
		delete& _child;
		return true;
	}

	Component* Entity::GetComponent(const std::string& _name) const
	{
		for (Component* component : m_components)
		{
			if (component->GetName() == _name) return component;
		}
		return nullptr;
	}

	bool Entity::DetachComponent(Component& _component)
	{
		Component* componentToDetach = &_component;
		for (size_t index = 0; index < m_components.size(); index++)
		{
			if (m_components[index] == componentToDetach)
			{
				m_components.erase(m_components.begin() + index);
				return true;
			}
		}
		return false;
	}

	bool Entity::DeleteComponent(const std::string& _name)
	{
		Component* component = GetComponent(_name);
		if (nullptr == component) return false;
		DetachComponent(*component);
		delete&* component;
		return true;
	}

	bool Entity::DeleteComponent(Component& _component)
	{
		if (false == DetachComponent(_component)) return false;
		delete& _component;
		return true;
	}

	void Entity::Load()
	{
	}

	void Entity::Update()
	{
		for (Entity* entity : m_childs) entity->Update();
		for (Component* component : m_components) component->Update();
	}

	void Entity::Draw() const
	{
		for (Entity* entity : m_childs) entity->Draw();
		for (Component* component : m_components) component->Draw();
	}

	void Entity::Exit() const
	{
	}

	Vector2D Entity::GetWorldPosition() const
	{
		if (m_parent == Root) return m_localPosition;
		return m_parent->GetWorldPosition() + m_localPosition;
	}

	void Entity::SetWorldPosition(const Vector2D& _position)
	{
		if (m_parent == Root) m_localPosition = _position;
		else m_localPosition = GetWorldPosition() - m_localPosition + _position;
	}

	float Entity::GetWorldAngle() const
	{
		if (m_parent == Root) return m_localAngle;
		return m_parent->GetWorldAngle() + m_localAngle;
	}

	void Entity::SetWorldAngle(const float& _angle)
	{
		if (m_parent == Root) m_localAngle = _angle;
		else m_localPosition = GetWorldAngle() - m_localAngle + _angle;
	}
}