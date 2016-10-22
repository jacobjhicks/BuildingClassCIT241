#include "Ui.h"
#include "Date.h"
#include "Order.h"
#include <iostream>
#include <string>

UI::UI()
{
	// invlist.load stocks into inventory
}

UI::~UI()
{
	// write stocks from inventory into file
}

void UI::mainMenu()
{ 
	bool continueUi = true;
	do
	{
		int option;
		string customername, customeremail, customerID;
		bool emailCheck,remCustomerCheck;
		CustomerType *tempCustomer;
		bool verifyInput = false;
		cout << string(3, '\n');

		do
		{
			if (verifyInput)
			{
				// This locks up if cin has never been used. Skip on first iteration
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Main Menu \n\n1) Add customer \n2) Remove coustomer \n3) Find customer" <<
				"\n4) List customer information \n5) Order menu \n6) Inventory menu \n7) Exit" << endl;
			cin >> option;

			// Set to verify cin after first read
			verifyInput = true;

			if (!cin)
			{
				cout << endl;
				cout << "Invalid option entered. Please try again." << endl;
				cout << endl;
			}

		} while (!cin);
		
		switch (option)
		{
		case 1:		// add customer
			do
			{
				// Need to get potential new customerID
				cout << "Enter Customer ID: ";
				cin >> customerID;
				// after reading in customerID - see if it already exists
				if (totalCustomers.findCustomer(customerID))
				{
					// if it already exists, warn user and go back to customer menu
					cout << endl << "Custeromer ID already exists.\nPlease Re-";
				}
			} while (totalCustomers.findCustomer(customerID));

			// collect rest of customer information

			cout << "Enter customer name: ";
			// names are notorious for having spaces in them - must use getline
			cin.ignore();
			getline(cin, customername);
			do
			{
				// Need to get potential new customeremail
				cout << "Enter customer email: ";
				cin.clear();
				cin >> customeremail;
				// After reading in customeremail - check if it is valid

				// Establish a general email pattern
				// regex emailMatch("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$");
				// Check the input for the regex pattern
				// if (regex_match(customeremail, emailMatch))

				int i = customeremail.find('@', 1);
				if (//customeremail.find('@', 1) == true && // this line produced a Warning
					customeremail.find('@', 1) != string::npos && // If no matches were found, the function returns string::npos.
					customeremail.find('.', i + 1) != string::npos &&
					customeremail.back() != '.') //Making sure there is an "@" and a "." afterwards. Characters must follow.
				{
					emailCheck = false;
				}
				else
				{
					cout << "ERROR: Incorrect email address entered. \nPlease Re-";
					emailCheck = true;
				}
			} while (emailCheck);
			// build customer and add to customer
			// customerlist.addCustomer(Customer(----,-----,-----));
			tempCustomer = new CustomerType(customerID, customername, customeremail);
			totalCustomers.addCustomer(*tempCustomer);
			break;
		case 2:		// remove customer
					// you may want to display list of customerIDs so user can choose one
			cout << "Current customers:" << endl;
			cout << totalCustomers << endl;
			do
			{
				cout << "Enter customer ID you want to delete: ";
				cin >> customerID;
				if (totalCustomers.findCustomer(customerID)) {
					remCustomerCheck = false;
					totalCustomers.removeCustomer(totalCustomers.getCustomer(customerID));
				}
				else
				{
					cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
					remCustomerCheck = true;
				}
			} while (remCustomerCheck);
			// find customer object in customerlist returning iterator pointing to the customer object
			// if found
			//		use customer list remove method passing iterator
			// else
			//		message to user not found

			break;
		case 3:		// find customer returning iterator pointing to the customer
					// you may want to display list of customerIDs so user can choose one
			cout << "enter customer ID" << endl;
			cin >> customerID;
			// CustomerType& cust = custlist.getcustomer(customerID)
			break;
		case 4: // list customer information
			cout << "Current customers:" << endl;
			cout << totalCustomers << endl;
			break;
		case 5:  //order menu
			orderMenu();
			break;
		case 6: //inv menu
			break;
		case 7: //exit
			continueUi = false;
			break;
		default:
			cout << "Invalid option try again";
			break;
		}
	} while (continueUi);
}

void UI::orderMenu()
{
	int option;
	string custID;
	bool notValidCustomer;
	Order *tempOrder;

	cout << "Order Menu" <<
		"\n1) List Orders for Customer \n2) Over all orders for all customers \n3) Add order to customer" <<
		"\n4) Cancel order for a customer \n5) Update order for a customer \n";
	cin >> option;

	switch (option)
	{
	case 1:     // list orders for a customer
		cout << "Current customers:" << endl;
		cout << totalCustomers << endl;//customerListprint;
		do
		{
			cout << "Enter customer ID: "; 
			cin >> custID;
			if (totalCustomers.findCustomer(custID)) { // iterator = find customer
				notValidCustomer = false;
				cout << totalCustomers.getOrders(totalCustomers.getCustomer(custID)) << endl;
			}else {
				notValidCustomer = true;
				cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
			}
		} while (notValidCustomer);
		
		
		// if iterator not = customer list end
		//		(*iterator) invoke method printOrders()
		// else
		//		customerid not found
		break;
	case 2:     // list all orders for all customers
				// use for range loop to retrieve each customer
				//		for current customer invoke printOrders() method
				// end loop

		break;
	case 3:		// add an order for a customer
				//customerListprint;
		cout << "Current customers:" << endl;
		cout << totalCustomers << endl;//customerListprint;
		do
		{
			cout << "Enter customer ID: ";
			cin >> custID;
			if (totalCustomers.findCustomer(custID)) { // iterator = find customer
				notValidCustomer = false;
				tempOrder = new Order();
				addOrderData(*tempOrder);


void UI::orderMenu()
{
	int option;
	string custID;
	bool notValidCustomer;
	Order *tempOrder;
	bool stayInMenu = true;
	
	do
	{
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Order Menu" <<
				"\n1) List Orders for Customer \n2) Over all orders for all customers \n3) Add order to customer" <<
				"\n4) Cancel order for a customer \n5) Update order for a customer \n6) Go Back \n";
			cin >> option;

			if (!cin)
			{
				cout << endl;
				cout << "Invalid option entered. Please try again." << endl;
				cout << endl;
			}

		} while (!cin);
		

		switch (option)
		{
		case 1:     // list orders for a customer
			cout << "Current customers:" << endl;
			cout << totalCustomers << endl;//customerListprint;
			do
			{
				cout << "Enter customer ID: ";
				cin >> custID;
				if (totalCustomers.findCustomer(custID)) { // iterator = find customer
					notValidCustomer = false;
					cout << totalCustomers.getOrders(totalCustomers.getCustomer(custID)) << endl;
				}
				else {
					notValidCustomer = true;
					cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
				}
			} while (notValidCustomer);
			break;

		case 2:     // list all orders for all customers
			// use for range loop to retrieve each customer
			for (CustomerType customer : totalCustomers)
			{
				// for current customer invoke printOrders() method
				cout << customer.printOrders();
			}

			break;

		case 3:		// add an order for a customer
			//customerListprint;
			cout << "Current customers:" << endl;
			cout << totalCustomers << endl;
			do
			{
				cout << "Enter customer ID: ";
				cin >> custID;
				if (totalCustomers.findCustomer(custID)) { // iterator = find customer
					notValidCustomer = false;
					tempOrder = new Order();
					addOrderData(*tempOrder);
					totalCustomers.addOrder(totalCustomers.getCustomer(custID), *tempOrder);// - Get oder to pass in
				}
				else {
					notValidCustomer = true;
					cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
				}
			} while (notValidCustomer);
			break;

		case 4:		// cancel order
			//customerListprint;
			cout << "Current customers:" << endl;
			cout << totalCustomers << endl;
			do
			{
				cout << "Enter customer ID: ";
				cin >> custID;
				if (totalCustomers.findCustomer(custID)) { // iterator = find customer
					notValidCustomer = false;
					CustomerType customer = totalCustomers.getCustomer(custID);
					cout << "Orders for customer " << customer.getId() << " : "<< customer.getName() << endl;
					cout << customer.printOrders() << endl;
					bool invalidOrder = true;
					string orderID;
					do
					{
						cout << "Enter order number to cancel: ";
						cin >> orderID;
						if (customer.findOrder(orderID))
						{
							invalidOrder = false;
							customer.removeOrder(orderID);
							cout << "Order " << orderID << " removed from customers order list." << endl;
						}
						else
						{
							cout << "ERROR: Invalid order ID entered." << endl;
							cout << "Please Re-";
						}

					} while (true);
				}
				else {
					notValidCustomer = true;
					cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
				}
			} while (true);
			break;

		case 5:			// update order
						//	updateOrderMenu()
			break;
		case 6:
			stayInMenu = false;
			break;
		default:
			cout << "Invalid Option \"" << option << "\"" << endl;
			break;
		}

	} while (stayInMenu);
}

void UI::invMenu()
{
	//int option, custID;
	//cout << "Order Menu" <<
	//	"1) List all items in inventory" << endl <<
	//	"2) Display an item in inventory" << endl <<
	//	"3) Process order from supplier" << endl <<
	//	"4) Generate orders to the suppliers for a given month" << endl <<
	//	"5) Find the high demand items for a period of time - month, qtr, yr" << endl <<
	//	endl;
	//cin >> option;

	//switch (option)
	//{
	//case 1:     // list all items in inventory
	//		invlist.printInventory();
	//		break;
	//case 2:     // display an item in inventory
	//		ask user for itemid
	//		Stock& stk = invlist.findItem(itemid)
	//		stk.printStock()
	//		break;
	//case 3:		//process an order from a supplier
	//		prompt user for filename of order from a supplier
	//		establish an input file using filename from user
	//		check if file was able to open
	//		while more records
	//			read new item information - itemid, qty
	//			Stock& stk = invlist.findItem(itemid)
	//			if stk not emptystock
	//				stk.incrementQuantity(qty)
	//			else
	//				error message
	//			endif
	//		end while
	//		close file
	//		break;
	//case 4:		// Generate orders to the suppliers for a given month
	//		get month and year for order header
	//		vector<SupplierItem> supplist;
	//		for each stock in invlist
	//			if stock.getInStock() < stock.getReorderPoint()
	//				supplist.push_back(SupplierItem(stock.getSupplierID(),
	//						stock.getID(), stock.reorderAmount())
	//			endif
	//		next
	//		supplist.sort
	//		generate report with breaks at supplierID change
	//		break;			
	//case 5:		Find the high demand items for a period of time - month, qtr, yr
	//		vector<pair<string, int>> usage;
	//		get startdate and enddate
	//		for each cust in custlist
	//			for each ord in cust.ordlist
	//				verify that orderdate is between startdate and enddate
	//				if so,
	//					for each orditem in orditemlist
	//						string itdata = orditem.getItemID()
	//						auto& itemiter = find(usage.begin(), usage.end(), 
	//							[itdata](pair<string, int> listel)
	//								{return (listel.first() == itdata); }
	//						if itemiter != usage.end() 
	//							itemiter->second += orditem.getQuant();
	//						else
	//							usage.push_back(make_pair(orditem.getItemID(), orditem.getQuant())
	//						endif
	//					next
	//				endif
	//			next
	//		next
	//						
	//}
}

void UI::addOrderData(Order &newOrder)
{
	string ordId, ordDateString, delDateString, itemID, option;
	Date ordDate,delDate;
	int quantity;
	bool moreItems = true;
	orderItem *tempItem;
	cout << "\nEnter Order Id: ";
	// Validate Order ID here ???
	cin >> ordId;
	cout << "\nEnter Order Date Ex: 1/1/1990: ";
	cin >> ordDateString;
	ordDate = { ordDateString };
	cout << "\nEnter Delivery Date Ex: 1/1/1990: ";
	cin >> delDateString;
	delDate = { delDateString };
	Order tempOrder(ordId, ordDate, delDate);
	
	do
	{
		cout << "\nEnter Item Id: ";
		cin >> itemID;
		cout << "\nEnter quantity: ";
		cin >> quantity;
		tempItem = new orderItem(itemID, quantity);
		tempOrder.addOrderItem(*tempItem);
		cout << "\nEnter 'Finish' to finish adding items otherwise any charter to continue entering items: ";
		cin >> option;
		std::transform(option.begin(), option.end(), option.begin(), ::toupper);
		if (option == "FINISH")
			moreItems = false;
	} while (moreItems);
	newOrder = tempOrder;
}

//void UI::custMenu(int ID)
//{
//	string itemID, qnty;
//	Listinvertory;
//	cin >> itemID
//	if ()
//	{
//
//	}
//}

// addOrderData routine
//void UI::addOrderData(CustomerType& cust)
//      collect orderid, orderdate, deliverydate
//		create order object
//		while more orderitems
//			collect orderitem data - itemid, quantity
//			orderitem reference = ord.findOrderItem(itemid)
//			if orderitem refence != emptyorderitem,
//				orderitem reference.incrementQuantity(quantity)
//			else
//				orderitem neworditem = invlist.checkIfInStock(itemid, quantity)
//				ord.addOrderItem(neworderitem)
//			endif
//			ask if more orderitems
//		end while when no more order items
//		cust.addOrder(order object)
