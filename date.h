#include <iostream>
#ifndef Date_h
#define Date_h

using namespace std;

class Date
{
    string date;

    string getDateFromSystem(int year, int month, int day);
    string setDateManually(tm currentDate);

    bool checkYear(int year, tm* currentDate);
    bool checkMonth(int month, int year, tm* currentDate);
    bool checkDay(int day, int month, int year);

public:
    void setDate();
    void setDate(string d);
    string getDate();
    string getLastDayOfCurrentMonth();
    string getLastDayOfPreviousMonth();
    string getFirstDayOfMonth(string lastDayOfMonth);
};

#endif
