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


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include <iostream>
//#include "Collection.h"
namespace sdds
{
class Book
{
	std::string m_title{};
	unsigned m_numChapters{};
	unsigned m_numPages{};
public:
    Book();
    Book(const std::string& title, unsigned nChapters, unsigned nPages);
    std::ostream& print(std::ostream& os) const;
    bool isValid() const;
    bool operator<(const Book& other) const;
    bool operator>(const Book& other) const;
    
};
std::ostream& operator<<(std::ostream& os, const Book& bk);
}
#endif