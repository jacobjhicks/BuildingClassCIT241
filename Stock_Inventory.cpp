// #include "stdafx.h"
#include "Stock_Inventory.h"

void Inventory::checkForLow() {
	std::vector <std::pair<std::string, int>> list;
	for (auto& g : stocks) {
		if (g.inStock < g.reorderPoint) {
			std::cout << g.id << ": " << g.reorderPoint * 3 - g.inStock << std::endl;
			list.emplace_back(g.id, g.reorderPoint * 3 - g.inStock);
		}
	}
}

bool Inventory::itemExists(std::string itemID)
{
	for (Stock item : stocks)
	{
		if (item.getID == itemID)
			return true;
	}

	return false;
}

//Stock& Stock::operator =(const Stock &S) { // Implemented, when you set something equal, you need to add it to the Stock Vector in the inventory class.
//	id = S.id; Broken and I don't feel like fixing it...
//	desc = S.desc;
//	quantity = S.quantity;
//	inStock = S.inStock;
//	supplierId = S.supplierId;
//	reorderPoint = S.reorderPoint;
//}

//orderItem Inventory::checkIfInStock(std::string id, int quantity) {
//	for (int x = 0; x < stocks.size(); x++) {
//		if (stocks[x].id == id) {
//			if (stocks[x].quantity >= quantity) {
//				stocks[x].quantity -= quantity;
//			}
//			else {
//				checkForLow();
//			}
//		}
//	}
//  // Must return an orderItem to compile
//	TODO: return orderItem or throw exception("message"); ???
//}

Stock& Inventory::findItem(std::string id) {
	for (int x = 0; x < stocks.size(); x++) {
		if (stocks[x].id == id) {
			return stocks[x];
		}
	}

	// TODO: return Stock or throw exception("message"); ???
}

void Inventory::createItem(std::string id, std::string desc, int quantity, int inStock, std::string supplierId, int reorderPoint) {
	Stock s;
	std::ofstream stream;
	// sets an Stock equal to the parameters 
	s.id = id;
	s.desc = desc;
	s.quantity = quantity;
	s.inStock = inStock;
	s.supplierId = supplierId;
	s.reorderPoint = reorderPoint;

	stocks.emplace_back(s);
	stream.open("products.txt");
	stream << id;
	stream.close();
	stream.open("products/" + id + ".txt");
	stream << id + '\n';
	stream << desc + '\n';
	stream << quantity + '\n';
	stream << inStock + '\n';
	stream << supplierId + '\n';
	stream << reorderPoint + '\n'; //This prints out in new lines in a file named after it's ID , probablly needs to be changed to prof. North's criteria 
}

Stock stringToStock(std::string s) {
	Stock stockItem;

	int temp = 0;

	std::vector<std::string> vars;

	for (int x = 0; x < 6; x++) {

		vars[x] = s.substr(temp, s.find('\n', x));

		temp = s.find('\n', x) + 1; // This line produces a warning, 
									// size_t find (char c, size_t pos = 0) const noexcept;
									//	Return Value:
									//	The position of the first character of the first match.
									//	If no matches were found, the function returns string::npos.
								// This is because It's checking for new lines. But I think I need to recode it so It looks for the | instead of a new line.

	}

	stockItem.id = vars[0];

	stockItem.desc = vars[1];

	stockItem.quantity = std::stoi(vars[2]);

	stockItem.inStock = std::stoi(vars[3]);

	stockItem.supplierId = vars[4];

	stockItem.reorderPoint = std::stoi(vars[5]); // This is setting the items = to there place in a vector of stoi IDK if it works, but it will definetly compile

	return stockItem;
}

std::vector<std::string> Inventory::outputList() {
	std::ifstream stream;

	std::string line;

	std::vector<std::string> list;

	stream.open("products.txt"); // list of files to load

	while (std::getline(stream, line)) {

		stream.close();
		stream.open("products/" + line + ".txt"); // files with all the information about stuff

		while (stream.is_open()) {
			std::string agam = "";
			while (std::getline(stream, line)) {
				std::cout << line << std::endl;
				agam += line + '\n';
			}
			// TODO: This line causes a compiler error
			// list.emplace_back(stringToStock(agam));
				// list is a vector<string>
				// stringToStock() returns a Stock object
			
			agam = "";
			stream.close();
		}
		stream.open("products.txt");
	}
	stream.close();
	return list;
}

void Stock::incrementQuantity(int qty) {
	quantity += qty;
}

std::string Stock::getID() {
	return id;
}

int Stock::getInStock() {
	return inStock;
}

int Stock::getReorderPoint() {
	return reorderPoint;
}

void Stock::printStock() {
	std::cout << std::to_string(inStock) << std::endl;
}