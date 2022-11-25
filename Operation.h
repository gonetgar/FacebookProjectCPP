#ifndef __OPERATION_H
#define __OPERATION_H

#include "User.h"
#include "Page.h"

class Operation
{
	User** _allUsers;
	Page** _allPages;
	User _currentUser;

	int numOfUsers = 0;
	int maxUsers = 1;
	int numOfPages = 0;
	int maxPages = 1;

public:
	Operation();
	User** getAllUsers(); // returns a ptr to all users 
	void initiateData(User** users, Page** pages);
	void displayMenu();
	void getCurrentMember();
	/*void addUserToOperation(User* user);
	void addPageToOperation(Page* page);*/
	void displayAllEntities();
	bool isValidUserName(char* userName); // sort & binary serach?
	bool isValidPageName(char* pageName);
	//	~Operation(); // TODO: free all memory here

};

#endif // __OPERATION_H