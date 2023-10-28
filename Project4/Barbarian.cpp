/*
CSCI235 Fall 2023
Project 4 - The Tainted Stew
Author: Jiaxiong Guan
Date: 10/27/23
Modified from Georgina Woo's Barbarian.cpp file

Description:
Barbarian.cpp defines the constructors and private and public function implementation of the Barbarian class
The Barbarian class is derived from the Character class and is a pickable role in the game
*/

#include "Barbarian.hpp"

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default weapons: "NONE". 
*/
Barbarian::Barbarian() : Character(), main_weapon_{"NONE"},secondary_weapon_{"NONE"},enraged_{false}
{
}

/**
    Parameterized constructor.
    @param      : The name of the character (a string)
    @param      : The race of the character (an enum)
    @param      : The character's vitality (an integer)
    @param      : The character's max armor level (an integer)
    @param      : The character's level (an integer)
    @param      : A flag indicating whether the character is an enemy
    @param      : The character's main weapon (a string). String inputs can be in lowercase, 
                  but must be converted to uppercase when setting the variable.
                  Only alphabetical characters are allowed.
    @param      : The character's offhand weapon (a string). String inputs can be in lowercase, 
                  but must be converted to uppercase when setting the variable.
                  Only alphabetical characters are allowed.
    @param      : A flag indicating whether the character is enraged, false by default
    @post       : The private members are set to the values of the corresponding parameters. 
                  If the main and secondary weapons are not provided or invalid, the variables are set to "NONE".
*/
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& main_weapon, const std::string& secondary_weapon, bool enraged)
: Character(name, race, vitality, armor, level, enemy), enraged_(enraged)
{
    if(!setMainWeapon(main_weapon))
    {
        main_weapon_ = "NONE";
    }
    if(!setSecondaryWeapon(secondary_weapon))
    {
        secondary_weapon_ = "NONE";
    }
}

/**
    @param  : a reference to a string representing the Character's main weapon
    @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
            : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setMainWeapon(const std::string& main_weapon)
{
    std::string temp = main_weapon;
    for (long unsigned int i = 0; i < temp.length(); i++)
    {
        if (!isalpha(temp[i]))
        {
            return false;
        }
        else
        {
            temp[i] = toupper(temp[i]);
        }
    }
    main_weapon_ = temp;
    return true;
}

/**
    @return  : a string of the Character's main weapon
**/
std::string Barbarian::getMainWeapon() const
{
    return main_weapon_;
}

/**
    @param  : a reference to a string representing the Character's secondary weapon
    @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
            : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon)
{
    std::string temp = secondary_weapon;
    for (long unsigned int i = 0; i < temp.length(); i++)
    {
        if (!isalpha(temp[i]))
        {
            return false;
        }
        else
        {
            temp[i] = toupper(temp[i]);
        }
    }
    secondary_weapon_ = temp;
    return true;
}

/**
    @return  : a string of the Character's secondary weapon
**/
std::string Barbarian::getSecondaryWeapon() const
{
    return secondary_weapon_;
}

/**
    @param  : a reference to a bool
    @post   : sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage(const bool& enraged)
{
    enraged_ = enraged;
}

/**
    @return  : a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage() const
{
    return enraged_;
}

/**
    @post   : sets the enraged variable to the opposite of what it was
**/
void Barbarian::toggleEnrage()
{
    enraged_ = !enraged_;
}

/**
    @post     : displays Barbarian data in the form:
        "[NAME] is a Level [LEVEL] [RACE] BARBARIAN.
        \nVitality: [VITALITY]
        \nArmor: [ARMOR]
        \nThey are [an enemy/not an enemy].
        \nMain Weapon: [MAINWEAPON]
        \nOffhand Weapon: [OFFHANDWEAPON]
        \nEnraged: [TRUE/FALSE]
        \n\n"
        
        Example:
        BONK is a Level 5 HUMAN BARBARIAN.
        Vitality: 11
        Armor: 5
        They are an enemy.
        Main Weapon: MACE
        Offhand Weapon: ANOTHERMACE
        Enraged: TRUE 
*/
void Barbarian::display() const {

    // Strings for printing enemy and enraged status
    std::string enemy = isEnemy() ? "They are an enemy." : "They are not an enemy.";
    std::string enraged = getEnrage() ? "TRUE\n\n" : "FALSE\n\n";

    std::cout << getName() << " is a Level " << getLevel() << " " << getRace() << " BARBARIAN."
        << "\nVitality: " << getVitality() << "\nArmor: " << getArmor() 
        << "\n" << enemy << "\nMain Weapon: " << getMainWeapon() 
        << "\nOffhand Weapon: " << getSecondaryWeapon() << "\nEnraged: " << enraged;
}

/**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens.
    
    If the character is NOT UNDEAD, Vitality is set to 1. 
    In addition, as a Barbarian: 
    Become enraged if the character was not enraged, and not enraged if they were already enraged. 
    If they have now become enraged, the offhand weapon is replaced with "TABLE". 
    If they are now not enraged, the main weapon is replaced with "BUCKET".
*/
void Barbarian::eatTaintedStew() {
    
    int vitality = 0; // int value for setting vitality
    if(getRace() == "UNDEAD") {

        vitality = getVitality() + 3;
        setVitality(vitality);
    }
    else {

        vitality = 1;
        setVitality(vitality);

        // Become enraged if not enraged, and become not enraged if enraged
        bool enrage = !(getEnrage());
        setEnrage(enrage);

        if(getEnrage()) {
            std::string table = "TABLE";
            setSecondaryWeapon(table);
        }
        else {
            std::string bucket = "BUCKET";
            setMainWeapon(bucket);
        }
    }
}