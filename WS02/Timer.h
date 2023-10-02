//Orang Tang Enow, tang-enow@myseneca.ca, 149924219, 2023-09-22
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*
*****************************************************************************
                        Workshop Two
Full Name  : Orang Tang Enow
Student ID#: 149924219
Email      : otang-enow@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>

namespace sdds {
    class Timer {
    private:
        std::chrono::steady_clock::time_point startTime;

    public:
        void start() {
            startTime = std::chrono::steady_clock::now();
        }

        long long stop() {
            std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
            std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
            return duration.count();
        }
    };
}

#endif // SDDS_TIMER_H

