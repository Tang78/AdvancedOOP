#pragma once
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <string>
extern double g_taxrate;
extern double g_discount;

namespace sdds
{
class RideRequest {
char customer_name[11];
char* extra_details; 
double price;
bool ondiscount;
public:
RideRequest();//defautlt constructor 
RideRequest(const RideRequest& other);//copy constructor 
~RideRequest();//destructor
void read (std::istream& is);//this function will read from the files into the attrivutes of the class
RideRequest& operator=(const RideRequest& other);//the copy assignment operator
void display() const ;//this function will display the attributes in a given format 
};
/*This are helper functions */
std::istream& operator>>(std::istream& is, RideRequest& riderequest);
void operator>>(const RideRequest& riderequest1, RideRequest& riderequest2);
}
#endif

