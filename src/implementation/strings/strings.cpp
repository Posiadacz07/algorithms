#include "../interface/strings.hpp"

#include <string>
#include <vector>

namespace strings
{

//! Helper function to check validity of source string and pattern string.
//! Some how sanity chaeck.
//! param[in] source  string in which pattern is searched
//! param[in] pattern string to search in source
//! returns
bool checkValidityOfSourceAndPattern(std::string source, std::string pattern)
{
  return source != "" && pattern != "" && pattern.length() <= source.length();
}

std::vector<int> searchPatternBruteForce(std::string source,
                                         std::string pattern)
{
  std::vector<int> result;
  if (!checkValidityOfSourceAndPattern(source, pattern))
  {
    return result;
  }

  for (int i = 0; i < source.length() - pattern.length() + 1; i++)
  {
    bool patternFound = true;
    for (int j = 0; j < pattern.length(); j++)
    {
      if (source[i + j] != pattern[j])
      {
        patternFound = false;
        break;
      }
    }

    if (patternFound)
    {
      result.push_back(i);
    }
  }
  return result;
}

//! Helper function to generate max prefix borders of pattern.
//! param[in] pattern string with pattern to search
//! returns   collection of max prefix borders of pattern
std::vector<int> generateMaxPrefixBorders(std::string pattern)
{
  if (pattern == "")
  {
    return {};
  }
  std::vector<int> result;
  result.reserve(pattern.length() + 1);
  result.at(0) = -1;
  int border = -1;

  for (int i = 0; i < pattern.length(); i++)
  {
    while (border > -1 && pattern[border] != pattern[i])
    {
      border = result.at(border);
    }
    border++;
    result.at(i) = border;
  }
  return result;
}

std::vector<int> searchPatternMorrisPratt(std::string source,
                                          std::string pattern)
{
  std::vector<int> result;
  if (!checkValidityOfSourceAndPattern(source, pattern))
  {
    return result;
  }

  std::vector<int> maxPrefixBorders = generateMaxPrefixBorders(pattern);
  int sourceIndex = 0;
  int patternIndex = 0;

  while (sourceIndex < source.length())
  {
    if (pattern[patternIndex] == source[sourceIndex])
    {
      patternIndex++;
      sourceIndex++;
      if (patternIndex == pattern.length())
      {
        result.push_back(sourceIndex - patternIndex);
      }
    }
    else
    {
      patternIndex = maxPrefixBorders[patternIndex];
      if (patternIndex < 0)
      {
        sourceIndex++;
        patternIndex++;
      }
    }
  }
  return result;
}
} // namespace strings
