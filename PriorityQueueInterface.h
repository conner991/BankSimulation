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
#ifndef __PRIORITYQUEUEINTERFACE_H__
#define __PRIORITYQUEUEINTERFACE_H__

template <class DT>
class PriorityQueueInterface
{
public:
    virtual bool isEmpty() const = 0;         // Sees whether this queue is empty.
    virtual bool add(const DT &newEntry) = 0; // Adds newEntry to this priority queue.
    virtual bool remove() = 0;                // Removes the entry with the highest priority from this priority queue.
    virtual DT peek() const = 0;              // Returns the entry in this priority queue with the highest priority. The operation does not change the priority queue.
};

#endif