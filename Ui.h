#pragma once
#include <iostream>
#include <vector>
#include <list>

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
	// missing customer list
	// inventory list
	void custMenu(int ID);
	//void addOrderData(CustomerType& cust);
	// void updateOrderMenu();
};

