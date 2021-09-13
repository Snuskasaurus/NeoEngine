#include "../../Includes/Systems/Component.h"
#include "../../Includes/Systems/Entity.h"

using namespace neo;

Component::Component(Entity& _parent, const std::string& _name)
	: m_parent((Entity&)_parent), m_name(_name)
{
	m_parent.AttachComponent(*this);
}