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
#ifndef __EVENTQUEUE_CPP__
#define __EVENTQUEUE_CPP__
#include "EventQueue.h"
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
EventQueue<DT>::EventQueue()
{
    slistPtr = new SortedLinkedList<DT>();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Copy Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
EventQueue<DT>::EventQueue(const EventQueue &pq)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Destructor   
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
EventQueue<DT>::~EventQueue()
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool EventQueue<DT>::isEmpty() const
{
    return SortedLinkedList<DT>::isEmpty();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool EventQueue<DT>::add(const DT &newEntry)
{
    slistPtr->insertSorted(newEntry);

    return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool EventQueue<DT>::remove()
{
    return slistPtr->remove(slistPtr->getLength()); // The highest-priority item is at the end of the sorted list
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
DT EventQueue<DT>::peek() const
{
    if (SortedLinkedList<DT>::isEmpty())
    {
        std::cout << "Event Queue is Empty!" << std::endl
                  << std::endl;
    }

    else
    {
        return slistPtr->getEntry(1);
    }
}

#endif