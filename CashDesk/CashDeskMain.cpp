#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "Item.h"
#include "FoodItem.h"
#include "DrinkItem.h"
#include "ItemType.h"
#include "Shop.h"
#include "Bill.h"

using namespace std;

void fillShopWithItems(Shop &shop)
{
	// Food product made by copy constructor 
	Item newItem = Item("Bread", "0000000001", 0.95f, item_t::not_set);
	FoodItem bread = FoodItem(newItem);
	shop.addItemToShop(bread);

	// Drink product made by copy constructor 
	Item newItem2 = Item("Wine", "0000000002", 10.00f, item_t::not_set);
	DrinkItem wine = DrinkItem(newItem2);
	shop.addItemToShop(wine);

	// The rest are just items
	Item milk = Item("Milk", "0000000003", 2.01f, item_t::drinks);	
	Item beer = Item("Beer", "0000000004", 2.05f, item_t::drinks);
	Item rakya = Item("Rakya", "0000000005", 15.55f, item_t::drinks);
	Item cheese = Item("Cheese", "0000000006", 6.70f, item_t::foods);
	Item ham = Item("Ham", "0000000007", 12.30f, item_t::foods);
	Item gin = Item("Gin", "0000000008", 14.45f, item_t::drinks);
	Item tomatos = Item("Tomatos", "0000000009", 2.89f, item_t::foods);
	Item beef = Item("Beef", "0000000010", 9.89f, item_t::foods);

	shop.addItemToShop(milk);
	shop.addItemToShop(beer);
	shop.addItemToShop(rakya);
	shop.addItemToShop(cheese);
	shop.addItemToShop(ham);
	shop.addItemToShop(gin);
	shop.addItemToShop(tomatos);
	shop.addItemToShop(beef);
}

void clearBill(Bill &bill)
{
	bill.clearBill();
	cout << "Bill cleared." << endl;
}

void displayTotalValue(Bill &bill)
{
	printf("Total value current bill: %0.2f leva\n", bill.getTotalValue());
}

void addItemToBill(Shop &shop, Bill &bill, string &itemCode)
{
	Item* item = shop.getItemByCode(itemCode);
	if (item->getName().empty())
	{
		printf("Item with code %s cannot be found.\n", itemCode.c_str());
	}
	else
	{
		bill.addItemToPurchases(item);
		printf("%s added to bill: %0.2f\n", item->getName().c_str(), item->getPrice());
	}
}

void executePayment(Bill &bill)
{
	float givenMoney;
	cout << "Please enter the amount of money: " << endl;
	cin >> givenMoney;
	bill.setGivenMoney(givenMoney);
	float change = bill.getChange();
	if (change >= 0) 
	{
		printf("The change is %0.2f leva\n", change);
		cin.ignore();
	}
	else
	{
		printf("Not enough money.\n");
		cin.ignore();
	}
}

void changeItemPrice(Shop &shop)
{
	string itemCode;
	cout << "Enter item code wich price want to change: " << endl;
	getline(cin, itemCode);
	Item* item = shop.getItemByCode(itemCode);
	item->printItemInfo();
	float newPrice;
	cout << "Enter new price: " << endl;
	cin >> newPrice;
	item->setPrice(newPrice);
	cout << "Item's price changed: " ;
	item->printItemInfo();
	cin.ignore();
}

void displayBillInfo(Bill &bill)
{
	bill.printBill();
}

int main()
{
	Shop candyShop = Shop("CandyShop", "12345678", "Somewhere in the middle of nowhere");
	fillShopWithItems(candyShop);
	cout << "Shop items:" << endl;
	candyShop.printShopItems();

	Bill bill = Bill(candyShop);

	string line;
	cout << "\nChoose command: C, T, G, P, N or enter Item Code from above:" << endl;
	getline(cin, line);

	while(!line.empty()) {
		if (line.size() > 1) 
		{
			addItemToBill(candyShop, bill, line);
		}
		else
		{
			char command = line[0];
			switch (command)
			{
			case 'C':
				clearBill(bill);
				break;
			case 'T':
				displayTotalValue(bill);
				break;
			case 'G':
				executePayment(bill);
				break;
			case 'N':
				changeItemPrice(candyShop);
				break;
			case 'P':
				displayBillInfo(bill);
				break;
			default:
				cout << "Unknown command" << endl;
				break;
			}
		}
		
		cout << "\nChoose command: C, T, G, P, N or enter Item Code from above:" << endl;
		getline(cin, line);
	} 

	return 0;
}