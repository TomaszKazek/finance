#include <iostream>
#include "date.h"
#include "Markup.h"
#include "User.h"
#include "Users.h"
#include <conio.h>
#include "FileUsers.h"

using namespace std;

void mainMenu(Users &listU);

int main()
{
    Users listU;

    char option='0';

    while(option!='3')
    {
        system("cls");
        cout<<"Bilans finansow\n1. Logowanie\n2. Rejestracja\n3. Zamknij program\n";
        option=getch();
        switch (option)
        {
        case '1':
        {
            listU.setUserID(listU.logging());
            if(listU.getUserID()!=0)
            {
                //wczytaj dane z pliku
                mainMenu(listU);
            }
        }
        break;
        case '2':
        {
            FileUsers *p_fileUsers=new FileUsers;
            p_fileUsers->addUser(listU.addUser(),listU.getLastUserID());
            delete p_fileUsers;
        }
        break;
        case '3':
            break;
        default:
            cout<<"Nie ma takiej opcji\n";
            system("pause");
            break;
        }
    }

    return 0;
}

void mainMenu(Users &listU)
{
    char opcja='0';

    while(opcja!='7')
    {
        system("cls");
        cout<<"Bilans finansow - menu glowne\n1. Zmiana hasla\n7. Wyloguj sie\n";
        opcja=getch();
        switch (opcja)
        {
        case '1':
        {
            FileUsers *p_fileUsers=new FileUsers;
            p_fileUsers->changePassword(listU.changePassword(),listU.getUserID());
            cout<<"Przeprowadzono zmiane hasla"<<endl;
            system("pause");
            delete p_fileUsers;
        }
        break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;

        default:
            cout<<"Nie ma takiej opcji\n";
            system("pause");
            break;
        }
    }
}
