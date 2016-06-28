#include <iostream>
#include <vector>
#include "Item.h"
#include "Bill.h"

using namespace std;

void Bill::addItemToPurchases(Item* item)
{
	this->purchases.push_back(*item);
	this->totalValue += item->getPrice();
}

float Bill::getTotalValue()
{
	return this->totalValue;
}

void Bill::setGivenMoney(float money)
{
	this->givenMoney = money;
}

float Bill::getGivenMoney()
{
	return this->givenMoney;
}

float Bill::getChange()
{
	return this->givenMoney - this->totalValue;
}

void Bill::clearBill()
{
	this->totalValue = 0;
	this->purchases.clear();
}

void Bill::printBill()
{
	this->shop.printShopInfo();
	printf("Purchases : %0.2f leva\nGiven : %0.2f leva\nChange : %0.2f leva\n",
		this->getTotalValue(),
		this->getGivenMoney(),
		this->getChange());
}