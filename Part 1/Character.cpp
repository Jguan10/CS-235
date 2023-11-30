/*
Author: Jiaxiong Guan
Date: 9/7/2023
Description: character.cpp, implementation and definitions of functions in chracter.hpp header
*/

#include "Character.hpp"

/**
@post : default constructor to initialize private members and set them 
        to default values
*/
Character::Character () {
    setName("NAMELESS");
    setRace("NONE");
    setArmor(0);
    setVitality(0);
    setLevel(0);
    this->enemy_ = false;

}

/**
@param : the character's name as a string data type
@param : the character's race as a string data type
@param : the character's vitality as an int data type, with default value 0
@param : the character's max armor level as an int data type, with default value 0
@param : the character's level as an int data type, with default value 0
@param : the character's enemy status as a bool data type, with default value false
@post : sets private members to the values of the corresponding given parameters using 
        setter functions
*/
Character::Character (std::string name, std::string race, int vitality, 
    int armor, int level, bool enemy) {

    setName(name);
    setRace(race);
    setVitality(vitality);
    setArmor(armor);
    setLevel(level);
    this->enemy_ = enemy;

}

/**
@param : the character's name as a string data type
@pre : the name has to be fully capitalized and only alphabetical characters
*/
void Character::setName (const std::string& name) {

    std::string nameFormatted = "";

    //formatting into only alphabetical characters
    for (long unsigned int i = 0; i < name.length(); i++) {
        if ( !(isdigit(name[i])) ) {
            nameFormatted += name[i];
        }
    }

    for (long unsigned int i = 0; i < nameFormatted.length(); i++) {
        nameFormatted[i] = toupper(nameFormatted[i]);
    }

    //checking if there are any valid alphabetical characters
    if (nameFormatted.length() > 0) 
        name_ = nameFormatted;
    else
        name_ = "NAMELESS";

}

/**
@return : returns the character's name as a string datatype
*/
std::string Character::getName () const {

    return name_;

}

/**
@param : the character's race as a string datatype
@post : uses conditionals to set the character's race to the provided parameter,
        race is set to NONE if given value is invalid and doesn't match 
*/
void Character::setRace (const std::string& race) {

    if (race == "HUMAN")
        race_ = HUMAN;
    else if (race == "ELF")
        race_ = ELF;
    else if (race == "DWARF")
        race_ = DWARF;
    else if (race == "LIZARD")
        race_ = LIZARD;
    else if (race == "UNDEAD")
        race_ = UNDEAD;
    else 
        race_ = NONE;   

}

/**
@post : uses conditional statements to match the race to the corresponding string value
@return : returns the character's race as a string data type
*/
std::string Character::getRace () const {

    if (race_ == HUMAN)
        return "HUMAN";
    else if (race_ == ELF) 
        return "ELF";
    else if (race_ == DWARF)
        return "DWARF";
    else if (race_ == LIZARD)
        return "LIZARD";
    else if (race_ == UNDEAD)
        return "UNDEAD";
    else
        return "NONE";

}

/**
@param : the character's vitality as an int data type
@pre : vitality must be above or at 0, cannot be negative
@post : sets the vitality private member to the value of given parameter,
        if given parameter is negative then does nothing
*/
void Character::setVitality (const int& vitality) {

    if (vitality >= 0) 
        vitality_ = vitality;

}

/**
@return : returns the character's vitality as an int data type
*/  
int Character::getVitality () const{

    return vitality_;

}

/**
@param : the character's armor level as an int data type
@pre : armor level must be above or at 0, cannot be negative
@post : sets the armor private member to the value of the given parameter,
        if given parameter is negative then does nothing
*/
void Character::setArmor (const int& armor) {

    if (armor >= 0) 
        armor_ = armor;

}

/**
@return : returns the character's armor as an int data type
*/
int Character::getArmor () const {

    return armor_;

}

/**
@param : the character's level as an int data type
@pre : level must be above or at 0, cannot be negative
@post : sets the level private member to the value of the given parameter,
        if given parameter is negative then does nothing
*/
void Character::setLevel (const int& level) {

    if (level >= 0)
        level_ = level;

}

/**
@return : returns the chracter's level as an int data type
*/
int Character::getLevel () const {

    return level_;

}

/**
@pre : enemy flag is defaulted to false
@post : sets the enemy flag to true 
*/
void Character::setEnemy () {

    enemy_ = true;

}

/**
@return : returns the enemy flag as a bool data type
*/
bool Character::isEnemy () const {

    return enemy_;

}