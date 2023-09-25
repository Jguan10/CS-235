/*
Author: Jiaxiong Guan
Project 2 - Inheritance
Date: 9/22/2023
Description: header file for the Mage class
*/

#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"

class Mage : public Character {

private:

    std::string school_of_magic_;   // A string that represents their school of magic
    std::string weapon_;            // A string that represents their weapon
    bool can_summon_incarnate_;     // A boolean indicating if they are able to summon an incarnate

public:
    /*
        Default constructor for the Mage class
        Sets private members to default values 
        Character name is defaulted to "NAMELESS" 
        Booleans are defaulted to false
        School of magic and weapon are defaulted to "NONE"

    */
    Mage();

    /*
        Parameterized constructor for the Mage class
        @param  : A const string reference for the name of the character
        @param  : A const string reference for the race of the character
        @param  : An integer for the character's vitality, defaults to 0
        @param  : An integer for the character's armor, defaults to 0
        @param  : An integer for the character's level, defaults to 0
        @param  : A boolean indicating whether the character is an enemy, defaults to false
        @param  : A const string reference for the character's school of magic, valid schools are: [ELEMENTAL, NECROMANCY, ILLUSION]
                  String inputs can be lowercase, but must be converted to uppercase when setting 
                  Cannot contain non-alphabetical characters
                  Defaults to "NONE" if there is no provided string or if invalid string 
        @param  : A const string reference for the character's weapon, valid weapons are: [WAND, STAFF]
                  String inputs can be lowercase, but must be converted to uppercase when setting 
                  Cannot contain non-alphabetical characters
                  Defaults to "NONE" if there is no provided string or if invalid string 
        @param  : A boolean indicating whether or not the character can summon an incarnate, defaults to false
        @post   : Sets private members of the Mage class to the values of the provided parameters 

    */
    Mage(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, 
        int level = 0, bool enemy = false, const std::string& school_of_magic = "NONE", 
        const std::string& weapon_name = "NONE", bool incarnate = false);

    /*
        @param  : A const string reference representing a character's school of magic
        @post   : Set private member variable "school_of_magic_" to the value of the provided parameter if the provided string is valid and return true
                  Provided string can be lowercase, but must be converted to uppercase when setting
                  If provided string is invalid (includes digits or special characters or is not [ELEMENTAL, NECROMANCY, ILLUSION]), do nothing and return false
        @return : True if the provided string is valid and setting was successful, false otherwise
    */
    bool setSchool(const std::string& school_of_magic);

    /*
        @return : The string indicating the character's school of magic, private member "school_of_magic_"
    */
    std::string getSchool() const;

    /*
        @param  : A const string reference representing a character's weapon
        @post   : Set private member variable "weapon_" to the value of the provided parameter if the provided string is valid and return true
                  Provided string can be lowercase, but must be converted to uppercase when setting
                  If provided string is invalid (includes digits or special characters or is not [WAND, STAFF]), do nothing and return false
        @return : True if the provided string is valid and setting was successful, false otherwise
    */
    bool setCastingWeapon(const std::string& weapon_name);

    /*
        @return : The string indicating the character's weapon, private member "weapon_"
    */
    std::string getCastingWeapon() const;

    /*
        @param  : A const reference to a boolean indicating if the character can summon an incarnate    
        @post   : Sets the private member variable "can_summon_incarnate_" to the provided boolean value
    */
    void setIncarnateSummon(const bool& incarnate);

    /*
        @return : The boolean indicating whether the character can summon an incarnate, private member "can_summon_incarnate_"
    */
    bool hasIncarnateSummon() const;

    /*
        @param  : A string that needs to have all its characters in uppercase
        @post   : Creates an empty string and adds the uppercase characters in the provided string to the empty string
                  Uses a for loop to loop through each character in the string and add uppercase characters to the created string
        @return : A string representing the uppercase version of the provided string
    */
    std::string formatString(std::string unformatted);
};

#endif