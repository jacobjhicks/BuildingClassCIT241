/*
 * This file needs to be merged with UIImp.cpp
 * This may be a lengthy process, so I'm simply uploading the file for now
 * If you have merged the functions INTO UIImp.cpp, then delete the function from here
 * That way others will be able to resolve issues rather than search for what needs resolving
 * 
 * Good luck! 
 * 
 * (obviously, I'll work on it too)
 */


#include "Ui.h"

void UI::orderMenu()
{
	char option;
	string custID;
	bool stayInMenu = true;
	bool reuse = false;

	while (stayInMenu == true)
	{

		if (reuse == true)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Press Enter to Continue" << endl;
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("CLS");
		}
		reuse = true;


		cout << "Order Menu" <<
			"\n1) List Orders for Customer \n2) Over all orders for all customers \n3) Add order to customer" <<
			"\n4) Cancel order for a customer \n5) Update order for a customer \n6) Go Back \n";
		cin >> option;

		switch (option)
		{
		case '1':     // list orders for a customer
			cout << "List Customer Order Procedure" << endl;
			//cout << "Current customers:" << endl;
			//cout << totalCustomers << endl;//customerListprint;
			//do
			//{
			//	cout << "Enter customer ID: ";
			//	cin >> custID;
			//	if (totalCustomers.findCustomer(custID)) { // iterator = find customer
			//		notValidCustomer = false;
			//		cout << totalCustomers.getOrders(totalCustomers.getCustomer(custID)) << endl;
			//	}
			//	else {
			//		notValidCustomer = true;
			//		cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
			//	}
			//} while (notValidCustomer);


			//// if iterator not = customer list end
			////		(*iterator) invoke method printOrders()
			//// else
			////		customerid not found
			break;
		case '2':     // list all orders for all customers
			cout << "List all orders Procedure" << endl;
			//		// use for range loop to retrieve each customer
			//for (CustomerType customer : totalCustomers)
			//{
			//	// for current customer invoke printOrders() method
			//	cout << customer.printOrders();
			//}

			break;
		case '3':		// add an order for a customer
			cout << "add order to customer Procedure" << endl;
			//		//customerListprint;
			//cout << "Current customers:" << endl;
			//cout << totalCustomers << endl;//customerListprint;
			//do
			//{
			//	cout << "Enter customer ID: ";
			//	cin >> custID;
			//	if (totalCustomers.findCustomer(custID)) { // iterator = find customer
			//		notValidCustomer = false;
			//		tempOrder = new Order();
			//		addOrderData(*tempOrder);
			//		totalCustomers.addOrder(totalCustomers.getCustomer(custID), *tempOrder);// - Get oder to pass in
			//	}
			//	else {
			//		notValidCustomer = true;
			//		cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
			//	}
			//} while (notValidCustomer);
			//// Customer& cust = custlist.getcustomer(custID)
			//// if cust != emptyCustomer
			////		invoke addOrderData(cust)
			//// else
			////		customerid not found
			break;
		case '4':		// cancel order
			cout << "cancel Customer Order Procedure" << endl;
			//		//customerListprint;
			//cin >> custID;
			//// Customer& cust = custlist.getcustomer(custID)
			//// if cust != emptyCustomer
			////		get orderid and canceldate
			////		if (*iterator).findOrder(orderid) is true
			////			(*iterator).removeOrder(orderid)
			////		else
			////			error message
			////		endif	
			//// else
			////		customerid not found
		case '5':			// update order
			cout << "Update Order Procedure" << endl;
			//	updateOrderMenu()
			break;
		case '6':
			stayInMenu = false;
			cout << "Exiting back to top" << endl;
			break;
		default:
			cout << "Invalid Option \"" << option << "\"" << endl;
			break;
		}

	}
}
