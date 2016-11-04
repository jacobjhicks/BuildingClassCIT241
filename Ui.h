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
		// mainMenu switch function.
	void listCustomerInformation();
	void addCustomer();
	void removeCustomer();
	void editCustomer();


	void orderMenu();
		// orderMenu switch functions
	void listCustomersOrders();
	void listAllOrders();
	void addOrder();
	void cancelOrder();
	void updateOrder();


	void invMenu();
		// invMenu switch functions
	void listInventory();
	void displayItem();
	void processOrder();
	void generateOrdersReport();
	void generateInventoryReport();

	void addOrderData(Order &newOrder, string custID);


	CustomerListType totalCustomers; // customer list
	Inventory totalInventory; // inventory list
};

