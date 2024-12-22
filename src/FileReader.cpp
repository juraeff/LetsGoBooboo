#include "FileReader.h"
#include <stdexcept>
using namespace std;

std::string FileReader::readAsciiArt(const std::string &filename) {
  std::ifstream file(filename);
  std::string content;

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filename);
  }

  std::string line;
  while (std::getline(file, line)) {
    content += line + "\n";
  }

  file.close();
  return content;
}
