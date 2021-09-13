#pragma once

#include "Collider.h"

namespace neo
{
	class NEOENGINE_API CircleCollider : public Collider
	{
	public:
		CircleCollider(float _radius = 10.0f) : m_radius(_radius) { m_type = Type::CIRCLE; }
		~CircleCollider() = default;

		virtual bool CheckGenericCollision(const Collider& _other) const override;
		bool CheckCollision(const CircleCollider& _other) const;

	private:
		float m_radius = 10.0f;
	};
}

