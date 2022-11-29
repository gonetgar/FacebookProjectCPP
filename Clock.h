#ifndef __CLOCK_H
#define __CLOCK_H
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <ctime>  
#include <string.h>

class Clock
{
public:
	int _day;
	int _month;
	int _year;
	int _hours;
	int _minutes;
	int _seconds;

public:
	Clock();
	Clock(int day, int month, int year); // to enter date manually (like in birthday)
	void displayDate(); 
	void displayTime();
	Clock getBirthdayInput();
};

#endif // __CLOCK_H
