#pragma once
#include <string>

class Enemy {
private:
  std::string name;
  std::string status = " appears!";
  std::string dialogue;

  unsigned short health = 0;
  unsigned short level = 1;
  unsigned short iterations = 0;

public:
  Enemy(std::string name, unsigned short level);

  std::string getName() const;
  std::string getStatus() const;
  std::string getDialogue() const;

  unsigned short getHealth() const;
  unsigned short getLevel() const;

  void setHealth(unsigned short newHealth);
  void setLevel(unsigned short newLevel);
  void setDialogue(std::string newDialogue);
  void setStatus(std::string newStatus);

  void printDialogue();

  void printGoblin(std::string status, Enemy enemy);
  void printWorm(std::string status, Enemy enemy);
  void printFrog(std::string status, Enemy enemy);
};
