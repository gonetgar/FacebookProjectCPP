#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "Date.h"
#include "Operation.h"
#include "Page.h"
#include "Status.h"

class User;

int displayMenu();
bool doesUserExist(const char* name, Operation* system);
void addUserToSystem(Operation* system);
void initFriendsLists(User*** allUsers, int numOfAllUsers);


//void myStrcpy(char* dest, char* source);

#endif // __FUNCTIONS_H