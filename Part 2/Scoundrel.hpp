/*
CSCI235 Fall 2023
Project 2 - Inheritance
Author: Jiaxiong Guan
Date: 9/22/2023

Description: 
Scoundrel.hpp declares the Scoundrel class along with its private and public members
The Scoundrel class is derived from the Character class and is a pickable role in the game
*/

#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP

#include "Character.hpp"

// An enum containing the types of dagger a Scoundrel can have
enum Dagger {WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE};

class Scoundrel : public Character {

private:

    Dagger dagger_; // The character's dagger
    std::string faction_; // A string representing the character's faction
    bool has_disguise_; // A boolean indicating if the character has a disguise

public:
   /*
        Default constructor for the Scoundrel class
        Sets private members to default values 
        Character name is defaulted to "NAMELESS" 
        Booleans are defaulted to false
        Dagger is defaulted to "WOOD" and faction is defaulted to "NONE"
    */
    Scoundrel();

    /*
        Parameterized constructor for the Scoundrel class
        @param  : A const string reference for the name of the character
        @param  : A const string reference for the race of the character
        @param  : An integer for the character's vitality, defaults to 0
        @param  : An integer for the character's armor, defaults to 0
        @param  : An integer for the character's level, defaults to 0
        @param  : A boolean indicating whether the character is an enemy, defaults to false
        @param  : A const string reference for the character's dagger type, valid daggers are: [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]
                  String inputs can be lowercase, but must be converted to uppercase when setting 
                  Cannot contain non-alphabetical characters
                  Defaults to WOOD if there is no provided string or if invalid string
        @param  : A const string reference for the character's faction, valid factions are: [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                  String inputs can be lowercase, but must be converted to uppercase when setting 
                  Cannot contain non-alphabetical characters
                  Defaults to "NONE" if there is no provided string or if invalid string
        @param  : A boolean indicating whether the character has a disguise, defaults to false
        @post   : Sets private members of the Scoundrel class to the values of the provided parameters 
    */
    Scoundrel(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, 
            int level = 0, bool enemy = false, const std::string& dagger = "WOOD", 
            const std::string& faction = "NONE", bool disguise = false);

    /*
        @param  : A const string reference to the character's dagger type
        @post   : Sets the private member variable "dagger_" to the provided value of the parameter if it is valid
                  String inputs can be lowercase, but must be converted to uppercase when setting 
                  Cannot contain non-alphabetical characters
                  Valid inputs are: [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]
                  If the inputs are invalid, then it should set to WOOD
    */
    void setDagger(const std::string& dagger);

    /*
        @return : A string indicating the character's dagger type
    */
    std::string getDagger() const;

    /*
        @param  : A const string reference to the character's faction
        @post   : Sets the private member variable "faction_" to the provided value of the parameter if it is valid
                  String inputs can be lowercase, but must be converted to uppercase when setting 
                  Cannot contain non-alphabetical characters
                  Valid inputs are: [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE]
                  If the inputs are invalid, then it should do nothing and return false
        @return : True if the provided string is valid and setting was successful, false otherwise
    */
    bool setFaction(const std::string& faction);

    /*
        @return : A string indicating the character's faction, private member "faction_"
    */
    std::string getFaction() const;

    /*
        @param  : A const bool reference to whether the character has a disguise
        @post   : Sets the private member "has_disguise_" to the provided parameter 
    */
    void setDisguise(const bool& disguise);

    /*
        @return : A bool indicating whether the character has a disguise, private member "has_disguise_"
    */
    bool hasDisguise() const;

    /*
    @param  : A string that needs to have all its characters in uppercase
    @post   : Creates an empty string and adds the uppercase characters in the provided string to the empty string
              Uses a for loop to loop through each character in the string and add uppercase characters to the created string
    @return : A string representing the uppercase version of the provided string
    */
    std::string formatString(std::string unformatted);

};

#endif