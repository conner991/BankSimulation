/* ------------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       Sorted List IS A. This class is a descendent of LinkedList class
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     03-25-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __SORTEDLINKEDLIST_H__
#define __SORTEDLINKEDLIST_H__
#include "LinkedList.h"
#include "Node.h"
// #include “PrecondViolatedExcept.h”
template <class DT>
class SortedLinkedList : public LinkedList<DT>
{
public:
    SortedLinkedList();
    SortedLinkedList(const SortedLinkedList<DT> &aList);
    virtual ~SortedLinkedList();
    void insertSorted(const DT &newEntry);
    bool removeSorted(const DT &anEntry);
    int getPosition(const DT &anEntry) const;

    // The inherited methods remove, clear, getEntry, isEmpty, and
    // getLength have the same specifications as given in ListInterface.

    // The following methods must be overridden to disable their
    // effect on a sorted list:
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    DT getEntry(int position) const;
    void setEntry(int position, const ItemType &newEntry);
};

#include "SortedLinkedList.cpp"
#endif