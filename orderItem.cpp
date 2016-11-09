#include "orderItem.h"

using namespace std;


orderItem::orderItem(string a, int b):itemID(a), quantity(b)
{
}


orderItem::~orderItem()
{
}

orderItem::orderItem(string a, string b, int c, double d): itemID(a), itemDesc(b), quantity(c), price(d)
{
}

string orderItem::write()
{
	stringstream out;

	out << "I|" << itemID << "|" << itemDesc << "|" << quantity << "|" << price << endl;

	return out.str();
}

ostream& operator<<(ostream& os, const orderItem& rig)
{
	os << "\t" << setw(7) << left << rig.itemID << "|" << setw(30) << rig.itemDesc << "|";
	os << right << setw(4) << right << rig.quantity << "|" << setw(5) << "$"<< rig.price;

	return os;
}

bool operator<(const orderItem& lef, const orderItem& rig)
{
	return lef.itemID < rig.itemID;
}
bool operator ==(const orderItem& lef, const orderItem& rig)
{
	return lef.itemID == rig.itemID;
}

