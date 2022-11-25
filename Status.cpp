#include <iostream>
using namespace std;

#include "Status.h"


Status::Status()
{
	_text = new char[MAX_CHARACTERS];
	_date = Date(1, 1, 2022); // TODO " insert current date automatically
}

Status::Status(char* text, Date date)
{
	_text = text;
	_date = date;
}

void Status::createStatus()
{
	time_t current_time;


}
