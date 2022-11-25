#ifndef __PAGE_H
#define __PAGE_H

class Status;
class User;

class Page
{
	char* _name;
	User** _fansList;
	Status** _statuses;

	int numOfFans = 0;
	int maxFans = 0;

public:
	Page() = delete; // we don't want to create a new page without a page name
	Page(const char* name);
	Page(const Page* page) = delete; //  Prevent duplicate
	void createStatus();
	void displayAllStatuses();
	void displayAllFans();
};

#endif // __PAGE_H
