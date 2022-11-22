#ifndef __DATE__H_
#define __DATE__H_

class Date
{
public:
    Date();
    Date(int mn, int day, int yr);  // constructor
    void display();                 // function to display date
    int GetMonth();
    void SetMonth(int mn);
    ~Date();
private:
    int month, day, year;
};

#endif // __DATE__H_
