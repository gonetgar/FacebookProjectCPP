#include <iostream>
using namespace std;
#include "Functions.h"


int displayMenu()
{
	int choice;

	cout << "Welcome To Facebook :)" << endl;
	cout << "Please choose an action:\n";
	cout << "1. Add new user\n";
	cout << "2. Add new page\n";
	cout << "3. Create a new status\n";
	cout << "4. Display all statuses\n";
	cout << "5. Display all 10 recent statuses\n";
	cout << "6. Add a new friend\n";
	cout << "7. Unfriend\n";
	cout << "8. Like a page\n";
	cout << "9. Unlike a page\n";
	cout << "10. Display all entities of Facebook\n";
	cout << "11. Display all friends\n";
	cout << "12. Exit\n";

	cin >> choice;

	return choice;
}

void doesUserExist(char* name, User** allUsers)
{

}
//void myStrcpy(char* dest, char* source)
//{
//	int len = strlen(source);
//	for (int i = 0; i < len; i++)
//	{
//		dest[i] = source[i];
//	}
//
//	dest[len] = '\0';
//}



