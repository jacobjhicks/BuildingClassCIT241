#pragma once

#include <iomanip>
#include <list>

#include "CustomerType.h"
#include "Order.h"
class CustomerListType
{
friend ostream& operator<<(ostream& out, CustomerListType & rightConstmerList);
public:
	CustomerListType();
	~CustomerListType();

	void addCustomer(const CustomerType customer);
	list<CustomerType>::iterator findCustomerObject(const string& custId);
	CustomerType & getCustomer(const string & custId);

	string print();

private:
	list<CustomerType> customers;
};
