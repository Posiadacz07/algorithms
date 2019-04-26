/*
 * Example of implemantation and usage of radix sort algorithm for integers.
 * As an output of the program is given numbers of sorted array.
 *
 * Made by: Posiadacz07
 */

#include <algorithm>
#include <vector>

namespace sort {

void countSort(std::vector<int> &array, int exp) {
  std::vector<int> result;
  result.resize(array.size());
  std::vector<int> count{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (int i : array)
    count.at((i / exp) % 10)++;

  for (int i = 1; i < count.size(); i++)
    count.at(i) += count.at(i - 1);

  for (auto i = array.rbegin(); i != array.rend(); ++i) {
    result.at(count.at((*i / exp) % 10) - 1) = *i;
    count.at((*i / exp) % 10)--;
  }

  for (int i = 0; i < array.size(); i++)
    array.at(i) = result.at(i);
}

void radixSort(std::vector<int> &array) {
  int maxValue = *(std::max_element(array.begin(), array.end()));

  for (int exp = 1; maxValue / exp > 0; exp *= 10)
    countSort(array, exp);
}

} // namespace sort
