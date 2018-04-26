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
    //cout<<"Dzis mamy: "<<1900+currentDate->tm_year<<"-"<<1+currentDate->tm_mon<<"-"<<currentDate->tm_mday<<endl;

    do
    {
    isDateCorrect=true;
    cout<<"podaj date w formacie yyyy-mm-dd: ";
    getline(cin,buffer);
    stringstream ss(buffer);
    getline(ss,yearString,'-');
    year=atoi(yearString.c_str());
    if (year<2000)
    {
        cout<<"Najstarsza mozliwa data to 2000-01-01"<<endl;
        isDateCorrect=false;
    }
    if (year>1900+currentDate->tm_year)
    {
        cout<<"Najodleglejsza mozliwa data to koniec biezacego miesiaca"<<endl;
        isDateCorrect=false;
    }
    date=yearString;

    getline(ss,monthString,'-');
    month=atoi(monthString.c_str());
    if (month>12||month<1)
    {
        cout<<"Nie ma takiego miesiaca"<<endl;
        isDateCorrect=false;
    }

    if (year==(1900+currentDate->tm_year)&&month>1+currentDate->tm_mon)
    {
        cout<<"Najodleglejsza mozliwa data to koniec biezacego miesiaca"<<endl;
        isDateCorrect=false;
    }
    date+="-";
    date+=monthString;

    getline(ss,dayString,'-');
    day=atoi(dayString.c_str());
    if (day<1)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        isDateCorrect=false;
    }
    if ((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        isDateCorrect=false;
    }
    if ((month==4||month==6||month==9||month==11)&&day>30)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        isDateCorrect=false;
    }
    if (month==2&&((year%4==0)&&(year%100!=0)||(year%400==0))&&day>29)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        isDateCorrect=false;
    }
    if (month==2&&!((year%4==0)&&(year%100!=0)||(year%400==0))&&day>28)
    {
        cout<<"Nie ma takiego dnia"<<endl;
        isDateCorrect=false;
    }
    date+="-";
    date+=dayString;
    }
    while(isDateCorrect==false);
}

 string Date::getDate()
 {
    return date;
 }
