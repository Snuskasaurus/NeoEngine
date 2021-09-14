#include "../../Includes/Core/Random.h"

using namespace neo;

Vector2D Random::Range(Vector2D _minInclusive, Vector2D _maxInclusive)
{
	Vector2D vector;
	vector.x = Range(_minInclusive.x, _maxInclusive.y);
	vector.y = Range(_minInclusive.x, _maxInclusive.y);
	return vector;
}

int Random::Range(int _minInclusive, int _maxInclusive)
{
	return rand() % (_maxInclusive + 1) + _minInclusive;
}

float Random::Range(float _minInclusive, float _maxInclusive)
{
	return ((float)Range((int)(_minInclusive * 100.0f), (int)(_maxInclusive * 100.0f)) / 100.0f);
}

float Random::Rotation()
{
	return 0.0f;
}

Random* Random::Instance()
{
	static Random random;
	return &random;
}
