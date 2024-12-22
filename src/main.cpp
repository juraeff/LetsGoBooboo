// source files
#include "Character.h"
#include "Enemy.h"
#include "game.h"
// libraries
#include <windows.h>

int main() {

  SetConsoleOutputCP(CP_UTF8);
  const char gameColor[] = "Color 0A"; // 0 - BLACK background, A - GREEN text
  system(gameColor);

  Character rusya;
  Game::showStartBanner(rusya);

  Enemy trickyWorm("Tricky Worm", 1);
  Game::wormGame(rusya, trickyWorm);

  Enemy grumpyGoblin("Grumpy Goblin", 2);
  Game::battle(rusya, grumpyGoblin);

  Enemy laFrogette("La Frogette", 0);
  Game::frenchFrog(rusya, laFrogette);

  Game::ending();

  return 0;
}
