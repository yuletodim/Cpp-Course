#include <iostream>
#include <stdio.h>
#include "GameUnitExtended.h"

using namespace std;

static int gameUnitIdCount = 0;

GameUnitExtended::GameUnitExtended()
{
	gameUnitIdCount++;
	this->_id = gameUnitIdCount;
}

GameUnitExtended::GameUnitExtended(string name, float mass, float jumpSpeed)
{
	gameUnitIdCount++;
	this->_id = gameUnitIdCount;
	this->setName(name);
	this->setMass(mass);
	this->setJumpSpeed(jumpSpeed);
}

unsigned int GameUnitExtended::GameUnitExtended::getId()
{
	return this->_id;
}

void GameUnitExtended::setName(string name)
{
	if (name.empty())
	{
		throw new exception("Name can not be empty string.");
	}

	this->_name = name;
}

string GameUnitExtended::getName()
{
	return this->_name;
}

void GameUnitExtended::setMass(float mass)
{
	if (mass <= 0)
	{
		throw new exception("Mass can not be negative or 0.");
	}

	this->_mass = mass;
}

float GameUnitExtended::getMass()
{
	return this->_mass;
}

void GameUnitExtended::setJumpSpeed(float jumpSpeed)
{
	if (jumpSpeed <= 0)
	{
		throw new exception("Mass can not be negative or 0.");
	}

	this->_jumpSpeed = jumpSpeed;
}

float GameUnitExtended::getJumpSpeed()
{
	return this->_jumpSpeed;
}

void GameUnitExtended::printGameUnit()
{
	printf("Game unit: ID: %d %s; Mass: %0.2fkg; Jump speed: %0.2fkm/h; \n",
		this->getId(),
		this->getName().c_str(),
		this->getMass(),
		this->getJumpSpeed());
}
