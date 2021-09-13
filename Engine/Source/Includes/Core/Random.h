#pragma once
#include "../Export.h"

#include "Vector2D.h"

namespace neo
{
	class NEOENGINE_API Random
	{
	public:
		static int Range(int _minInclusive, int _maxInclusive);
		static float Range(float _minInclusive, float _maxInclusive);
		static Vector2D Range(Vector2D _minInclusive, Vector2D _maxInclusive);
		static float Rotation();
	};
}
