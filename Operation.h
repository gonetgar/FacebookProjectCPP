#ifndef __OPERATION__H_
#define __OPERATION__H_

#include "User.h"
#include "Page.h"

class Operation
{
private:
	User* _allUsers;
	Page* _allPages;

public:
	Operation(User* allUsers, Page* allPages);
	void initiateData(User* users, Page* pages, User* allUsers, Page* allPages);
	void addUserToOperation(User user, User* allUsers);
	void addPageToOperation(Page page, Page* allPages);
	void displayAllEntities(User* allUsers, Page* allPages);
	void displayMenu();
	bool isValidUserName(char* userName, User* allUsers); // sort & binary serach?
	bool isValidPageName(char* pageName, Page* allPages);
	~Operation(); // TODO: free all memory here

};

#endif // __OPERATION__H_