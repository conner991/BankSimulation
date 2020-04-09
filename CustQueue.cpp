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
#ifndef __CUSTQUEUE_CPP__
#define __CUSTQUEUE_CPP__

#include "CustQueue.h"
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor
RETURNS:           
NOTES:              
------------------------------------------------------------------------------ */
template <class DT>
CustQueue<DT>::CustQueue()
{
    listPtr = new LinkedList<DT>();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
CustQueue<DT>::CustQueue(const DT &aQueue)
{
    listPtr = aQueue->listPtr();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
CustQueue<DT>::~CustQueue()
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
bool CustQueue<DT>::isEmpty() const
{
    return listPtr->isEmpty();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
bool CustQueue<DT>::enqueue(const DT &newEntry)
{
    return listPtr->insert(listPtr->getLength() + 1, newEntry);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
bool CustQueue<DT>::dequeue()
{
    return listPtr->remove(1);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
DT CustQueue<DT>::peekFront() const
{
    if (isEmpty())
    {
        std::cout << "Queue is Empty!" << std::endl
                  << std::endl;
    }

    else
    {
        return listPtr->getEntry(1);
    }
}

#endif