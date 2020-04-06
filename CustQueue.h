/* ------------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       ADT queue: ADT list implementation. 
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     03-25-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __CUSTQUEUE_H__
#define __CUSTQUEUE_H__

#include "QueueInterface.h"
#include "LinkedList.h"
// #include "PreCondViolatedExcept.h"

template <class DT>
class CustQueue : public QueueInterface<DT>
{
private:
    LinkedList<DT> *listPtr; // Pointer to list of queue items

public:
    CustQueue();
    CustQueue(const DT &aQueue);
    ~CustQueue();

    // Methods
    bool isEmpty() const;
    bool enqueue(const DT &newEntry);
    bool dequeue();
    DT peekFront() const; // throw (PreCondViolatedExcept) @throw PreCondViolatedExcept if the queue is empty
};

#include "CustQueue.cpp"

#endif