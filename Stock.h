#pragma once

#include "orderItem.h"

#include <string>
#include <vector>

class Stock {
public:
	void printStock();
	void incrementQuantity(int qty);
	std::string getID();
	int getInStock();
	int getReorderPoint();
	double getPrice();
	string getDesc();
	Stock& Stock::operator =(const std::string);
	Stock() { id = " ", desc = " ", price = 0; inStock = 0, supplierId = " ", reorderPoint = -1; }
	Stock(string);
	int getReorderAmount() { return (reorderPoint * 3) + (reorderPoint - inStock); }
	string getSupplierID() { return supplierId; }
	Stock& operator=(const Stock&);
	friend ostream& operator<<(ostream&, const Stock&);
	friend bool operator==(const Stock& lef, const Stock& rig) { return lef.id == rig.id; }

// private: Should be able to make these private...  
	std::string id;
	std::string desc;
	int quantity;
	int inStock = 0;
	std::string supplierId;
	int reorderPoint = -1;
	double price;
};

Stock stringToStock(std::string s); // Had to add definition
