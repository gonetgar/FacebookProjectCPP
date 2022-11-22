#include <iostream>
using namespace std;

#include "User.h"
#include "Operation.h"
#include "Status.h"
#include "Friend.h"
#include "Page.h"
#include "Date.h"

int main()
{
	Operation operation;
	User* initiateUsers = new User[3];
	Page* initiatePages = new Page[2];

	User ori;
	char username[256] = "ori nurieli";
	ori.setName(username);

	User gon;
	char username2[256] = "gon etgar";
	gon.setName(username2);

	User gon2;
	char username3[256] = "gon etgar2";
	gon2.setName(username3);

	Page oripage;
	Page gonpage;

	initiateUsers[0] = ori;
	initiateUsers[1] = gon;
	initiateUsers[2] = gon2;

	initiatePages[0] = oripage;
	initiatePages[1] = gonpage;


	operation.initiateData(initiateUsers, 3, initiatePages, 2);

	operation.displayAllEntities();

	cout << "hello";

	return 0;
}
