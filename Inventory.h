#pragma once

#include "orderItem.h"
#include "Stock.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


class Inventory {
public:
	std::vector<Stock> stocks;
	void load();//stocks into inventory
	void write();// stocks from inventory into file
	std::vector<std::string> outputList();
	void checkForLow();
	bool itemExists(std::string itemID);
	bool itemInStock(std::string itemID, int quantity);
	string getItemDescription(string itemID);
	double getItemPrice(string itemID);
	void removeStock(string itemID, int quantity);
	Stock& findItem(std::string id);
	void createItem(std::string id, std::string desc, int quantity, int inStock, std::string supplierId, int reorderPoint);
	orderItem checkIfInStock(std::string id, int quantity);
	friend ostream& operator<<(ostream&, const Inventory&);
	// void printInventory() const;
};