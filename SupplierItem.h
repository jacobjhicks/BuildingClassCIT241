#pragma once

#include <string>

using namespace std;

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