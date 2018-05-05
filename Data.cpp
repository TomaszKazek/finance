#include <iostream>
#include "Data.h"
#include "Markup.h"
#include <sstream>

using namespace std;

void Data::addRecord(Record newRecord, string IorE)
{
    CMarkup xml;
    xml.Load(IorE+"s.xml");

    if(!xml.FindElem(IorE+"s"))
    {
        xml.AddElem(IorE+"s");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem(IorE);
    xml.IntoElem();
    xml.AddElem("ID",newRecord.getID());
    xml.AddElem("UserID",newRecord.getUserID());
    Date buffer=newRecord.getDate();
    xml.AddElem("Date",buffer.getDate());
    xml.AddElem("Category",newRecord.getCategory());
    stringstream ss;
    ss<<newRecord.getValue();
    xml.AddElem("Value",ss.str());
    xml.OutOfElem();

    xml.Save(IorE+"s.xml");
}
