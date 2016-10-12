#pragma once
#ifndef Date_h
#define Date_h
#include <time.h>

#include <string>
using namespace std;

class Date {
private:
	short mMon;
	short mDay;
	short mYear;
	bool isLeapYear(short inyear) const;
	string isValidDate(short inmon, short inday, short inyear) const;		// empty string means valid date value
public:
	Date(short inmon = 1, short inday = 1, short inyr = 1900);
	Date(string indate);
	Date(time_t timevalue);
	~Date() {}
	Date increment(string dateunit, short incr) const;
	short difference(string dateunit, const Date& rightside) const;
	string dateString() const;
	// accessors
	short Mon() const { return mMon; }
	short Day() const { return mDay; }
	short Year() const { return mYear; }
};

bool operator<(const Date& leftDate, const Date& rightDate);
bool operator>(const Date& leftDate, const Date& rightDate);
bool operator>=(const Date& leftDate, const Date& rightDate);
bool operator<=(const Date& leftDate, const Date& rightDate);
bool operator==(const Date& leftDate, const Date& rightDate);
bool operator!=(const Date& leftDate, const Date& rightDate);

#endif
