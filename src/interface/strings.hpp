#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>
#include <vector>

namespace strings
{

//! Function to search pattern in string using brute force.
//! param[in] source  string in which pattern is searched
//! param[in] pattern string to search in source
//! returns   collection of indexes of every pattern start in source
std::vector<int> searchPatternBruteForce(std::string source,
                                         std::string pattern);

//! Function to search pattern in string using Morris-Pratt algorithm.
std::vector<int> searchPatternMorrisPratt(std::string source,
                                          std::string pattern);
} // namespace strings

#endif // STRINGS_HPP