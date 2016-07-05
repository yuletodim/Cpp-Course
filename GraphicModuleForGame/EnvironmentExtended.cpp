#include <iostream>
#include <stdio.h>
#include "EnvironmentExtended.h"

using namespace std;

static int environmentIdCount = 0;

EnvironmentExtended::EnvironmentExtended()
{
	environmentIdCount++;
	this->_id = environmentIdCount;
}

EnvironmentExtended::EnvironmentExtended(string name, double gravity)
{
	environmentIdCount++;
	this->_id = environmentIdCount;
	this->setName(name);
	this->setGarvity(gravity);
}

unsigned int EnvironmentExtended::getId()
{
	return this->_id;
}

void EnvironmentExtended::setName(string name)
{
	if (name.empty())
	{
		throw new exception("Name cannot be an empty string.");
	}

	this->_name = name;
}

string EnvironmentExtended::getName()
{
	return this->_name;
}

void EnvironmentExtended::setGarvity(double gravity)
{
	if (gravity < 0)
	{
		throw new exception("Gravity cannot be negative number.");
	}

	this->_gravity = gravity;
}

double EnvironmentExtended::getGravity()
{
	return this->_gravity;
}

void EnvironmentExtended::printEnvironmentInfo()
{
	printf("Environment: ID: %d %s; Gravity: %0.2f m/s2 \n",
		this->getId(),
		this->getName().c_str(),
		this->getGravity());
}