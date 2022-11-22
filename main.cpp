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
	Date* d;
	User u("gon");
	d = new Date(11, 15, 2022);
	d->display();

	return 0;
}
