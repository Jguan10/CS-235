#include "Tavern.hpp"
#include "Character.hpp"

int main() {

    Tavern tavern;
    Character c1("MAINCHARACTER", "HUMAN", 1, 1, 1, false);
    Character c2("Person1", "ELF", 2, 2, 2, true);

    tavern.enterTavern(&c1);
    tavern.enterTavern(&c2);
    tavern.setMainCharacter(&c1);

    

    c1.setVitality(100);
    c1.setArmor(100);
    Character c3("Second Person", "DWARF", 2, 2, 2, true);
    Character c4("Third Person", "LIZARD", 2, 2, 2, true);

    tavern.enterTavern(&c3);
    tavern.enterTavern(&c4);
    tavern.createCombatQueue();
    
    tavern.combat();
}