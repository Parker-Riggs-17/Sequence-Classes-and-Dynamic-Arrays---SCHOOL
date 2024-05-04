/*************************************************************************
 * This is the header file for a class called Profile. It holds some Profile
 * information about a single Instagram profile, just their name and 
 * birthday. It uses a class called Date for the storage of the birthday. 
 * The member functions are just accessors and input/output functions.
 * 
 * Patricia Lindner	    Spring 2024		Ohio University
*************************************************************************/

#include <iostream>
#include <string>
#include "date.h"
#ifndef PROFILE_H
#define PROFILE_H

class Profile{
    public:
		Profile(std::string n = "N/A", Date d = Date()){
			name = n;
			bday = d;
		}	//Default Constructor for Profile

		std::string get_name()const;	// Returns the name of Profile
		Date get_bday()const;	// Returns b-day of Profile

		bool operator == (const Profile& other)const; // Overloaded == Operator
		bool operator != (const Profile& other)const; // Overloaded != Operator

		void input(std::istream& ins);	// Input function to input Profile to instream
		void output(std::ostream& outs)const; // Output function to Output Profile
		
    private:
		std::string name;
		Date bday;
};

std::istream& operator >> (std::istream& ins, Profile& p);	// Overloaded Extraction Operator
std::ostream& operator << (std::ostream& outs, const Profile& p);	// Overloaded Insertion Operator

#endif