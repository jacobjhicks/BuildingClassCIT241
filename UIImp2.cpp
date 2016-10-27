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

/* Should pobably move this line below the function you are currently working on, that way you can use Intellesence to see whats happening without causing a million compiler errors.


void UI::mainMenu()
{
	char option;
	string customername, customeremail, customerID;
	bool runMM, verifyInput;
	verifyInput = false;
	runMM = false;

	while (runMM == false)
	{
		if (verifyInput == true)
		{
			// This locks up if cin has never been used. Skip on first iteration
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Press enter to continue." << endl;
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("CLS");
		}
		verifyInput = true;
		cout << "Main Menu \n\n1) Add customer \n2) Remove coustomer \n3) Find customer" <<
			"\n4) List customer information \n5) Order menu \n6) Inventory menu \n7) Exit" << endl;
		cin >> option;

		// Set to verify cin after first read
		verifyInput = true;

		switch (option)
		{
		case '1':		// add customer
			cout << "Add Customer Procedure" << endl;
			//do
			//{
			//	// Need to get potential new customerID
			//	cout << "Enter Customer ID: ";
			//	cin >> customerID;
			//	// after reading in customerID - see if it already exists
			//	if (totalCustomers.findCustomer(customerID))
			//	{
			//		// if it already exists, warn user and go back to customer menu
			//		cout << endl << "Custeromer ID already exists.\nPlease Re-";
			//	}
			//} while (totalCustomers.findCustomer(customerID));

			//// collect rest of customer information

			//cout << "Enter customer name: ";
			//// names are notorious for having spaces in them - must use getline
			//cin.ignore();
			//getline(cin, customername);
			//do
			//{
			//	// Need to get potential new customeremail
			//	cout << "Enter customer email: ";
			//	cin.clear();
			//	cin >> customeremail;
			//	// After reading in customeremail - check if it is valid

			//	// Establish a general email pattern
			//	// regex emailMatch("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$");
			//	// Check the input for the regex pattern
			//	// if (regex_match(customeremail, emailMatch))

			//	int i = customeremail.find('@', 1);
			//	if (//customeremail.find('@', 1) == true && // this line produced a Warning
			//		customeremail.find('@', 1) != string::npos && // If no matches were found, the function returns string::npos.
			//		customeremail.find('.', i + 1) != string::npos &&
			//		customeremail.back() != '.') //Making sure there is an "@" and a "." afterwards. Characters must follow.
			//	{
			//		emailCheck = false;
			//	}
			//	else
			//	{
			//		cout << "ERROR: Incorrect email address entered. \nPlease Re-";
			//		emailCheck = true;
			//	}
			//} while (emailCheck);
			//// build customer and add to customer
			//// customerlist.addCustomer(Customer(----,-----,-----));
			//tempCustomer = new CustomerType(customerID, customername, customeremail);
			//totalCustomers.addCustomer(*tempCustomer);

			break;
		case '2':		// remove customer
			cout << "Remove Customer Procedure" << endl;
			// you may want to display list of customerIDs so user can choose one
			//cout << "Current customers:" << endl;
			//cout << totalCustomers << endl;
			//do
			//{
			//	cout << "Enter customer ID you want to delete: ";
			//	cin >> customerID;
			//	if (totalCustomers.findCustomer(customerID)) {
			//		remCustomerCheck = false;
			//		totalCustomers.removeCustomer(totalCustomers.getCustomer(customerID));
			//	}
			//	else
			//	{
			//		cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
			//		remCustomerCheck = true;
			//	}
			//} while (remCustomerCheck);
			//// find customer object in customerlist returning iterator pointing to the customer object
			//// if found
			////		use customer list remove method passing iterator
			//// else
			////		message to user not found

			break;
		case '3':		// find customer returning iterator pointing to the customer
			cout << "Find Customer Procedure" << endl;
			// you may want to display list of customerIDs so user can choose one
				//cout << "enter customer ID" << endl;
				//cin >> customerID;
			// CustomerType& cust = custlist.getcustomer(customerID)
			break;
		case '4': // list customer information
			cout << "list customer Procedure:" << endl;
			cout << "Current customers:" << endl << totalCustomers << endl;
			break;
		case '5':  //order menu
			system("CLS");
			orderMenu();
			break;
		case '6': //inv menu
			system("CLS");
			invMenu();
			break;
		case '7': //exit
			runMM = true;
			cout << "Exiting Program." << endl;
			break;
		default:
			cout << "Invalid option try again";
			break;
		}

	}
}

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

*/