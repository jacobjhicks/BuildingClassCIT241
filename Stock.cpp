#include "Stock.h"

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
