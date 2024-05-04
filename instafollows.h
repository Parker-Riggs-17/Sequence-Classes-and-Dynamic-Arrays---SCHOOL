/*************************************************************************
 * This class is a container that holds objects of the class Profile.
 * It uses an internal iterator to give the application the ability to
 * order the container and access the elements in the container.
 * Because it uses dynamic memory, it must have the Big 3.
 * 
 * Patricia Lindner     Spring 2024		Ohio University EECS
*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "profile.h"
#ifndef INSTAF_H
#define INSTAF_H

class InstaFollows{
    public:
        InstaFollows(); // Default Constructor for InstaFollows

        //The functions known as the Big 3
        ~InstaFollows();    // InstaFollows Deconstructor
        InstaFollows(const InstaFollows& other);    // InstaFollows Copy function
        void operator = (const InstaFollows& other);    // InstaFollows overloaded = operator

        // Functions for the internal iterator
        void start();   // Starting point of the array
        void advance(); // Advances through the array
        bool is_item()const; // Returns true of false depending on if you're pointing at an item or not
        Profile current()const; // Returns the current item being pointed at
        void remove_current(); // Removes current Item being pointed at
        void insert(const Profile& p); // Adds a new item right before current_index or at index 0 if iterator is invalid
        void attach(const Profile& p); // Adds and item right after the current index or at the very end if iterator is invalid
        
        // Other useful functions
        void show_all(std::ostream& outs)const; // Outputs all profiles
        void bday_sort(); // Sorts followers based on their birthdays
        Profile find_profile(const std::string& name)const; // Finds a given profile based off the name of profile
        bool is_profile(const Profile& p) const; // Returns true or false depending on if the profile entered is real or not

        // File I/O functions
        void load(std::istream& ins);   // Loads info into txt file
        void save(std::ostream& outs)const; // Saves txt file

    private:
        Profile *data;
        int used;
        int capacity;
        int current_index;

        void resize();  // Resizes array if no more room
};

#endif