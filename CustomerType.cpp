#include "CustomerType.h"



CustomerType::CustomerType()
{
	custId = "";
	name = "";
	email = "";
}

CustomerType::CustomerType(string newCustId, string newName, string newEmail)
{
	custId = newCustId;
	name = newName;
	email = newEmail;
}

CustomerType::CustomerType(string newCustId, string newName, string newEmail, const Order & order)
{
	custId = newCustId;
	name = newName;
	email = newEmail;
	addOrder(order);
}

CustomerType::~CustomerType()
{
}

string CustomerType::getId()
{
	return custId;
}

string CustomerType::getEmail()
{
	return email;
}

string CustomerType::getName()
{
	return name;
}

void CustomerType::setEmail(const string & newEmail)
{
	email = newEmail;
}

void CustomerType::addOrder(const Order & order)
{
	orders.push_back(order);
}

Order & CustomerType::getOrder(const string & orderId)
{
	auto found = find_if(orders.begin(), orders.end(), [& orderId](Order order) {
		return order.getOrderID() == orderId;
	});

	return *found;
}

bool CustomerType::findOrder(const string & orderId) const
{
	auto found = find_if(orders.begin(), orders.end(), [& orderId](Order order) {
		return order.getOrderID() == orderId;
	});

	return found != orders.end();
}

void CustomerType::removeOrder(const string & orderId)
{
	orders.remove_if([orderId](Order order) {
		return order.getOrderID() == orderId;
	});
}

string CustomerType::print()
{
	ostringstream out;

	out << setw(10) << right <<  custId;
	out << setw(35) << left << name;
	out << setw(35) << left << email;
	out << endl;
	printOrders();
	out << endl;

	return out.str();
}

string CustomerType::printOrders()
{
	ostringstream out;
	out << "orders:";
	//cout << "orders:";
	double totals = 0.0;

	for_each(orders.begin(), orders.end(), [&totals, &out](Order order) {
		out << order << endl;
		//totals += order.getTotal();
	});

	//out << "Order totals: " << totals << endl;

	return out.str();
}

string CustomerType::printOrderIds()
{
	stringstream out;

	for (Order order : orders)
	{
		out << order.getOrderID() << endl;
	}

	return out.str();
}

ostream & operator<<(ostream & out, CustomerType & rightConstmer)
{
	out << setw(10) << right << rightConstmer.custId;
	out << setw(35) << left << rightConstmer.name;
	out << setw(35) << left << rightConstmer.email;
	out << endl;

	return out;
}

bool operator==(CustomerType & leftCustomer, CustomerType & rightCustomer)
{
	return &leftCustomer == &rightCustomer || leftCustomer.getId() == rightCustomer.getId();
}

bool operator<=(CustomerType & leftCustomer, CustomerType & rightCustomer)
{
	return leftCustomer.getName() < rightCustomer.getName();
}
