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

#include "CustQueue.h"
#include "EventQueue.h"

class Event
{
public:
    int arr, tTime;
    bool aType;

    Event();
    Event(int x, int y);
    ~Event();
    bool isArrival();
};

#endif