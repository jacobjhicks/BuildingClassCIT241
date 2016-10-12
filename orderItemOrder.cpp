#include "orderItem.h"


orderItem::orderItem()
{
}


orderItem::~orderItem()
{
}

bool orderItem::operator==(orderItem &rhs)
{
	if (rhs.orderItemID == this->orderItemID)
		return true;
	else
		return false;
}
