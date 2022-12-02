#ifndef __PAGE_H
#define __PAGE_H

//class User;
//class Status;
#include "Status.h"
#include "User.h"


class Page
{
private:
	char* _name;
	User** _fansList;
	Status** _statuses;

	int _numOfFans = 0;
	int _maxFans = 1;
	int _numOfStatuses = 0;
	int _maxStatuses = 1;

public:
	Page() = delete; // we don't want to create a new page without a page name
	Page(const char* name);
	Page(const Page* page) = delete; //  Prevent duplicate

	const char* getName() const { return _name; };
	const int getNumOfFans() const { return _numOfFans; };
	User** getFanListGON() const { return _fansList;  } // TODO delete later

	char* setName(char* name) { _name = name; };

	void addFanToPage(Operation* system, User* current_user);
	//void addFanORI(User* newUser);
	void removeFan(User* removeUser);

	void createStatus();

	void displayAllStatuses();
	void displayAllFans();
};

#endif // __PAGE_H
