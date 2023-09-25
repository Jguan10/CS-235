#include "Ranger.hpp"

/*
    Default constructor for the Scoundrel class
    Sets private members to default values 
    Character name is defaulted to "NAMELESS" 
    Booleans are defaulted to false
*/
Ranger::Ranger() : Character() {

    bool companion = false;
    setCompanion(companion);

}

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
Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, 
                bool enemy, std::vector<Arrows> arrows, std::vector<std::string> affinity, bool recruit) :
                Character(name, race, vitality, armor, level, enemy) {


    for(long unsigned int i = 0; i < arrows.size(); i++) {
        addArrows(arrows[i].type_, arrows[i].quantity_);
    }
    for(long unsigned int i = 0; i < affinity.size(); i++) {
        addAffinity(affinity[i]);
    }
    setCompanion(recruit);
}

/*
    @return : An Arrows vector representing the character's arrows, private member "arrows_"
*/
std::vector<Arrows> Ranger::getArrows() const{
    return arrows_;

}

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
bool Ranger::addArrows(const std::string& arrow_type, const int& amount) {

    // Return false if the amount is non-positive
    if(amount <= 0)
        return false;

    // String variable to hold the uppercase version of the given string parameter 
    std::string upper_type = formatString(arrow_type);

    if(validArrow(upper_type)) {

        // Check if that type is in the vector
        if(checkArrows(upper_type) >= 0) { 
            arrows_[checkArrows(upper_type)].quantity_ += amount;
        }

        // Create a new arrow and add to the vector
        else {
            Arrows a1;
            a1.type_ = upper_type;
            a1.quantity_ = amount;
            arrows_.push_back(a1);
        }
        return true;
    }
    else 
        return false;

}

/*
    @param  : A const string reference for the type of arrow
    @post   : If the character has that type of arrow in the Arrows vector and a positive amount of that type of arrows, then an arrow is fired (quantity - 1) and return true
              Type inputs can be lowercase, but must be converted to uppercase
              If the vector only has one of that type of arrow, then decrement to 0
              Returns false if the type is invalid or if the amount of arrows is non-positive
    @return : True if the provided input is valid and an arrow was fired, false otherwise
*/
bool Ranger::fireArrow(const std::string& arrow_type) {

    // String variable to hold the uppercase version of the given string parameter
    std::string upper_type = formatString(arrow_type);

    // Check if the type is in the vector and if the quantity is more than 1
    if(checkArrows(upper_type) >= 0 && arrows_[checkArrows(upper_type)].quantity_ > 0) {
        arrows_[checkArrows(upper_type)].quantity_--;
        return true;
    }
    else    
        return false;

}

/*
    @param  : A const string reference to the character's affinity
    @post   : If the affinity does not exist in the "affinities_" vector, then add it in and return true
              String inputs can be lowercase, but must be converted to uppercase
              The vector should have no duplicates
              Valid affinities are: [FIRE, WATER, POISON, BLOOD]
              If the affinity is not valid or already exists in the vector, return false
    @return : True if the provided affinity is valid and added to the vector, false otherwise
*/
bool Ranger::addAffinity(const std::string& affinity) {

    // String variable to hold the uppercase version of the given string parameter
    std::string upper_affinity = formatString(affinity); 

    // Check if the affinity type is valid
    if(upper_affinity != "WOOD" && validArrow(upper_affinity)) {

        // Check if the affinity is in the vector
        for(long unsigned int i = 0; i < affinities_.size(); i++) {
            if(upper_affinity == affinities_[i]) 
                return false; 
        }
        affinities_.push_back(upper_affinity);
    }
    return false;

}

/*
    @return : A string vector of the character's affinities, private member "affinities_"
*/
std::vector<std::string> Ranger::getAffinities() const{

    return affinities_;

}

/*
    @param  : A const bool reference to whether the character can recruit a companion
    @post   : Sets the private member "has_companion_" to the value of the provided parameter
*/
void Ranger::setCompanion(const bool& companion) {

    has_companion_ = companion;

}

/*
    @return : A boolean indicating the character's ability to recruit a companion, private member "has_companion_"
*/
bool Ranger::getCompanion() const{

    return has_companion_;

}

/*
    @param  : A string that needs to have all its characters in uppercase
    @post   : Creates an empty string and adds the uppercase characters in the provided string to the empty string
              Uses a for loop to loop through each character in the string and add uppercase characters to the created string
    @return : A string representing the uppercase version of the provided string
*/
std::string Ranger::formatString(std::string unformatted) {
    std::string formatted = ""; // String variable to hold the uppercase version of the given string parameter

    // A for loop to capitalize all characters in the given string parameter and then adds them to "upper_school"
    for(long unsigned int i = 0; i < unformatted.length(); i++) {
        formatted += toupper(unformatted[i]);
    }

    return formatted;
}

/*
    @param  : A string indicating the type of the arrow
    @post   : Searches through the Arrows vector "arrows_" to check the index of the type of arrow provided in the vector
    @return : Returns the index of the type of arrow in "arrows_", return -1 if the provided type is not in the vector
*/
int Ranger::checkArrows(std::string arrow_type) {

    for(long unsigned int i = 0; i < arrows_.size(); i++) {
        if(arrow_type == arrows_[i].type_) 
            return i;
    }

    return -1;

}

/*
    @param  : A string indicating the type of the arrow
    @post   : Checks if the provided arrow type is one of: [WOOD, FIRE, WATER, POISON, BLOOD] and returns true if the type is valid
    @return : True if the provided arrow type is valid, false otherwise
*/
bool Ranger::validArrow(std::string arrow_type) {

    if(arrow_type == "WOOD" || arrow_type == "FIRE" || arrow_type == "WATER" || arrow_type == "POISON" || arrow_type == "BLOOD")
        return true;
    else    
        return false;
}




