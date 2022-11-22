#ifndef __PAGE_H
#define __PAGE_H

#include "Status.h"
#include "Friend.h"

class Page
{
public:
	char* name;
	Friend** fansList;
	Status* statuses;

	void createStatus();
	void displayAllStatuses();
	void displayAllFans();
};

#endif // __PAGE_H
