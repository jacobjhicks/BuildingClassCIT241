#include "CustomerListType.h"

using namespace std;

CustomerListType::CustomerListType()
{
	vector<string> input;
	ifstream inDat("CustData.txt");
	bool notFirstOrder = false;
	if (!inDat)
	{
		cout << "CustData.txt Not Found" << endl;
	}
	else
	{
		while (!inDat.eof())
		{
			string a;
			getline(inDat, a, '\n');
			input.push_back(a);
		}
	}
	inDat.close();

	CustomerType CustHolder;
	Order OrderHolder;

	for (auto b = input.begin(); b != input.end(); ++b)
	{
		string j;
		istringstream iss{ *b };
		getline(iss, j, '|');

		

		if (j == "C")
		{
			CustHolder.addOrder(OrderHolder);
			customers.push_back(CustHolder);
			notFirstOrder = false;
			string f, g, h;
			getline(iss, f, '|');
			getline(iss, g, '|');
			getline(iss, h, '|');
			CustomerType hold(f, g, h);
			CustHolder = hold;
		}
		if (j == "O")
		{
			if (notFirstOrder) {
				CustHolder.addOrder(OrderHolder);
			}
			notFirstOrder = true;
			string f, g, h;
			if (OrderHolder.getOrderID() == "")
			{
			}
			else
			{
				//CustHolder.addOrder(OrderHolder);
			}
			getline(iss, f, '|');
			getline(iss, g, '|');
			getline(iss, h, '|');
			Date y(g);
			Date z(h);
			Order hold(f, y, z);
			OrderHolder = hold;
		}
		if (j == "I")
		{
			string f, g, i, k;
			int y;
			double z;

			getline(iss, f, '|');
			getline(iss, g, '|');
			getline(iss, i, '|');
			getline(iss, k, '|');

			try
			{
				y = stoi(i);
				z = stod(k);
			}
			catch (exception)
			{
				system("CLS");
				cerr << "Error: Exception " << current_exception << " thrown." << endl
					<< "Invalid input for OrderItem object." << endl
					<< "Exiting Program" << endl;
				system("pause");
				exit(1);
			}
			orderItem hold(f, g, y, z);
			OrderHolder.addOrderItem(hold);
		}
	}

	CustHolder.addOrder(OrderHolder);
	customers.push_back(CustHolder);
}


CustomerListType::~CustomerListType()
{

}

void CustomerListType::addCustomer(const CustomerType customer)
{
	customers.push_back(customer);
}

// Not needed?
//list<CustomerType>::iterator CustomerListType::findCustomerObject(const string & custId)
//{
//	list<CustomerType>::iterator found = find_if(customers.begin(), customers.end(), [&custId](CustomerType customer) {
//		return customer.getId() == custId;
//	});
//
//	if (found != customers.end())
//		return found;
//	throw exception("Customer not found.");
//}

/**
* Returns the CustomerType object with the given ID from the list of customers.
* Throws an error if the custId is not found
*/
CustomerType & CustomerListType::getCustomer(const string & custId)
{
	auto found = find_if(customers.begin(), customers.end(), [&custId](CustomerType customer) {
		return customer.getId() == custId;
	});

	if (found != customers.end())
		return *found;
	throw exception("Customer not found.");
}

/**
* Returns true if a customer with the given ID is found.
*/
bool CustomerListType::findCustomer(const string & custId)
{
	auto found = find_if(customers.begin(), customers.end(), [&custId](CustomerType customer) {
		return customer.getId() == custId;
	});

	return found != customers.end();
}

void CustomerListType::removeCustomer( CustomerType customer)
{
	//customers.remove(*customer);
	list<CustomerType>::iterator rmIt;
	for (rmIt = customers.begin(); rmIt != customers.end(); ++rmIt)
	{
		if (customer == *rmIt)
		{
			customers.erase(rmIt);
			break;
		}
	}
}

string CustomerListType::getOrders(CustomerType customer)
{
	list<CustomerType>::iterator rmIt;
	string out;
	for (rmIt = customers.begin(); rmIt != customers.end(); ++rmIt)
	{
		if (customer == *rmIt)
		{
			out = rmIt->printOrders();
			break;
		}					
	}
	return out;
}

void CustomerListType::addOrder(CustomerType customer, const Order & order)
{
	list<CustomerType>::iterator rmIt;
	for (rmIt = customers.begin(); rmIt != customers.end(); ++rmIt)
	{
		if (customer == *rmIt)
		{
			rmIt->addOrder(order);
			break;
		}
	}
}

/**
* Returns an iterator to the first customer.
*/
list<CustomerType>::iterator CustomerListType::begin()
{

	return customers.begin();
}

/**
* Returns an iterator just past the last customer
*/
list<CustomerType>::iterator CustomerListType::end()
{

	return customers.end();
}

/**
 * Returns a string object detailing each customer.
 * Example:
 * "CustId      Name                              Email                             "
 * "--------------------------------------------------------------------------------"
 * "OK123       Full Name                         EmailAddress@example.com          "
 * "...                                                                             "
 */
string CustomerListType::print()
{
	stringstream out;

	out << left << setw(12) << "CustId";
	out << left << setw(34) << "Name";
	out << left << setw(34) << "Email";
	out << endl;
	out << left << setfill('-') << setw(80) << "" << endl;
	for_each(customers.begin(), customers.end(), [&out](CustomerType customer) {
		out << customer << endl;
	});

	return out.str();
}

/**
* Prints the details of each customer.
* Example:
* "CustId      Name                              Email                             "
* "--------------------------------------------------------------------------------"
* "OK123       Full Name                         EmailAddress@example.com          "
* "...                                                                             "
*/
ostream & operator<<(ostream & out, CustomerListType & rightConstmerList)
{
	for (CustomerType customer : rightConstmerList.customers)
	{
		out << customer << endl;
	}

	return out;
}
