#include <iostream>
#include <vector>
#include "Record.h"
#ifndef IncomesAndExpenses_h
#define IncomesAndExpenses_h

using namespace std;

class IncomesAndExpenses
{

    vector<Record> recordsList;
    int lastID;

public:
    IncomesAndExpenses (int userID, string IorE);
    Record addRecord (int userID);
    vector<Record> getRecordsList();
};

#endif
