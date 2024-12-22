#pragma once
#include "Character.h"
#include "Enemy.h"

namespace Game {

  void showStartBanner(Character player);

  void printWormIntro(Enemy enemy);
  bool wormGame(Character &player, Enemy &enemy);
  void printWormOutro(Enemy enemy, Character &player);

  void showBattleScreen(Enemy &enemy, Character &player, bool isBattleFinished);
  Weapon getPlayerChoice();
  bool battle(Character &player, Enemy &enemy);

  bool frenchFrog(Character &player, Enemy &enemy);

  void ending();

} // namespace Game
