#include <iostream>
#include "User.h"

using namespace std;

void User::setUserID(int ID)
{
    userID=ID;
}
void User::setName(string n)
{
    name=n;
}
void User::setLastName(string l)
{
    lastName=l;
}
void User::setLogin(string l)
{
    login=l;
}
void User::setPassword(string p)
{
    password=p;
}
int User::getUserID()
{
    return userID;
}
string User::getName()
{
    return name;
}
string User::getLastName()
{
    return lastName;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
