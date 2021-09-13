#pragma once

// TODO later
// https://www.toptal.com/game/video-game-physics-part-ii-collision-detection-for-solid-objects

#include "../Core/Vector2D.h"
#include "../Systems/Entity.h"

namespace neo
{
	class NEOENGINE_API Collider
	{
	public:

		enum class Type
		{
			NONE,
			CIRCLE,
			BOX,
		};

		inline Type GetType() const { return m_type; }
		inline unsigned int GetTag() const { return m_parent->GetTag(); }
		void SetPosition(Vector2D _newPosition);

		virtual bool CheckGenericCollision(const Collider& _other) const = 0;

	protected:

		Entity* m_parent = nullptr;
		Vector2D m_currentPosition;
		Vector2D m_previousPosition;
		Type m_type = Type::NONE;
	};
}