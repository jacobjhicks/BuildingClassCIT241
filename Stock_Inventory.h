 #pragma once
#include "orderItem.h"
#include <fstream>
#include <iostream>
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
	//Stock& Stock::operator =(const Stock &S); Broken and I don't feel like fixing it...
};

class Inventory {
public:
	std::vector<Stock> stocks;
	// void load stocks into inventory
	// void write stocks from inventory into file

public:
	std::vector<std::string> Inventory::outputList();
	void Inventory::checkForLow();
	Stock& Inventory::findItem(std::string id);
	void Inventory::createItem(std::string id, std::string desc, int quantity, int inStock, std::string supplierId, int reorderPoint);
	orderItem Inventory::checkIfInStock(std::string id, int quantity);
	// void printInventory() const;
};

// class SupplierItem {
//	private:
//		string supplierID{""}
//		string itemID={""}
//		int reorderAmount{0}
//  public:
//		SupplierItem() = default;
//		SupplierItem(s suppid, s itemID, i amt);
//};

Stock stringToStock(std::string s); // Had to add definition
