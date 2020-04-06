/* -----------------------------------------------------------------------------
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
#pragma once
#include "ListInterface.h"

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
/*
void displayList(aList)
{
    for (position = 1 through aList.getLength())
    {
        dataItem = aList.getEntry(position);
        display dataItem;
    }
}
*/

/* -----------------------------------------------------------------------------
FUNCTION:          replace()
DESCRIPTION:       Replaces the i-th entry in the list with newEntry
RETURNS:           
NOTES:             Returns true if the replacement was successful
------------------------------------------------------------------------------- */
template <class DT>
bool ListInterface<DT>::replace(int position, const DT &newEntry)
{
    bool success;
}
