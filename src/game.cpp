#include "game.h"
#include "FileReader.h"
#include "resources.h"
#include "utils.h"
#include "windows.h"
#include <conio.h>
#include <iostream>
#include <limits>
#include <set>
#include <string>

namespace Game {
  void showStartBanner(Character player) {
    std::string banner = FileReader::readAsciiArt("./asciiArt/startbanner.txt");
    PlaySound(TEXT("../audio/startBannerSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    std::cout << banner << std::endl
              << GameResources::SPACES << "Press ENTER to start your adventure...\n\n";
    std::cin.get();
    std::cout << GameResources::SPACES << "Ehm... This is you by the way:\n";

    Sleep(500);
    PlaySound(TEXT("../audio/enterKeySound.wav"), NULL, SND_FILENAME | SND_ASYNC);

    player.showStats();
    Sleep(1000);
    std::cout << std::endl;
  }

  void printWormIntro(Enemy enemy) {
    enemy.printDialogue();
    Sleep(250);
    std::cout << GameResources::SPACES << "*  " << enemy.getName() << enemy.getStatus() << std::endl;
    Sleep(1000);

    enemy.printWorm(" appears!", enemy);
    Sleep(1000);
  }

  bool wormGame(Character &player, Enemy &enemy) {

    PlaySound(TEXT("../audio/gameTheme.wav"), NULL, SND_FILENAME | SND_ASYNC); // change it later
    enemy.setDialogue("W: Howdy, here's the deal: I'm bored so catch me if you can!");
    printWormIntro(enemy);
    Sleep(1000);
    std::cout << "+---------------------------------------┃   ┃-----------------------------------------" << std::endl;
    std::cout << "+---------------------------------------╰⬮⬮⬮╯-----------------------------------------" << std::endl;

    int score = 0;
    while (score < 10) {
      for (int i = 0; i <= 80 - 1; i++) {
        std::cout << GameResources::wormPositionsList[i] << '\r' << std::flush;
        std::cout << "SCORE:" << score << "/10" << '\r' << std::flush;
        Sleep(1);
        if (_kbhit()) {
          _getch();
          if (i >= 38 && i <= 46) {
            PlaySound(TEXT("../audio/scoreSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            score++;
          } else {
            PlaySound(TEXT("../audio/wrongSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            if (score > 0) {
              score--;
            }
          }
        }
      }
      for (int i = 80 - 1; i >= 0; i--) {
        std::cout << GameResources::wormPositionsList[i] << '\r' << std::flush;
        std::cout << "SCORE:" << score << "/10" << '\r' << std::flush;
        Sleep(1);
        if (_kbhit()) {
          _getch();
          if (i >= 38 && i <= 46) {
            PlaySound(TEXT("../audio/scoreSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            score++;
          } else {
            PlaySound(TEXT("../audio/wrongSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            if (score > 0) {
              score--;
            }
          }
        }
      }
    }
    std::cout << std::flush << std::endl;
    printWormOutro(enemy, player);
    return 0;
  }

  void printWormOutro(Enemy enemy, Character &player) {

    enemy.setDialogue("W: Wow, you're really fast kid! Take this");
    enemy.setHealth(100);
    enemy.setStatus(" is fascinated by you");
    player.setIsCapTrue();
    player.setLevel(player.getLevel() + 1);

    enemy.printDialogue();
    Sleep(250);
    std::cout << std::endl
              << GameResources::SPACES << "*  " << enemy.getName() << enemy.getStatus() << std::endl;
    enemy.printWorm(enemy.getStatus(), enemy);
    Sleep(1000);
    PlaySound(TEXT("../audio/enterKeySound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    player.showStats();
    std::cout << std::endl
              << std::endl;
    Sleep(2000);
    std::cout << std::endl
              << GameResources::SPACES << "Press ENTER to continue your adventure...\n\n";
    std::cin.get();
  }

  void showBattleScreen(Enemy &enemy, Character &player, bool isBattleFinished) {

    enemy.printDialogue();

    Sleep(250);
    std::cout << GameResources::SPACES << "*  " << enemy.getName() << enemy.getStatus() << std::endl;
    Sleep(1000);

    enemy.printGoblin(enemy.getStatus(), enemy);
    Sleep(1000);

    player.showStats();

    if (!isBattleFinished) {
      std::cout << GameResources::SPACES << "Choose your action:" << std::endl;
      std::cout << GameResources::SPACES << "1. [HUG]       2. [COMPLIMENT]" << std::endl;
      std::cout << GameResources::SPACES << "3. [JOKE]      4. [LISTEN]\n"
                << std::endl;
    }
  }

  Weapon getPlayerChoice() {
    char choice;
    do {
      choice = _getch();
    } while (choice < '1' || choice > '4');

    switch (choice) {
    case '1':
      return Weapon::HUG;
    case '2':
      return Weapon::COMPLIMENT;
    case '3':
      return Weapon::JOKE;
    case '4':
      return Weapon::LISTEN;
    default:
      return Weapon::JOKE;
    }
  }

  bool battle(Character &player, Enemy &enemy) {

    PlaySound(TEXT("../audio/gameTheme.wav"), NULL, SND_FILENAME | SND_ASYNC);
    enemy.setDialogue("G: I'm a scary ugly goblin. Be afraid!..");

    while (enemy.getHealth() < 100 && player.getHealth() > 0) {
      showBattleScreen(enemy, player, false);
      Weapon choice = getPlayerChoice();
      std::string joke = GameResources::jokesList[randInt(0, 12)];
      std::string story = GameResources::storiesList[randInt(0, 6)];
      std::string compliment = GameResources::complimentsList[randInt(0, 6)];

      switch (choice) {
      case Weapon::HUG:
        enemy.setDialogue("* You try to hug the goblin...");
        if (randInt(0, 1)) {
          enemy.setStatus(" accepts your hug");
          enemy.setHealth(enemy.getHealth() + 20);
        } else {
          enemy.setStatus(" doesn't want to hug now");
          player.setHealth(player.getHealth() - 10);
        }
        break;
      case Weapon::COMPLIMENT:
        enemy.setDialogue(compliment);
        if (randInt(0, 2) > 0) {
          enemy.setStatus(" says: “You think so?..” ");
          enemy.setHealth(enemy.getHealth() + 20);
        } else {
          enemy.setStatus(" doesn't believe you");
          player.setHealth(player.getHealth() - 10);
        }
        break;
        break;
      case Weapon::JOKE:
        enemy.setDialogue(joke);
        if (randInt(0, 2) > 0) {
          enemy.setStatus(" is laughing");
          enemy.setHealth(enemy.getHealth() + 20);
        } else {
          enemy.setStatus(" is not impressed");
          player.setHealth(player.getHealth() - 10);
        }
        break;
      case Weapon::LISTEN:
        if (randInt(0, 2) > 0) {
          enemy.setDialogue(story);
          enemy.setStatus(" is glad to vent");
          enemy.setHealth(enemy.getHealth() + 20);
        } else {
          enemy.setDialogue("G: I don't wanna talk");
          enemy.setStatus(" doesn't want to talk");
          player.setHealth(player.getHealth() - 10);
        }
        break;
      }
    }

    if (enemy.getHealth() >= 100) {
      player.setLevel(player.getLevel() + 1);
      showBattleScreen(enemy, player, true);
      PlaySound(TEXT("../audio/victorySound.wav"), NULL, SND_FILENAME | SND_ASYNC);
      std::cout << std::endl
                << GameResources::SPACES << "* Grumpy Goblin is happy, it's a Victory ✧˖ ⋆" << std::endl;
      Sleep(2000);
      return 1;
    } else {
      showBattleScreen(enemy, player, true);
      std::cout << std::endl
                << GameResources::SPACES << "* Your mood's no good, it's a Defeat 🏳" << std::endl;
      Sleep(2000);
      return 0;
    }
  }

  bool frenchFrog(Character &player, Enemy &enemy) {

    enemy.setDialogue("F: Bonjour, I'm La Frogette! I have some French today. Let's see if you forget!");
    enemy.printDialogue();
    Sleep(2000);
    enemy.printFrog(enemy.getStatus(), enemy);
    Sleep(2000);
    unsigned short score = 0;
    std::vector<std::pair<std::string, std::string>> unusedWords = GameResources::frenchDictionary;

    for (int i = 0; i < 10; i++) {
      enemy.setLevel(enemy.getLevel() + 1);

      const unsigned short numOfCorrectWord = randInt(0, 41 - i);
      std::string meaning = unusedWords[numOfCorrectWord].first;
      std::string translation = unusedWords[numOfCorrectWord].second;

      std::string arrayOfWords[4] = {translation};

      unusedWords.erase(unusedWords.begin() + numOfCorrectWord);

      for (int j = 1; j < 4; j++) {
        const unsigned short randIndex = randInt(0, unusedWords.size() - 1);
        arrayOfWords[j] = unusedWords[randIndex].second;
      }

      shuffleArray(arrayOfWords, 4);

      enemy.setDialogue("MEANING: " + meaning);
      enemy.printDialogue();
      enemy.printFrog(enemy.getStatus(), enemy);
      Sleep(250);
      std::cout << GameResources::SPACES << GameResources::SPACES << GameResources::SPACES << "SCORE: " << score << std::endl;
      std::cout << GameResources::SPACES << "Choose the correct word:" << std::endl;
      std::cout << GameResources::SPACES << " 1. " << arrayOfWords[0] << " 2. " << arrayOfWords[1] << std::endl;
      std::cout << GameResources::SPACES << " 3. " << arrayOfWords[2] << " 4. " << arrayOfWords[3] << std::endl
                << std::endl;

      char choice;
      std::string choiceStr;

      do {
        choice = _getch();
      } while (choice < '1' || choice > '4');
      switch (choice) {
      case '1':
        choiceStr = arrayOfWords[0];
        break;
      case '2':
        choiceStr = arrayOfWords[1];
        break;
      case '3':
        choiceStr = arrayOfWords[2];
        break;
      case '4':
        choiceStr = arrayOfWords[3];
        break;
      default:
        choiceStr = arrayOfWords[3];
        break;
      }

      if (choiceStr == translation) {
        PlaySound(TEXT("../audio/scoreSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        std::string dialogue = GameResources::yesReplicas[randInt(0, 4)];
        enemy.setDialogue(dialogue);
        score++;
      } else {
        PlaySound(TEXT("../audio/wrongSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        std::string dialogue = GameResources::noReplicas[randInt(0, 4)] + translation;
        enemy.setDialogue(dialogue);
      }

      enemy.printDialogue();
      enemy.setHealth(enemy.getHealth() + 10);
    }
    PlaySound(TEXT("../audio/victorySound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    std::cout << std::endl
              << GameResources::SPACES
              << "Your final score is: " << score << std::endl;

    player.setLevel(player.getLevel() + 1);
    Sleep(1000);
    player.showStats();
    std::cout << std::endl
              << std::endl;
    return 0;
  }

  void ending() {
    std::cout << GameResources::SPACES << "To CONTINUE enter the password" << std::endl;
    std::cout << GameResources::SPACES << "HINT: If the soup we used to eat became a US state how would it sound like?" << std::endl;
    std::cout << GameResources::EXTRA_SPACES << "ENTER PASSWORD: > ";
    std::set<std::string> possibleInputs = {
        "MISSOSOUPI", // the best
        "MISSOSOUPIE",
        "MISSISOUPI",
        "MISOSOUPI",
        "MISOSOUPIE"};

    std::string input;
    while (possibleInputs.find(input) == possibleInputs.end()) {
      std::cin >> input;
      if (possibleInputs.find(input) == possibleInputs.end()) {
        std::cout << GameResources::SPACES << "Try again" << std::endl;
      }
    }
    PlaySound(TEXT("../audio/victorySound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    std::cout << std::endl;
    Sleep(1000);

    std::string ending = FileReader::readAsciiArt("./asciiArt/finalart.txt");
    std::cout << ending << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
  }
} // namespace Game
