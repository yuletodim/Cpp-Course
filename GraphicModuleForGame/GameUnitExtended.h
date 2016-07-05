#include <iostream>
#include "GameUnit.h"

using namespace std;

#ifndef __GAME_UNIT_EXTENDED_H
#define __GAME_UNIT_EXTENDED_H

class GameUnitExtended : public GameUnit
{
	unsigned int _id;
	string _name;
	float _mass;
	float _jumpSpeed;

public:
	GameUnitExtended();
	GameUnitExtended(string name, float mass, float jumpSpeed);
	unsigned int getId();
	void setName(string name);
	string getName();
	void setMass(float mass);
	float getMass();
	void setJumpSpeed(float jumpSpeed);
	float getJumpSpeed();
	void printGameUnit();
};

#endif
