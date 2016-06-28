#include <iostream>
#include <vector>
#include "Item.h"
#include "Shop.h"


void Shop::addItemToShop(Item &newItem)
{
	this->items.push_back(newItem);
}

Item* Shop::getItemByCode(string itemCode)
{
	Item* searchedItem;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i].getItemCode() == itemCode) 
		{
			searchedItem = &items[i];
		}
	}

	return searchedItem;
}

void Shop::printShopItems()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		items[i].printItemInfo();
	}
}

void Shop::printShopInfo()
{
	printf("\n%s\nBIC:%s\nAddress: %s\n", 
		this->shopName.c_str(), 
		this->bic.c_str(),
		this->shopAddress.c_str());
}