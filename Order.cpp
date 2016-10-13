#include "Order.h"
#include "orderItem.h"


Order::Order()
{
}

Order::Order(string orderID, Date orderDate, Date deliveryDate)
{
	this->orderID = orderID;
	if (deliveryDate >= orderDate)
	{
		this->orderDate = orderDate;
		this->deliveryDate = deliveryDate;
	}
	else
	{
		cout << "delivery date need later than order date";
	}
}

void Order::addOrderItem(const orderItem& inItem)
{
	bool foundFlag = false;
	for (orderItem eachItem : orderItems)
	{
		if (inItem == eachItem)
		{
			foundFlag = true;
			cout << "Item exists. Do you want to add this item? yes/no" << endl;
			string inStr;
			cin >> inStr;
			if (inStr == "yes")
			{
				// add item
				orderItems.push_back(inItem);
			}
			else
			{
				// do nothing
			}
			break;
		}
	}

	if (foundFlag==false)
		orderItems.push_back(inItem);

}

void Order::removeOrderItem(orderItem& inItem)
{
	orderItems.remove(inItem);

}

string Order::getOrderID()
{
	return orderID;
}

Date Order::getDeliveryDate()
{
	return deliveryDate;
}

Date Order::getOrderDate()
{
	return orderDate;
}


string Order::printOrder()
{
	stringstream out;

	out << "Order ID is: " << orderID << endl;
	out << "Order date is: " << orderDate.dateString() << endl;
	out << "Delivery date is: " << deliveryDate.dateString() << endl;

	for (orderItem eachItem : orderItems)
	{
		out << eachItem << endl;
	}

	return out.str();
}

bool Order::isOrder(string inStr)
{
	if (inStr == orderID)
		return true;
	else
		return false;

}

bool Order::operator==(Order& rhs)
{
	if (rhs.getOrderID() == this->orderID)
		return true;
	else
		return false;
}

bool Order::operator<(Order& rhs)
{
	if (rhs.getOrderDate() < this->orderDate)
		return true;
	else
		return false;
}


Order::~Order()
{
}

ostream & operator<<(ostream & out, Order & rightOrder)
{
	out << rightOrder.printOrder();

	return out;
}
