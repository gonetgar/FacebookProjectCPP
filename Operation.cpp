#include <iostream>
using namespace std;

#include "Operation.h"

// no default constructor is needed
Operation::Operation(User* allUsers = new User[1], Page* allPages = new Page[1])
{
	_allUsers = allUsers;
	_allPages = allPages;
}


void Operation::initiateData(User* users, Page* pages, User* allUsers, Page* allPages)
{

}

void Operation::addUserToOperation(User user, User* allUsers)
{

}

void Operation::addPageToOperation(Page page, Page* allPages)
{

}

void Operation::displayAllEntities(User* allUsers, Page* allPages)
{

}

void Operation::displayMenu()
{

}

bool Operation::isValidUserName(char* userName, User* allUsers)
{
	return true; // only for complier
}

bool Operation::isValidPageName(char* pageName, Page* allPages)
{
	return true; // only for complier
}