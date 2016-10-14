#include "Ui.h"


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
	int option;
	string customername, customeremail, customerID;
	bool emailCheck;
	CustomerType *tempCustomer;
	cout << "main menu" << "1)add customer" << "2) remove coustomer"
		<< "3)find customer" << "4) list customer information" << "5) Order menu" << "6) Inventory menu" << endl;
	cin >> option;
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

		cout << "enter customer name" << endl;
		// names are notorious for having spaces in them - must use getline
		cin.clear(); // .clear() might be needed
		getline(cin, customername, '\n');
		do
		{
			// Need to get potential new customeremail
			cout << "Enter customer email: " << endl;
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
		cout << "enter customer ID" << endl;
		cin >> customerID;
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
		// case 5:  order menu
		// orderMenu()
	default:
		break;
	}
}

void UI::orderMenu()
{
	int option, custID;
	cout << "Order Menu" <<
		"1) List Orders for Customer" << endl <<
		"2) Over all orders for all customers" << endl <<
		"3) Add order to customer" << endl <<
		"4) Cancel order for a customer" << endl <<
		"5) Update order for a customer" << endl <<
		endl;
	cin >> option;

	switch (option)
	{
	case 1:     // list orders for a customer
		cout << "Enter customer ID: ";
		//customerListprint;
		cin >> custID;
		//custMenu(custID);???
		// iterator = find customer
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
		cin >> custID;
		// Customer& cust = custlist.getcustomer(custID)
		// if cust != emptyCustomer
		//		invoke addOrderData(cust)
		// else
		//		customerid not found
	case 4:		// cancel order
				//customerListprint;
		cin >> custID;
		// Customer& cust = custlist.getcustomer(custID)
		// if cust != emptyCustomer
		//		get orderid and canceldate
		//		if (*iterator).findOrder(orderid) is true
		//			(*iterator).removeOrder(orderid)
		//		else
		//			error message
		//		endif	
		// else
		//		customerid not found
	case 5:			// update order
					//	updateOrderMenu()
	default:
		break;
	}

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
