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
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
DT EventQueue<DT>::peek() const
{
}

#endif