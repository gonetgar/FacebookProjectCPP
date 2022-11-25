#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
#include "Status.h"

int stringToNumber(char* str, int start, int end)
{
	int res = 0;
	for (int i = start ; i <= end ; i++)
	{
		res *= 10;
		res += (str[i] - '0');
	}

	return res;
}

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

////////////////////////////////////

Status::Status()
{
	_text = new char[MAX_CHARACTERS];
	_date = Date(1, 1, 2022);
	_time = Clock();
}

Status::Status(char* text, Date date, Clock time)
{
	_text = text;
	_date = date;
	_time = time;
}

// returns Status* ?
Status* Status::createStatus()
{
	Status* newStatus;
	newStatus = new Status[MAX_CHARACTERS];

	cout << "Please insert your status: ";
	cin.getline(newStatus->_text, MAX_CHARACTERS);	//TODO shrink

	//// for debugging: ////

	cout << "\nyou entered: ";
	cout << newStatus->_text;
	cout << "\non date: ";
	cout << setw(2) << setfill('0') << newStatus->_time._day << ".";
	cout << setw(2) << setfill('0') << newStatus->_time._month << ".";
	cout << setw(2) << setfill('0') << newStatus->_time._year;
	cout << "\non time: ";
	cout << setw(2) << setfill('0') << newStatus->_time._hours << ":";
	cout << setw(2) << setfill('0') << newStatus->_time._minutes << ":";
	cout << setw(2) << setfill('0') << newStatus->_time._seconds;

	return newStatus;
}
