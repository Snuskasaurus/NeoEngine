#include "../../Includes/Components/CircleCollider.h"

using namespace neo;

bool CircleCollider::CheckGenericCollision(const Collider& _other) const
{
    switch (_other.GetType())
    {
        case Type::CIRCLE :
            return CheckCollision((CircleCollider&)_other);
        break;
    }
    return false;
}

bool CircleCollider::CheckCollision(const CircleCollider& _other) const
{
    // Calculate total radius squared
    float totalRadiusSquared = m_radius + _other.m_radius;
    totalRadiusSquared *= totalRadiusSquared;

    // If the distance between the centers of the circles is less than the sum of their radius
    if (Vector2D::SquareDistance(m_currentPosition, _other.m_currentPosition) < totalRadiusSquared)
    {
        return true; // The circles have collided
    }
    return false; // The circles have not collided
}
