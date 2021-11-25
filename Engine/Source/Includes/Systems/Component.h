#pragma once
#include "../Export.h"
#include <string>

namespace neo
{
	class Entity;

	class NEOENGINE_API Component
	{
	public:
		Component(Entity& _parent, const std::string& _name);
		virtual ~Component() = default;

		virtual void Update() = 0;
		virtual void Draw() const = 0;

		inline std::string GetName() const { return m_name; }

	private:
		std::string m_name;
		Entity& m_parent;
	};
}

