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
	cout << "11. Display all friends of a friend or page\n";
	cout << "12. Exit\n";

	cin >> choice;

	if (choice > 0 && choice << 13)
		return choice;
	else
		return 12;
}

// returns the user's index in allUsers array, and -1 if not found.
int doesUserExist(const char* name, Operation* system)
{
	int index;
	// for now we do O(n)
	User** allUsers = system->getAllUsers();

	for (index = 0; index < system->getNumOfUsers(); index++)
	{
		if (strcmp(allUsers[index]->getName(), name) == 0)
			return index;
	}

	return -1;
}

bool doesPageExist(const char* name, Operation* system)
{
	// for now we do O(n)
	Page** allPages = system->getAllPages();

	for (int i = 0; i < system->getNumOfPages(); i++)
	{
		if (strcmp(allPages[i]->getName(), name) == 0)
			return true;
	}

	return false;
}

void getUserInput(Operation* system)
{
	char* username = new char[256];
	Clock birthday(1, 1, 2020);

	cout << "Please enter your username: " << endl;
	cin.ignore();
	cin.getline(username, 256);

	// validate username
	if (doesUserExist(username, system) >= 0) {
		cout << "username is already taken" << endl;
		getUserInput(system);
		return;
	}

	// GON add code here:


	// get day, month and year of birth from user
	// birthday.getBirthdayInput(); // todo: create in Clock.cpp

	User* userToAdd = new User(username, birthday);

	system->addUserToOperation(userToAdd);
}

void addPageToSystem(Operation* system)
{
	char* pageName = new char[256];

	cout << "Please enter page name: " << endl;
	cin.ignore();
	cin.getline(pageName, 256);

	// validate username
	if (doesPageExist(pageName, system)) {
		cout << "page name is already taken" << endl;
		addPageToSystem(system);
		return;
	}

	Page* pageToAdd = new Page(pageName);

	system->addPageToOperation(pageToAdd);
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

void getUserOrPageInput(int userChoice, Operation* system)
{
	// userChoice is according to handleMenu()

	char* username = new char[256];
	char* pageName = new char[256];

	User** allUsers = system->getAllUsers();
	Page** allPages = system->getAllPages();

	bool isUserToDisplay = 0;

	cout << "Choose: " << endl;
	cout << "0 - Page" << endl << "1 - User" << endl;
	cin >> isUserToDisplay;

	if (isUserToDisplay) { // the choice was User
		cout << "Please enter username: " << endl;
		cin.ignore();
		cin.getline(username, 256);

		int friendIndex = doesUserExist(username, system);

		if (friendIndex >= 0) {
			switch (userChoice)
			{
			case 3:
				allUsers[friendIndex]->createStatus();
				break;
			case 4:
				allUsers[friendIndex]->displayAllStatuses();
				break;
			default:
				break;
			}
		}
		else cout << "user was not found" << endl;
	}
	else  // choice was Page
	{
		cout << "Please enter page name: " << endl;
		cin.ignore();
		cin.getline(pageName, 256);

		int pageIndex = doesPageExist(pageName, system);

		if (pageIndex >= 0) {
			switch (userChoice)
			{
			case 3:
				allPages[pageIndex]->createStatus();
				break;
			case 4:
				allPages[pageIndex]->displayAllStatuses();
				break;
			default:
				break;
			}
		}
		else cout << "page was not found" << endl;
	}
}

