#pragma once
#include <string>

enum class Weapon { JOKE,
                    COMPLIMENT,
                    HUG,
                    LISTEN };

class Character {
private:
  static constexpr unsigned short MAX_HEALTH = 100;
  static constexpr unsigned short HEALTH_STEP = 10;
  unsigned short health = 100;
  unsigned short armour = 0;
  unsigned short level = 1;
  bool isCap = 0;
  Weapon need;

public:
  bool getIsCap() const;
  void setIsCapTrue();
  void setIsCapFalse();

  unsigned short getHealth() const;
  void setHealth(int newHealth);
  unsigned short getArmour() const;
  unsigned short getLevel() const;
  void setLevel(int newLevel);
  Weapon getNeed() const;

  std::string showActualHealth(int healthInt);
  void showStats();
};
