#pragma once

#include "NeoEngine.h"

class EntityTest : public neo::Entity
{
public:

	EntityTest() : secondtest(10.0f) {}
	~EntityTest() = default;

	bool test = false;
	int value = 16;
	float secondtest = 0.0f;
};

