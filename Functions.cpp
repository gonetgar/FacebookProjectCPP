#include <iostream>
#include "Functions.h"
using namespace std;


User** initiateUsers()
{
	User** initUsers = new User * [5];

	User* user1 = new User("Keren Kalif", Clock(15, 4, 1980), 2, 2);
	initUsers[0] = user1;
	User* user2 = new User("Steve Jobs", Clock(1, 3, 1960), 2, 2);
	initUsers[1] = user2;
	User* user3 = new User("Mark Zuckerberg", Clock(6, 8, 1976), 4, 3);
	initUsers[2] = user3;
	User* user4 = new User("Ori Nurieli", Clock(1, 7, 1997), 2, 1);
	initUsers[3] = user4;
	User* user5 = new User("Gon Etgar", Clock(21, 10, 1996), 2, 2);
	initUsers[4] = user5;

	// keren and steve jobs -> todo delete later remarks
	user1->getFriendsList()[0] = user2;
	user2->getFriendsList()[0] = user1;

	// keren and mark
	user1->getFriendsList()[1] = user3;
	user3->getFriendsList()[0] = user1;

	// steve and mark
	user2->getFriendsList()[1] = user3;
	user3->getFriendsList()[1] = user2;

	// gon and ori
	user5->getFriendsList()[0] = user4;
	user4->getFriendsList()[0] = user5;

	// gon and mark
	user5->getFriendsList()[1] = user3;
	user3->getFriendsList()[2] = user5;

	return initUsers;
}

void initiateFriendships(User** allUsers)
{
	
}

Page** initiatePages()
{
	Page** initPages = new Page * [5];

	Page* page1 = new Page("Maccabi Haifa");
	initPages[0] = page1;
	Page* page2 = new Page("Harry Potter");
	initPages[1] = page2;
	Page* page3 = new Page("Pink Floyd");
	initPages[2] = page3;
	Page* page4 = new Page("Led Zeppelin");
	initPages[3] = page4;
	Page* page5 = new Page("Dogs");
	initPages[4] = page5;

	return initPages;
}

void initiateStatuses()
{

}

void initiatePageLikes() // initiate likes on pages from users
{

}

int displayMenu()
{
	int choice;

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
	// for now we do O(n) // TODO -> change to binary search
	User** allUsers = system->getAllUsers();

	for (index = 0; index < system->getNumOfUsers(); index++)
	{
		if (strcmp(allUsers[index]->getName(), name) == 0)
			return index;
	}

	return -1;
}

// returns the page's index in the allPages array, or -1 if is not found
int doesPageExist(const char* name, Operation* system)
{
	int index;
	// for now we do O(n) // TODO -> change to binary search
	Page** allPages = system->getAllPages();

	for (index = 0; index < system->getNumOfPages(); index++)
	{
		if (strcmp(allPages[index]->getName(), name) == 0)
			return index;
	}

	return -1;
}

void getUserInput(Operation* system)
{
	char* username = new char[256];

	cout << "Please enter your username: " << endl;
	cin.ignore();
	cin.getline(username, 256);

	// validate username
	if (doesUserExist(username, system) >= 0) {
		cout << "username is already taken" << endl;
		getUserInput(system);
		return;
	}

	Clock birthday = birthday.getBirthdayInput();

	User* userToAdd = new User(username, birthday, 1, 0);

	system->addUserToOperation(userToAdd);
}

void addPageToSystem(Operation* system)
{
	char* pageName = new char[256];

	cout << "Please enter page name: " << endl;
	cin.ignore();
	cin.getline(pageName, 256);

	// validate username
	if (doesPageExist(pageName, system) >= 0) {
		cout << "page name is already taken" << endl;
		addPageToSystem(system);
		return;
	}

	Page* pageToAdd = new Page(pageName);

	system->addPageToOperation(pageToAdd);
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
			case 11:
				allUsers[friendIndex]->displayAllFriends();
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
			case 11:
				allPages[pageIndex]->displayAllFans();
				break;
			default:
				break;
			}
		}
		else cout << "page was not found" << endl;
	}
}

// asks for a page name and search it in the system.
// returns pointer to the page, and null if not found
Page* getPageDetails(Operation* system)
{
	Page** allPages = system->getAllPages();
	char pageName[MAX_CHARACTERS];
	int index = 0;

	cout << "Enter page name:\n";
	//cin.ignore();
	cin.getline(pageName, MAX_CHARACTERS);

	index = doesPageExist(pageName, system);

	if (index >= 0)
		return allPages[index];
	else
		return nullptr;
}

// ask for name and search it on allUsers array, returns the user's pointer, or nullptr if not found
User* askForUsername(Operation* system)
{
	User* user;
	char* username = new char[MAX_CHARACTERS];
	int userIndex;

	cout << "Please enter your username: ";
	cin.ignore();
	cin.getline(username, MAX_CHARACTERS);
	userIndex = doesUserExist(username, system);
	delete[] username;

	if (userIndex == -1)
	{
		cout << "User not found!\n\n";
		user = nullptr;
	}
	else
		user = system->getAllUsers()[userIndex];
	
	return user;
}