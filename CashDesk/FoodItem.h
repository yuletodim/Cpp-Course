#include <iostream>
#include "Item.h"
#include "ItemType.h"

#ifndef __FOOD_ITEM_H
#define __FOOD_ITEM_H
class FoodItem : public Item
{
public:
	FoodItem(){};
	// Copy constructor
	FoodItem(Item &item)
	{
		this->name = item.getName();
		this->itemCode = item.getItemCode();
		this->price = item.getPrice();
		this->itemType = item_t::foods;
	}
};
#endif
