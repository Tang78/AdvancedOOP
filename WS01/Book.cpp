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
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include "Book.h"
namespace sdds{

Book::Book() : m_title(""), m_numChapters(1), m_numPages(1) {}
Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}


std::ostream& operator<<(std::ostream& os, const Book& bok) 
{
    return bok.print(os);
}

bool Book::operator>(const Book& other) const {
    double ratio = static_cast<double>(m_numPages) / m_numChapters;
    double otherRatio = static_cast<double>(other.m_numPages) / other.m_numChapters;
    return ratio > otherRatio;
}
bool Book::operator<(const Book& other) const {
    double ratio = static_cast<double>(m_numPages) / m_numChapters;
    double otherRatio = static_cast<double>(other.m_numPages) / other.m_numChapters;
    return ratio < otherRatio;
}

std::ostream& Book::print(std::ostream& os) const {
    if (isValid()) {
        std::string Field = m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages);
        std::string average = "(" + std::to_string(static_cast<double>(m_numPages) / m_numChapters) + ")";
        os << std::setw(56) << std::right << Field << " | " 
           << std::setw(15) << std::left << average  ;

    } else {
        os << "| Invalid book data";
    }
    return os;
}

bool Book::isValid() const {
    return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
}
}
