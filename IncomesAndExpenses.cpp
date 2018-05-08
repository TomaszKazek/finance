#include <iostream>
#include <vector>
#include "Record.h"
#include "Markup.h"
#include "IncomesAndExpenses.h"

using namespace std;

IncomesAndExpenses::IncomesAndExpenses (int userID, string IorE)
{
    recordsList.clear();
    string buffer;

    CMarkup xml;
    xml.Load(IorE+"s.xml");
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem(IorE))
    {
        Record *p_Record = new Record;

        xml.IntoElem();

        xml.FindElem("ID");
        buffer=xml.GetData();
        p_Record->setID(atoi(buffer.c_str()));

        xml.FindElem("UserID");
        buffer=xml.GetData();
        p_Record->setUserID(atoi(buffer.c_str()));

        xml.FindElem("Date");
        Date *p_dateToSet=new Date;
        p_dateToSet->setDate(xml.GetData());
        p_Record->setDate(*p_dateToSet);
        delete p_dateToSet;

        xml.FindElem("Category");
        p_Record->setCategory(xml.GetData());

        xml.FindElem("Value");
        p_Record->setValue(xml.GetData());

        xml.OutOfElem();

        if (p_Record->getUserID()==userID)
        recordsList.push_back(*p_Record);
        lastID=p_Record->getID();
        delete p_Record;
    }
}

Record IncomesAndExpenses::addRecord (int userID)
{
    Record newRecord;
    string buffer;
    vector<Record>::iterator index=recordsList.end();

    newRecord.setID(lastID+1);
    lastID+=1;

    newRecord.setUserID(userID);

    Date *p_date=new Date;
    p_date->setDate();
    newRecord.setDate(*p_date);

    do
    {
    cout<<"Podaj kategorie: ";
    cin.sync();
    getline(cin, buffer);
    newRecord.setCategory(buffer);
    }while (buffer=="");

    do
    {
    cout<<"Podaj kwote: ";
    cin.sync();
    getline(cin, buffer);
    if (buffer.find(",")!=-1)
    buffer.replace(buffer.find(","),1,".");
    newRecord.setValue(buffer);
    }while (buffer==""||newRecord.getValue()<=0);

    recordsList.push_back(newRecord);
    system("pause");
    return newRecord;
}

vector<Record> IncomesAndExpenses::getRecordsList()
{
    return recordsList;
}
