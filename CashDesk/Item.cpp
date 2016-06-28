#include <iostream>
#include "Item.h"

using namespace std;

Item::Item()
{
}

Item::Item(string newName, string newItemCode, float newPrice, item_t newItemType)
{
	this->setName(newName);
	this->setItemCode(newItemCode);
	this->setPrice(newPrice);
	this->itemType = newItemType;
}

void Item::setName(string &newName)
{
	if (newName.empty()) 
	{
		throw new exception("Name should be valid string.");
	}

	this->name = newName;
}

string Item::getName()
{
	return this->name;
}

void Item::setItemCode(string &newItemCode)
{
	if (newItemCode.size() != 10) 
	{
		throw new exception("Item code should be a string with 10 digits.");
	}

	this->itemCode = newItemCode;
}

string Item::getItemCode()
{
	return this->itemCode;
}

void Item::setPrice(float newPrice)
{
	if (newPrice < 0) 
	{
		throw new exception("Item price should be positive float number.");
	}

	this->price = newPrice;
}

float Item::getPrice()
{
	return this->price;
}

string Item::getItemType()
{
	string type;
	switch (this->itemType)
	{
		case(item_t::foods) :
			type = "Foods";
			break;
		case(item_t::drinks) :
			type = "Drinks";
			break;
		case(item_t::not_set) :
			type = "Not specified";
			break;
		default:
			break;
	}

	return type;
}

void Item::printItemInfo()
{
	printf(" - %s: %s; %s; %0.2flv.\n",
		this->getItemCode().c_str(),
		this->getItemType().c_str(),
		this->getName().c_str(),
		this->getPrice());
}


