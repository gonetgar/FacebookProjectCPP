#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "Date.h"
#include "Operation.h"
#include "Page.h"
#include "Status.h"

class User;

int displayMenu();
int doesUserExist(const char* name, Operation* system);
int doesPageExist(const char* name, Operation* system);

void getUserInput(Operation* system);
void addPageToSystem(Operation* system);
void getUserOrPageInput(int userChoice, Operation* system);
Page* getPageDetails(Operation* system);

void initFriendsLists(User*** allUsers, int numOfAllUsers);



#endif // __FUNCTIONS_H