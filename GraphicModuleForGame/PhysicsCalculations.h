#include <iostream>
#include "GameUnit.h"
#include "Environment.h"

#ifndef __PHYSICS_CALCULATIONS_H
#define __PHYSICS_CALCULATIONS_H

class PhysicsCalculations
{
public:
	// Dependency injection - all methods depends on abstract classes(interfaces)
	static float calcullateMaxJumpHeightInMeters(Environment &environment, GameUnit &gameUnit);
	static float timeOfJumpInSeconds(Environment &environment, GameUnit &gameUnit);
	static bool isCapableToJumpOnHeight(Environment &environment, GameUnit &gameUnit, float height);
};

#endif