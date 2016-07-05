#include <iostream>

using namespace std;

#ifndef __GAME_UNIT_H
#define __GAME_UNIT_H

// Base class - abstract class that cannot be instantiate
class GameUnit
{
public:
	// Pure virtual function providing interface framework
	virtual void setName(string name) = 0;
	virtual string getName() = 0;
	virtual void setMass(float mass) = 0;
	virtual float getMass() = 0;
	virtual void setJumpSpeed(float jumpSpeed) = 0;
	virtual float getJumpSpeed() = 0;
	virtual void printGameUnit() = 0;
};

#endif
