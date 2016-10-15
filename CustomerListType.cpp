#include "CustomerListType.h"



CustomerListType::CustomerListType()
{

}


CustomerListType::~CustomerListType()
{

}

void CustomerListType::addCustomer(const CustomerType customer)
{
	customers.push_back(customer);
}

// Not needed?
//list<CustomerType>::iterator CustomerListType::findCustomerObject(const string & custId)
//{
//	list<CustomerType>::iterator found = find_if(customers.begin(), customers.end(), [&custId](CustomerType customer) {
//		return customer.getId() == custId;
//	});
//
//	if (found != customers.end())
//		return found;
//	throw exception("Customer not found.");
//}

/**
* Returns the CustomerType object with the given ID from the list of customers.
* Throws an error if the custId is not found
*/
CustomerType & CustomerListType::getCustomer(const string & custId)
{
	auto found = find_if(customers.begin(), customers.end(), [&custId](CustomerType customer) {
		return customer.getId() == custId;
	});

	if (found != customers.end())
		return *found;
	throw exception("Customer not found.");
}

/**
* Returns true if a customer with the given ID is found.
*/
bool CustomerListType::findCustomer(const string & custId)
{
	auto found = find_if(customers.begin(), customers.end(), [&custId](CustomerType customer) {
		return customer.getId() == custId;
	});

	return found != customers.end();
}

void CustomerListType::removeCustomer( CustomerType customer)
{
	//customers.remove(*customer);
	list<CustomerType>::iterator rmIt;
	for (rmIt = customers.begin(); rmIt != customers.end(); ++rmIt)
	{
		if (customer == *rmIt)
		{
			customers.erase(rmIt);
			break;
		}
	}
}

string CustomerListType::getOrders(CustomerType customer)
{
	list<CustomerType>::iterator rmIt;
	string out;
	for (rmIt = customers.begin(); rmIt != customers.end(); ++rmIt)
	{
		if (customer == *rmIt)
		{
			out = rmIt->printOrders();
			break;
		}					
	}
	return out;
}

void CustomerListType::addOrder(CustomerType customer, const Order & order)
{
	list<CustomerType>::iterator rmIt;
	for (rmIt = customers.begin(); rmIt != customers.end(); ++rmIt)
	{
		if (customer == *rmIt)
		{
			rmIt->addOrder(order);
			break;
		}
	}
}

/**
 * Returns a string object detailing each customer.
 * Example:
 * "CustId      Name                              Email                             "
 * "--------------------------------------------------------------------------------"
 * "OK123       Full Name                         EmailAddress@example.com          "
 * "...                                                                             "
 */
string CustomerListType::print()
{
	stringstream out;

	out << left << setw(12) << "CustId";
	out << left << setw(34) << "Name";
	out << left << setw(34) << "Email";
	out << endl;
	out << left << setfill('-') << setw(80) << "" << endl;
	for_each(customers.begin(), customers.end(), [&out](CustomerType customer) {
		out << customer << endl;
	});

	return out.str();
}

/**
* Prints the details of each customer.
* Example:
* "CustId      Name                              Email                             "
* "--------------------------------------------------------------------------------"
* "OK123       Full Name                         EmailAddress@example.com          "
* "...                                                                             "
*/
ostream & operator<<(ostream & out, CustomerListType & rightConstmerList)
{
	for (CustomerType customer : rightConstmerList.customers)
	{
		out << customer << endl;
	}

	return out;
}
