#include "../../Includes/Components/Collider.h"

using namespace neo;

void Collider::SetPosition(Vector2D _newPosition)
{
	m_previousPosition = m_currentPosition;
	m_currentPosition = _newPosition;
}
