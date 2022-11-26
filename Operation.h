#ifndef __OPERATION_H
#define __OPERATION_H

#include "User.h"
#include "Page.h"

class Operation
{
private:
	User** _allUsers;
	Page** _allPages;
	User _currentUser;

	// numbers according to init data
	int _numOfUsers = 5;
	int _maxUsers = 8;
	int _numOfPages = 3;
	int _maxPages = 4;

public:
	Operation();
	User** getAllUsers(); // returns a ptr to all users 
	void initiateData(User** users, Page** pages);
	void handleMenu(int userChoice);
	void getCurrentMember();
	const int getNumOfUsers() const { return _numOfUsers; };
	void addUserToOperation(User* user);
	const int getNumOfPages() const { return _numOfPages; };
	void addPageToOperation(Page* page);
	void displayAllEntities();
	bool isValidUserName(char* userName); // sort & binary serach?
	bool isValidPageName(char* pageName);
	//	~Operation(); // TODO: free all memory here

};

#endif // __OPERATION_H