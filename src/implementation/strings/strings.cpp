#include "../interface/strings.hpp"

#include <string>
#include <vector>

namespace strings {

std::vector<int> searchPatternBruteForce(std::string source,
                                         std::string pattern) {
  std::vector<int> result;
  if (source == "" || pattern == "" || pattern.length() > source.length()) {
    return result;
  }

  for (int i = 0; i < source.length() - pattern.length() + 1; i++) {
    bool patternFound = true;
    for (int j = 0; j < pattern.length(); j++) {
      if (source[i + j] != pattern[j]) {
        patternFound = false;
        break;
      }
    }

    if (patternFound) {
      result.push_back(i);
    }
  }
  return result;
}

} // namespace strings
