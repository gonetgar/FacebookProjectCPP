#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
#include "Status.h"

Status::Status()
{
	_text = new char[MAX_CHARACTERS];
	_time = Clock();
}

Status::Status(char* text, Clock time)
{
	_text = text;
	_time = time;
}

Clock Status::getStatusTime()
{
	return _time;
}

void Status::getStatusInfo(Status* newStatus)
{
	cout << "Please insert your status: ";
	cin.getline(newStatus->_text, MAX_CHARACTERS);	//TODO shrink?
	cout << endl;
}

Status::~Status()
{
	delete _text;
}