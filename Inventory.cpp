#include "Inventory.h"



void Inventory::checkForLow() {
	std::vector <std::pair<std::string, int>> list;
	for (auto& g : stocks) {
		if (g.inStock < g.reorderPoint) {
			std::cout << g.id << ": " << g.reorderPoint * 3 - g.inStock << std::endl;
			list.emplace_back(g.id, g.reorderPoint * 3 - g.inStock);
		}
	}
}

orderItem Inventory::checkIfInStock(std::string id, int quantity) {
	for (int x = 0; x < stocks.size(); x++) {
		if (stocks[x].id == id) {
			if (stocks[x].quantity >= quantity) {
				stocks[x].quantity -= quantity;
			}
			else {
				checkForLow();
			}
		}
	}

	//
	//
	// TODO: This return does nothing meaningful.
	// Added the return statement to avoid compiler error
	//
	//
	orderItem temp;
	return temp;
}

bool Inventory::itemExists(std::string itemID)
{
	for (Stock item : stocks)
	{
		if (item.getID() == itemID)
			return true;
	}

	return false;
}

bool Inventory::itemInStock(std::string itemID, int quantity)
{
	for (Stock item : stocks)
	{
		if (item.getID() == itemID) {
			if(item.getInStock() >= quantity)
				return true;
		}
			
	}

	return false;
}

Stock& Inventory::findItem(std::string id) {
	for (int x = 0; x < stocks.size(); x++) {
		if (stocks[x].id == id) {
			return stocks[x];
		}
	}

	//
	//
	// TODO: This return does nothing meaningful.
	// Added the return statement to avoid compiler error
	//
	//
	Stock hold;
	return hold;
}

/* Not sure which findItem function is needed. Please eliminate one of these or merge them if needed.
Stock& Inventory::findItem(std::string id) {

vector<Stock>::iterator a;
for (a = stocks.begin(); a != stocks.end(); ++a)
{
if ((*a).id == id)
{
return *a;
}
}

Stock hold;
return hold;

// TODO: return Stock or throw exception("message"); ???
}
*/

void Inventory::createItem(std::string id, std::string desc, int quantity, int inStock, std::string supplierId, int reorderPoint) {
	Stock s;
	std::ofstream stream;

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
	stream << reorderPoint + '\n';	//This prints out in new lines in a file named after it's ID , probablly needs to be changed to prof. North's criteria 
}

void Inventory::load()
{
	ifstream inDat;
	inDat.open("Inventory.txt");

	while (!inDat.eof())
	{
		string fil;
		getline(inDat, fil);
		Stock hold(fil);
		if (hold.getID() == "")
		{

		}
		else
		{
			stocks.push_back(hold);
		}

	}

	inDat.close();
}

void Inventory::write()
{
	ofstream outDat;
	ostringstream oss;
	outDat.open("Inventory.txt");


	for (auto a = stocks.begin(); a != stocks.end(); ++a)
	{
		if ((*a).getID() == "")
		{
		}
		else
		{
			oss << *a << endl;
		}
	}
	outDat << oss.str();
	outDat.close();
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

ostream & operator<<(ostream& os, const Inventory& in)
{
	for (auto a = in.stocks.begin(); a != in.stocks.end(); ++a)
	{
		os << *a << endl;
	}

	return os;

}