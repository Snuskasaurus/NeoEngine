#include "../../Includes/Core/Random.h"

using namespace neo;

Vector2D Random::Range(Vector2D _minInclusive, Vector2D _maxInclusive)
{
	return Vector2D::Zero;
}

int Random::Range(int _minInclusive, int _maxInclusive)
{
	return rand() % (_maxInclusive + 1) + _minInclusive;
}

float Random::Range(float _minInclusive, float _maxInclusive)
{
	return 0.0f;
}

float Random::Rotation()
{
	return 0.0f;
}