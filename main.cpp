#include <iostream>
#include "date.h"
#include "Markup.h"
#include "User.h"
#include "Users.h"
#include <conio.h>
#include "FileUsers.h"
#include "IncomesAndExpenses.h"
#include "Data.h"
#include "Balance.h"

using namespace std;

void mainMenu(Users &listU, IncomesAndExpenses *p_Incomes, IncomesAndExpenses *p_Expenses);

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
                IncomesAndExpenses *p_Incomes=new IncomesAndExpenses (listU.getUserID(), "Income");
                IncomesAndExpenses *p_Expenses=new IncomesAndExpenses (listU.getUserID(), "Expense");
                mainMenu(listU,p_Incomes,p_Expenses);
                delete p_Incomes;
                delete p_Expenses;
            }
        }
        break;
        case '2':
        {
            FileUsers *p_fileUsers=new FileUsers;
            p_fileUsers->addUser(listU.addUser());
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

void mainMenu(Users &listU, IncomesAndExpenses *p_Incomes, IncomesAndExpenses *p_Expenses)
{
    char opcja='0';

    while(opcja!='7')
    {
        system("cls");
        cout<<"Bilans finansow - menu glowne\n1. Dodaj przychod\n2. Dodaj wydatek\n3. Bilans biezacego miesiaca\n4. Bilans poprzedniego miesiaca\n5. Bilans wybranego okresu\n6. Zmiana hasla\n7. Wyloguj sie\n";
        opcja=getch();
        switch (opcja)
        {
        case '1':
        {
            Data *p_data = new Data;
            p_data->addRecord(p_Incomes->addRecord(listU.getUserID()),"Income");
            delete p_data;
        }
        break;
        case '2':
        {
            Data *p_data = new Data;
            p_data->addRecord(p_Expenses->addRecord(listU.getUserID()),"Expense");
            delete p_data;
        }
            break;
        case '3':
            {
                Date *temp=new Date;
                string lastDate=temp->getLastDayOfCurrentMonth();
                string firstDate=temp->getFirstDayOfMonth(lastDate);
                delete temp;
                Balance *currentMonth=new Balance (*p_Incomes, *p_Expenses, firstDate, lastDate);
                delete currentMonth;
            }
            break;
        case '4':
            {
                Date *temp=new Date;
                string lastDate=temp->getLastDayOfPreviousMonth();
                string firstDate=temp->getFirstDayOfMonth(lastDate);
                delete temp;
                Balance *previousMonth=new Balance (*p_Incomes, *p_Expenses, firstDate, lastDate);
                delete previousMonth;
            }
            break;
        case '5':
            {
                system("cls");
                cout<<"Podaj date poczatku wybranego okresu"<<endl;
                Date *firstDate=new Date;
                firstDate->setDate();
                system("cls");
                cout<<"Podaj date konca wybranego okresu"<<endl;
                Date *lastDate=new Date;
                lastDate->setDate();
                Balance *givenDates=new Balance (*p_Incomes, *p_Expenses, firstDate->getDate(), lastDate->getDate());
                delete givenDates;
            }
            break;
        case '6':
        {
            FileUsers *p_fileUsers=new FileUsers;
            p_fileUsers->changePassword(listU.changePassword(),listU.getUserID());
            cout<<"Przeprowadzono zmiane hasla"<<endl;
            system("pause");
            delete p_fileUsers;
        }
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
