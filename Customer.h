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
#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "CustQueue.h"
#include "EventQueue.h"

class Customer
{
public:
    int custNum;

    Customer();
    Customer(int num);
    ~Customer();
};

#endif