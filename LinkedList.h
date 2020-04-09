/*------------------------------------------------------------------------------------
FILE NAME:		   LinkList.h

DESCRIPTION:	   Specification file for the LinkList class

USAGE:  	       Used in conjunction with the Int_List.cpp file for the linked_list_demo.cpp driver file 		   

COMPILER:		   GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:

Author				             Date			    Version
---------------               ----------		 -------------
Conner Fissell		          02-08-2020		 1.0 - Set up class and Makefile. 
------------------------------------------------------------------------------------*/
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"
#include "ListInterface.h"

template <class DT>
class LinkedList : public ListInterface<DT>
{
private:
    Node<DT> *headPtr; // Pointer to first node in the chain (contains the first entry in the list)
    int itemCount;     // Current count of list items

    // Locates a specified node in a linked list.
    // @pre position is the number of the desired node;
    // position >= 1 and position <= itemCount.
    // @post The node is found and a pointer to it is returned.
    // @param position The number of the node to locate.
    // @return A pointer to the node at the given position.
    Node<DT> *getNodeAt(int position) const;

public:
    LinkedList();                            // Default Constructor
    LinkedList(const LinkedList<DT> &aList); // Copy Constructor
    virtual ~LinkedList();                   // Virtual Destructor
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const DT &newEntry);
    bool remove(int position);
    void clear();
    DT getEntry(int position);
    void setEntry(int position, const DT &newEntry);
};

#include "LinkedList.cpp"

#endif