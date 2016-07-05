#include <iostream>
#include <cmath>
#include "PhysicsCalculations.h"
#include "GameUnit.h"
#include "Environment.h"

#define CONST_CONVERT_KMPH_IN_MPS 0.277

float PhysicsCalculations::calcullateMaxJumpHeightInMeters(Environment &environment, GameUnit &gameUnit)
{
	// h = (Vo^2 / g) / 2 
	float speed = gameUnit.getJumpSpeed() * CONST_CONVERT_KMPH_IN_MPS;
	float gravity = environment.getGravity();
	float height = (pow(speed, 2) / gravity) / 2;

	return height;
}

float PhysicsCalculations::timeOfJumpInSeconds(Environment &environment, GameUnit &gameUnit)
{
	// t = Vo / g + sqrt(2*h/g)
	float speed = gameUnit.getJumpSpeed() * CONST_CONVERT_KMPH_IN_MPS;
	float gravity = environment.getGravity();
	float height = PhysicsCalculations::calcullateMaxJumpHeightInMeters(environment, gameUnit);
	float jumpingTime = speed / gravity + sqrt(2 * height / gravity);

	return jumpingTime;
}

bool PhysicsCalculations::isCapableToJumpOnHeight(Environment &environment, GameUnit &gameUnit, float height)
{
	float jumpingHeight = PhysicsCalculations::calcullateMaxJumpHeightInMeters(environment, gameUnit);
	bool isCapable = jumpingHeight > height;

	return isCapable;
}