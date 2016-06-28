#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

#ifndef __SHOP_H
#define __SHOP_H
class Shop
{
	string shopName;
	string shopAddress;
	string bic;
	vector<Item> items;
public:
	Shop() {};
	Shop(string newShopName, string newBic, string newShopAddress)
		: shopName(newShopName), bic(newBic), shopAddress(newShopAddress) {};
	void addItemToShop(Item &newItem);
	Item* getItemByCode(string itemCode);
	void printShopItems();
	void printShopInfo();
};
#endif
