/**
 * problem description:  Design the following classes: FrontListIsA, FrontListHasA, FrontListAsA.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/19/2023
*/

/**
 * Abstract class for the ADT FrontList.
 * Defines the operations that can be performed on the list.
 */

#ifndef FRONTLIST_INTERFACE
#define FRONTLIST_INTERFACE

// Abstract class (interface) for the ADT FrontList
template <typename ItemType>
class FrontListInterface {
public:
    /**
     * Inserts a new item at the front of the list.
     * @param newEntry The item to be inserted.
     * @return True if the insertion is successful, false otherwise.
     */
    virtual bool insert(const ItemType& newEntry) = 0;

    /**
     * Removes the item at the front of the list.
     * @return True if the removal is successful, false otherwise.
     */
    virtual bool remove() = 0;

    /**
     * Retrieves the item at the front of the list.
     * @return The item at the front of the list.
     */
    virtual ItemType retrieve() const = 0;

    /**
     * Destructor to ensure proper deallocation of memory.
     */
    virtual ~FrontListInterface() {}
};
#endif
