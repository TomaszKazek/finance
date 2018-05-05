#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Users.h"
#include "Markup.h"

using namespace std;

Users::Users()
{
    usersList.clear();
    string buffer;
    lastUserID=0;

    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        User *p_User = new User;

        xml.IntoElem();

        xml.FindElem("ID");
        buffer=xml.GetData();
        p_User->setUserID(atoi(buffer.c_str()));

        xml.FindElem("Name");
        p_User->setName(xml.GetData());

        xml.FindElem("LastName");
        p_User->setLastName(xml.GetData());

        xml.FindElem("Login");
        p_User->setLogin(xml.GetData());

        xml.FindElem("Password");
        p_User->setPassword(xml.GetData());

        xml.OutOfElem();

        usersList.push_back(*p_User);
        lastUserID=p_User->getUserID();
        delete p_User;
    }
}

int Users::logging()
{
    string name, password;
    cout<<"Podaj nazwe uzytkownika: ";
    cin.sync();
    getline(cin, name);

    vector<User>::iterator index=usersList.begin();

    while (index!=usersList.end())
    {
        if (name==index->getLogin())
        {
            for(int i=0; i<3; i++)
            {
                cout<<"Podaj haslo: ";
                cin.sync();
                getline(cin,password);
                if (password==index->getPassword())
                {
                    system("cls");
                    cout<<"Witaj "<<index->getName()<<" "<<index->getLastName()<<endl;
                    system("pause");
                    return index->getUserID();
                }
                else
                    cout<<"Haslo niepoprawne\n";
            }
        }
        index++;
    }
    system("cls");
    cout<<"Proba logowania zakonczyla sie niepowodzeniem\n";
    system("pause");
    return 0;
}

User Users::addUser()
{
    User newUser;
    string buffer;
    stringstream ss;
    vector<User>::iterator index=usersList.end();

    newUser.setUserID(lastUserID+1);
    lastUserID+=1;
    cout<<"ID: "<<newUser.getUserID()<<endl;

    cout<<"Podaj imie: ";
    cin.sync();
    getline(cin, buffer);
    newUser.setName(buffer);

    cout<<"Podaj nazwisko: ";
    cin.sync();
    getline(cin, buffer);
    newUser.setLastName(buffer);

    cout<<"Podaj login: ";
    cin.sync();
    getline(cin, buffer);
    newUser.setLogin(buffer);

    cout<<"Podaj haslo: ";
    cin.sync();
    getline(cin, buffer);
    newUser.setPassword(buffer);

    usersList.push_back(newUser);
    system("pause");
    return newUser;
}

vector<User> Users::getUsersList()
{
    return usersList;
}

string Users::changePassword()
{
    string buffer;
    cout<<"Podaj haslo: ";
    cin.sync();
    getline(cin, buffer);

    vector<User>::iterator index=usersList.begin();
    while (index!=usersList.end())
    {
        if (userID==index->getUserID())
        {
            index->setPassword(buffer);
            break;
        }
        index++;
    }
    return buffer;
}

int Users::getUserID()
{
    return userID;
}

void Users::setUserID(int u)
{
    userID=u;
}

int Users::getLastUserID()
{
    return lastUserID;
}

