#ifndef __OPERATION__H_
#define __OPERATION__H_

#include "Operation.h"
#include "User.h"
#include "Page.h"

class Operation
{
public:
	User* allUsers;
	Page* allPages;

	void initiateData();
	void addUserToOperation();
	void addPageToOperation();
	void displayAllEntities();
	void displayMenu();
	bool isValidUserName(char* userName, char* allUserNames);
	bool isValidPageName(char* pageName, char* allPagesNames);
};

#endif // __OPERATION__H_