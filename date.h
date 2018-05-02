#include <iostream>

using namespace std;

class Date
{
    string date;

    bool checkYear(int year, tm* currentDate);
    bool checkMonth(int month, int year, tm* currentDate);
    bool checkDay(int day, int month, int year);

public:
    void setDate();
    string getDate();
};
