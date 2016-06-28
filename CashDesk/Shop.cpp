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
	// Item *itemsPointer;
	// for (itemsPointer = &items[0]; itemsPointer != &items[0] + items.size(); ++itemsPointer)
	// {
	//	 Item item = *itemsPointer;
	//	 if (item.getItemCode().compare(itemCode) == 0)
	//	 {
	//		 searchedItem = item;
	//		 break;
	//	 }
	// }
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
	//Item *itemsPointer;
	//for (itemsPointer = &items[0]; itemsPointer != &items[0] + items.size(); ++itemsPointer)
	//{
	//	Item item = *itemsPointer;
	//	item.printItemInfo();
	//}

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