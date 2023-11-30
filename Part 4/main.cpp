#include "Tavern.hpp"
#include "Barbarian.hpp"
#include "Ranger.hpp"
#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"

int main() {
  Tavern t1 = Tavern("characters.csv");
  t1.displayCharacters();
}