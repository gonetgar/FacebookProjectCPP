#ifndef __STATUS_H
#define __STATUS_H

#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <ctime>  
#include <string.h>
const int MAX_CHARACTERS = 256;
#include "Date.h"

// only relevant for Status class
// but can be moved to class Date
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
	Clock(int hours, int minutes, int seconds) = delete; // we dont want users to insert time on their own
};

class Status
{
public:
	char* _text;
	Date _date;
	Clock _time;

	Status();
	Status(char* text, Date date, Clock time);

	Status* createStatus(); // maybe it will be in here and inside the user/page we'll add it to his list of statuses.

	// d'tor
};

#endif // __STATUS_H