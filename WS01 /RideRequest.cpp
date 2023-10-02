//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*Name. : ORANG TANG ENOW, 
Seneca email:otang-enow@myseneca.ca, 
Seneca Student ID :149924219
 Date :Saturday September 16
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstring>
#include "RideRequest.h"
using namespace sdds;
using namespace std;
double g_taxrate;
double g_discount;

RideRequest::RideRequest() : extra_details(nullptr), price(0.0), ondiscount(false) 
{
            customer_name[0] = '\0';
        }
        
RideRequest::~RideRequest() 
{
    delete[] extra_details;
    extra_details = nullptr;
}
void RideRequest::read(istream& is) {
    char discount;
    if (!is.good()) {
        return;
    }

    std::string temp;
    getline(is, temp, ',');
    strncpy(customer_name, temp.c_str(), sizeof(customer_name) - 1);
    customer_name[sizeof(customer_name) - 1] = '\0';

    getline(is, temp, ',');
    delete[] extra_details;
    extra_details = nullptr;
    extra_details = new char[temp.length() + 1];
    strcpy(extra_details, temp.c_str());

    is >> price;
    is.ignore();
    is >> discount;
    ondiscount = (discount == 'Y');
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
RideRequest::RideRequest(const RideRequest& other): extra_details(nullptr), price(0.0), ondiscount(false)
{
    std::strncpy(customer_name, other.customer_name, sizeof(customer_name) - 1);
     customer_name[sizeof(customer_name) - 1] = '\0'; // Ensure null-termination
     delete[] extra_details;
   extra_details = new char[strlen(other.extra_details) + 1];
    strcpy(extra_details, other.extra_details);
     price = other.price;
   ondiscount = other.ondiscount;
}
RideRequest&::RideRequest :: operator=(const RideRequest& other){
    if (this != &other) {
        std::strncpy(customer_name, other.customer_name, sizeof(customer_name) - 1);
     customer_name[sizeof(customer_name) - 1] = '\0'; // Ensure null-termination
     delete[] extra_details;
  extra_details = new char[strlen(other.extra_details) + 1];
       strcpy(extra_details, other.extra_details);
        price = other.price;
   ondiscount = other.ondiscount;
    }
    return *this;
}
void RideRequest::display() const 
{
    static int counter = 1;

    if (customer_name[0] =='\0' )
    {
        std::cout << std::setw(2) << counter << ". " << "No Ride Request" << std::endl;
    }
    else 
    {
        double taxedPrice = price * (1+ g_taxrate);
        
        std::cout << std::left << std::setw(2) << counter << ". ";
        std::cout << std::left << std::setw(10) <<customer_name ;
        std::cout << "|" << std::left << std::setw(25) << std::fixed << extra_details;
        std::cout << "|" << std::fixed << std::setprecision(2) << std::setw(12) << taxedPrice << "|";
         if (ondiscount)
       {
           double discountedPrice = ondiscount ? taxedPrice -  g_discount : 0;

            std::cout << std::setw(13) <<std::right << std::fixed <<std::setprecision(2) << discountedPrice;
         }
       std::cout << std::endl;
    
   }
    ++counter;
}
std::istream& sdds::operator>>(std::istream& is, RideRequest& riderequest)
{
    riderequest.read(is);
    return is;
}
void operator>>(const RideRequest& riderequest1, RideRequest& riderequest2)
{
    riderequest2 = riderequest1;
}


