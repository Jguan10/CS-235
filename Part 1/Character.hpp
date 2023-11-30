/*
Author: Jiaxiong Guan
Date: 9/7/2023
Description: header file character.hpp
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

enum Race {NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};

class Character {

private:
    std::string name_;
    Race race_;
    int vitality_;
    int armor_;
    int level_;
    bool enemy_;

public:
    //Constructors for Character class
    Character();
    Character(std::string name, std::string race, int vitality = 0, 
        int armor = 0, int level = 0, bool enemy = false);

    //getter and setter functions
    void setName(const std::string& name);
    std::string getName() const;
    void setRace(const std::string& race);
    std::string getRace() const;
    void setVitality(const int& vitality);
    int getVitality() const;
    void setArmor(const int& armor);
    int getArmor() const;
    void setLevel(const int& level);
    int getLevel() const;
    void setEnemy();
    bool isEnemy() const;

};

#endif