#include "../interface/strings.hpp"

#include <string>
#include <vector>

namespace strings
{

//! Helper function to check validity of source string and pattern string.
//! Some how sanity chaeck.
//! param[in] source  string in which pattern is searched
//! param[in] pattern string to search in source
//! returns   true if source and pattern are valid, false otherwise
bool checkValidityOfSourceAndPattern(std::string source, std::string pattern)
{
  return source != "" && pattern != "" && pattern.length() <= source.length();
}

//! Helper function to check if pattern is found in the source at given index.
//! param[in] source               string in which pattern is searched
//! param[in] pattern              string to search in source
//! param[in] currentIndexOfSource index in source string where pattern search starts
//! retruns   true if pattern is found at given index, false otherwise
bool checkPatternFound(const std::string &source,
                       const std::string &pattern,
                       int currentIndexOfSource)
{
  bool patternFound = true;
  for (int j = 0; j < pattern.length(); j++)
  {
    if (source[currentIndexOfSource + j] != pattern[j])
    {
      patternFound = false;
      break;
    }
  }
  return patternFound;
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
    bool patternFound = checkPatternFound(source, pattern, i);

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
  result[0] = -1;
  int border = -1;

  for (int i = 1; i <= pattern.length(); i++)
  {
    while (border > -1 && pattern[border] != pattern[i - 1])
    {
      border = result[border];
    }
    border++;
    result[i] = border;
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

//! Helper function to calculate hash for Karp-Rabin algorithm.
//! Hash is the sum of the all letters in ASCII.
//! param[in] word string to calculate hash
//! returns   calculated hash value
long long calculateHash(std::string word)
{
  long long result = 0;
  for (char letter : word)
  {
    result += letter;
  }
  return result;
}

std::vector<int> searchPatternKarpRabin(std::string source,
                                        std::string pattern)
{
  std::vector<int> result;
  if (!checkValidityOfSourceAndPattern(source, pattern))
  {
    return result;
  }

  long long patternHash = calculateHash(pattern);
  long long sourceHash = calculateHash(source.substr(0, pattern.length()));

  int i = 0;
  while (i + pattern.length() - 1 < source.length())
  {
    if (patternHash == sourceHash)
    {
      bool patternFound = checkPatternFound(source, pattern, i);

      if (patternFound)
      {
        result.push_back(i);
      }
    }

    i++;

    if (i + pattern.length() - 1 < source.length())
    {
      sourceHash = calculateHash(source.substr(i, pattern.length()));
    }
  }
  return result;
}

} // namespace strings
