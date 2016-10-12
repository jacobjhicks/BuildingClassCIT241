#include "Date.h"
#include <array>
#include <sstream>

const array<short, 13> daysInMonthTable{ { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
Date::Date(short inmon, short inday, short inyr) {
	string potmsg;
	potmsg = isValidDate(inmon, inday, inyr);
	if (potmsg.size() != 0) {
		throw exception(potmsg.c_str());
	}
	mMon = inmon;
	mDay = inday;
	mYear = inyr;
}

Date::Date(string indate) {
	istringstream instr{ indate };
	short extmon, extday, extyr;
	char ch;
	instr >> extmon >> ch >> extday >> ch >> extyr;
	string potmsg = isValidDate(extmon, extday, extyr);
	if (potmsg.size() != 0) {
		throw exception(potmsg.c_str());
	}
	mMon = extmon;
	mDay = extday;
	mYear = extyr;
}

string Date::dateString() const {
	ostringstream outstr;
	outstr << mMon << "/" << mDay << "/" << mYear;
	return outstr.str();
}

bool Date::isLeapYear(short inyr) const {
	if ((inyr % 4 == 0 && inyr % 100 != 0) || inyr % 400 == 0)
		return true;
	return false;
}

string Date::isValidDate(short inmon, short inday, short inyear) const {
	ostringstream outstr;
	if (isLeapYear(inyear) == true) {
		if (inmon == 2) {
			if (inday >= 1 && inday <= 29)
				return "";
		}
	}
	if (inyear < 1900 || inyear > 9999)
		return "Year must be between 1900 and 9999";
	if (inmon < 1 || inmon > 12)
		return "Month must be between 1 and 12";
	short maxday = daysInMonthTable[inmon];
	if (inday < 1 || inday > maxday) {
		outstr << "Day must be between 1 and " << maxday << " for month " << inmon;
		return outstr.str();
	}
	return "";
}

Date Date::increment(string dateunit, short incr) const {
	// verify each dateunit
	if (dateunit == "years") {
		if (incr < -2 || incr > 2) {
			throw exception("Years must be within -2 and 2");
		}
		else {
			return (Date(mMon, mDay, mYear + incr));
		}
	}
	else {
		array<short, 13> DayMonTab = daysInMonthTable;
		if (dateunit == "months") {
			short adjyr, adjmon, adjDay;
			if (incr < -24 || incr > 24) {
				throw exception("Months must be within -24 and 24");
			}
			else {
				adjDay = mDay;
				short tempmon = mMon + incr;
				adjmon = tempmon % 12;
				if (adjmon == 0)
					adjmon = 12;
				adjyr = tempmon / 12 - ((tempmon < 0) ? 1 : 0) + mYear;
				DayMonTab[2] = (isLeapYear(adjyr)) ? 29 : 28;
				if (adjDay > DayMonTab[adjmon]) {
					adjDay = DayMonTab[adjmon];
				}
			}
			return (Date(adjmon, adjDay, adjyr));
		}
		else if (dateunit == "days") {
			// first verify correct 2 year range
			if (incr < -730 || incr > 730) {
				throw exception("Days must be within -730 and 730");
			}
			Date retDate{ *this };
			short incrDays;
			DayMonTab[2] = (isLeapYear(retDate.Year())) ? 29 : 28;
			if (incr >= 0) {
				incrDays = incr;
				while (incrDays > 0) {
					incrDays--; retDate.mDay++;
					if (retDate.mDay > DayMonTab[retDate.mMon]) {
						retDate.mDay = 1;
						if (++retDate.mMon > 12) {
							retDate.mMon = 1;
							DayMonTab[2] = (isLeapYear(++retDate.mYear)) ? 29 : 28;
						}
					}
				}
			}
			else {

				incrDays = -incr;
				while (incrDays > 0) {
					incrDays--; retDate.mDay--;
					if (retDate.mDay < 1) {
						if (--retDate.mMon < 1) {
							retDate.mMon = 12;
							DayMonTab[2] = (isLeapYear(--retDate.mYear)) ? 29 : 28;
						}
						retDate.mDay = DayMonTab[retDate.mMon];
					}
				}
			}
			return retDate;
		}
	}
}

short Date::difference(string dateunit, const Date& rightside) const {
	Date lowdate, hidate;
	short retval{ 0 };
	short sign = 1;
	if (*this < rightside) {
		lowdate = *this;
		hidate = rightside;
	}
	else {
		lowdate = rightside;
		hidate = *this;
		sign = -1;
	}
	if (dateunit == "years") {
		do {
			lowdate.increment("years", 1);
			if (lowdate <= hidate)
				++retval;
		} while (lowdate < hidate);
	}
	else if (dateunit == "months") {
		do {
			lowdate.increment("months", 1);
			if (lowdate <= hidate)
				++retval;
		} while (lowdate < hidate);
	}
	else if (dateunit == "days") {
		do {
			lowdate.increment("days", 1);
			if (lowdate <= hidate)
				++retval;
		} while (lowdate < hidate);
	}
	else {
		throw exception("Incorrect units requested for date difference");
	}
	return retval * sign;
}

bool operator<(const Date& left, const Date& right) {
	if (left.Year() < right.Year())
		return true;
	if (left.Year() == right.Year() && left.Mon() < right.Mon())
		return true;
	if (left.Year() == right.Year() && left.Mon() == right.Mon() && left.Day() < right.Day())
		return true;
	return false;
}

bool operator>(const Date& left, const Date& right) {
	return right < left;
}

bool operator==(const Date& left, const Date& right) {
	return !(left < right || right < left);
}

bool operator<=(const Date& left, const Date& right) {
	return left < right || left == right;
}

bool operator>=(const Date& left, const Date& right) {
	return left > right || left == right;
}

bool operator!=(const Date& left, const Date& right) {
	return !(left == right);
}