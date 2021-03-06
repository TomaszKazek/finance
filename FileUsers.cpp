#include <iostream>
#include "FileUsers.h"
#include "Markup.h"

using namespace std;

void FileUsers::addUser(User newUser)
{
    CMarkup xml;
    xml.Load("Users.xml");
    if(!xml.FindElem("UsersList"))
    {
        xml.AddElem("UsersList");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("ID",newUser.getUserID());
    xml.AddElem("Name",newUser.getName());
    xml.AddElem("LastName",newUser.getLastName());
    xml.AddElem("Login",newUser.getLogin());
    xml.AddElem("Password",newUser.getPassword());
    xml.OutOfElem();

    xml.Save("Users.xml");
}

void FileUsers::changePassword (string newPassword, int userID)
{
    string buffer;

    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("User"))
    {
        xml.IntoElem();

        xml.FindElem("ID");
        buffer=xml.GetData();
        if(atoi(buffer.c_str())==userID)
        {
            xml.FindElem("Password");
            xml.SetData(newPassword);
            xml.Save("Users.xml");
            break;
        }
        xml.OutOfElem();
    }
}

