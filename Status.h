#ifndef __STATUS_H
#define __STATUS_H

#include <ctime>
const int MAX_CHARACTERS = 256;

#include "Date.h"

class Status
{
public:
	char* _text;
	Date _date;
	//Clock time; // needs to be added as a class


	Status();
	Status(char* text, Date date);

	void createStatus(); // maybe it will be in here and inside the user/page we'll add it to his list of statuses.
};

#endif // __STATUS_H