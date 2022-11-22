#ifndef __DATE__H_
#define __DATE__H_
#define _CRT_SECURE_NO_WARNINGS

#include <ctime>

class Date
{
public:
    Date();
    Date(int mn, int day, int yr);  // constructor
    void display();                 // function to display date
    int GetMonth();
    void SetMonth(int mn);
    ~Date();
    time_t getCurrentDate();
private:
    int month, day, year;
};

#endif // __DATE__H_
