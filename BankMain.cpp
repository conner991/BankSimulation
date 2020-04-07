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
void processArrival(Event x, EventQueue<Event> *y, CustQueue<Customer> *z);
void processDepart(Event x, EventQueue<Event> *y, CustQueue<Customer> *z);
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
    int customer = 1;
    int arrival, transaction;
    char line[20]; //aString[2], tString[2];
    std::string inputLine, aString, tString;
    EventQueue<Event> *PQ = new EventQueue<Event>();
    CustQueue<Customer> *CQ = new CustQueue<Customer>();

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
        PQ->add(anEvent);
        anEvent.cust(customer);
        customer++;
    }

    while (!PQ->isEmpty()) // Event Loop
    {
        Event newEvent = PQ->peek();
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
void processArrival(Event arrivalEvent, EventQueue<Event> PQ, CustQueue<Customer> CQ)
{
    bool removed = PQ.remove(); // Remove this event from the event list
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void processDepart(Event departEvent, EventQueue<Event> PQ, CustQueue<Customer> CQ)
{
}