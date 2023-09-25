/*
Author: Jiaxiong Guan
Project 2 - Inheritance
Date: 9/22/2023
Description: Scoundrel.cpp implements and defines the functions in the Scoundrel class
*/

#include "Scoundrel.hpp"

/*
    Default constructor for the Scoundrel class
    Sets private members to default values 
    Character name is defaulted to "NAMELESS" 
    Booleans are defaulted to false
    Dagger is defaulted to "WOOD" and faction is defaulted to "NONE"
*/
Scoundrel::Scoundrel() : Character() {
    std::string wood = "WOOD"; // String variable for setting the character's dagger type to WOOD
    setDagger(wood);

    std::string none = "NONE"; // String variable for setting the character's faction to "NONE"
    setFaction(none);

    bool faction = false; // Bool variable for setting the character's disguise to false
    setDisguise(faction);

}

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
    @param  : A const string reference for the character's faction, valid factions are: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
              String inputs can be lowercase, but must be converted to uppercase when setting 
              Cannot contain non-alphabetical characters
              Defaults to "NONE" if there is no provided string or if invalid string
    @param  : A boolean indicating whether the character has a disguise, defaults to false
    @post   : Sets private members of the Scoundrel class to the values of the provided parameters 
*/
Scoundrel::Scoundrel(const std::string& name, const std::string& race, int vitality, int armor, int level, 
                    bool enemy, const std::string& dagger, const std::string& faction, bool disguise) : 
                    Character(name, race, vitality, armor, level, enemy) {
            
            setDagger(dagger);
            setFaction(faction);
            setDisguise(disguise);
}

/*
    @param  : A const string reference to the character's dagger type
    @post   : Sets the private member variable "dagger_" to the provided value of the parameter if it is valid
              String inputs can be lowercase, but must be converted to uppercase when setting 
              Cannot contain non-alphabetical characters
              Valid inputs are: [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]
              If the inputs are invalid, then it should set to WOOD
*/
void Scoundrel::setDagger(const std::string& dagger) {

    // String variable to hold the uppercase version of the given string parameter
    std::string upper_dagger = formatString(dagger);
    
    // Checks to see if the given string parameter is one of [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]
    if(upper_dagger == "BRONZE") 
        dagger_ = BRONZE;
    else if(upper_dagger == "IRON")
        dagger_ = IRON;
    else if(upper_dagger == "STEEL")
        dagger_ = STEEL;
    else if(upper_dagger == "MITHRIL")
        dagger_ = MITHRIL;
    else if(upper_dagger == "ADAMANT")
        dagger_ = ADAMANT;
    else if(upper_dagger == "RUNE")
        dagger_ = RUNE;
    else 
        dagger_ = WOOD;

}

/*
    @return : A string indicating the character's dagger type
*/
std::string Scoundrel::getDagger() const {

    // Checks enum dagger_ to return the string version
    switch(dagger_) {
    case WOOD:
        return "WOOD";
    case BRONZE:
        return "BRONZE";
    case IRON:
        return "IRON";
    case STEEL:
        return "STEEL";
    case MITHRIL:
        return "MITHRIL";
    case ADAMANT:
        return "ADAMANT";
    case RUNE:
        return "RUNE";
    }

    return "WOOD";
}

/*
    @param  : A const string reference to the character's faction
    @post   : Sets the private member variable "faction_" to the provided value of the parameter if it is valid
              String inputs can be lowercase, but must be converted to uppercase when setting 
              Cannot contain non-alphabetical characters
              Valid inputs are: [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE]
              If the inputs are invalid, then it should do nothing and return false
    @return : True if the provided string is valid and setting was successful, false otherwise
*/
bool Scoundrel::setFaction(const std::string& faction) {

    // String variable to hold the uppercase version of the given string parameter
    std::string upper_faction = formatString(faction);

    // Checks to see if the given string parameter is one of [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE]
    if (upper_faction == "NONE") {
        faction_ = "NONE";
        return true;
    }
    else if (upper_faction == "CUTPURSE") {
        faction_ = "CUTPURSE";
        return true;
    }
    else if (upper_faction == "SHADOWBLADE") {
        faction_ = "SHADOWBLADE";
        return true;
    }
    else if (upper_faction == "SILVERTONGUE") {
        faction_ = "SILVERTONGUE";
        return true;
    }
    else    
        return false;

}

/*
    @return : A string indicating the character's faction, private member "faction_"
*/
std::string Scoundrel::getFaction() const {

    return faction_;

}

/*
    @param  : A const bool reference to whether the character has a disguise
    @post   : Sets the private member "has_disguise_" to the provided parameter 
*/
void Scoundrel::setDisguise(const bool& disguise) {

    has_disguise_ = disguise;

}

/*
    @return : A bool indicating whether the character has a disguise, private member "has_disguise_"
*/
bool Scoundrel::hasDisguise() const {

    return has_disguise_;

}

/*
    @param  : A string that needs to have all its characters in uppercase
    @post   : Creates an empty string and adds the uppercase characters in the provided string to the empty string
              Uses a for loop to loop through each character in the string and add uppercase characters to the created string
    @return : A string representing the uppercase version of the provided string
*/
std::string Scoundrel::formatString(std::string unformatted) {
    std::string formatted = ""; // String variable to hold the uppercase version of the given string parameter

    // A for loop to capitalize all characters in the given string parameter and then adds them to "upper_school"
    for(long unsigned int i = 0; i < unformatted.length(); i++) {
        formatted += toupper(unformatted[i]);
    }

    return formatted;
}