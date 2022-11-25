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

const std::string currentDateTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d-%m-%Y : %X", &tstruct);

	return buf;
}

void Status::createStatus()
{
	std::cout << "current date time: " << currentDateTime() << std::endl;


}
