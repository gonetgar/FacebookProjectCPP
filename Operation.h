#ifndef __OPERATION_H
#define __OPERATION_H

#include "User.h"
#include "Page.h"

class Operation
{
private:
	User** _allUsers;
	Page** _allPages;
	User _currentUser; // TODO- delete current user

	// numbers according to init data
	int _numOfUsers = 5;
	int _maxUsers = 8;
	int _numOfPages = 5;
	int _maxPages = 8;

public:
	Operation();
	void initiateData(User** users, Page** pages);
	void handleMenu(int userChoice);

	User** getAllUsers() { return _allUsers; };
	Page** getAllPages() { return _allPages; };
	User* getCurrentUser();
	void getCurrentMemberInput();
	const char* getCurrentMemberName() const { return _currentUser.getName(); };
	const int getNumOfPages() const { return _numOfPages; };
	const int getNumOfUsers() const { return _numOfUsers; };

	void addUserToOperation(User* user);
	void addPageToOperation(Page* page);
	void displayAllEntities();

	bool isValidUserName(char* userName); // sort & binary serach?
	bool isValidPageName(char* pageName);
	~Operation();
};

#endif // __OPERATION_H