// Enemy.cpp
#include "Enemy.h"
#include "resources.h"
#include <iostream>
#include <windows.h>

Enemy::Enemy(std::string name, unsigned short level)
    : name(name), level(level) {
}

std::string Enemy::getName() const {
  return name;
}

unsigned short Enemy::getHealth() const {
  return health;
}

void Enemy::setHealth(unsigned short newHealth) {
  health = newHealth;
}

void Enemy::setLevel(unsigned short newLevel) {
  level = newLevel;
}

unsigned short Enemy::getLevel() const {
  return level;
}

void Enemy::setDialogue(std::string newDialogue) {
  dialogue = newDialogue;
}

void Enemy::setStatus(std::string newStatus) {
  status = newStatus;
}

std::string Enemy::getStatus() const {
  return status;
}

std::string Enemy::getDialogue() const {
  return dialogue;
}

void Enemy::printDialogue() {
  std::cout
      << GameResources::barrierLine << std::endl;
  std::cout << "| " << std::endl;
  std::cout << "| ";
  std::string tmp = dialogue;
  const char *array = tmp.c_str();
  int numElements = tmp.size();
  for (int i = 0; i <= numElements - 1; i++) {
    Sleep(50);
    std::cout << array[i];
  }
  std::cout << "\n| " << std::endl;
  std::cout << GameResources::barrierLine << std::endl
            << std::endl;
}

void Enemy::printGoblin(std::string status, Enemy enemy) {
  if (status == " is laughing") {
    std::cout << GameResources::EXTRA_SPACES << "    .-????\?\?-. " << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "|\\  |        |  /|  LEVEL: " << enemy.getLevel() << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "| \\ | =.  .= | / |  MOOD: " << enemy.getHealth() << "/100" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "\\( \\  >—\\/—<  / )/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << " \\_, '-/  \\-' ,_/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "     \\ \\  / /" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "        \\/" << std::endl
              << std::endl
              << std::endl;
  }
  if (status == " says: “You think so?..” ") {
    std::cout << GameResources::EXTRA_SPACES << "    .-????\?\?-. " << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "|\\  |        |  /|  LEVEL: " << enemy.getLevel() << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "| \\ | =.  .= | / |  MOOD: " << enemy.getHealth() << "/100" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "\\( \\  >—\\/—<  / )/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << " \\_,〃-/  \\-〃,_/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "     \\ \\  / /" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "        \\/" << std::endl
              << std::endl
              << std::endl;
  }
  if (status != " accepts your hug" && status != " is laughing" && status != " says: “You think so?..” " && status != " is glad to vent") {
    std::cout << GameResources::EXTRA_SPACES << "    .-????\?\?-. " << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "|\\  |        |  /|  LEVEL: " << enemy.getLevel() << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "| \\ | =\\  /= | / |  MOOD: " << enemy.getHealth() << "/100" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "\\( \\   ◕\\/◕   / )/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << " \\_, '-/  \\-' ,_/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "     \\ \\  / /" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "        \\/" << std::endl
              << std::endl
              << std::endl;
  }
  if (status == " is glad to vent" || status == " accepts your hug") {
    std::cout << GameResources::EXTRA_SPACES << "    .-????\?\?-. " << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "|\\  |        |  /|  LEVEL: " << enemy.getLevel() << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "| \\ | =.  .= | / |  MOOD: " << enemy.getHealth() << "/100" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "\\( \\   ◕\\/◕   / )/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << " \\_, '-/  \\-' ,_/" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "     \\ \\  / /" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "        \\/" << std::endl
              << std::endl
              << std::endl;
  }
}

void Enemy::printWorm(std::string status, Enemy enemy) {
  if (status == " appears!") {
    std::cout << GameResources::EXTRA_SPACES << "╭🧢━╮" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "┃-ᴗ-┃ LEVEL: " << enemy.getLevel() << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "┃━━━┃ MOOD: " << enemy.getHealth() << "/100" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "┃━━━┃━━━━╮" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "╰━━━━━━━━┃" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "     ╰━━━╯~" << std::endl
              << std::endl;
  } else {
    std::cout << GameResources::EXTRA_SPACES << "╭━━━╮" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "┃-ᴗ-┃ LEVEL: " << enemy.getLevel() << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "┃━━━┃ MOOD: " << enemy.getHealth() << "/100" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "┃━━━┃━━━━╮" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "╰━━━━━━━━┃" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "     ╰━━━╯~" << std::endl
              << std::endl;
  }
}

void Enemy::printFrog(std::string status, Enemy enemy) {

  std::cout << GameResources::EXTRA_SPACES << "           .--.👒.-." << std::endl;
  std::cout << GameResources::EXTRA_SPACES << "          ( ◕    ◕ )  LEVEL: " << enemy.getLevel() << std::endl;
  std::cout << GameResources::EXTRA_SPACES << "          /   . .   \\  MOOD:  " << enemy.getHealth() << "/100" << std::endl;
  std::cout << GameResources::EXTRA_SPACES << "         .`._______.'." << std::endl;
  std::cout << GameResources::EXTRA_SPACES << "        /(           )\\" << std::endl;
  std::cout << GameResources::EXTRA_SPACES << "      _/  \\  \\   /  /  \\_" << std::endl;
  std::cout << GameResources::EXTRA_SPACES << "   .~   `  \\  \\ /  /  '   ~." << std::endl;
  std::cout << GameResources::EXTRA_SPACES << "  /  \\    `._\\/\\_.'    /  \\" << std::endl;
  std::cout << GameResources::EXTRA_SPACES << " /    `-.           .-'    \\" << std::endl
            << std::endl;
}
