#ifndef __PAGE_H
#define __PAGE_H

#include "Status.h"
#include "Friend.h"

class Page
{
	char _name[100];
	Friend** _fansList;
	Status* _statuses;

public:
	Page();
	void createStatus();
	void displayAllStatuses();
	void displayAllFans();
};

#endif // __PAGE_H
