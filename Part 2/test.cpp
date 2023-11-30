#include "Character.hpp"
#include "Scoundrel.hpp"
#include "Mage.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"

/*
    @param  : A boolean indicating whether the character is an enemy
    @return : Return "an enemy" if true, and "not an enemy" if false
*/
std::string stringEnemy(bool enemy) {
    if(enemy) 
        return "an enemy";
    else    
        return "not an enemy";
}

/*
    @param  : A boolean 
    @return : Return string "TRUE" if boolean is true, "FALSE" otherwise
*/
std::string trueOrFalse(bool b) {
    if(b) 
        return "TRUE";
    else    
        return "FALSE";
}

/*
    @param  : A vector of Arrows
    @post   : Loop through the vector and print out the type of arrows and then the quantity of arrows
*/
void printArrows(std::vector<Arrows> arrows) {
    std::cout << "Vector of Arrows: ";
    for(long unsigned int i = 0; i < arrows.size(); i++) {
        std::cout << arrows[i].type_ << ", " << arrows[i].quantity_;
        if(i != arrows.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

/*
    @param  : A string vector of the character's affinities
    @post   : Loop through the vector and print out the affinities
*/
void printAffinities(std::vector<std::string> affinities) {
    std::cout << "Affinities: ";
    for(long unsigned int i = 0; i < affinities.size(); i++) {
        std::cout << affinities[i];
        if(i != affinities.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

int main() {
    // Test for default constructor of Mage class
    Mage mage1 = Mage();
    mage1.setName("defaultMage");
    mage1.setRace("ELF");
    mage1.setVitality(5);
    mage1.setArmor(3);
    mage1.setLevel(2);
    mage1.setEnemy();
    std::cout << mage1.getName() << " is a level " << mage1.getLevel() << 
    " " << mage1.getRace() << ".\n" << "Vitality: " << mage1.getVitality() 
    << "\n" << "Armor: " << mage1.getArmor() << "\n" << "They are " << stringEnemy(mage1.isEnemy()) 
    << std::endl;

    std::cout << std::endl;

    // Test for paramaterized constructor of Mage class
    Mage mage2 = Mage("SPYNACH", "ELF", 6, 4, 4, false);
    mage2.setSchool("Illusion");
    mage2.setCastingWeapon("Wand");
    mage2.setIncarnateSummon(true);
    std::cout << mage2.getName() << " is a level " << mage2.getLevel() << 
    " " << mage2.getRace() << ".\n" << "Vitality: " << mage2.getVitality()  << "\n" << 
    "Armor: " << mage2.getArmor() << "\n" << "They are " << stringEnemy(mage2.isEnemy()) << 
    "\n" << "School of Magic: " << mage2.getSchool() << "\n" << "Weapon: " << 
    mage2.getCastingWeapon() << "\n" << "Summon Incarnate: " << trueOrFalse(mage2.hasIncarnateSummon()) << std::endl;
 
    std::cout << std::endl;

    // Test for default constructor of Scoundrel class
    Scoundrel s1 = Scoundrel();
    s1.setName("defaultScoundrel");
    s1.setRace("HUMAN");
    s1.setVitality(6);
    s1.setArmor(4);
    s1.setLevel(3);
    s1.setEnemy();
    std::cout << s1.getName() << " is a level " << s1.getLevel() << 
    " " << s1.getRace() << ".\n" << "Vitality: " << s1.getVitality() 
    << "\n" << "Armor: " << s1.getArmor() << "\n" << "They are " << stringEnemy(s1.isEnemy()) 
    << std::endl;

    std::cout << std::endl;

    // Test for parameterized constructor of Scoundrel class
    Scoundrel s2 = Scoundrel("FLEA", "DWARF", 12, 7, 5, false);
    s2.setDagger("Adamant");
    s2.setFaction("Cutpurse");
    s2.setDisguise(true);
    std::cout << s2.getName() << " is a level " << s2.getLevel() << 
    " " << s2.getRace() << ".\n" << "Vitality: " << s2.getVitality() 
    << "\n" << "Armor: " << s2.getArmor() << "\n" << "They are " << stringEnemy(s2.isEnemy()) 
    << "\n" << "Dagger: " << s2.getDagger() << "\n" << "Faction: " << s2.getFaction() << "\n" 
    << "Disguise: " << trueOrFalse(s2.hasDisguise()) << std::endl;

    std::cout << std::endl;

    // Test for default constructor of Ranger class
    Ranger r1 = Ranger();
    r1.setName("defaultRanger");
    r1.setRace("UNDEAD");
    r1.setVitality(8);
    r1.setArmor(4);
    r1.setLevel(5);
    r1.setEnemy();
    std::cout << r1.getName() << " is a level " << r1.getLevel() << 
    " " << r1.getRace() << ".\n" << "Vitality: " << r1.getVitality() 
    << "\n" << "Armor: " << r1.getArmor() << "\n" << "They are " << stringEnemy(r1.isEnemy()) 
    << std::endl;

    std::cout << std::endl;

    // Test for parameterized constructor of Ranger class
    Ranger r2 = Ranger("MARROW", "UNDEAD", 9, 6, 5, true);
    std::string wood = "WOOD";
    std::string fire = "FIRE";
    std::string water = "WATER";
    std::string poison = "POISON";
    int arrows30 = 30;
    int arrows5 = 5;
    bool companion = true;
    r2.addArrows(wood, arrows30);
    r2.addArrows(fire, arrows5);
    r2.addArrows(water, arrows5);
    r2.addArrows(poison, arrows5); 
    r2.addAffinity(fire);
    r2.addAffinity(poison);
    r2.setCompanion(companion);
    std::cout << r2.getName() << " is a level " << r2.getLevel() << 
    " " << r2.getRace() << ".\n" << "Vitality: " << r2.getVitality() 
    << "\n" << "Armor: " << r2.getArmor() << "\n" << "They are " << stringEnemy(r2.isEnemy()) 
    << "\n"; 
    printArrows(r2.getArrows()); 
    printAffinities(r2.getAffinities());
    std::cout << "Animal Companion: " << trueOrFalse(r2.getCompanion()) << std::endl;

    std::cout << std::endl;

    // Test for default constructor of Barbarian class
    Barbarian b1 = Barbarian();
    b1.setName("defaultBarbarian");
    b1.setRace("HUMAN");
    b1.setVitality(10);
    b1.setArmor(5);
    b1.setLevel(5);
    b1.setEnemy();
    std::cout << b1.getName() << " is a level " << b1.getLevel() << 
    " " << b1.getRace() << ".\n" << "Vitality: " << b1.getVitality() 
    << "\n" << "Armor: " << b1.getArmor() << "\n" << "They are " << stringEnemy(b1.isEnemy()) 
    << std::endl;

    std::cout << std::endl;

    // Test for parameterized constructor of Barbarian class
    Barbarian b2 = Barbarian("BONK", "HUMAN", 11, 5, 5, true);
    std::string mainWeapon = "MACE";
    std::string offhand = "ANOTHERMACE";
    bool enrage = true;
    b2.setMainWeapon(mainWeapon);
    b2.setSecondaryWeapon(offhand);
    b2.setEnrage(enrage);
    std::cout << b2.getName() << " is a level " << b2.getLevel() << 
    " " << b2.getRace() << ".\n" << "Vitality: " << b2.getVitality() 
    << "\n" << "Armor: " << b2.getArmor() << "\n" << "They are " << stringEnemy(b2.isEnemy()) 
    << "\n" << "Main Weapon: " << b2.getMainWeapon() << "\n" << "Offhand Weapon: " << b2.getSecondaryWeapon() 
    << "\n" << "Enraged: " << trueOrFalse(b2.getEnrage());
}