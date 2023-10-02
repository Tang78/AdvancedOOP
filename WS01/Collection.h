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
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Book.h"
namespace sdds
{
template <typename T, unsigned C>
class Collection {
         static T m_smallestItem;//modifier to receive an object of type T, as unmodifiable reference. It sets m_smallestItem to the received object if the received object is smaller than it.
        static T m_largestItem;
protected :
        T m_items[C];
        unsigned m_size = 0;
 static void setSmallestItem(const T& item) {
        if (item < m_smallestItem) {
            m_smallestItem = item;
           
        }
    }

    
 const T& operator[](unsigned index) const {//a mutator operator to receive an array index and return corresponding element from m_items array
    if (index >= m_size) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_items[index];
}
// Modifier to set m_largestItem
    static void setLargestItem(const T& item) {
        if (item > m_largestItem) {
            m_largestItem = item;
             //std::cout << m_largestItem <<std::endl;
        }
    }
void incrSize() {
    if (m_size < C) {
        ++m_size;
    }
}
public:
 Collection() {};
 static T getSmallestItem() {
        return m_smallestItem;
    }

    static T getLargestItem() {
        return m_largestItem;
    }
     unsigned capacity() const 
     {
         return C;
     }
     unsigned size() const 
    {
        return m_size;
    }
     
bool operator+=(const T& item) {
    if (m_size == C) {
        return false;
    } else {
        if (item < m_smallestItem || m_size == 0) {
            m_smallestItem = item;
        }
        if (item > m_largestItem || m_size == 0) {
            m_largestItem = item;
        }
        m_items[m_size] = item;
        ++m_size;
        return true;
    }
}
void print(std::ostream& os) const {
    os << "[";
    for (unsigned i = 0; i < m_size; ++i) {
        os << m_items[i];
        if (i < m_size - 1) {
            os << ",";
        }
    }
    os << "]" << '\n';
}

};

template <typename T, unsigned C>
T Collection<T, C>::m_smallestItem = 9999; 
template <typename T, unsigned C>
T Collection<T, C>::m_largestItem = -9999; 
template<>
Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);
template<>
Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);
template<>
Book Collection<Book, 72>::m_smallestItem= Book("", 1, 10000);
template<>
Book Collection<Book, 72>::m_largestItem= Book("", 10000, 1);

template<>
void Collection<Book, 10>::print (std::ostream& os) const {
    os << "| ---------------------------------------------------------------------------|" << '\n';
    for (unsigned i = 0; i < m_size; ++i) {
        // os << "| " << std::setw(75) << std::left << m_items[i] << '|\n';
             os << "| " << std::setw(75) << std::left << m_items[i] << " |\n";
    }
    os << "| ---------------------------------------------------------------------------|" << '\n';
}
template<>
void Collection<Book, 72>::print (std::ostream& os) const {
    os << "| ---------------------------------------------------------------------------|" << '\n';
    for (unsigned i = 0; i < m_size; ++i) {
        // os << "| " << std::setw(75) << std::left << m_items[i] << '\n';
             os << "| " << std::setw(75) << std::left << m_items[i] << " |\n";
    }
    os << "| ---------------------------------------------------------------------------|" << '\n';
}


}

#endif










