#include <iostream>
#include "Date.h"
#ifndef Record_h
#define Record_h


using namespace std;

class Record
{
    int ID;
    int userID;
    Date date;
    string category;
    float value;

public:
    void setID(int IDtoSet);
    void setUserID(int ID);
    void setDate(Date d);
    void setCategory (string c);
    void setValue(string v);
    int getID();
    int getUserID();
    Date getDate();
    string getCategory();
    float getValue();
};

#endif
