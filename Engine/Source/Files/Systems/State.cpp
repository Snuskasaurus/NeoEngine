#include "../../Includes/Systems/State.h"
#include "../../Includes/Systems/Entity.h"

using namespace neo;

void State::Update()
{
	OnUpdate();
	Entity::Root->Update();
}

void State::Draw() const 
{
	OnDraw();
	Entity::Root->Draw();
}

void State::OnUpdate()
{
}

void State::OnDraw() const
{
}
