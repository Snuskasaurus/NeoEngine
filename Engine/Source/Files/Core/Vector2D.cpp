#include "../../Includes/Core/Vector2D.h"

#include <cassert>

using namespace neo;

Vector2D Vector2D::Zero = Vector2D(0.0f, 0.0f);
Vector2D Vector2D::Up = Vector2D(0.0f, -1.0f);
Vector2D Vector2D::Right = Vector2D(1.0f, 0.0f);
Vector2D Vector2D::Down = Vector2D(0.0f, 1.0f);
Vector2D Vector2D::Left = Vector2D(-1.0f, 0.0f);

Vector2D Vector2D::Clamp(Vector2D _current, Vector2D _min, Vector2D _max)
{
	Vector2D vectorToReturn = _current;
	if (vectorToReturn.x < _min.x) vectorToReturn.x = _min.x;
	if (vectorToReturn.x > _max.x) vectorToReturn.x = _max.x;
	if (vectorToReturn.y < _min.y) vectorToReturn.x = _min.y;
	if (vectorToReturn.y > _max.y) vectorToReturn.x = _max.y;
	return vectorToReturn;
}

Vector2D Vector2D::MoveTowards(Vector2D _current, Vector2D _target, float _maxDelta)
{
	Vector2D toDo = _target - _current;
	Vector2D toDoNormalized = toDo.Normalized();
	if (toDo.Magnitude() <= _maxDelta) { return _target; }
	Vector2D newPosition = _current + toDoNormalized * _maxDelta;
	return newPosition;
}

Vector2D Vector2D::Lerp(const Vector2D& _v1, const Vector2D& _v2, float _t)
{
	return Vector2D((1 - _t) * _v1.x + _t * _v2.x, (1 - _t) * _v1.y + _t * _v2.y);
}

float Vector2D::Dot(const Vector2D& _v1, const Vector2D& _v2)
{
	return _v1.x * _v2.x + _v1.y * _v2.y;
}

float Vector2D::Angle(const Vector2D& _from, const Vector2D& _to)
{
	return RAD_TO_DEG(atan2(_to.y - _from.y, _to.x - _from.x));
}

Vector2D Vector2D::GetForward(float _angle)
{
	Vector2D vector;
	_angle = DEG_TO_RAD(_angle);
	vector.x = cos(_angle);
	vector.y = sin(_angle);
	return vector;
}

float Vector2D::Distance(const Vector2D& _point1, const Vector2D& _point2)
{
	float diff_x = _point1.x - _point2.x;
	float diff_y = _point1.y - _point2.y;
	return sqrtf(diff_x * diff_x + diff_y * diff_y);
}

float Vector2D::SquareDistance(const Vector2D& _point1, const Vector2D& _point2)
{
	float diff_x = _point1.x - _point2.x;
	float diff_y = _point1.y - _point2.y;
	return (diff_x * diff_x + diff_y * diff_y);
}

Vector2D& Vector2D::operator+=(const Vector2D& _v)
{
	x += _v.x;
	y += _v.y;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& _v)
{
	x -= _v.x;
	y -= _v.y;
	return *this;
}

Vector2D& Vector2D::operator*=(float _f)
{
	x *= _f;
	y *= _f;
	return *this;
}

Vector2D& Vector2D::operator/=(float _f)
{
	assert(_f != 0.0f); // Dividing a vector by 0.
	x /= _f;
	y /= _f;
	return *this;
}

Vector2D Vector2D::Normalized() const
{
	float magnitude = Magnitude();
	if (magnitude < EPSILON) { return Vector2D::Zero; }
	return Vector2D(x / magnitude, y / magnitude);
}

std::string Vector2D::ToString() const
{
	std::string s;
	s += "(";
	s += std::to_string(x);
	s += ":";
	s += std::to_string(y);
	s += ")";
	return s;
}

//std::ostream& operator<<(std::ostream& _out, const Vector2D& _vector)
//{
//	_out << _vector.ToString();
//	return _out;
//}
