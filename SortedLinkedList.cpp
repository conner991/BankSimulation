/*------------------------------------------------------------------------------------
FILE NAME:		   Node.cpp

DESCRIPTION:	   Implementation file for the Node class

USAGE:			   

COMPILER:		   GNU g++ compiler on Linux

NOTES:              

MODIFICATION HISTORY:

Author				              Date			   Version
---------------                 ----------		-------------
Conner Fissell		            02-08-2020		1.0 - Started building basic outline 
------------------------------------------------------------------------------------*/
#ifndef __SORTEDLINKEDLIST_CPP__
#define __SORTEDLINKEDLIST_CPP__
#include "SortedLinkedList.h"
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
SortedLinkedList<DT>::SortedLinkedList()
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Copy Constructor
RETURNS:           
NOTES:            Invokes LinkedList’s copy constructor by using an initializer: 
------------------------------------------------------------------------------- */
template <class DT>
SortedLinkedList<DT>::SortedLinkedList(const SortedLinkedList<DT> &sList) : LinkedList<DT>(sList)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Destructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
SortedLinkedList<DT>::~SortedLinkedList()
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool SortedLinkedList<DT>::isEmpty() const
{
    return LinkedList<DT>::isEmpty();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Inserts an entry into this sorted list in its proper order
                    so that the list remains sorted.??
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
void SortedLinkedList<DT>::insertSorted(const DT &newEntry)
{
    int newPosition = getPosition(newEntry);

    // We need to call the LinkedList version of insert, since the
    // SortedLinkedList version does nothing but return false
    LinkedList<DT>::insert(newPosition, newEntry);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
bool SortedLinkedList<DT>::removeSorted(const DT &anEntry)
{
    bool ableToRemove = false;
    if (!LinkedList<DT>::isEmpty())
    {
        int position = getPosition(anEntry);
        ableToRemove = position > 0;

        if (ableToRemove)
            ableToRemove = LinkedList<DT>::remove(position);
    }

    return ableToRemove;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:              
------------------------------------------------------------------------------- */
template <class DT>
int SortedLinkedList<DT>::getPosition(const DT &anEntry) const
{
    int position = 1;
    int length = LinkedList<DT>::getLength();

    while ((position <= length) && (anEntry > LinkedList<DT>::getEntry(position)))
    {
        position++;
    }

    if ((position > length) || (anEntry != LinkedList<DT>::getEntry(position)))
    {
        position = -position;
    }

    return position;
}

#endif