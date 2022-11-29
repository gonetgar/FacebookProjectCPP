#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "Date.h"
#include "Operation.h"
#include "Page.h"
#include "Status.h"

class User;

int displayMenu();
bool doesUserExist(const char* name, Operation* system);
bool doesPageExist(const char* name, Operation* system);
void addUserToSystem(Operation* system);
void addPageToSystem(Operation* system);
void initFriendsLists(User*** allUsers, int numOfAllUsers);



#endif // __FUNCTIONS_H