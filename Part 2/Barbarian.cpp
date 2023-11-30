/*
CSCI235 Fall 2023
Project 2 - Inheritance
Author: Jiaxiong Guan
Date: 9/22/2023

Description: 
Barbarian.cpp defines the constructors and private and public function implementation of the Barbarian class
The Barbarian class is derived from the Character class and is a pickable role in the game
*/

#include "Barbarian.hpp"

/*
    Default constructor for the Barbarian class
    Sets private members to default values 
    Character name is defaulted to "NAMELESS" 
    Booleans are defaulted to false
    Weapons are defaulted to "NONE"
*/
Barbarian::Barbarian() : Character() {

    bool enrage = false; // Bool variable for setting the character's enrage to false
    setEnrage(enrage); 

    std::string none = "NONE"; // String variable for setting the character's weapons to "NONE"
    setMainWeapon("NONE");
    setSecondaryWeapon("NONE");

}

/*
    Parameterized constructor for the Barbarian class
    @param  : A const string reference for the name of the character
    @param  : A const string reference for the race of the character
    @param  : An integer for the character's vitality, defaults to 0
    @param  : An integer for the character's armor, defaults to 0
    @param  : An integer for the character's level, defaults to 0
    @param  : A boolean indicating whether the character is an enemy, defaults to false
    @param  : A const string reference for the main weapon of the character
              String inputs can be lowercase, but must be converted to uppercase when setting
              Only alphabetical characters are allowed
              Default to "NONE"
    @param  : A const string reference for the offhand weapon of the character
              String inputs can be lowercase, but must be converted to uppercase when setting
              Only alphabetical characters are allowed
              Default to "NONE"
    @param  : A boolean indicating whether the character is enraged, defaults to false
    @post   : Sets private members of the Mage class to the values of the provided parameters 
*/
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, 
                        int armor, int level, bool enemy, const std::string& main_weapon,
                        const std::string& offhand_weapon, bool enraged) : 
                        Character(name, race, vitality, armor, level, enemy) {

    setMainWeapon(main_weapon);
    setSecondaryWeapon(offhand_weapon);
    setEnrage(enraged);
}

/*
    @param  : A const string reference to the character's main weapon 
    @post   : Sets the private member "main_weapon_" to the provided parameter if the parameter is valid and then return true
              String inputs can be lowercase, but must be converted to uppercase when setting
              Only alphabetical characters are allowed
              If the input contains non-alphabetical characters then do nothing and return false
    @return : True if the provided string is valid and setting was successful, false otherwise
*/
bool Barbarian::setMainWeapon(const std::string& main_weapon) {

    std::string upper_weapon = ""; // String variable to hold the uppercase version of the given string parameter
 
    for(long unsigned int i = 0; i < main_weapon.length(); i++) {

        // Check if all characters are alphabetical
        if(!(isalpha(main_weapon[i]))) {
            main_weapon_ = "NONE";
            return false;
        }
 
        else
            upper_weapon += toupper(main_weapon[i]);
    }
    main_weapon_ = upper_weapon;
    return true;

}

/*
    @return : A string indicating the character's main weapon, private member "main_weapon_"
*/
std::string Barbarian::getMainWeapon() const {

    return main_weapon_;    

}

/*
    @param  : A const string reference to the character's secondary weapon
    @post   : Sets the private member "secondary_weapon_" to the provided parameter if the parameter is valid and then return true
              String inputs can be lowercase, but must be converted to uppercase when setting
              Only alphabetical characters are allowed
              If the input contains non-alphabetical characters then do nothing and return false
    @return : True if the provided string is valid and setting was successful, false otherwise
*/
bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon) {

    std::string upper_weapon = ""; // String variable to hold the uppercase version of the given string parameter
        for(long unsigned int i = 0; i < secondary_weapon.length(); i++) {

            // Check if all characters are alphabetical
            if(!(isalpha(secondary_weapon[i]))) {
                secondary_weapon_ = "NONE";
                return false;
            }
            else 
                upper_weapon += toupper(secondary_weapon[i]);
        }
        secondary_weapon_ = upper_weapon;
        return true;

}

/*
    @return : A string indicating the character's secondary weapon, private member "secondary_weapon_"
*/
std::string Barbarian::getSecondaryWeapon() const {

    return secondary_weapon_;

}

/*
    @param  : A const bool reference to whether the character is enraged
    @post   : Set the private member "enraged_" to the provided parameter
*/
void Barbarian::setEnrage(const bool& enrage) {

    enraged_ = enrage;

}

/*
    @return : A boolean of whether the character is enraged, private member "enraged_"
*/
bool Barbarian::getEnrage() const {

    return enraged_;

}

/*
    @post  : Sets the enraged variable to the opposite of what it is
*/
void Barbarian::toggleEnrage() {

    if(enraged_) 
        enraged_ = false;
    else if(!(enraged_)) 
        enraged_ = true;

}
