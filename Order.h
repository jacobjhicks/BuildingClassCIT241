#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Date.h"
#include <list>
#include "orderItem.h"

#pragma once

using namespace std;

class Order
{
	friend ostream& operator<<(ostream& out, Order & rightOrder);
public:
	Order();
	Order(string orderID, Date orderDate, Date deliveryDate);
	~Order();

	bool isOrder(string inStr);
	bool operator==(Order& rhs);
	bool operator<(Order& rhs);
	bool itemInOrder(string itemID);
	string printOrder();
	void addOrderItem(const orderItem& inItem);
	void removeOrderItem(orderItem inItem);
	orderItem getItem(string itemID);

	string getOrderID();
	Date getOrderDate();
	Date getDeliveryDate();
	// orderitem& findOrderItem(string itemid);
	string write();

private:
	string orderID;
	Date orderDate;
	Date deliveryDate;
	list<orderItem> orderItems;


};

