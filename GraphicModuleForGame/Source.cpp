#include <iostream>
#include <stdio.h>
#include "GameUnit.h"
#include "GameUnitExtended.h"
#include "Environment.h"
#include "EnvironmentExtended.h"
#include "PhysicsCalculations.h"

using namespace std;

#define EARTH_GRAVITY 9.81
#define MOON_GRAVITY 1.622
#define DESIRED_HEIGHT 100

int main()
{
	GameUnitExtended rubberBall = GameUnitExtended("RUBBER BALL", 0.3, 50);
	GameUnitExtended fireBall = GameUnitExtended("FIRE BALL", 0.01, 100);

	rubberBall.printGameUnit();
	fireBall.printGameUnit();

	EnvironmentExtended earthEnvironment = EnvironmentExtended("Earth", EARTH_GRAVITY);
	EnvironmentExtended moonEnvironment = EnvironmentExtended("Moon", MOON_GRAVITY);

	earthEnvironment.printEnvironmentInfo();
	moonEnvironment.printEnvironmentInfo();

	float maxJumpHeihtOfRubberBallOnEarth = PhysicsCalculations::calcullateMaxJumpHeightInMeters(earthEnvironment, rubberBall);
	float maxJumpHeightOfFireBallOnMoon = PhysicsCalculations::calcullateMaxJumpHeightInMeters(moonEnvironment, fireBall);

	float timeForJumpOfRubberBallOnEarth = PhysicsCalculations::timeOfJumpInSeconds(earthEnvironment, rubberBall);
	float timeForJumpOfFireBallOnMoon = PhysicsCalculations::timeOfJumpInSeconds(moonEnvironment, fireBall);

	bool isCapableRubberBallToJumpDesiredHeightOnEarth =
		PhysicsCalculations::isCapableToJumpOnHeight(earthEnvironment, rubberBall, DESIRED_HEIGHT);
	bool isCapableFireBallToJumpDesiredHeightOnMoon =
		PhysicsCalculations::isCapableToJumpOnHeight(moonEnvironment, fireBall, DESIRED_HEIGHT);
	
	printf("\n%s jumping on %s:\n", rubberBall.getName().c_str(), earthEnvironment.getName().c_str());
	printf(" - Max height of jump: %0.2fm\n", maxJumpHeihtOfRubberBallOnEarth);
	printf(" - Time for jump: %0.2fs\n", timeForJumpOfRubberBallOnEarth);
	printf(" - Is capable to jump %dm: %s\n", DESIRED_HEIGHT, 
		isCapableRubberBallToJumpDesiredHeightOnEarth ? "Yes" : "No");

	printf("\n%s jumping on %s:\n", fireBall.getName().c_str(), moonEnvironment.getName().c_str());
	printf(" - Max height of jump: %0.2fm\n", maxJumpHeightOfFireBallOnMoon);
	printf(" - Time for jump: %0.2fs\n", timeForJumpOfFireBallOnMoon);
	printf(" - Is capable to jump %dm: %s\n", DESIRED_HEIGHT,
		isCapableFireBallToJumpDesiredHeightOnMoon ? "Yes" : "No");

	return 0;
}

