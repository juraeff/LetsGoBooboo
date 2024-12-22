#pragma once
#include <fstream>
#include <string>

class FileReader {
public:
  static std::string readAsciiArt(const std::string &filename);
  // Можно добавить другие методы для работы с файлами
private:
  // Приватные методы, если нужны
};
