#ifndef __PAGE_H
#define __PAGE_H

#include "Status.h"
#include "Friend.h"

class Page
{
	char* name;
	Friend** fansList;
	Status* statuses;

public:
	void createStatus();
	void displayAllStatuses();
	void displayAllFans();
};

#endif // __PAGE_H
