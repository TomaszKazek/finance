    #include <iostream>
    #include "Record.h"
    #include "Date.h"
    #include <cstdlib>

    using namespace std;

    void Record::setID(int IDtoSet)
    {
        ID=IDtoSet;
    }

    void Record::setUserID(int ID)
    {
        userID=ID;
    }
    void Record::setDate(Date d)
    {
        date=d;
    }
    void Record::setCategory (string c)
    {
        category=c;
    }
    void Record::setValue(string v)
    {
        value=atof(v.c_str());
    }
    int Record::getID()
    {
        return ID;
    }

    int Record::getUserID()
    {
        return userID;
    }
    Date Record::getDate()
    {
        return date;
    }
    string Record::getCategory()
    {
        return category;
    }
    float Record::getValue()
    {
        return value;
    }
