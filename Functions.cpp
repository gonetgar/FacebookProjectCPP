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

	if (choice > 0 && choice << 13)
		return choice;
	else
		return 12;
}

bool doesUserExist(const char* name, Operation* system)
{
	// for now we do O(n)
	User** allUsers = system->getAllUsers();

	for (int i = 0; i < system->getNumOfUsers(); i++)
	{
		if (strcmp(allUsers[i]->getName(), name) == 0)
			return true;
	}

	return false;
}

void addUserToSystem(Operation* system)
{
	char* username = new char[256];
	Clock birthday(1, 1, 2020);

	cout << "Please enter your username: " << endl;
	cin.ignore();
	cin.getline(username, 256);

	// validate username
	if (doesUserExist(username, system)) {
		cout << "username is already taken" << endl;
		addUserToSystem(system);
		return;
	}

	// get day, month and year of birth from user
	// birthday.getBirthdayInput(); // todo: create in Clock.cpp

	User* userToAdd = new User(username, birthday);

	system->addUserToOperation(userToAdd);
	// Error: here userToAdd dies so he is not saved to _allUsers
	// maybe try making User* instead 
}

void initFriendsLists(User*** allUsers, int numOfAllUsers)
{
	//// keren and steve jobs:
	//(*allUsers)[0]->addFriendToFriendList(*allUsers, *allUsers[0], *allUsers[1]);
	//(*allUsers)[1]->addFriendToFriendList(*allUsers, *allUsers[1], *allUsers[0]);

	//// keren and ori:
	//(*allUsers)[0]->addFriendToFriendList(*allUsers, *allUsers[0], *allUsers[3]);
	//(*allUsers)[3]->addFriendToFriendList(*allUsers, *allUsers[3], *allUsers[0]);

	//// gon and ori:
	//(*allUsers)[4]->addFriendToFriendList(*allUsers, *allUsers[4], *allUsers[3]);
	//(*allUsers)[3]->addFriendToFriendList(*allUsers, *allUsers[3], *allUsers[4]);
}

