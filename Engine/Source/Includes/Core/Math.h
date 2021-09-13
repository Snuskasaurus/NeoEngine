#pragma once

#define PI 3.14f

#define RAD_TO_DEG(_rad)(_rad * 180.0f / PI)
#define DEG_TO_RAD(_deg)(_deg * PI / 180.0f)

#define EPSILON 0.0001f
#define EQUALS(x, y) fabs(x - y) < EPSILON
#define NOTEQUALS(x, y) fabs(x - y) > EPSILON
#define INF(x, y) (y - x) > EPSILON
#define INFEQUALS(x, y) INF(x, y) || EQUALS(x, y)
#define SUP(x, y) (x - y) > EPSILON
#define SUPEQUALS(x, y) SUP(x, y) || EQUALS(x, y) 

namespace neo
{
	class NEOENGINE_API Math
	{
	public:
		template<typename T> // float | int | double
		static inline T Clamp(T _value, T _low, T _high) { if (_value <= _low) return _low;	return _value > _high ? _high : _value; }

		template<typename T> // float | int | double
		static inline T Lerp(T _start, T _end, float _t) { return ((T)1.0f - _t) * _start + _t * _end; }

		// Loops the value, so that it is never larger than length and never smaller than 0.
		static float Repeat(float _value, float _length);

		// Return value is 1 when f is positive or zero, -1 when f is negative.
		static float Sign(float _float) { return _float >= 0.0f ? 1.0f : -1.0f; };

		// Calculates the shortest difference between two given angles.
		static float DeltaAngle(float _current, float _target);

		// Moves a current value towards target value.
		static float MoveTowards(float _current, float _target, float _maxDelta);

		// MoveTowards but makes sure the values interpolate correctly when they wrap around 360 degrees.
		static float MoveAngleTowards(float _current, float _target, float _maxDelta);
	};
}