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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include"AirportModels.h"
 using namespace std;
 namespace sdds{
 
 
 AirportLog::AirportLog() :ALog(nullptr), Log_length(0) {}
 
 void AirportLog:: addAirport( const Airport& airport)
 {
     
     // Create a new array with increased size
		Airport* newALog = new Airport[Log_length + 1];

		copy(ALog, ALog + Log_length, newALog);

		newALog[Log_length] = airport;
		delete[] ALog;
		ALog = newALog;
		++Log_length;
     }
 AirportLog::AirportLog(const char* filename)
 {
     fstream my_file(filename);
     if(!my_file.is_open())
     {
         return ;
     }
       else
     {
        std::string line;
        std::getline(my_file, line);
        size_t count =0;
        while (std::getline(my_file, line)) 
        {
        if(!line.empty())
           ++count;
        }
        my_file.close();
       my_file.open(filename);
       Log_length = count;
       ALog = new Airport[Log_length];
       size_t index = 0;
       std::getline(my_file, line);

        // Read airport data and populate the ALog array
        while(getline(my_file, line))
        {
        if(!line.empty())
        {
            Airport& airport = ALog[index];
            passAirportData(line, airport);
            ++index;// Handle an error if reading fails (e.g., throw an exception or return)
        }
    }
    my_file.close();
 }
 }
 void AirportLog::passAirportData(const string& line, Airport& airport)
	{
		std::istringstream iss(line);

		
		std::getline(iss, airport.code, ',');
		std::getline(iss, airport.name, ',');
	    std::getline(iss, airport.city, ',');
        std::getline(iss, airport.state, ',');               
		std::getline(iss, airport.country, ',');
	   	iss >> airport.latitude;
        iss.ignore(); // Ignore the comma separator
        iss >> airport.longitude;
}
	ostream& operator<<(ostream& os, const Airport& airportinstance)
 {
     char originalFill = os.fill();// this prevents the set fill from working on the statistics column so that only the variables of the Airport have setfill
     if(airportinstance.code.empty())
     {
         os << "Empty Airport" ;
     }
     else
     {
            os << std::right << std::setw(23) << std::setfill('.') << "Airport Code : " << std::left << std::setw(30) << std::setfill('.') << airportinstance.code << '\n';
            os << std::right << std::setw(23) << "Airport Name : " << std::left << std::setw(30) << std::setfill('.') << airportinstance.name << '\n';
            os << std::right << std::setw(23) << "City : " << std::left << std::setw(30) << std::setfill('.') << airportinstance.city << '\n';
            os << std::right << std::setw(23) << "State : " << std::left << std::setw(30) << std::setfill('.') << airportinstance.state << '\n';
            os << std::right << std::setw(23) << "Country : " << std::left << std::setw(30) << std::setfill('.') << airportinstance.country << '\n';
            os << std::right << std::setw(23) << "Latitude : " << std::left << std::setw(30) << std::setfill('.') << airportinstance.latitude << '\n';
            os << std::right <<std:: setw(23) <<"Longitude : " << std::left << std::setw(30) << std::setfill('.') << airportinstance.longitude << '\n';
        }
        os.fill(originalFill);
        return os;
     
 }
 
 
     AirportLog AirportLog::findAirport(const char* state_name, const char* country_name)
      {
          AirportLog filteredAirports;

    for (size_t i = 0; i < Log_length; ++i) 
    {
        const Airport& airport = ALog[i];
        if (strcmp(airport.state.c_str(), state_name) == 0 && strcmp(airport.country.c_str(), country_name) == 0) {
            filteredAirports.addAirport(airport);
        }
    }

    return filteredAirports;
      }
Airport&  AirportLog::operator[](size_t index) 
{
    static Airport emptyAirport;
    if (index < Log_length) {
        return ALog[index];
    } else {
        return emptyAirport; // Return an empty Airport for invalid index
    }
}
AirportLog::operator size_t() const {
    return Log_length;
}
AirportLog::AirportLog(const AirportLog& other)	: ALog(nullptr), Log_length(other.Log_length)
	{
		*this = other;
	}
AirportLog& AirportLog::operator =(const AirportLog& other)
{
    if(this != &other)
    {
        delete [] ALog;
        Log_length = other.Log_length;
        if (other.ALog)
        {
            ALog = new Airport[Log_length];
				for (size_t i = 0; i < Log_length; ++i)
					ALog[i] = other.ALog[i];
        }
        else
        {
            ALog = nullptr;
        }
    }
    return *this;
}

 AirportLog::AirportLog(AirportLog&& other) noexcept: ALog(other.ALog), Log_length(other.Log_length) {
    other.ALog = nullptr; // Leave the source object in an empty state
    other.Log_length = 0;
}
AirportLog& AirportLog::operator=(AirportLog&& other)
{
    
    if(this != &other)
    {
    delete [] ALog;
    Log_length = other.Log_length;
    ALog = other.ALog;
    other.ALog = nullptr;
    other.Log_length = 0;
       }
    
    return *this;
}
AirportLog::~AirportLog() 
{ 
    delete[] ALog;
};






}
 
 
 
 
 
 
 
 
 
