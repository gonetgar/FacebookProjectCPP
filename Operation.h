#ifndef __OPERATION__H_
#define __OPERATION__H_

#include "User.h"
#include "Page.h"

class Operation
{
	User* _allUsers;
	Page* _allPages;
	User _currentUser;

public:
	Operation(User* allUsers, Page* allPages);
	void initiateData(User* users, int usersSize, Page* pages, int pagesSize);
	User* getAllUsers(); // returns all users 
	void displayMenu();
	void getCurrentMember();
	void addUserToOperation(User user);
	void addPageToOperation(Page page);
	void displayAllEntities();
	bool isValidUserName(char* userName, User* allUsers); // sort & binary serach?
	bool isValidPageName(char* pageName, Page* allPages);
	//	~Operation(); // TODO: free all memory here

};

#endif // __OPERATION__H_