#include <iostream>
using namespace std;

#include "Date.h"

// constructor definition
Date::Date()
{
    month = day = year = 1;
}

Date::Date(int mn, int dy, int yr)
{
    static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    month = max(1, mn);
    month = min(month, 12);

    day = max(1, dy);
    day = min(day, length[month]);

    year = max(1, yr);
}

void Date::display()
{
    char name[13][256] = { "nothing", "January", "February", "March", "April",
             "May", "June", "July", "August", "September", "October",
             "November", "December" };

    cout << '\n' << name[month] << ' ' << day << "," << year << '\n';
}

Date::~Date()
{
}

int Date::GetMonth()
{
    return month;
}

void Date::SetMonth(int mn)
{
    month = max(1, mn);
    month = min(month, 12);
}

time_t Date::getCurrentDate()
{
    return time(0);
}



