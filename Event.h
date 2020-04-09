/* ------------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     03-25-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __EVENT_H__
#define __EVENT_H__

class Event
{
public:
    int arrTime, tTime, departTime; // char for A or D,
    char eventType;
    Event(char type, int AT, int TT);
    ~Event();
    //Event(bool type, int &newTime);
    // void cust(int num);
    //bool isArrival(bool type);
    //void typeInfo(bool type, int &time);
};

#include "Event.cpp"

#endif