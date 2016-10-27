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
			/*cout << "enter customer ID" << endl;
			cin >> customerID;*/
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

void UI::invMenu()
{
	char option;
	bool run, reuse;
	run = true;
	reuse = false;

	while (run == true)
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

		cout << "Order Menu" << endl <<
			"1) List all items in inventory" << endl <<
			"2) Display an item in inventory" << endl <<
			"3) Process order from supplier" << endl <<
			"4) Generate orders to the suppliers for a given month" << endl <<
			"5) Find the high demand items for a period of time - month, qtr, yr" << endl <<
			"6). Go Back" << endl;

		cin >> option;

		switch (option)
		{
		case '1':     // list all items in inventory
		{
			system("CLS");
			cout << "All Items in Inventory: " << endl;
			cout << totalInventory << endl;
			break;
		}
		case '2':     // display an item in inventory
		{
			system("CLS");
			std::string idIn;
			cout << "Display Inventory Item Procedure" << endl;
			cout << "What is the itemID of the Item you're looking for?" << endl;
			cin >> idIn;
			Stock& stk = totalInventory.findItem(idIn);
			Stock hold;
			if (stk == hold)
			{
				cout << "ItemID Not found. Item " << idIn << " not in Inventory." << endl;
			}
			else
			{
				system("CLS");

				cout << "Item Found: " << stk << endl;
			}
			break;
		}
		case '3':		//process an order from a supplier
		{
			cout << "Process Supplier Order" << endl;
			//prompt user for filename of order from a supplier
			//establish an input file using filename from user
			ifstream FL("fileList.txt");
			if (!FL)
			{
				cout << "fileList.txt not found" << endl;
			}
			else
			{
				while (!FL.eof())
				{
					string a;
					getline(FL, a, '\n');
					cout << a << endl;
				}
			}
			FL.close();
			string file, a;
			ifstream inDat;
			cout << "Please enter the Supplier file name" << endl;
			cin.ignore(10000, '\n');
			getline(cin, file);
			//check if file was able to open
			inDat.open(file);
			if (!inDat)
			{
				cout << "Unable to open file " << file << ". File not found." << endl;
			}
			else
			{
				cout << "Processing File" << endl;
				getline(inDat, a, '\n');
				while (!inDat.eof())
				{
					string itemID, qtyStr;
					int qty;
					getline(inDat, itemID, '|');
					getline(inDat, qtyStr, '\n');
					if (qtyStr == "")
					{
					}
					else
					{
						try
						{
							qty = stoi(qtyStr);
						}
						catch (exception)
						{
							system("CLS");
							cerr << "Load Error: Exception " << current_exception << " thrown." << endl
								<< "Invalid Quantity input from " << file << " file" << endl
								<< "Exiting Program" << endl;
							system("pause");
							exit(1);
						}
					}
					Stock test;
					Stock& stk = totalInventory.findItem(itemID);
					if (stk == test)
					{
						system("CLS");
						cerr << "Load Error: Exception " << current_exception << " thrown." << endl
							<< "Invalid ItemID input from " << file << " file" << endl
							<< "Exiting Program" << endl;
						system("pause");
						exit(1);
					}
					else
					{

						stk.incrementQuantity(qty);
					}
				}
				cout << "File Processed" << endl;
				inDat.close();
			}
			//while more records
			//	read new item information - itemid, qty
			//	Stock& stk = invlist.findItem(itemid)
			//	if stk not emptystock
			//		stk.incrementQuantity(qty)
			//	else
			//		error message
			//		endif
			//		end while
			//		close file*/
			break;
		}

		case '4':		// Generate orders to the suppliers for a given month
		{
			cout << "Orders for a month Procedure" << endl;
			string a, b, y;
			cin.ignore(10000, '\n');
			cout << "What is the month for the Order Header?" << endl;
			getline(cin, a);
			cout << "What is the Year for the order header?" << endl;
			getline(cin, b);
			//get month and year for order header
			//vector<SupplierItem> supplist;
			vector<SupplierItem> supplist;
			list<string> suppMas;

			for (auto c = totalInventory.stocks.begin(); c != totalInventory.stocks.end(); ++c)
			{
				if ((*c).getInStock() < (*c).getReorderPoint())
				{
					suppMas.push_back((*c).getSupplierID());
					supplist.push_back(SupplierItem((*c).getSupplierID(), (*c).getID(), (*c).getReorderAmount()));
				}
			}



			for (auto j = supplist.begin(); j != supplist.end(); ++j)
			{

				cout << (*j).getiID() << "|" << (*j).getAmount() << endl;
			}

			suppMas.unique();
			sort(supplist.begin(), supplist.end());

			for (auto u = suppMas.begin(); u != suppMas.end(); ++u)
			{
				stringstream filename;
				filename << *u << a << "-" << b << ".txt";
				y = filename.str();
				ofstream outData(y.c_str());
				if (!outData)
				{
					cout << "File " << filename.str() << " not created." << endl;
				}
				else
				{
					outData << "Supplier " << *u << " Order: " << a << "/" << b << endl;
					for (auto d = supplist.begin(); d != supplist.end(); ++d)
					{
						if ((*d).getSupp() == *u)
						{
							outData << (*d).getiID() << "|" << (*d).getAmount() << endl;
						}
					}
					outData.close();
					cout << "File " << y << " created" << endl;
					ofstream upD("fileList.txt", ios::app);
					if (!upD)
					{
						cout << "fileList.txt not found." << endl;
					}
					else
					{
						upD << y << endl;
					}
					upD.close();
					/*for each stock in invlist
					if stock.getInStock() < stock.getReorderPoint()
					supplist.push_back(SupplierItem(stock.getSupplierID(),
					stock.getID(), stock.reorderAmount())
					endif
					next
					supplist.sort
					generate report with breaks at supplierID change*/
				}
			}
			cout << "Processing Complete" << endl;
			break;
		}
		case '5':		//Find the high demand items for a period of time - month, qtr, yr
			cout << "Find High demand Items procedure" << endl;
			/*vector<pair<string, int>> usage;
			get startdate and enddate
			for each cust in custlist
			for each ord in cust.ordlist
			verify that orderdate is between startdate and enddate
			if so,
			for each orditem in orditemlist
			string itdata = orditem.getItemID()
			auto& itemiter = find(usage.begin(), usage.end(),
			[itdata](pair<string, int> listel)
			{return (listel.first() == itdata); }
			if itemiter != usage.end()
			itemiter->second += orditem.getQuant();
			else
			usage.push_back(make_pair(orditem.getItemID(), orditem.getQuant())
			endif
			next
			endif
			next
			next*/
			break;
		case '6':
			run = false;
			cout << "Exiting back to top" << endl;
			break;
		default:
			cout << "Input not recognized. Please try again." << endl;
			break;
		}
	}
}
//void UI::addOrderData(Order &newOrder)
//{
//	string ordId, ordDateString, delDateString, itemID, option;
//	Date ordDate,delDate;
//	int quantity;
//	bool moreItems = true;
//	orderItem *tempItem;
//	cout << "\nEnter Order Id: ";
//	// Validate Order ID here ???
//	cin >> ordId;
//	cout << "\nEnter Order Date Ex: 1/1/1990: ";
//	cin >> ordDateString;
//	ordDate = { ordDateString };
//	cout << "\nEnter Delivery Date Ex: 1/1/1990: ";
//	cin >> delDateString;
//	delDate = { delDateString };
//	Order tempOrder(ordId, ordDate, delDate);
//	
//	do
//	{
//		cout << "\nEnter Item Id: ";
//		cin >> itemID;
//		cout << "\nEnter quantity: ";
//		cin >> quantity;
//		tempItem = new orderItem(itemID, quantity);
//		tempOrder.addOrderItem(*tempItem);
//		cout << "\nEnter 'Finish' to finish adding items otherwise any charter to continue entering items: ";
//		cin >> option;
//		std::transform(option.begin(), option.end(), option.begin(), ::toupper);
//		if (option == "FINISH")
//			moreItems = false;
//	} while (moreItems);
//	newOrder = tempOrder;
//}

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
