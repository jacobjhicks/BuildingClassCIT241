#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class orderItem
{
public:
	//constructor
	orderItem() = default;
	orderItem(string, int);
	orderItem(string, string, int, double);
	~orderItem();

	//accessors
	string getitemID() { return itemID; }
	string getitemDesc() { return itemDesc; }
	int getQuant() { return quantity; }
	double getPrice() { return price; }

	//sets
	void setitemID(string a) { itemID = a; }
	void setitemDesc(string a) { itemDesc = a; }
	void setQuant(int a) { quantity =a; }
	void setPrice(double a) { price = a; }

	//operators
	friend ostream& operator<<(ostream&, const orderItem&);
	friend bool operator<(const orderItem&, const orderItem&);
	friend bool operator ==(const orderItem&, const orderItem&);

	//function
	double getItemTotal() { return quantity * price; }
	string write();

	// void incrementQuantity(int qty);

	
private:
	string itemID{ "" };
	string itemDesc{ "" };
	int quantity{ 0 };
	double price{ 0.0 };
};

