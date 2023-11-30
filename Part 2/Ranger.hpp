/*
CSCI235 Fall 2023
Project 2 - Inheritance
Author: Jiaxiong Guan
Date: 9/22/2023

Description: 
Ranger.hpp declares the Ranger class along with its private and public members
The Ranger class is derived from the Character class and is a pickable role in the game
*/

#ifndef RANGER_HPP
#define RANGER_HPP

#include "Character.hpp"
#include <vector>
#include <string>


// A struct that contains the type of arrows and the quantity of each type of arrow
struct Arrows {
    std::string type_;
    int quantity_;
};

class Ranger : public Character {

private:
    std::vector<Arrows> arrows_; // A vector of Arrows 
    std::vector<std::string> affinities_; // A string vector of the character's affinities
    bool has_companion_; // A boolean indicating if the character is able to recruit a companionn

public:
    /*
        Default constructor for the Scoundrel class
        Sets private members to default values 
        Character name is defaulted to "NAMELESS" 
        Booleans are defaulted to false
    */
    Ranger();

    /*
        Parameterized constructor for the Scoundrel class
        @param  : A const string reference for the name of the character
        @param  : A const string reference for the race of the character
        @param  : An integer for the character's vitality, defaults to 0
        @param  : An integer for the character's armor, defaults to 0
        @param  : An integer for the character's level, defaults to 0
        @param  : A boolean indicating whether the character is an enemy, defaults to false
        @param  : A vector of Arrows, valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                  String inputs can be lowercase, but must be converted to uppercase when setting
                  Invalid inputs are those with non-positive quantitites or invalid types, invalid inputs are discarded
                  Defaults to empty vector
        @param  : A string vector of the character's affinities, valid affinities are: [FIRE, WATER, POISON, BLOOD]
                  String inputs can be lowercase, but must be converted to uppercase when setting
                  Invalid inputs are those invalid types and are discarded
                  Defaults to empty vector
        @param  : A boolean indicating whether the character is able to recruit an animal companion, defaults to false
        @post   : Sets private members of the Ranger class to the values of the provided parameters 
    */
    Ranger(const std::string& name, const std::string& race, int vitality = 0, int armor = 0,
            int level = 0, bool enemy = false, std::vector<Arrows> arrows = {}, 
            std::vector<std::string> affinity = {}, bool recruit = false);

    /*
        @return : An Arrows vector representing the character's arrows, private member "arrows_"
    */
    std::vector<Arrows> getArrows() const;

    /*
        @param  : A const string reference for the type of arrow
        @param  : A const int reference for the amount of a specific type of arrows
        @post   : Adds a type of arrow to the Arrows vector if the type is not already there and the quantity is positive and returns true if successful
                  Type inputs can be lowercase, but must be converted to uppercase
                  If that type of arrow is already in the vector, then the quantity is updated
                  Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                  Invalid inputs have invalid arrow types or nonpostive quantities, invalid inputs are not added and return false
        @return : True if the provided input is valid and arrows were added, false otherwise
    */
    bool addArrows(const std::string& arrow_type, const int& amount);

    /*
        @param  : A const string reference for the type of arrow
        @post   : If the character has that type of arrow in the Arrows vector and a positive amount of that type of arrows, then an arrow is fired (quantity - 1) and return true
                  Type inputs can be lowercase, but must be converted to uppercase
                  If the vector only has one of that type of arrow, then decrement to 0
                  Returns false if the type is invalid or if the amount of arrows is non-positive
        @return : True if the provided input is valid and an arrow was fired, false otherwise
    */
    bool fireArrow(const std::string& arrow_type);

    /*
        @param  : A const string reference to the character's affinity
        @post   : If the affinity does not exist in the "affinities_" vector, then add it in and return true
                  String inputs can be lowercase, but must be converted to uppercase
                  The vector should have no duplicates
                  Valid affinities are: [FIRE, WATER, POISON, BLOOD]
                  If the affinity is not valid or already exists in the vector, return false
        @return : True if the provided affinity is valid and added to the vector, false otherwise
    */
    bool addAffinity(const std::string& affinity);

    /*
        @return : A string vector of the character's affinities, private member "affinities_"
    */
    std::vector<std::string> getAffinities() const;

    /*
        @param  : A const bool reference to whether the character can recruit a companion
        @post   : Sets the private member "has_companion_" to the value of the provided parameter
    */
    void setCompanion(const bool& companion);

    /*
        @return : A boolean indicating the character's ability to recruit a companion, private member "has_companion_"
    */
    bool getCompanion() const;

    /*
        @param  : A string that needs to have all its characters in uppercase
        @post   : Creates an empty string and adds the uppercase characters in the provided string to the empty string
                  Uses a for loop to loop through each character in the string and add uppercase characters to the created string
        @return : A string representing the uppercase version of the provided string
    */
    std::string formatString(std::string unformatted);

    /*
        @param  : A string indicating the type of the arrow
        @post   : Searches through the Arrows vector "arrows_" to check the index of the type of arrow provided in the vector
        @return : Returns the index of the type of arrow in "arrows_", return -1 if the provided type is not in the vector
    */
    int checkArrows(std::string arrow_type);

    /*
        @param  : A string indicating the type of the arrow
        @post   : Checks if the provided arrow type is one of: [WOOD, FIRE, WATER, POISON, BLOOD] and returns true if the type is valid
        @return : True if the provided arrow type is valid, false otherwise
    */
    bool validArrow(std::string arrow_type);
};

#endif
