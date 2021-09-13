#pragma once

#include "Math.h"

namespace neo
{
	class NEOENGINE_API Vector2D
	{
	public:
		static Vector2D Zero;
		static Vector2D Up;
		static Vector2D Right;
		static Vector2D Down;
		static Vector2D Left;

		static Vector2D Clamp(Vector2D _current, Vector2D _min, Vector2D _max);
		static Vector2D MoveTowards(Vector2D _current, Vector2D _target, float _maxDelta);
		static Vector2D Lerp(const Vector2D& _v1, const Vector2D& _v2, float _t);
		static float Dot(const Vector2D& _v1, const Vector2D& _v2);
		static float Angle(const Vector2D& _from, const Vector2D& _to);
		static Vector2D GetForward(float _angle);

		// Returns the distance between point1 and point2.
		static float Distance(const Vector2D& _point1, const Vector2D& _point2);
		// Returns the square distance between point1 and point2.
		static float SquareDistance(const Vector2D& _point1, const Vector2D& _point2);

		Vector2D(const sf::Vector2u& _other) :x((float)_other.x), y((float)_other.y) {}
		Vector2D(const sf::Vector2i& _other) :x((float)_other.x), y((float)_other.y) {}
		Vector2D(const sf::Vector2f& _other) :x(_other.x), y(_other.y) {}
		Vector2D(const Vector2D& _other) :x(_other.x), y(_other.y) {}
		Vector2D(float _x = 0.0f, float _y = 0.0f) :x(_x), y(_y) {}
		~Vector2D() = default;

		Vector2D& operator+= (const Vector2D& _v);
		Vector2D& operator-= (const Vector2D& _v);
		Vector2D& operator*= (float _f);
		Vector2D& operator/= (float _f);
		inline Vector2D operator- () const { return Vector2D(-x, -y); }
		inline Vector2D operator+ (const Vector2D& _v) const { return Vector2D(x + _v.x, y + _v.y); }
		inline Vector2D operator- (const Vector2D& _v) const { return Vector2D(x - _v.x, y - _v.y); }
		inline Vector2D operator* (float _f) const { return Vector2D(x * _f, y * _f); }
		inline Vector2D operator/ (float _f) const { return Vector2D(x / _f, y / _f); }
		inline bool operator== (const Vector2D& _v) const { return EQUALS(x, _v.x) && EQUALS(y, _v.y); }
		inline bool operator!= (const Vector2D& _v) const { return NOTEQUALS(x, _v.x) || NOTEQUALS(y, _v.y); }
		inline bool operator< (const Vector2D& _v) const { return INF(SquareMagnitude(), _v.SquareMagnitude()); }
		inline bool operator<= (const Vector2D& _v) const { return INFEQUALS(SquareMagnitude(), _v.SquareMagnitude()); }
		inline bool operator> (const Vector2D& _v) const { return SUP(SquareMagnitude(), _v.SquareMagnitude()); }
		inline bool operator>= (const Vector2D& _v) const { return SUPEQUALS(SquareMagnitude(), _v.SquareMagnitude()); }

		inline Vector2D GetRight() const { return Vector2D(y, -x).Normalized(); }
		inline Vector2D GetLeft() const { return Vector2D(-y, x).Normalized(); }

		std::string ToString() const;
		//friend std::ostream& operator<<(std::ostream& _out, const Vector2D& _vector);

		inline float GetAngle() const { return Angle(Vector2D::Zero, *this); }
		inline float Magnitude() const { return sqrtf(x * x + y * y); }
		inline float SquareMagnitude() const { return x * x + y * y; }
		Vector2D Normalized() const;
		inline sf::Vector2f ToSFML() const { return sf::Vector2f(x, y); }

		float x = 0.0f;
		float y = 0.0f;
	};
}