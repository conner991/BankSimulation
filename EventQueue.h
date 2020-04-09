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
#ifndef __EVENTQUEUE_H__
#define __EVENTQUEUE_H__

#include "PriorityQueueInterface.h"
#include "SortedLinkedList.h"
// #include "PreCondViolatedExcept.h

template <class DT>
class EventQueue : public PriorityQueueInterface<DT>
{
private:
    SortedLinkedList<DT> *slistPtr; // Pointer to sorted list of items in the PQ
public:
    EventQueue();
    EventQueue(const EventQueue &pq);
    ~EventQueue();
    bool isEmpty() const;
    bool add(DT &newEntry);
    bool remove();
    // @throw PrecondViolatedExcept if priority queue is empty
    DT peek() const; // throw(PreCondViolatedExcept);
};

#include "EventQueue.cpp"

#endif