#include <string>
#include <iostream>

#pragma once

using namespace std;

class orderItem
{
public:
	orderItem();
	~orderItem();
	bool operator==(orderItem& rhs);

private:
	string orderItemID;
};

