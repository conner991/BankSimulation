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
#ifndef __QUEUEINTERFACE_H__
#define __QUEUEINTERFACE_H__

template <class DT>
class QueueInterface
{
public:
    virtual bool isEmpty() const = 0;             // Sees whether this queue is empty.
    virtual bool enqueue(const DT &newEntry) = 0; // Adds a new entry to the back of this queue.
    virtual bool dequeue() = 0;                   // Removes the front of this queue.
    virtual DT peekFront() const = 0;             // Returns the front of this queue.
};

#endif

/*
A "const function", denoted with the keyword const after a function declaration, makes it a compiler 
error for this class function to change a member variable of the class. However, reading of a class 
variables is okay inside of the function, but writing inside of this function will generate a compiler error.

Another way of thinking about such "const function" is by viewing a class 
function as a normal function taking an implicit this pointer. 
So a method int Foo::Bar(int random_arg) (without the const at the end) results in a 
function like int Foo_Bar(Foo* this, int random_arg), and a 
call such as Foo f; f.Bar(4) will internally correspond to something like Foo f; Foo_Bar(&f, 4). 
Now adding the const at the end (int Foo::Bar(int random_arg) const) can 
then be understood as a declaration with a const this pointer: int Foo_Bar(const Foo* this, int random_arg). 
Since the type of this in such case is const, no modifications of member variables are possible.

It is possible to loosen the "const function" restriction of not allowing the function to write to 
any variable of a class. To allow some of the variables to be writable even 
when the function is marked as a "const function", these class variables are marked with the 
keyword mutable. Thus, if a class variable is marked as mutable, and a "const function" 
writes to this variable then the code will compile cleanly and the variable is possible to change. (C++11)

As usual when dealing with the const keyword, changing the location of the const 
key word in a C++ statement has entirely different meanings. The above usage of const only 
applies when adding const to the end of the function declaration after the parenthesis.

const is a highly overused qualifier in C++: the syntax and ordering is often not straightforward 
in combination with pointers. Some readings about const correctness and the const keyword:
*/
