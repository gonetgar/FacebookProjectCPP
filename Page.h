#ifndef __PAGE__H_
#define __PAGE__H_

#include "Status.h"

class Page
{
public:
	char* name;
	char** fansList;
	Status* statuses;

	void createStatus();
	void displayAllStatuses();
	void displayAllFans();
};

#endif // __PAGE__H_
