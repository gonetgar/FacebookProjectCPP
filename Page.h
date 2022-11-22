#ifndef __PAGE_H
#define __PAGE_H

#include "Status.h"
#include "Friend.h"

class Page
{
	char* _name;
	Friend** _fansList;
	Status* _statuses;

public:
	void createStatus();
	void displayAllStatuses();
	void displayAllFans();
};

#endif // __PAGE_H
