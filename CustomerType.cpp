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

/**
* Returns a string object of the customers ID.
*/
string CustomerType::getId()
{
	return custId;
}

/**
* Returns a string object of the customers email.
*/
string CustomerType::getEmail()
{
	return email;
}

/**
* Returns a string object of the customers name.
*/
string CustomerType::getName()
{
	return name;
}

/**
 * Sets the email of the customer
 */
void CustomerType::setEmail(const string & newEmail)
{
	email = newEmail;
}

/**
* Adds the given order to the customers list of orders
*/
void CustomerType::addOrder(const Order & order)
{
	orders.push_back(order);
}

/**
 * Returns the order object with the given ID from the list of orders.
 * Throws an exception if the orderId is not found.
 */
Order & CustomerType::getOrder(const string & orderId)
{
	auto found = find_if(orders.begin(), orders.end(), [&orderId](Order order) {
		return order.getOrderID() == orderId;
	});

	return *found;
}

/**
 * Returns true if the orderId parameter is found within the orders list.
 */
bool CustomerType::findOrder(const string & orderId) const
{
	auto found = find_if(orders.begin(), orders.end(), [&orderId](Order order) {
		return order.getOrderID() == orderId;
	});

	return found != orders.end();
}

/**
 * Removes all orders with the id matching the parameter
 */
void CustomerType::removeOrder(const string & orderId)
{
	orders.remove_if([orderId](Order order) {
		return order.getOrderID() == orderId;
	});
}

/**
* Returns a string object detailing the customer.
* Example:
* "OK123       Full Name                         EmailAddress@example.com          "
*/
string CustomerType::print()
{
	ostringstream out;

	out << setw(12) << left << custId;
	out << setw(34) << left << name;
	out << setw(34) << left << email;
	out << endl;
	printOrders();
	out << endl;

	return out.str();
}

/**
 * Returns a string object of all this customers orders.
 * Example:
 * TBD
 */
string CustomerType::printOrders()
{
	ostringstream out;
	out << "orders:";
	//cout << "orders:";
	double totals = 0.0;

	for_each(orders.begin(), orders.end(), [&totals, &out](Order order) {
		out << order.printOrder() << endl;
		//totals += order.getTotal();
	});

	//out << "Order totals: " << totals << endl;

	return out.str();
}

/**
 * Returns a string object of all the order numbers, all on one line
 * Example:
 * "OR123       OR123       OR123      OR123     ..."
 */
string CustomerType::printOrderIds()
{
	stringstream out;

	for (Order order : orders)
	{
		out << left << setw(12) << order.getOrderID() << endl;
	}

	return out.str();
}

/**
* Returns a string object of all the order numbers, all on one line
* Example:
* "OK123|My Name|my.email@example.com|"
* "OR123...order stuff"
* "OR123...order stuff"
*/
string CustomerType::write()
{
	stringstream out;
	out << "C|" << custId << "|" << name << "|" << email << endl;
	for (Order order : orders)
	{
		out << order.write();
	}

	return out.str();
}

/**
* Prints the customers details.
* Example:
* "OK123       Full Name                         EmailAddress@example.com          "
*/
ostream & operator<<(ostream & out, CustomerType & rightCustomer)
{

	out << setw(12) << left << rightCustomer.getId();
	out << setw(34) << left << rightCustomer.getName();
	out << setw(34) << left << rightCustomer.getEmail();

	return out;
}

/**
 * Returns true if the customers match
 */
bool operator==(CustomerType & leftCustomer, CustomerType & rightCustomer)
{
	return &leftCustomer == &rightCustomer || leftCustomer.getId() == rightCustomer.getId();
}

/**
* Returns true if the left customer's name comes before the right customer's name
*/
bool operator<=(CustomerType & leftCustomer, CustomerType & rightCustomer)
{
	return leftCustomer.getName() < rightCustomer.getName();
}
