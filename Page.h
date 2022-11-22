#ifndef __PAGE__H_
#define __PAGE__H_

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

#endif // __PAGE__H_
