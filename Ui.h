#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <regex>
#include "CustomerListType.h"
#include "Stock.h"
#include "Inventory.h"
#include "SupplierItem.h"
#include "Order.h"
#include "orderItem.h"
#include "Date.h"

using namespace std;

class UI
{
public:
	UI();
	~UI();
	void mainMenu();

private:
	void orderMenu();
	void invMenu();
	CustomerListType totalCustomers; // customer list
	Inventory totalInventory; // inventory list
	void custMenu(int ID);
	void addOrderData(Order &newOrder);
	// void updateOrderMenu();
};

