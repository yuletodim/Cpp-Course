#include <iostream>
#include "Item.h"
#include "ItemType.h"

#ifndef __DRINK_ITEM_H
#define __DRINK_ITEM_H
class DrinkItem : public Item
{
public:
	DrinkItem() {};
	// Copy constructor
	DrinkItem(Item &item)
	{
		this->name = item.getName();
		this->itemCode = item.getItemCode();
		this->price = item.getPrice();
		this->itemType = item_t::drinks;
	}
};
#endif
