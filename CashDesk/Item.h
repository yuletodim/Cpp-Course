#include <iostream>
#include "ItemType.h"

using namespace std;

#ifndef __ITEM_H
#define __ITEM_H

class Item
{
protected:
	string name;
	string itemCode;
	float price;
	item_t itemType;
public:
	Item();
	Item(string newName, string newItemCode, float newPrice, item_t newItemType);
	void setName(string &newName);
	string getName();
	void setItemCode(string &newItemCode);
	string getItemCode();
	void setPrice(float newPrice);
	float getPrice();
	string getItemType();
	void printItemInfo();
};

#endif
