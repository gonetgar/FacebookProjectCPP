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


void Status::getStatusInfo(Status* newStatus)
{
	//Status* newStatus = new Status();

	cout << "Please insert your status: ";
	cin.ignore();
	cin.getline(newStatus->_text, MAX_CHARACTERS);	//TODO shrink?

	//// for debugging: ////

	cout << "\nyou entered: ";
	cout << newStatus->_text;
	cout << "\non date: ";
	cout << setw(2) << setfill('0') << newStatus->_time._day << ".";
	cout << setw(2) << setfill('0') << newStatus->_time._month << ".";
	cout << setw(2) << setfill('0') << newStatus->_time._year << endl;
	cout << "\non time: ";
	cout << setw(2) << setfill('0') << newStatus->_time._hours << ":";
	cout << setw(2) << setfill('0') << newStatus->_time._minutes << ":";
	cout << setw(2) << setfill('0') << newStatus->_time._seconds << endl;
}

Status::~Status()
{
	delete[] _text;
}