#include <iostream>
#include "date.h"
#include <time.h>
#include "Markup.h"

using namespace std;

int main()
{
    time_t currentTime;
    time (&currentTime);
    tm *currentDate;
    currentDate=localtime(&currentTime);
    cout<<"Dzis mamy: "<<1900+currentDate->tm_year<<"-"<<1+currentDate->tm_mon<<"-"<<currentDate->tm_mday<<endl;

    Date d1,d2;
    d1.setDate();
    d2.setDate();
    if(d1.getDate()>d2.getDate()) cout<<"pierwsza data jest pozniejsza";
    if(d1.getDate()<d2.getDate()) cout<<"druga data jest pozniejsza";
    if(d1.getDate()==d2.getDate()) cout<<"daty sa takie same";

    CMarkup xml;
    //xml.AddElem("date",d1.getDate());
    //xml.Save("data.xml");
    xml.Load("data.xml");
    xml.FindElem();
    cout<<xml.GetData();


    return 0;
}
