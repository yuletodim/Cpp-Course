#include <iostream>

using namespace std;

#ifndef __ENVIRONMENT_H
#define __ENVIRONMENT_H

// Base class - abstract class that cannot be instantiate
class Environment
{
// Pure virtual function providing interface framework
public:
	virtual unsigned int getId() = 0;
	virtual void setName(string name) = 0;
	virtual string getName() = 0;
	virtual void setGarvity(double gravity) = 0;
	virtual double getGravity() = 0;
	virtual void printEnvironmentInfo() = 0;
};

#endif
