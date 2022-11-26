#ifndef __STATUS_H
#define __STATUS_H

#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <ctime>  
#include <string.h>
const int MAX_CHARACTERS = 256;
#include "Date.h"
#include "Clock.h"

class Status
{
public:
	char* _text;
	Clock _time;

	Status();
	Status(char* text, Clock time);

	Status* createStatus(); // maybe it will be in here and inside the user/page we'll add it to his list of statuses.

	~Status();
};

#endif // __STATUS_H