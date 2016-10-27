#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>
#include "Order.h"

using namespace std;

class CustomerType
{
	friend ostream& operator<<(ostream& out, CustomerType & rightCustomer);
public:
	CustomerType();
	CustomerType(string newCustId, string name, string email);
	CustomerType(string newCustId, string name, string email, const Order & order);
	~CustomerType();

	string getId();
	string getEmail();
	string getName();
	void setEmail(const string & newEmail);

	void addOrder(const Order & order);
	Order & getOrder(const string & orderId);
	bool findOrder(const string & orderId) const;
	void removeOrder(const string & orderId);

	string print();
	string printOrders();
	string printOrderIds();

	string write();

private:
	string custId;
	string name;
	string email;
	list<Order> orders;
};

bool operator==(CustomerType & leftCustomer, CustomerType & rightCustomer);
bool operator<=(CustomerType & leftCustomer, CustomerType & rightCustomer);
