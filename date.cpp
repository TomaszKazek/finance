#include <iostream>
#include "date.h"
#include <sstream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Date::setDate()
{
    string buffer,yearString,monthString,dayString;
    int year,month,day;
    bool isDateCorrect;

    time_t currentTime;
    time (&currentTime);
    tm *currentDate;
    currentDate=localtime(&currentTime);

    do
    {
        isDateCorrect=true;
        cout<<"podaj date w formacie yyyy-mm-dd: ";
        getline(cin,buffer);
        stringstream ss(buffer);

        getline(ss,yearString,'-');
        year=atoi(yearString.c_str());
        if (checkYear(year, currentDate))
        {
            date=yearString;
        }
        else
            isDateCorrect=false;

        getline(ss,monthString,'-');
        month=atoi(monthString.c_str());
        if (checkMonth(month, year, currentDate))
        {
            date+="-";
            date+=monthString;
        }
        else
            isDateCorrect=false;

        getline(ss,dayString,'-');
        day=atoi(dayString.c_str());
        if (checkDay(day, month, year))
        {
            date+="-";
            date+=dayString;
        }
        else
            isDateCorrect=false;
    }
    while(isDateCorrect==false);
}

string Date::getDate()
{
    return date;
}

bool Date::checkYear(int year, tm* currentDate)
{
    if (year<2000)
    {
        cout<<"Najstarsza mozliwa data to 2000-01-01"<<endl;
        return false;
    }
    if (year>1900+currentDate->tm_year)
    {
        cout<<"Najodleglejsza mozliwa data to koniec biezacego miesiaca"<<endl;
        return false;
    }
    return true;
}

bool Date::checkMonth (int month, int year, tm* currentDate)
{
    if (month>12||month<1)
    {
        cout<<"Nie ma takiego miesiaca"<<endl;
        return false;
    }

    if (year==(1900+currentDate->tm_year)&&month>1+currentDate->tm_mon)
    {
        cout<<"Najodleglejsza mozliwa data to koniec biezacego miesiaca"<<endl;
        return false;
    }
    return true;
}

bool Date::checkDay (int day, int month, int year)
{
    if (day<1)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        return false;
    }
    if ((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        return false;
    }
    if ((month==4||month==6||month==9||month==11)&&day>30)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        return false;
    }
    if (month==2&&((year%4==0)&&(year%100!=0)||(year%400==0))&&day>29)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        return false;
    }
    if (month==2&&!((year%4==0)&&(year%100!=0)||(year%400==0))&&day>28)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        return false;
    }
    return true;
}
