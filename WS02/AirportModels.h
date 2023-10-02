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

#ifndef  SDDS_AIRPORTMODELS_H
#define  SDDS_AIRPORTMODELS_H
#include <iostream>
#include <string>
namespace sdds
{
     struct Airport{
    std ::string code;
    std::string name;
    std::string city;
   std:: string state;
    std::string country;
    double latitude;
    double longitude;

};
 std ::ostream& operator<<(std::ostream& os, const Airport& airportinstance);//this will help display the output in the required format
  class AirportLog//the class that stores a dynamic array of the Airport and keeps count of the number of Airports
  {
      Airport* ALog{};
      size_t Log_length;
      void passAirportData(const std:: string& line, Airport& airport);//this function will set the variables of the struct based on the information it reads from the file 
      
public:
      AirportLog();//default constructor
      ~AirportLog();//destructor
      AirportLog(const AirportLog& other);//the copy constructor will be used to copy an object 
      AirportLog( AirportLog&& other) noexcept;//move constructor
      AirportLog(const char* filename);//constructor that recieves a filename and passes values
     void  addAirport( const Airport& airport);//this will add an airport
     AirportLog findAirport(const char* state_name, const char* country_name);//This will find a specified airport information
     Airport& operator[](size_t index);//[] 
     AirportLog& operator=(AirportLog&& other);
     AirportLog& operator =(const AirportLog& other);
     operator size_t() const ;
};
}
#endif
