#include <iostream>
#include "Environment.h"

#ifndef __ENVIRONMENT_EXTENDED_H
#define __ENVIRONMENT_EXTENDED_H

class EnvironmentExtended : public Environment
{
	unsigned int _id;
	string _name;
	double _gravity;

public:
	EnvironmentExtended();
	EnvironmentExtended(string name, double gravity);
	unsigned int getId();
	void setName(string name);
	string getName();
	void setGarvity(double gravity);
	double getGravity();
	void printEnvironmentInfo();
};

#endif


