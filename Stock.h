#pragma once

#include "orderItem.h"

#include <string>
#include <vector>

class Stock {
public:
	std::string id;
	std::string desc;
	int quantity;
	int inStock = 0;
	std::string supplierId;
	int reorderPoint = -1;

	void printStock();
	void incrementQuantity(int qty);
	std::string getID();
	int getInStock();
	int getReorderPoint();
	Stock& Stock::operator =(const std::string);

	double price;


	Stock() { id = " ", desc = " ", price = 0; inStock = 0, supplierId = " ", reorderPoint = -1; }
	Stock(string);
	int getReorderAmount() { return (reorderPoint * 3) + (reorderPoint - inStock); }
	string getSupplierID() { return supplierId; }
	Stock& operator=(const Stock&);
	friend ostream& operator<<(ostream&, const Stock&);
	friend bool operator==(const Stock& lef, const Stock& rig) { return lef.id == rig.id; }
};

Stock stringToStock(std::string s); // Had to add definition
