#include <iostream>
using namespace std;

#include "User.h"
#include "Operation.h"
#include "Status.h"
#include "Page.h"
#include "Functions.h"

int main()
{
	int userChoice = 0;

	Operation system;
	User** initUsers = new User * [5];
	Page** initPages = new Page * [3];

	// ################################ initiate data ################################ 
	initUsers = initiateUsers();
	initPages = initiatePages(&system, initUsers);
	system.initiateData(initUsers, initPages);
	system.getCurrentMemberInput();

	//// ################################ Menu ################################ 
	userChoice = displayMenu(); // todo - do while
	system.handleMenu(userChoice);

	while (userChoice > 0 || userChoice < 13)
	{
		userChoice = displayMenu();
		system.handleMenu(userChoice);
	}

	cout << "end of main()." << endl; // todo - delete this?

	return 0;
}
