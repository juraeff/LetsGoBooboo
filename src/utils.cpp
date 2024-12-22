#include "utils.h"
#include <random>

int randInt(int minInt, int maxInt) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(minInt, maxInt);
  return dis(gen);
}

void shuffleArray(std::string arr[], int n) {
  for (int i = n - 1; i > 0; i--) {
    int j = randInt(0, i);
    std::string temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
