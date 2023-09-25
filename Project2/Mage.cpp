/*
Author: Jiaxiong Guan
Project 2 - Inheritance
Date: 9/22/2023
Description: Mage.cpp defines and implements the functions of the Mage class
*/

#include "Mage.hpp"

/*
    Default constructor for the Mage class
    Sets private members to default values 
    Character name is defaulted to "NAMELESS" 
    Booleans are defaulted to false
    School of magic and weapon are defaulted to "NONE"
*/
Mage::Mage() : Character() {

    std::string none = "NONE"; // String variable for setting the character's weapon and school to "NONE"
    setSchool(none);
    setCastingWeapon(none);

    bool incarnate = false; // Bool variable for setting the character's incarnate summon to false
    setIncarnateSummon(incarnate);

}

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
Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, 
            bool enemy, const std::string& school_of_magic, const std::string& weapon, bool incarnate) : 
            Character(name, race, vitality, armor, level, enemy) {
                
    setSchool(school_of_magic);
    setCastingWeapon(weapon);
    setIncarnateSummon(incarnate);

}

/*
    @param  : A const string reference representing a character's school of magic
    @post   : Set private member variable "school_of_magic_" to the value of the provided parameter if the provided string is valid and return true
              Provided string can be lowercase, but must be converted to uppercase when setting
              If provided string is invalid (includes digits or special characters or is not [ELEMENTAL, NECROMANCY, ILLUSION]), do nothing and return false
    @return : True if the provided string is valid and setting was successful, false otherwise
*/
bool Mage::setSchool(const std::string& school_of_magic) {

    // String variable to hold the uppercase version of the given string parameter
    std::string upper_school = formatString(school_of_magic);

    // Checks to see if the given string parameter is one of [ELEMENTAL, NECROMANCY, ILLUSION]
    if(upper_school == "ELEMENTAL") {
        school_of_magic_ = "ELEMENTAL";
        return true;
    }
    else if(upper_school == "NECROMANCY") {
        school_of_magic_ = "NECROMANCY";
        return true;
    }
    else if(upper_school == "ILLUSION") {
        school_of_magic_ = "ILLUSION";
        return true;
    }
    else {
        if(school_of_magic_ == "")
            school_of_magic_ = "NONE";
        return false;
    }
}

/*
    @return : The string indicating the character's school of magic, private member "school_of_magic_"
*/
std::string Mage::getSchool() const {

    return school_of_magic_;

}

/*
    @param  : A const string reference representing a character's weapon
    @post   : Set private member variable "weapon_" to the value of the provided parameter if the provided string is valid and return true
              Provided string can be lowercase, but must be converted to uppercase when setting
              If provided string is invalid (includes digits or special characters or is not [WAND, STAFF]), do nothing and return false
    @return : True if the provided string is valid and setting was successful, false otherwise
*/
bool Mage::setCastingWeapon(const std::string& weapon_name) {

    // String variable to hold the uppercase version of the given string parameter
    std::string upper_weapon = formatString(weapon_name); 
    
    // Checks to see if the given string parameter is one of [STAFF, WAND]
    if(upper_weapon == "WAND") {
        weapon_ = "WAND";
        return true;
    }
    else if(upper_weapon == "STAFF") {
        weapon_ = "STAFF";
        return true;
    }
    else  {
        if(weapon_ == "")
            weapon_ = "NONE";
        return false;
    }
}

/*
    @return : The string indicating the character's weapon, private member "weapon_"
*/
std::string Mage::getCastingWeapon() const {

    return weapon_;

}

/*
    @param  : A const reference to a boolean indicating if the character can summon an incarnate    
    @post   : Sets the private member variable "can_summon_incarnate_" to the provided boolean value
*/
void Mage::setIncarnateSummon(const bool& incarnate) {

    can_summon_incarnate_ = incarnate;

}

/*
    @return : The boolean indicating whether the character can summon an incarnate, private member "can_summon_incarnate_"
*/
bool Mage::hasIncarnateSummon() const {

    return can_summon_incarnate_;
}

/*
    @param  : A string that needs to have all its characters in uppercase
    @post   : Creates an empty string and adds the uppercase characters in the provided string to the empty string
              Uses a for loop to loop through each character in the string and add uppercase characters to the created string
    @return : A string representing the uppercase version of the provided string
*/
std::string Mage::formatString(std::string unformatted) {
    std::string formatted = ""; // String variable to hold the uppercase version of the given string parameter

    // A for loop to capitalize all characters in the given string parameter and then adds them to "upper_school"
    for(long unsigned int i = 0; i < unformatted.length(); i++) {
        formatted += toupper(unformatted[i]);
    }

    return formatted;
}

