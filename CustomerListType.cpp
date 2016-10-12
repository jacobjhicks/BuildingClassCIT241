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

list<CustomerType>::iterator CustomerListType::findCustomerObject(const string & custId)
{
	list<CustomerType>::iterator found = find_if(customers.begin(), customers.end(), [& custId](CustomerType customer) {
		return customer.getId() == custId;
	});

	if(found != customers.end())
		return found;
	throw exception("Customer not found.");
}

CustomerType & CustomerListType::getCustomer(const string & custId)
{
	auto found = find_if(customers.begin(), customers.end(), [&custId](CustomerType customer) {
		return customer.getId() == custId;
	});

	return *found;
}

string CustomerListType::print()
{
	stringstream out;

	out << left << "  CustId  ";
	out << left << setw(17) << setw(17) << "Name";
	out << left << setw(17) << setw(17) << "Email";
	out << endl;
	out << left << setfill('-') << setw(80) << "" << endl;
	for_each(customers.begin(), customers.end(), [&out](CustomerType customer) {
		out << customer << endl;
	});

	return out.str();
}
ostream & operator<<(ostream & out, CustomerListType & rightConstmerList)
{
	out << rightConstmerList.print();

	return out;
}
