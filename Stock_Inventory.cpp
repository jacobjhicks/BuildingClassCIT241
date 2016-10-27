//S
// #include "stdafx.h"
#include "Stock_Inventory.h"

Stock::Stock(string in)
{
	try
	{
		istringstream iss{ in };
		string a, b, c;
		getline(iss, id, '|');
		getline(iss, desc, '|');
		getline(iss, a, '|');
		getline(iss, b, '|');
		getline(iss, supplierId, '|');
		getline(iss, c, '|');
		if (id == "")
		{
		}
		else
		{
			price = stod(a);
			inStock = stoi(b);
			reorderPoint = stoi(c);
		}
	}
	catch (exception)
	{
		system("CLS");
		cerr << "Error: Exception " << current_exception << " thrown." << endl
			<< "Invalid input for stock object." << endl
			<< "Exiting Program" << endl;
		system("pause");
		exit(1);
	}

}

void Inventory::checkForLow() {
	std::vector <std::pair<std::string, int>> list;
	for (auto& g : stocks) {
		if (g.inStock < g.reorderPoint) {
			std::cout << g.id << ": " << g.reorderPoint * 3 - g.inStock << std::endl;
			list.emplace_back(g.id, g.reorderPoint * 3 - g.inStock);
		}
	}
}

Stock& Stock::operator =(const std::string temp) {
	return stringToStock(temp);
}

Stock& Stock::operator =(const Stock &S) { // Implemented, when you set something equal, you need to add it to the Stock Vector in the inventory class.
	id = S.id;
	desc = S.desc;
	price = S.price;
	inStock = S.inStock;
	supplierId = S.supplierId;
	reorderPoint = S.reorderPoint;

	return *this;
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

/* An old version of this function ??? Please look at these two stringToStock functions
Stock stringToStock(std::string s) {
Stock rip;
int harambe = 0;
std::vector<std::string> vars;
for (int x = 0; x < 6; x++) {
vars[x] = s.substr(harambe, s.find('\n', x));
harambe = s.find('\n', x) + 1;
}
rip.id = vars[0];
rip.desc = vars[1];
rip.quantity = std::stoi(vars[2]);
rip.inStock = std::stoi(vars[3]);
rip.supplierId = vars[4];
rip.reorderPoint = std::stoi(vars[5]);
return rip;
}
*/

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

ostream & operator<<(ostream & os, const Stock & in)
{
	os << in.id << "|" << in.desc << "|" << in.price << "|" << in.inStock << "|" << in.supplierId << "|" << in.reorderPoint;
	return os;
}

ostream & operator<<(ostream& os, const Inventory& in)
{
	for (auto a = in.stocks.begin(); a != in.stocks.end(); ++a)
	{
		os << *a << endl;
	}

	return os;

}
