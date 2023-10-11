/*
CSCI235 Fall 2023
Project 3 - The Tavern
Author: Jiaxiong Guan
Date: October 5th 2023

Description:
Tavern.cpp defines the constructors and private and public function implementation of the Tavern class
The Tavern class is derived from the ArrayBag class and it is an array of Characters
*/

#include "Tavern.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
    Defaults total_enemies_ and total_levels_ to 0
*/
Tavern::Tavern() : ArrayBag() {
    total_enemies_ = 0;
    total_levels_ = 0;
}

/** 
    @param   :  A const reference to a Character entering the Tavern
    @return  :  Returns true if a Character was successfully added to the tavern (i.e. items_), false otherwise
    @post    :  Adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(const Character& character) {

    if(add(character)) {

        // Checks if the character is an enemy then adds it to the total
        if(character.isEnemy()) 
            total_enemies_++;
         
        total_levels_ += character.getLevel();
        return true;
    }
    return false;

}

/** 
    @param  : A const reference to a Character leaving the Tavern  
    @return : Returns true if a character was successfully removed from the tavern (i.e. items_), false otherwise
    @post   : Removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(const Character& character) {

    if(remove(character)) {

        // If the character is an enemy then remove from total enemies
        if(character.isEnemy())
            total_enemies_--;

        total_levels_ -= character.getLevel();
        return true;
    }
    return false;

}

/** 
    @return : The integer level count of all the characters currently in the Tavern
**/
int Tavern::getLevelSum() {

    return total_levels_;

}

/** 
    @return : The average level of all the characters in the Tavern
    @post   : Computes the average level of the Tavern rounded to the NEAREST integer.
**/
int Tavern::calculateAvgLevel() {

    // Double versions of the integer values to prevent integer division
    double total_level = total_levels_;        
    double current_size = getCurrentSize();

    // Round to the nearest integer
    return round(total_level / current_size);

}

/** 
    @return : The integer enemy count of the Tavern
**/
int Tavern::getEnemyCount() {

    // Reset total_enemies_ and rechecks for the total amount of enemies
    total_enemies_ = 0;
    for(int i = 0; i < getCurrentSize(); i++) {
        if(items_[i].isEnemy())
            total_enemies_++;
    }

    return total_enemies_;

}

/** 
    @return : The percentage (double) of all the enemy characters in the Tavern
    @post   : Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
**/
double Tavern::calculateEnemyPercentage() {
    
    // Double versions of the integer values to prevent integer division
    double enemy_count = getEnemyCount();
    double current_size = getCurrentSize();

    // Round to the nearest hundredth and put in percentage 
    return round(enemy_count / current_size * 10000.0) / 100.0;
    
}


/** 
    @param  : A const reference to a string representing a character Race with value in 
                ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return : An integer tally of the number of characters in the Tavern of the given race. 
                If the argument string does not match one of the expected race values, 
                the tally is zero. NOTE: no pre-processing of the input string necessary, only uppercase input will match.
**/
int Tavern::tallyRace(const std::string& race) {

    // Convert string to uppercase
    std::string race_upper = "";
    for(long unsigned int i = 0; i < race.length(); i++) {
        race_upper += toupper(race[i]);
    }

    // Loop through array and count the amount of the inputted race
    int counter = 0;
    for(int i = 0; i < getCurrentSize(); i++) {
        if(items_[i].getRace() == race_upper) 
            counter++;
    }

    return counter;

}


/**
    @post   : Outputs a report of the characters currently in the tavern in the form:
                "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n"
                Note that the average level should be rounded to the NEAREST integer, and the enemy percentage should be rounded to 2 decimal places.

                Example output: 
                Humans: 3
                Elves: 5
                Dwarves: 8
                Lizards: 6
                Undead: 0

                The average level is: 7
                46.67% are enemies.
*/
void Tavern::tavernReport() {

    // String varibles to pass into function tallyRace
    std::string human = "HUMAN";
    std::string elf = "ELF";
    std::string dwarf = "DWARF";
    std::string lizard = "LIZARD";
    std::string undead = "UNDEAD";

    std::cout << "Humans: " << tallyRace(human) << "\n" << "Elves: " << tallyRace(elf) << "\n"
    << "Dwarves: " << tallyRace(dwarf) << "\n" << "Lizards: " << tallyRace(lizard) << "\n"
    << "Undead: " << tallyRace(undead) << "\n\n" << "The average level is: " << calculateAvgLevel() 
    << "\n";

    // Prints out at double precision
    printf("%.2lf%%", calculateEnemyPercentage());
    std::cout << " are enemies.\n";

}

