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
#include "Event.h"
#include "Customer.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>

// Prototypes
void simulate();
void processArrival(Event x, EventQueue<Event> y, CustQueue<Event> z);
void processDepart(Event x, EventQueue<Event> y, CustQueue<Event> z);
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
    simulate();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void simulate()
{
    int arrival, transaction, lineLength;
    char line[20]; //aString[2], tString[2];
    std::string inputLine, aString, tString;
    EventQueue<Event> PQ;
    CustQueue<Event> CQ;

    std::fstream fileIn;
    fileIn.open("InputFile.txt", std::ios::in);

    if (!fileIn)
    {
        std::cout << "\nError Opening File.\n\n";
    }

    while (fileIn) // Create and add arrivals to the EventQueue
    {
        fileIn.getline(line, 20, '\n');
        aString.assign(line, 1, 3);
        arrival = stoi(aString);
        tString.assign(line, 4, 10);
        transaction = stoi(tString);

        Event anEvent = Event(arrival, transaction);
        PQ.add(anEvent);
    }

    while (!PQ.isEmpty()) // Event Loop
    {
        Event newEvent = PQ.peek();
        int currentTime = newEvent.tTime; // Get current time

        if (newEvent.aType)
            processArrival(newEvent, PQ, CQ);
        else
            processDepart(newEvent, PQ, CQ);
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void processArrival(Event newEvent, EventQueue<Event> PQ, CustQueue<Event> CQ)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void processDepart(Event newEvent, EventQueue<Event> PQ, CustQueue<Event> CQ)
{
}