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
	for (int i = 0; i < 3; i++)
	{
		cout << "user #" << i << ":\n";
		//User user("gon", Date(i + 1, i + 1, 2020));
		User user("gon", Clock(i + 1, i + 1, 2020));
		Page page("page test");
		initUsers[i] = &user;
		initPages[i] = &page;
		cout << endl;
	}

	system.initiateData(initUsers, initPages);
	system.displayAllEntities(); // TODO: print names and not addresses
	 //ori - i put it all in green
	system.getCurrentMember();

	bool flag = doesUserExist("gon", initUsers);
	cout << "flag: " << flag << endl;


	//// ################################ Menu ################################ 
	userChoice = displayMenu();
	system.handleMenu(userChoice);

	while (userChoice < 0 || userChoice > 13)
	{
		cout << "Invalid Input, try again." << endl;
		userChoice = displayMenu();
		system.handleMenu(userChoice);
	}


	// ####### ori try 19:00 #######

	//Status stat;
	//stat.createStatus();


	// gon try 10:00 //



	return 0;
}
