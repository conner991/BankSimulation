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
#ifndef __LISTINTERFACE_H__
#define __LISTINTERFACE_H__

template <class DT>
class ListInterface
{
public:
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool insert(int newPosition, const DT &newEntry) = 0;
    virtual bool remove(int position) = 0;
    virtual void clear() = 0;
    virtual DT getEntry(int position) = 0;
    virtual void setEntry(int position, const DT &newEntry) = 0;
};

#endif

/** Sees whether this list is empty.
@return True if the list is empty; otherwise returns false. */
// ==========================
/** Gets the current number of entries in this list.
@return The integer number of entries currently in the list. */
// ===========================
/** Inserts an entry into this list at a given position.
@pre None.
@post If 1 <= position <= getLength() + 1 and the insertion is
 successful, newEntry is at the given position in the list,
 other entries are renumbered accordingly, and the returned
 value is true.
@param newPosition The list position at which to insert newEntry.
@param newEntry The entry to insert into the list.
@return True if insertion is successful, or false if not. */
// ============================
/** Removes the entry at a given position from this list.
@pre None.
@post If 1 <= position <= getLength() and the removal is successful,
 the entry at the given position in the list is removed, other
 items are renumbered accordingly, and the returned value is true.
@param position The list position of the entry to remove.
@return True if removal is successful, or false if not. */
// ============================
/** Removes all entries from this list.
@post List contains no entries and the count of items is 0. */
// =============================
/** Gets the entry at the given position in this list.
@pre 1 <= position <= getLength().
@post The desired entry has been returned.
@param position The list position of the desired entry.
@return The entry at the given position. */
// ==============================
/** Replaces the entry at the given position in this list.
@pre 1 <= position <= getLength().
@post The entry at the given position is newEntry.
@param position The list position of the entry to replace.
@param newEntry The replacement entry. */