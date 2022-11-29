#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

#include "Clock.h"

// takes a string of char numbers from a certain place, and returns the number
int stringToNumber(char* str, int start, int end)
{
	int res = 0;
	for (int i = start; i <= end; i++)
	{
		res *= 10;
		res += (str[i] - '0');
	}

	return res;
}

// returns current date and hour
const std::string currentDateTime(Clock* clock)
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d-%m-%Y : %X", &tstruct);

	clock->_day = stringToNumber(buf, 0, 1);
	clock->_month = stringToNumber(buf, 3, 4);
	clock->_year = stringToNumber(buf, 6, 9);
	clock->_hours = tstruct.tm_hour;
	clock->_minutes = tstruct.tm_min;
	clock->_seconds = tstruct.tm_sec;

	return buf;
}

Clock::Clock()
{
	_hours = 0;
	_minutes = 0;
	_seconds = 0;
	_day = 0;
	_month = 0;
	_year = 0;

	currentDateTime(this);
}

// to enter date manually
Clock::Clock(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;

	// in birthday the hour is not important
	_hours = 0;
	_minutes = 0;
	_seconds = 0;
}

void Clock::displayDate()
{
	cout << _day << "." << _month << "." << _year << endl;
}

void Clock::displayTime()
{
	cout << _hours << ":" << _minutes << ":" << _seconds << endl;
}

Clock Clock::getBirthdayInput()
{
	int d, m, y;

	cout << "Please enter date of birth: ";
	cout << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year:";
	cin >> y;

	Clock res(d, m, y);

	return res;
}

