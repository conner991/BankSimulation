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
#include "EventQueue.h"
#include "Customer.h"
#include "CustQueue.h"

// Prototypes
void simulate();
void processArrival(Event x, EventQueue<Event> *y, CustQueue<Customer> *z, bool teller, int &curretTime);
void processDepart(EventQueue<Event> *y, CustQueue<Customer> *z, bool teller, int &currentTime);
void Delete();
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
    simulate();

    //Delete();

    std::cout << "\nSimulation Over\n\n";
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
    char line[20], eType = 'A'; //aString[2], tString[2];
    bool tellerAvail = true;
    std::string inputLine, aString, tString;
    EventQueue<Event> *PQ;
    CustQueue<Customer> *CQ;

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

        Event anEvent = Event(eType, arrival, transaction);
        PQ->add(anEvent);
        customer++;
    }

    std::cout << "\nSimulation Begins\n";

    while (!PQ->isEmpty()) // Event Loop, check for A or D flag
    {
        Event newEvent = PQ->peek();
        int currentTime = newEvent.arrTime; // Get current time

        if (newEvent.eventType == 'A')
            processArrival(newEvent, PQ, CQ, tellerAvail, currentTime);
        else
            processDepart(PQ, CQ, tellerAvail, currentTime);
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void processArrival(Event arrivalEvent, EventQueue<Event> &PQ, CustQueue<Customer> &CQ, bool tellerAvail, int &currentTime)
{
    int departTime;

    PQ.remove(); // Remove this event from the event list,
    Customer customer;
    customer.arrTime = arrivalEvent.arrTime;
    customer.transTime = arrivalEvent.tTime;

    if (CQ.isEmpty() && tellerAvail)
    {
        char eType = 'D';
        departTime = currentTime + arrivalEvent.tTime;
        Event newDepartEvent = Event(eType, departTime, 0); // create with the char D
        PQ.add(newDepartEvent);
        tellerAvail = false;
    }

    else
    {
        CQ.enqueue(customer);
    }

    std::cout << "Processing an Arrival event at time:       " << currentTime << std::endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void processDepart(EventQueue<Event> &PQ, CustQueue<Customer> &CQ, bool tellerAvail, int &currentTime)
{
    int departTime;
    char eType = 'D';

    PQ.remove(); // Remove this event from the event list
    if (!CQ.isEmpty())
    {
        Customer customer = CQ.peekFront();
        CQ.dequeue();
        departTime = currentTime + customer.arrTime;
        Event newDepartEvent = Event(eType, departTime, 0);
        PQ.add(newDepartEvent);
    }

    else
    {
        tellerAvail = true;
    }

    std::cout << "Processing a Departure event at time:       " << departTime << std::endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- 
void Delete()
{
}
*/