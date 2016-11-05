#include "Ui.h"

UI::UI()
{
	totalInventory.load(); // load stocks into inventory from file
}

UI::~UI()
{
	totalInventory.write(); // write stocks in inventory to file
}

void UI::mainMenu()
{ 
	bool loopMainMenu = true;
	do
	{
		int option;
		cout << string(3, '\n');

		bool verifyInput = false;
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
			addCustomer();
			// TODO: Add a cancel option to addCustomer()
			break;
		case 2:		// remove customer
			removeCustomer();
			// TODO: Add a cancel option to removeCustomer()
			break;
		case 3:		// find customer returning iterator pointing to the customer
					// you may want to display list of customerIDs so user can choose one
			editCustomer();
			// TODO: Finish the function???
			// TODO: Add a cancel option to editCustomer()
			break;
		case 4: // list customer information
			listCustomerInformation();
			break;
		case 5:  // order menu
			orderMenu();
			break;
		case 6: // inv menu
			invMenu();
			break;
		case 7: // exit
			loopMainMenu = false;
			break;
		default:
			cout << "Invalid option try again";
			break;
		}
	} while (loopMainMenu);
}

void UI::listCustomerInformation()
{
	cout << "Current customers:" << endl;
	cout << totalCustomers << endl;
}

void UI::addCustomer()
{
	string customerID, customerName, customerEmail;

	do
	{
		// Need to get potential new customerID
		cout << "Enter Customer ID: ";
		cin >> customerID;
		// after reading in customerID - see if it already exists
		if (totalCustomers.findCustomer(customerID))
		{
			// if it already exists, warn user and go back to customer menu
			cout << endl << "Customer ID already exists.\nPlease Re-";
		}
	} while (totalCustomers.findCustomer(customerID));

	// collect rest of customer information

	cout << "Enter customer name: ";
	// names are notorious for having spaces in them - must use getline
	cin.ignore();
	getline(cin, customerName);

	bool emailValidated;
	do
	{
		// Need to get potential new customeremail
		cout << "Enter customer email: ";
		cin.clear();
		cin >> customerEmail;
		// After reading in customeremail - check if it is valid

		// Establish a general email pattern
		// regex emailMatch("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$");
		// Check the input for the regex pattern
		// if (regex_match(customeremail, emailMatch))

		int i = customerEmail.find('@', 1);
		if (//customeremail.find('@', 1) == true && // this line produced a Warning
			customerEmail.find('@', 1) != string::npos && // If no matches were found, the function returns string::npos.
			customerEmail.find('.', i + 1) != string::npos &&
			customerEmail.back() != '.') //Making sure there is an "@" and a "." afterwards. Characters must follow.
		{
			emailValidated = true;
		}
		else
		{
			cout << endl << "ERROR: Incorrect email address entered. \nPlease Re-";
			emailValidated = false;
		}
	} while (!emailValidated);

	// build customer and add to customerList
	totalCustomers.addCustomer(CustomerType(customerID, customerName, customerEmail));
}

void UI::removeCustomer()
{
	string customerID;

	// you may want to display list of customerIDs so user can choose one
	listCustomerInformation();

	do
	{
		cout << "Enter customer ID you want to delete: ";
		cin >> customerID;
		if (totalCustomers.findCustomer(customerID))
		{
			totalCustomers.removeCustomer(totalCustomers.getCustomer(customerID));

			return;
		}

		cout << endl << "ERROR: Invalid customer ID entered. \nPlease Re-";

	} while (true);
}

void UI::editCustomer()
{
	string customerID;

	// TODO: Finish the function ???
	listCustomerInformation();

	do
	{

		cout << "Enter customer ID you want to edit: ";
		cin >> customerID;

		if (totalCustomers.findCustomer(customerID))
		{
			CustomerType & customer = totalCustomers.getCustomer(customerID);

			return;
		}

		cout << endl << "ERROR: Invalid customer ID entered. \nPlease Re-";

	} while (true);
}




void UI::orderMenu()
{
	int option;
	bool loopOrderMenu = true;
	
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
			listCustomersOrders();
			break;
		case 2:     // list all orders for all customers
			listAllOrders();
			break;
		case 3:		// add an order for a customer
			addOrder();
			break;
		case 4:		// cancel order
			cancelOrder();
			break;
		case 5:		// update order
			updateOrder();
			break;
		case 6:		// exit
			loopOrderMenu = false;
			break;
		default:
			cout << "Invalid Option \"" << option << "\"" << endl;
			break;
		}

	} while (loopOrderMenu);
}

void UI::listCustomersOrders()
{
	string custID;
	bool invalidCustomer = true;
	listCustomerInformation();

	do
	{
		cout << "Enter customer ID: ";
		cin >> custID;
		if (totalCustomers.findCustomer(custID)) { // iterator = find customer
			invalidCustomer = false;
			cout << totalCustomers.getOrders(totalCustomers.getCustomer(custID)) << endl;
		}
		else {
			cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
		}
	} while (invalidCustomer);
}

void UI::listAllOrders()
{
	// use for range loop to retrieve each customer
	for (CustomerType customer : totalCustomers)
	{
		// for current customer invoke printOrders() method
		cout << customer.printOrders();
	}
}

void UI::addOrder()
{
	string custID;
	bool invalidCustomer = true;
	listCustomerInformation();

	do
	{
		cout << "Enter customer ID: ";
		cin >> custID;
		if (totalCustomers.findCustomer(custID)) { // iterator = find customer
			invalidCustomer = false;
			Order *tempOrder = new Order();
			addOrderData(*tempOrder, custID);
			totalCustomers.addOrder(totalCustomers.getCustomer(custID), *tempOrder);// - Get oder to pass in
		}
		else {
			cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
		}
	} while (invalidCustomer);
}

void UI::cancelOrder() // Need to repopulate Inventory
{
	string custID;
	bool notValidCustomer;

	listCustomerInformation();

	do
	{
		cout << "Enter customer ID: ";
		cin >> custID;
		if (totalCustomers.findCustomer(custID)) { // iterator = find customer
			notValidCustomer = false;
			CustomerType customer = totalCustomers.getCustomer(custID);
			cout << "Orders for customer " << customer.getId() << " : " << customer.getName() << endl;
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
					totalCustomers.removeOrder(customer,orderID);
					cout << "Order " << orderID << " removed from customers order list." << endl;
				}
				else
				{
					invalidOrder = true;
					cout << "ERROR: Invalid order ID entered." << endl;
					cout << "Please Re-";
				}

			} while (invalidOrder);
		}
		else {
			notValidCustomer = true;
			cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
		}
	} while (notValidCustomer);
}

void UI::updateOrder()
{
	string custID;
	bool notValidCustomer;

	listCustomerInformation();

	do
	{
		cout << "Enter customer ID: ";
		cin >> custID;
		if (totalCustomers.findCustomer(custID)) { // iterator = find customer
			notValidCustomer = false;
			CustomerType customer = totalCustomers.getCustomer(custID);
			cout << "Orders for customer " << customer.getId() << " : " << customer.getName() << endl;
			cout << customer.printOrders() << endl;
			bool invalidOrder = true;
			string orderID;
			Order *tempOrder = new Order();
			do
			{
				cout << "Enter order number to Update: ";
				cin >> orderID;
				if (customer.findOrder(orderID))
				{
					invalidOrder = false;
					*tempOrder = customer.getOrder(orderID);
					updateOrderData(*tempOrder);
					cout << "Order " << orderID << " Updated." << endl;
				}
				else
				{
					invalidOrder = true;
					cout << "ERROR: Invalid order ID entered." << endl;
					cout << "Please Re-";
				}

			} while (invalidOrder);
		}
		else {
			notValidCustomer = true;
			cout << "ERROR: Invalid customer ID entered. \nPlease Re-";
		}
	} while (notValidCustomer);
}




void UI::invMenu()
{
	int option;
	bool stayInMenu = true;
	do
	{
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Inventory Menu" << endl;
			cout << "1) List all items in inventory" << endl;
			cout << "2) Display an item in inventory" << endl;
			cout << "3) Process order from supplier" << endl;
			cout << "4) Generate orders to the suppliers for a given month" << endl;
			cout << "5) Find the high demand items for a period of time - month, qtr, yr" << endl;
			cout << "6) Exit" << endl;
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
		case 1:     // list all items in inventory
			listInventory();
			break;
		case 2:     // display an item in inventory
			displayItem();
			break;
		case 3:		//process an order from a supplier
			processOrder();
			// TODO: 2 versions of this function exist. Pick one and make sure it works as intended.
			break;
		case 4:		// Generate orders to the suppliers for a given month
			generateOrdersReport();
			break;
		case 5:		//Find the high demand items for a period of time - month, qtr, yr
			generateInventoryReport();
			// TODO: Entire function needed
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

void UI::listInventory()
{
	system("CLS");
	cout << "All Items in Inventory: " << endl;
	cout << totalInventory << endl;
}

void UI::displayItem()
{
	bool invalidItem = true;
	string itemID;

	listInventory();

	do
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//	ask user for itemid
		cout << "Enter the id of the item you would to display: ";
		cin >> itemID;
		if (totalInventory.itemExists(itemID))
		{
			invalidItem = false;
			Stock& itemStock = totalInventory.findItem(itemID);
			cout << itemStock << endl;
		}
		else
		{
			cout << "ERROR: Invalid item ID entered." << endl;
			cout << "Please Re-";
		}
	} while (invalidItem);
}

void UI::generateOrdersReport()
{
	string month, year;

	//get month and year for order header
	cout << "Orders for a month Procedure" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "What is the month for the Order Header?" << endl;
	getline(cin, month);
	cout << "What is the Year for the order header?" << endl;
	getline(cin, year);

	vector<SupplierItem> supplist;
	list<string> suppMas;

	// for each stock in invlis, add to reorder list if needed.
	for (Stock stockItem : totalInventory.stocks)
	{
		if (stockItem.getInStock() < stockItem.getReorderPoint())
		{
			suppMas.push_back(stockItem.getSupplierID());
			supplist.push_back(SupplierItem(stockItem.getSupplierID(), stockItem.getID(), stockItem.getReorderAmount()));
		}
	}

	// Display reorder list
	for (SupplierItem supplierItem : supplist)
	{

		cout << supplierItem.getiID() << "|" << supplierItem.getAmount() << endl;
	}
	
	// Remove duplicates and sort
	suppMas.unique();
	sort(supplist.begin(), supplist.end());

	for (string suppMasObject : suppMas)
	{
		stringstream filename;

		filename << suppMasObject << month << "-" << year << ".txt";

		ofstream outData(filename.str().c_str());
		if (!outData)
		{
			cout << "File " << filename.str() << " not created." << endl;
		}
		else
		{
			outData << "Supplier " << suppMasObject << " Order: " << month << "/" << year << endl;
			for (SupplierItem suppListObject : supplist)
			{
				if (suppListObject.getSupp() == suppMasObject)
				{
					outData << suppListObject.getiID() << "|" << suppListObject.getAmount() << endl;
				}
			}

			outData.close();

			cout << "File " << filename.str() << " created" << endl;

			ofstream upD("fileList.txt", ios::app);
			if (!upD)
			{
				cout << "fileList.txt not found." << endl;
			}
			else
			{
				upD << filename.str() << endl;
			}

			upD.close();
		}
		cout << "Processing Complete" << endl;
	}
}

void UI::processOrder()
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
}


	void UI::generateInventoryReport()
{
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
}

void UI::addOrderData(Order &newOrder, string custID)
{
	string ordId, ordDateString, delDateString, itemID, option;
	Date ordDate,delDate;
	bool moreItems = true, invadOrderId = false, invadItem= false;
	
	cout << endl;
	do
	{
		cout << "Enter Order Id: ";
		cin >> ordId;

		if (totalCustomers.findOrder((totalCustomers.getCustomer(custID)), ordId)) {
			invadOrderId = true;
			cout << "ERROR: Invalid item ID entered." << endl;
			cout << "Please Re-";
		}else{
			invadOrderId = false;			
		}
	} while (invadOrderId);
	cout << "\nEnter Order Date Ex: 1/1/1990: ";
	cin >> ordDateString;
	ordDate = { ordDateString };
	cout << "\nEnter Delivery Date Ex: 1/1/1990: ";
	cin >> delDateString;
	delDate = { delDateString };
	Order tempOrder(ordId, ordDate, delDate);	
	updateOrderData(tempOrder);
	newOrder = tempOrder;
}

void UI::updateOrderData(Order & order)
{
	bool stayInMenu = true, invadItem = false, moreItems = true;
	int menuOption, quantity;
	string itemID, option;
	orderItem *tempItem;
	system("CLS");

	cout << "\n\n" << order.printOrder();
	
	do
	{
		cout << "\n1) Update quantity of item"
		<< "\n2) Remove Item"
		<< "\n3) Add Item"
		<< "\n4) View current order"
		<< "\n5) Finished editing order\n";

		cout << "Enter option: ";
		cin >> menuOption;
		switch (menuOption)
		{
		case 1:

			break;
		case 2:
			do
			{
				do
				{
					cout << "\n" << order.printOrder();
					if (invadItem)
					{
						cout << "ERROR: Invalid item ID entered." << endl;
						cout << "Please Re-";
					}
					cout << "Enter Item Id: ";
					cin >> itemID;
					if (order.itemInOrder(itemID)) {
						invadItem = false;
					}
					else {
						invadItem = true;
					}
				} while (invadItem);
				orderItem *tempOrderItem = new orderItem;
				*tempOrderItem = order.getItem(itemID);
				totalInventory.addStock(itemID, tempOrderItem->getQuant());
				order.removeOrderItem(*tempOrderItem);
				delete tempOrderItem;
				cout << "\nEnter 'Finish' to finish adding items otherwise any charter to continue entering items: ";
				cin >> option;
				std::transform(option.begin(), option.end(), option.begin(), ::toupper);
				if (option == "FINISH")
					moreItems = false;
			} while (moreItems);
			break;
		case 3:
			do
			{
				do
				{
					listInventory();
					if (invadItem)
					{
						cout << "ERROR: Invalid item ID entered." << endl;
						cout << "Please Re-";
					}
					cout << "Enter Item Id: ";
					cin >> itemID;
					cout << "\nEnter quantity: ";
					cin >> quantity;
					if (totalInventory.itemInStock(itemID, quantity)) {
						invadItem = false;
					}
					else {
						invadItem = true;
					}
				} while (invadItem);
				totalInventory.removeStock(itemID, quantity);
				tempItem = new orderItem(itemID, (totalInventory.getItemDescription(itemID)), quantity, (totalInventory.getItemPrice(itemID)));
				order.addOrderItem(*tempItem);
				cout << "\nEnter 'Finish' to finish adding items otherwise any charter to continue entering items: ";
				cin >> option;
				std::transform(option.begin(), option.end(), option.begin(), ::toupper);
				if (option == "FINISH")
					moreItems = false;
			} while (moreItems);
			break;
		case 4:
			cout << "\n" << order.printOrder();
			break;
		case 5:
			stayInMenu = false;
			break;
		default:
			cout << "ERROR: Invalid item option entered." << endl;
						break;
		}
	} while (stayInMenu);

}





// system("CLS");