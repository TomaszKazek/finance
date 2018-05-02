#include <iostream>
#ifndef User_h
#define User_h

using namespace std;

class User
{
    int userID;
    string name;
    string lastName;
    string login;
    string password;

public:
    void setUserID(int ID);
    void setName(string n);
    void setLastName (string l);
    void setLogin(string l);
    void setPassword(string p);
    int getUserID();
    string getName();
    string getLastName();
    string getLogin();
    string getPassword();
};

#endif
