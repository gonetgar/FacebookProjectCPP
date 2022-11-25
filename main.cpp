#include <iostream>
using namespace std;

#include "User.h"
#include "Operation.h"
#include "Status.h"
#include "Friend.h"
#include "Page.h"
#include "Date.h"
#include "Functions.h"

int main()
{
	Operation system;
	User** initUsers = new User * [3];
	Page** initPages = new Page * [3];
	User** test;
	int userChoice = 0;

	// ################################ initiate data ################################ 
	for (int i = 1; i < 4; i++)
	{
		cout << "user #" << i << ":\n";
		User user("gon", Date(i, i, 2020));
		Page page("page test");
		initUsers[i] = &user;
		initPages[i] = &page;
		cout << endl;
	}

	system.initiateData(initUsers, initPages);
	system.displayAllEntities();


	// ################################ Menu ################################ 
	userChoice = displayMenu();

	while (userChoice < 1 || userChoice > 12)
	{
		cout << "Invalid Input, try again.";
		userChoice = displayMenu();
		system.handleMenu(userChoice);
	}



	/////// ori try 18:55 ////
	Status stat;

	stat.createStatus();

	return 0;
}
