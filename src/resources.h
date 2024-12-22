#pragma once
#include <map>
#include <string>
#include <vector>

namespace GameResources {

  extern const std::string SPACES;       // 25
  extern const std::string EXTRA_SPACES; // 33
  extern const std::string barrierLine;  // 86 symbols

  extern const std::vector<std::pair<std::string, std::string>> frenchDictionary;

  extern const char *noReplicas[5];
  extern const char *yesReplicas[5];

  extern const char *storiesList[7];

  extern const char *jokesList[13];

  extern const char *complimentsList[7];

  extern const char *wormPositionsList[80];

} // namespace GameResources
