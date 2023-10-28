/*
CSCI235 Fall 2023
Project 4 - The Tainted Stew
Author: Jiaxiong Guan
Date: 10/27/23
Modified from Georgina Woo's Tavern.cpp file

Description:
Tavern.cpp defines the constructors and private and public function implementation of the Tavern class
The Tavern class is derived from the ArrayBag class and it is an array of Characters
*/

#include "Tavern.hpp"

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}

/**
  @param: the name of an input file
  @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
    1. Name: An uppercase string
    2. Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
    3. Subclass: An uppercase string [BARBARIAN, MAGE, SCOUNDREL, RANGER]
    4. Level/Vitality/Armor: A positive integer
    5. Enemy: 0 (False) or 1 (True)
    6. Main: Uppercase string or strings representing the main weapon (Barbarian and Mage), Dagger type (Scoundrel), or arrows (Ranger). A ranger's arrows are of the form [TYPE] [QUANTITY];[TYPE] [QUANTITY], where each arrow type is separated by a semicolon, and the type and its quantity are separated with a space.
    7. Offhand: An uppercase string that is only applicable to Barbarians, and may be NONE if the Barbarian does not have an offhand weapon, or if the character is of a different subclass.
    8. School/Faction: Uppercase strings that represent a Mage's school of magic: [ELEMENTAL, NECROMANCY, ILLUSION] or a Scoundrel's faction: [CUTPURSE, SHADOWBLADE, SILVERTONGUE], and NONE where not applicable
    9. Summoning: 0 (False) or 1 (True), only applicable to Mages (summoning an Incarnate) and Rangers (Having an Animal Companion)
    10. Affinity: Only applicable to Rangers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a semicolon. Th value may be NONE for a Ranger with no affinities, or characters of other subclasses.
    11. Disguise: 0 (False) or 1 (True), only applicable to Scoundrels, representing if they have a disguise.
    12. Enraged: 0 (False) or 1 (True), only applicable to Barbarians, representing if they are enraged.
  @post: Each line of the input file corresponds to a Character subclass and dynamically allocates Character derived objects, adding them to the Tavern.
*/
Tavern::Tavern(std::string file_name) : ArrayBag<Character*>() {

  std::ifstream input_file;
  input_file.open(file_name);

  // Check if file is opened
  if(!input_file.is_open()) {
    std::cerr << "ERROR: Unable to open the CSV file." << std::endl;
  }

  std::string file_line;
  std::getline(input_file, file_line);
  while(std::getline(input_file, file_line)) {

    // Vector to contain processed strings
    std::vector<std::string> line_parts;

    // Loop through the line and create substrings to add to array
    for(int i = 0; i < 13; i++) {

      // Find the next comma, create a substr of the part before the comma, and add it to the array, then remove the part up to the comma 
      long unsigned int index = file_line.find(",");

      // if there are no more commas, add the remainder of the line to the vector
      if(index == std::string::npos)
        line_parts.push_back(file_line);
      else {
        std::string processed = file_line.substr(0, index);
        file_line = file_line.substr(index + 1);
        line_parts.push_back(processed);
      }
    }
    
    // Variables for creating the character class later 
    std::string name = line_parts[0];
    std::string race = line_parts[1];
    std::string subclass = line_parts[2];
    int level = stoi(line_parts[3]);
    int vitality = stoi(line_parts[4]);
    int armor = stoi(line_parts[5]);
    bool enemy = line_parts[6] == "1" ? true : false;
    std::string main_weapon = line_parts[7];
    std::string offhand_weapon = line_parts[8];
    std::string faction = line_parts[9];
    bool summoning = line_parts[10] == "1" ? true : false;
    std::string affinity = line_parts[11];
    bool disguise = line_parts[12] == "1" ? true : false;
    bool enraged = line_parts[13] == "1" ? true : false;
    
    // Create a character pointer to a Barbarian class and add it to the Tavern
    if(subclass == "BARBARIAN") {
      Character* p = new Barbarian(name, race, vitality, armor, level, enemy, main_weapon, offhand_weapon, enraged);
      enterTavern(p);
    } 

    // Create a character pointer to a Ranger class and add it to the Tavern
    else if(subclass == "RANGER") {

      // Vectors for class construction and index to process the strings
      std::vector<Arrows> arrows;
      std::vector<std::string> affinities;
      long unsigned int index = 0;

      // While there is a semicolon, process the string and add it to the vector
      while(index != std::string::npos) {
        index = affinity.find(";");
        if (index != std::string::npos) {
          std::string processed = affinity.substr(0, index);
          affinity = affinity.substr(index + 1);
          affinities.push_back(processed);
        }
      }

      // Add the last affinity
      affinities.push_back(affinity);

      // Reset index variable
      index = 0;

      // While there is a semicolon, process the string and add arrows to the vector
      while(index != std::string::npos) {
        index = main_weapon.find(";");
        if (index != std::string::npos) {
          std::string processed = main_weapon.substr(0, index);

          // Separate string into the amount and type of arrows
          std::string type = processed.substr(0, main_weapon.find(" "));
          int amount = stoi(processed.substr(main_weapon.find(" ") + 1));
          main_weapon = main_weapon.substr(index + 1);

          // Create and add arrow to vector
          Arrows arrow; 
          arrow.quantity_ = amount;
          arrow.type_ = type;
          arrows.push_back(arrow);
        }
      }

      // Add the last arrow to the vector
      std::string type = main_weapon.substr(0, main_weapon.find(" "));
      int amount = stoi(main_weapon.substr(main_weapon.find(" ") + 1));
      Arrows arrow; 
      arrow.quantity_ = amount;
      arrow.type_ = type;
      arrows.push_back(arrow);
      
      Character* p = new Ranger(name, race, vitality, armor, level, enemy, arrows, affinities, summoning);
      enterTavern(p);
    }

    // Create a character pointer to a Mage class and add it to the Tavern
    else if(subclass == "MAGE") {
      Character* p = new Mage(name, race, vitality, armor, level, enemy, faction, main_weapon, summoning);
      enterTavern(p);
    }

    // Create a character pointer to a Scoundrel class and add it to the Tavern
    else if(subclass == "SCOUNDREL") {
      Character* p = new Scoundrel(name, race, vitality, armor, level, enemy, main_weapon, faction, disguise);
      enterTavern(p);
    }
  }
  input_file.close();
}

/** 
    @param:   A pointer to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else {
    return false;
  }
  return false;
}

/** @param:   A pointer to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}



/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}

/**
  @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters() const{

  for(int i = 0; i < getCurrentSize(); i++) 
    items_[i]->display();

}

/**
  @param: a string reference to a race
  @post: For every character in the tavern of the given race (only exact matches to the input string), displays each character's information
*/
void Tavern::displayRace(const std::string& race) const{

  for(int i = 0; i < getCurrentSize(); i++) {
    if(race == items_[i]->getRace())
      items_[i]->display();
  }
}

/**
  @post: Every character in the tavern eats a tainted stew.
*/
void Tavern::taintedStew() {
  for(int i = 0; i < getCurrentSize(); i++) 
    items_[i]->eatTaintedStew();
}