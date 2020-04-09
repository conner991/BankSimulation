/*------------------------------------------------------------------------------------
FILE NAME:		   LinkedList.cpp

DESCRIPTION:	   Implementation file for LinkedList and Node class

USAGE:			   

COMPILER:		   GNU g++ compiler on Linux

NOTES:              

MODIFICATION HISTORY:   

Author				              Date			   Version
---------------                 ----------		-------------
Conner Fissell		            02-08-2020		1.0 - Started building basic outline 
------------------------------------------------------------------------------------*/
#ifndef __LINKEDLIST_CPP__
#define __LINKEDLIST_CPP__
#include "LinkedList.h"

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Default Constructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
LinkedList<DT>::LinkedList()
{
    headPtr = nullptr;
    itemCount = 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Destructor for LinkedList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
LinkedList<DT>::~LinkedList()
{
    clear();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Sees whether this list is empty.
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool LinkedList<DT>::isEmpty() const
{
    return itemCount == 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Gets the current number of entries in this list.
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
int LinkedList<DT>::getLength() const
{
    return itemCount;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Inserts an entry into this list at a given position.
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool LinkedList<DT>::insert(int newPosition, const DT &newEntry)
{
    bool ableToInsert = ((newPosition >= 1) && (newPosition <= itemCount + 1));

    if (ableToInsert)
    {
        Node<DT> *newNodePtr = new Node<DT>(newEntry); // Create a new node containing the new entry

        if (newPosition == 1) // Attach new node to chain
        {
            newNodePtr->setNext(headPtr); // Insert new node at beginning of chain
            headPtr = newNodePtr;
        }

        else
        {
            Node<DT> *prevPtr = getNodeAt(newPosition - 1); // Find node that will be before new node
            newNodePtr->setNext(prevPtr->getNext());        // Insert new node after node to which prevPtr points
            prevPtr->setNext(newNodePtr);
        }

        itemCount++; // Increase count of entries
    }

    return ableToInsert;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:      Removes the entry at a given position from this list. 
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
bool LinkedList<DT>::remove(int position)
{
    bool ableToRemove = ((position >= 1) && (position <= itemCount));

    if (ableToRemove)
    {
        Node<DT> *currentptr = nullptr;

        if (position == 1)
        {
            currentptr = headPtr; // remove the first node in the chain. Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            Node<DT> *prevPtr = getNodeAt(position - 1); // Find node that is before the one to delete
            currentptr = prevPtr->getNext();             // Point to node to delete
            prevPtr->setNext(currentptr->getNext());     // Disconnect indicated node from chainby connecting the prior node with the one after
        }
        currentptr->setNext(nullptr); // Return node to system
        delete currentptr;
        currentptr = nullptr;
        itemCount--;
    }

    return ableToRemove;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Removes all entries from this list.
RETURNS:           
NOTES:             The method 'clear' can't simply set itemCount to 0, thereby 
                   ignoring all the entries in the linked chain. Because the nodes 
                   in the chain were allocated dynamically, 'clear' must deallocate
                   them.
------------------------------------------------------------------------------- */
template <class DT>
void LinkedList<DT>::clear()
{
    while (!isEmpty())
        remove(1);
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:     Gets the entry at the given position in this list.  
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
DT LinkedList<DT>::getEntry(int position)
{
    Node<DT> *nodePtr = getNodeAt(position);
    return nodePtr->getItem();
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:      Replaces the entry at the given position in this list.
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
void LinkedList<DT>::setEntry(int position, const DT &newEntry)
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:    Locates a specified node in a linked list.   
RETURNS:           
NOTES:          The private method getNodeAt locates the node at a given position by
                traversing the chain. It then returns a pointer to the located node. The traversal 
                begins at the first node of the chain and moves from node to node, counting as 
                it goes, until it reaches the desired one.

                Since getNodeAt is a private method and is called only by other methods within the class, those
                methods are responsible for honoring its precondition. Thus, we need not throw an exception if the
                precondition is violated. Rather, we simply use an assertion during debugging. 
------------------------------------------------------------------------------- */
template <class DT>
Node<DT> *LinkedList<DT>::getNodeAt(int position) const
{
    // assert((position >= 1) && (position <= itemCount)); // Debugging check of pre-condition
    Node<DT> *currentPtr = headPtr; // Count from beginning of the chain

    for (int i = 0; i < position; i++)
        currentPtr = currentPtr->getNext();

    return currentPtr;
}

#endif