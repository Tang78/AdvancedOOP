/*
*****************************************************************************
						MileStone Two
Full Name  : Orang Tang Enow 
Student ID#: 149924219
Email      : otang-enow@myseneca.ca
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#ifndef ORDEREDCOLLECTION_H
#define ORDEREDCOLLECTION_H
#include "Collection.h"
namespace sdds 
{


template <typename T>
class OrderedCollection : public Collection<T, 72> {
public:
    bool operator+=(const T& item)  {
        if (this->size() >= this->capacity()) {
            return false;
        }

        unsigned insertIndex = 0;
        while (insertIndex < this->size() && item > this->m_items[insertIndex]) {
            ++insertIndex;
        }

        // Shift elements to make space for the new item
        for (unsigned i = this->size(); i > insertIndex; --i) {
            this->m_items[i] = this->m_items[i - 1];
        }

        // Insert the new item at the correct position
        this->m_items[insertIndex] = item;

        // Update smallest, largest items, and size
        if (this->size() == 0 || item < this->getSmallestItem()) {
            this->setSmallestItem(item);
        }
        if (item > this->getLargestItem()) {
            this->setLargestItem(item);
        }
        this->incrSize();

        return true;
    }
};



} // namespace sdds

#endif // ORDEREDCOLLECTION_H
