#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "Date.h"
#include "Operation.h"
#include "Page.h"
#include "Status.h"

class User;

int displayMenu();
bool doesUserExist(const char* name, User** allUsers);


//void myStrcpy(char* dest, char* source);

#endif // __FUNCTIONS_H