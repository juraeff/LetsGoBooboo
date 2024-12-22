#include "Character.h"
#include "resources.h"
#include <iostream>

bool Character::getIsCap() const { return isCap; }
void Character::setIsCapTrue() {
  isCap = true;
  armour += 10;
}
void Character::setIsCapFalse() { // in case it was broken
  isCap = false;
  armour -= 10;
}

unsigned short Character::getHealth() const { return health; }
void Character::setHealth(int newHealth) { health = newHealth; }
unsigned short Character::getArmour() const { return armour; }
unsigned short Character::getLevel() const { return level; }
void Character::setLevel(int newLevel) { level = newLevel; }
Weapon Character::getNeed() const { return need; }

std::string Character::showActualHealth(int healthInt) {
  std::string healthStr;
  switch (healthInt) {
  case 100:
    return "MOOD:  ♥♥♥♥♥♥♥♥♥♥";
  case 90:
    return "MOOD:  ♥♥♥♥♥♥♥♥♥♡";
  case 80:
    return "MOOD:  ♥♥♥♥♥♥♥♥♡♡";
  case 70:
    return "MOOD:  ♥♥♥♥♥♥♥♡♡♡";
  case 60:
    return "MOOD:  ♥♥♥♥♥♥♡♡♡♡";
  case 50:
    return "MOOD:  ♥♥♥♥♥♡♡♡♡♡";
  case 40:
    return "MOOD:  ♥♥♥♥♡♡♡♡♡♡";
  case 30:
    return "MOOD:  ♥♥♥♡♡♡♡♡♡♡";
  case 20:
    return "MOOD:  ♥♥♡♡♡♡♡♡♡♡";
  case 10:
    return "MOOD:  ♥♡♡♡♡♡♡♡♡♡";
  case 0:
    return "MOOD:  ♡♡♡♡♡♡♡♡♡♡";
  default:
    return "";
  }
}

void Character::showStats() {

  std::string head;
  if (getIsCap()) {
    head = "{\\\\🧢/} ";
  } else {
    head = "{\\\\__/} ";
  }

  const std::string characterArt[] = {
      head + showActualHealth(getHealth()),
      " (◕ᴥ◕)  ARMOR: " + std::to_string(getArmour()),
      "  (••)  LEVEL: " + std::to_string(getLevel())};

  for (const auto &line : characterArt) {
    std::cout << GameResources::SPACES << line << std::endl;
  }
}
