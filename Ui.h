#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "CustomerListType.h"
#include "Stock_Inventory.h"

using namespace std;

class UI
{
public:
	UI();
	~UI();
	void mainMenu();
	void orderMenu();
	void invMenu();
private:

	CustomerListType totalCustomers; // customer list
	Inventory totalInventory; // inventory list
	void custMenu(int ID);
	//void addOrderData(CustomerType& cust);
	// void updateOrderMenu();
};

