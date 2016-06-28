#include <iostream>
#include <vector>
#include "Item.h"
#include "Shop.h"

using namespace std;

#ifndef __BILL_H
#define __BILL_H
class Bill 
{
	Shop shop;
	vector<Item> purchases;
	float totalValue;
	float givenMoney;
public:
	Bill() {};
	Bill(Shop &newShop) : shop(newShop), totalValue(0), givenMoney(0) {};
	void addItemToPurchases(Item* item);
	float getTotalValue();
	void setGivenMoney(float money);
	float getGivenMoney();
	float getChange();
	void printBill();
	void clearBill();
};
#endif
