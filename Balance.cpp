#include <iostream>
#include "Balance.h"
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;

Balance::Balance (IncomesAndExpenses incomes, IncomesAndExpenses expenses, string firstDate, string lastDate)
{
    SumOfIncomes=0;
    SumOfExpenses=0;
    vector<Record> listI, listE;
    listI=incomes.getRecordsList();
    listE=expenses.getRecordsList();

    system("cls");
    cout<<"Przychody: "<<endl;
    SumOfIncomes=loadTextToVector(firstDate,lastDate, listI);
    displayVector();

    cout<<endl<<"Wydatki: "<<endl;
    SumOfExpenses=loadTextToVector(firstDate,lastDate, listE);
    displayVector();

    cout<<endl<<"Suma przychodow: "<<SumOfIncomes<<endl;
    cout<<"Suma wydatkow: "<<SumOfExpenses<<endl;
    cout<<"Roznica: "<<SumOfIncomes-SumOfExpenses<<endl;
    system("pause");
}

float Balance::loadTextToVector(string firstDate, string lastDate, vector<Record> listIorE)
{
    vector<Record>::iterator index=listIorE.begin();
    float sum=0;
    stringstream ss;
    string textToDisplay;

    listToDisplay.clear();

    while (index!=listIorE.end())
    {
        if (firstDate<=(index->getDate().getDate())&&lastDate>=(index->getDate().getDate()))
        {
            ss.str("");
            ss<<index->getValue();
            textToDisplay=index->getDate().getDate()+" "+ss.str()+" "+index->getCategory();
            listToDisplay.push_back(textToDisplay);
            sum+=index->getValue();
        }
        index++;
    }
    return sum;
}

void Balance::displayVector()
{
    vector<string>::iterator index=listToDisplay.begin();

    sort(listToDisplay.begin(),listToDisplay.end());

    while (index!=listToDisplay.end())
    {
            cout<<*index<<endl;
            index++;
    }

}

