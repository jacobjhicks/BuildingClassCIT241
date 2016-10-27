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

class Inventory {
public:
	std::vector<Stock> stocks;
	void load();//stocks into inventory
	void write();// stocks from inventory into file
	std::vector<std::string> outputList();
	void checkForLow();
	bool itemExists(std::string itemID);
	Stock& findItem(std::string id);
	void createItem(std::string id, std::string desc, int quantity, int inStock, std::string supplierId, int reorderPoint);
	orderItem checkIfInStock(std::string id, int quantity);
	friend ostream& operator<<(ostream&, const Inventory&);
	// void printInventory() const;
};

class SupplierItem {
private:
	string supplierID{ " " };
	string itemID{ " " };
	int reorderAmount{ 0 };
public:
	SupplierItem() = default;
	SupplierItem(string suppid, string iID, int amt) { supplierID = suppid, itemID = iID, reorderAmount = amt; }
	friend bool operator==(const SupplierItem& lef, const SupplierItem& rig) { return lef.supplierID == rig.supplierID; }
	friend bool operator<(const SupplierItem& lef, const SupplierItem& rig) { return lef.supplierID == rig.supplierID; }
	string getiID() { return itemID; }
	int getAmount() { return reorderAmount; }
	string getSupp() { return supplierID; }
};

Stock stringToStock(std::string s); // Had to add definition
