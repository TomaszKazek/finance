#include <iostream>
#include "date.h"
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

void Date::setDate()
{
    time_t currentTime;
    time (&currentTime);
    tm *currentDate;
    currentDate=localtime(&currentTime);

    char opcja='0';

    while(opcja!='1'&&opcja!='2')
    {
        cout<<endl<<"1. Uzyj biezacej daty\n2. Wprowadz inna date\n";
        opcja=getch();
        switch (opcja)
        {
        case '1':
            date=getDateFromSystem(currentDate->tm_year+1900, currentDate->tm_mon+1, currentDate->tm_mday);
            break;
        case '2':
            date=setDateManually(*currentDate);
            break;
        default:
            cout<<"Nie ma takiej opcji\n";
            system("pause");
            break;
        }
    }
}

    void Date::setDate(string d)
    {
        date=d;
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

    string Date::setDateManually(tm currentDate)
    {
        bool isDateCorrect;
        stringstream ss;
        string date, buffer,yearString,monthString,dayString;
        int year,month,day;

        do
            {
                isDateCorrect=true;
                cout<<"podaj date w formacie yyyy-mm-dd: ";
                getline(cin,buffer);
                ss<<buffer;

                getline(ss,yearString,'-');
                year=atoi(yearString.c_str());
                if (checkYear(year, &currentDate))
                {
                    date=yearString;
                }
                else
                    isDateCorrect=false;

                getline(ss,monthString,'-');
                month=atoi(monthString.c_str());
                if (checkMonth(month, year, &currentDate))
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

    return date;
    }

    string Date::getDateFromSystem(int year, int month, int day)
    {
        string date;
        stringstream ss;

        ss<<year;
        date=ss.str()+"-";

        if (month<10)
            date+="0";

        ss.str("");
        ss<<month;
        date+=ss.str()+"-";

        if (day<10)
            date+="0";

        ss.str("");
        ss<<day;
        date+=ss.str();

        return date;
    }

    string Date::getLastDayOfCurrentMonth()
    {
        time_t currentTime;
        time (&currentTime);
        tm *currentDate;
        currentDate=localtime(&currentTime);

        string date;
        stringstream ss;

        ss<<(currentDate->tm_year+1900);
        date=ss.str()+"-";

        if (currentDate->tm_mon<9)
            date+="0";

        ss.str("");
        ss<<(currentDate->tm_mon+1);
        date+=ss.str()+"-31";

        return date;
    }
    string Date::getLastDayOfPreviousMonth()
    {
        time_t currentTime;
        time (&currentTime);
        tm *currentDate;
        currentDate=localtime(&currentTime);

        string date;
        stringstream ss;

        if (currentDate->tm_mon==11)
        {
            ss<<(currentDate->tm_year+1900-1)<<"-12-31";
            date=ss.str();
            return date;
        }

        ss<<(currentDate->tm_year+1900);
        date=ss.str()+"-";

        if (currentDate->tm_mon<9)
            date+="0";

        ss.str("");
        ss<<(currentDate->tm_mon);
        date+=ss.str()+"-31";

        return date;
    }
    string Date::getFirstDayOfMonth(string lastDayOfMonth)
    {
        string date;
        date=lastDayOfMonth.substr(0,8)+"01";
        return date;
    }
