#include <iostream>
#include "IncomesAndExpenses.h"

using namespace std;

class Balance
{
    float SumOfIncomes, SumOfExpenses;
    vector<string> listToDisplay;
    float loadTextToVector(string firstDate, string lastDate, vector<Record> listIorE);
    void displayVector();

public:
    Balance (IncomesAndExpenses incomes, IncomesAndExpenses expenses, string firstDate, string lastDate);
};
