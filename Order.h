#include <string>
#include <iostream>
#include <vector>
#include "Date.h"
#include <list>
#include "orderItem.h"

#pragma once

using namespace std;

class Order
{
public:
	Order();
	Order(string orderID, Date orderDate, Date deliveryDate);
	~Order();

	bool isOrder(string inStr);
	bool operator==(Order& rhs);
	bool operator<(Order& rhs);
	void printOrder();
	void addOrderItem(const orderItem& inItem);
	void removeOrderItem(orderItem& inItem);
	string getOrderID();
	Date getOrderDate();
	Date getDeliveryDate();
	// orderitem& findOrderItem(string itemid);

private:
	string orderID;
	Date orderDate;
	Date deliveryDate;
	list<orderItem> orderItems;


};

