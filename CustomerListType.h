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

	// Not needed?
	//list<CustomerType>::iterator findCustomerObject(const string& custId);
	CustomerType & getCustomer(const string & custId);
	bool findCustomer(const string & custId);
	void removeCustomer(CustomerType customer);
	string getOrders(CustomerType customer);
	void addOrder(CustomerType customer, const Order & order);

	list<CustomerType>::iterator begin();
	list<CustomerType>::iterator end();

	string print();

private:
	list<CustomerType> customers;
	//list<CustomerType>::iterator it = customers.begin(); // I don't need this yet...
};
