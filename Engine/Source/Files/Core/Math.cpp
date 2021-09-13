#include "../../Includes/Core/Math.h"

#include <cmath>

using namespace neo;

float Math::Repeat(float _value, float _length)
{
    return Clamp(_value - floorf(_value / _length) * _length, 0.0f, _length);
}

float Math::DeltaAngle(float _current, float _target)
{
    float delta = Repeat((_target - _current), 360.0f);
    if (delta > 180.0f) delta -= 360.0f;
    return delta;
}

float Math::MoveTowards(float _current, float _target, float _maxDelta)
{
    if (abs(_target - _current) <= _maxDelta) return _target;
    return _current + Sign(_target - _current) * _maxDelta;
}

float Math::MoveAngleTowards(float _current, float _target, float _maxDelta)
{
    float deltaAngle = DeltaAngle(_current, _target);
    if (-_maxDelta < deltaAngle && deltaAngle < _maxDelta) return _target;
    _target = _current + deltaAngle;
    return MoveTowards(_current, _target, _maxDelta);
}
