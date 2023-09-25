#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {

private:

    std::string main_weapon_; // A string representing their main weapon
    std::string secondary_weapon_; // A string representing their offhand weapon
    bool enraged_; // A boolean indicating if they are enraged

public:

    /*
    Default constructor for the Barbarian class
    Sets private members to default values 
    Character name is defaulted to "NAMELESS" 
    Booleans are defaulted to false
    Weapons are defaulted to "NONE"
    */
    Barbarian();

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
    Barbarian(const std::string& name, const std::string& race, int vitality = 0, 
                int level = 0, int armor = 0, bool enemy = false, const std::string& main_weapon = "NONE", 
                const std::string& offhand_weapon = "NONE", bool enraged = false);

    /*
        @param  : A const string reference to the character's main weapon 
        @post   : Sets the private member "main_weapon_" to the provided parameter if the parameter is valid and then return true
                  String inputs can be lowercase, but must be converted to uppercase when setting
                  Only alphabetical characters are allowed
                  If the input contains non-alphabetical characters then do nothing and return false
        @return : True if the provided string is valid and setting was successful, false otherwise
    */
    bool setMainWeapon(const std::string& main_weapon);

    /*
        @return : A string indicating the character's main weapon, private member "main_weapon_"
    */
    std::string getMainWeapon() const;

    /*
        @param  : A const string reference to the character's secondary weapon
        @post   : Sets the private member "secondary_weapon_" to the provided parameter if the parameter is valid and then return true
                  String inputs can be lowercase, but must be converted to uppercase when setting
                  Only alphabetical characters are allowed
                  If the input contains non-alphabetical characters then do nothing and return false
        @return : True if the provided string is valid and setting was successful, false otherwise
    */
    bool setSecondaryWeapon(const std::string& secondary_weapon);

    /*
        @return : A string indicating the character's secondary weapon, private member "secondary_weapon_"
    */
    std::string getSecondaryWeapon() const;

    /*
        @param  : A const bool reference to whether the character is enraged
        @post   : Set the private member "enraged_" to the provided parameter
    */
    void setEnrage(const bool& enrage);

    /*
        @return : A boolean of whether the character is enraged, private member "enraged_"
    */
    bool getEnrage() const;

    /*
        @post  : Sets the enraged variable to the opposite of what it is
    */
    void toggleEnrage();
};

#endif