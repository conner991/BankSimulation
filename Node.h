/*------------------------------------------------------------------------------------
FILE NAME:		   Node.h

DESCRIPTION:	   Specification file for the Node class

USAGE:  	        		   

COMPILER:		   GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:

Author				             Date			    Version
---------------               ----------		 -------------
Conner Fissell		          02-13-2020		 1.0 - Set up class and Makefile. 
------------------------------------------------------------------------------------*/
#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

template <class DT>
class Node
{
private:
    DT item;        // Node data item
    Node<DT> *next; // Pointer to the next node

public:
    Node(); // Default Constructor
    Node(const DT &anItem);
    Node(const DT &anItem, Node<DT> *nextNodePtr);
    void setItem(const DT &anItem);
    void setNext(Node<DT> *nextNodePtr);
    DT getItem() const;
    Node<DT> *getNext() const;
};

#include "Node.cpp"

#endif